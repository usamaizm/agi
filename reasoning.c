#include "reasoning.h"
#include "knowledge_graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *copy_string(const char *value) {
    size_t length = strlen(value);
    char *copy = malloc(length + 1);
    if (copy) memcpy(copy, value, length + 1);
    return copy;
}

int reasoning_step(char **derived, size_t *derived_len) {
    if (!derived || !derived_len) return -1;
    *derived = NULL;
    *derived_len = 0;

    char *stimulus = kg_query("input", "stimulus", NULL);
    if (stimulus) {
        const char prefix[] = "Observed and reflected: ";
        size_t prefix_len = sizeof(prefix) - 1;
        size_t stimulus_len = strlen(stimulus);
        if (stimulus_len > SIZE_MAX - prefix_len - 1) {
            free(stimulus);
            return -1;
        }
        *derived = malloc(prefix_len + stimulus_len + 1);
        if (*derived) {
            memcpy(*derived, prefix, prefix_len);
            memcpy(*derived + prefix_len, stimulus, stimulus_len + 1);
        }
        free(stimulus);
    } else {
        *derived = copy_string("No strong signal detected. Exploring cautiously.");
    }

    if (!*derived) return -1;
    *derived_len = strlen(*derived);
    return 0;
}
