#include "knowledge_graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRIPLES 10000  // arbitrary limit to start

typedef struct {
    char* subject;
    char* predicate;
    char* object;
} Triple;

static Triple* triples = NULL;
static size_t triple_count = 0;
static size_t capacity = 0;

int kg_init(void) {
    if (triples) return 0;  // already init

    capacity = 1024;
    triples = calloc(capacity, sizeof(Triple));
    if (!triples) return -1;

    triple_count = 0;
    return 0;
}

void kg_cleanup(void) {
    if (!triples) return;
    for (size_t i = 0; i < triple_count; i++) {
        free(triples[i].subject);
        free(triples[i].predicate);
        free(triples[i].object);
    }
    free(triples);
    triples = NULL;
    triple_count = capacity = 0;
}

static int add_triple(const char* s, const char* p, const char* o) {
    if (triple_count >= capacity) {
        capacity *= 2;
        Triple* new = realloc(triples, capacity * sizeof(Triple));
        if (!new) return -1;
        triples = new;
    }

    triples[triple_count].subject   = s ? strdup(s) : NULL;
    triples[triple_count].predicate = p ? strdup(p) : NULL;
    triples[triple_count].object    = o ? strdup(o) : NULL;
    triple_count++;
    return 0;
}

int kg_add(const char* subject, const char* predicate, const char* object) {
    if (!subject || !predicate || !object) return -1;
    return add_triple(subject, predicate, object);
}

char* kg_query(const char* subject, const char* predicate, const char* object) {
    // Very basic: return first matching object (exact match)
    // NULL means no match or error
    if (!triples) return NULL;

    for (size_t i = 0; i < triple_count; i++) {
        if (triples[i].subject && triples[i].predicate && triples[i].object &&
            strcmp(triples[i].subject, subject) == 0 &&
            (predicate == NULL || strcmp(triples[i].predicate, predicate) == 0) &&
            (object == NULL || strcmp(triples[i].object, object) == 0)) {
            return strdup(triples[i].object);
        }
    }
    return NULL;
}

bool kg_load(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) return false;

    char line[1024];
    bool success = true;

    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = 0;  // trim newline
        char* s = strtok(line, "\t");
        char* p = strtok(NULL, "\t");
        char* o = strtok(NULL, "\t");
        if (s && p && o) {
            if (add_triple(s, p, o) != 0) {
                success = false;
                break;
            }
        }
    }
    fclose(fp);
    return success;
}

void kg_save(const char* filename) {
    FILE* fp = fopen(filename, "w");
    if (!fp) return;

    for (size_t i = 0; i < triple_count; i++) {
        if (triples[i].subject && triples[i].predicate && triples[i].object) {
            fprintf(fp, "%s\t%s\t%s\n",
                    triples[i].subject,
                    triples[i].predicate,
                    triples[i].object);
        }
    }
    fclose(fp);
}