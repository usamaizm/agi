#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

// Core headers — comment out any that do not exist or compile yet
#include "knowledge_graph.h"
// #include "reasoning.h"
// #include "language.h"
// #include "output.h"
// #include "vision.h"
// #include "speech2text.h"
// #include "model.h"
// #include "agi.h"
// #include "ai.h"

#define STATE_FILE "state.kb"
#define MAX_STEPS 500
#define INPUT_BUFFER_SIZE 1024

static int evaluate(const char* output, size_t output_len) {
    if (output_len == 0) return -10;
    if (strstr(output, "error") || strstr(output, "fail")) return -8;
    if (output_len > 40) return 6 + (int)(output_len / 20);
    return 2;
}

static void mutate_self(void) {
    int r = rand() % 3;
    if (r == 0) {
        kg_add("meta", "strategy", "explore_more");
    } else if (r == 1) {
        kg_add("meta", "utility", "increase_novelty_weight");
    } else {
        kg_add("meta", "adjustment", "try_deeper_chaining");
    }
}

int main(void) {
    srand((unsigned)time(NULL));

    if (kg_init() != 0) {
        fprintf(stderr, "Knowledge graph init failed\n");
        return 1;
    }

    bool loaded = kg_load(STATE_FILE);
    printf("State %s\n", loaded ? "loaded" : "initialized");

    if (!loaded) {
        kg_add("self", "goal", "undefined");
        kg_add("self", "utility", "max_novelty + coherence");
        kg_add("meta", "rule", "if low_score then mutate");
    }

    size_t step = 0;
    char input_buffer[INPUT_BUFFER_SIZE];

    while (step < MAX_STEPS) {
        step++;
        printf("\nStep %zu\n", step);

        const char* stimulus = "Generate next hypothesis or action.";
        // For interactive mode (uncomment when ready):
        // printf("> ");
        // if (fgets(input_buffer, sizeof(input_buffer), stdin) && input_buffer[0] != '\n') {
        //     stimulus = input_buffer;
        //     stimulus[strcspn(stimulus, "\n")] = 0;
        // }

        kg_add("input", "stimulus", stimulus);

        char* derived = NULL;
        size_t derived_len = 0;

        // Placeholder — replace with actual call when reasoning module exists
        // int reason_ok = reasoning_step(&derived, &derived_len);
        int reason_ok = -1;

        if (reason_ok == 0 && derived && derived_len > 0) {
            printf("Derived: %s\n", derived);
            kg_add("output", "derived", derived);
        } else {
            derived = strdup("no_output");
            derived_len = 9;
        }

        int score = evaluate(derived, derived_len);
        printf("Score: %d\n", score);

        kg_add("meta", "step_score", (score >= 0 ? "positive" : "negative"));

        if (score < 3) {
            mutate_self();
        } else {
            kg_add("meta", "reinforce", derived ? derived : "good_step");
        }

        kg_save(STATE_FILE);

        if (derived) free(derived);
    }

    printf("Run complete after %zu steps\n", step);
    kg_cleanup();
    return 0;
}