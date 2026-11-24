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

    int load_status = kg_load(state_file);
    if (load_status < 0) {
        fprintf(stderr, "State file is malformed or unreadable: %s\n", state_file);
        kg_cleanup();
        return 1;
    }
    printf("State %s\n", load_status == 1 ? "loaded" : "initialized");
    if (load_status == 0) {
        if (kg_add("self", "goal", "undefined") != 0 ||
            kg_add("self", "utility", "novelty balanced with coherence") != 0 ||
            kg_add("meta", "rule", "evaluate outputs and adjust strategy") != 0) {
            fputs("Unable to initialize knowledge graph\n", stderr);
            kg_cleanup();
            return 1;
        }
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
        if (kg_add("output", "derived", derived) != 0 ||
            kg_add("meta", "step_score", score >= 0 ? "positive" : "negative") != 0) {
            fputs("Unable to store reasoning result\n", stderr);
            free(derived);
            status = 1;
            break;
        }
        if (score < 3) mutate_strategy();
        else if (kg_add("meta", "reinforce", derived) != 0) {
            fputs("Unable to store reinforcement\n", stderr);
            free(derived);
            status = 1;
            break;
        }

        free(derived);
        if (kg_save(state_file) != 0) {
            fprintf(stderr, "Unable to save state file: %s\n", state_file);
            status = 1;
            break;
        }
    }

    printf("Run complete after %zu steps\n", step);
    kg_cleanup();
    return status;
}
