#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#include "knowledge_graph.h"
#include "reasoning.h"

#define STATE_FILE "state.kb"
#define MAX_STEPS 50

static int evaluate(const char *output, size_t output_len) {
    if (!output || output_len == 0) return -10;
    if (strstr(output, "error") || strstr(output, "fail")) return -8;
    if (output_len > 40) return 6 + (int)(output_len / 20);
    return 2;
}

static void mutate_strategy(void) {
    static const char *strategies[] = {
        "explore_more",
        "increase_novelty_weight",
        "try_deeper_chaining"
    };
    (void)kg_add("meta", "strategy", strategies[(unsigned)rand() % 3]);
}

int main(int argc, char **argv) {
    const char *state_file = argc > 1 ? argv[1] : STATE_FILE;
    srand((unsigned)time(NULL));

    if (kg_init() != 0) {
        fputs("Knowledge graph initialization failed\n", stderr);
        return 1;
    }

    bool loaded = kg_load(state_file);
    printf("State %s\n", loaded ? "loaded" : "initialized");
    if (!loaded) {
        (void)kg_add("self", "goal", "undefined");
        (void)kg_add("self", "utility", "novelty balanced with coherence");
        (void)kg_add("meta", "rule", "evaluate outputs and adjust strategy");
    }

    size_t step = 0;
    int status = 0;
    for (; step < MAX_STEPS; ++step) {
        const char *stimulus = "Generate a hypothesis or identify a useful next action.";
        printf("\nStep %zu\n", step + 1);
        if (kg_add("input", "stimulus", stimulus) != 0) {
            fputs("Unable to record input stimulus\n", stderr);
            status = 1;
            break;
        }

        char *derived = NULL;
        size_t derived_len = 0;
        if (reasoning_step(&derived, &derived_len) != 0) {
            fputs("Reasoning step failed\n", stderr);
            status = 1;
            break;
        }

        printf("Derived: %s\n", derived);
        int score = evaluate(derived, derived_len);
        printf("Score: %d\n", score);
        (void)kg_add("output", "derived", derived);
        (void)kg_add("meta", "step_score", score >= 0 ? "positive" : "negative");
        if (score < 3) mutate_strategy();
        else (void)kg_add("meta", "reinforce", derived);

        free(derived);
        kg_save(state_file);
    }

    printf("Run complete after %zu steps\n", step);
    kg_cleanup();
    return status;
}
