#include "reasoning.h"
#include "knowledge_graph.h"  // for kg_query, etc.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reasoning_step(char** derived, size_t* derived_len) {
    if (!derived || !derived_len) return -1;

    *derived = NULL;
    *derived_len = 0;

    // Example 1: Check for recent stimulus and echo/reflect it
    char* stimulus = kg_query("input", "stimulus", NULL);
    if (stimulus) {
        // Simple derivation: "Observed: [stimulus]"
        char buf[256];
        snprintf(buf, sizeof(buf), "Observed and reflected: %s", stimulus);
        *derived = strdup(buf);
        if (*derived) {
            *derived_len = strlen(*derived);
            free(stimulus);  // if kg_query allocates (as in the earlier KG example)
            return 0;        // success
        }
        free(stimulus);
    }

    // Example 2: Check meta strategy and use it
    char* strategy = kg_query("meta", "strategy", NULL);
    if (strategy) {
        char buf[128];
        snprintf(buf, sizeof(buf), "Applying strategy: %s", strategy);
        *derived = strdup(buf);
        if (*derived) {
            *derived_len = strlen(*derived);
            free(strategy);
            return 0;
        }
        free(strategy);
    }

    // Fallback: generic output if nothing found
    *derived = strdup("No strong signal detected. Exploring randomly.");
    if (*derived) {
        *derived_len = strlen(*derived);
        return 0;
    }

    return -1;  // allocation failed or no idea
}