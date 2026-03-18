#include "language.h"
#include "knowledge_graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int language_parse(const char* input) {
    if (!input || strlen(input) == 0) return -1;

    int added = 0;

    // Very crude parsing examples (expand with more rules later)
    if (strstr(input, "Generate next") || strstr(input, "hypothesis")) {
        kg_add("self", "task", "generate_hypothesis");
        kg_add("meta", "phase", "exploration");
        added += 2;
    } else if (strstr(input, "reflect") || strstr(input, "score")) {
        kg_add("self", "task", "self_reflect");
        added++;
    } else {
        // Generic fallback: store raw as observation
        char buf[256];
        snprintf(buf, sizeof(buf), "raw_input_%zu", time(NULL));
        kg_add("input", buf, input);
        added++;
    }

    // Could add more: entity extraction, relation guessing, etc.
    // For now: keep it simple so it compiles and adds something useful

    return added;
}