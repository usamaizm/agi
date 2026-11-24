#include "knowledge_graph.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *subject;
    char *predicate;
    char *object;
} Triple;

static Triple *triples = NULL;
static size_t triple_count = 0;
static size_t capacity = 0;

static char *copy_string(const char *value) {
    if (!value) return NULL;
    size_t length = strlen(value);
    char *copy = malloc(length + 1);
    if (copy) memcpy(copy, value, length + 1);
    return copy;
}

int kg_init(void) {
    if (triples) return 0;
    capacity = 32;
    triples = calloc(capacity, sizeof(*triples));
    if (!triples) {
        capacity = 0;
        return -1;
    }
    triple_count = 0;
    return 0;
}

void kg_cleanup(void) {
    if (!triples) return;
    for (size_t i = 0; i < triple_count; ++i) {
        free(triples[i].subject);
        free(triples[i].predicate);
        free(triples[i].object);
    }
    free(triples);
    triples = NULL;
    triple_count = 0;
    capacity = 0;
}

static int add_triple(const char *subject, const char *predicate, const char *object) {
    if (!triples && kg_init() != 0) return -1;
    if (triple_count == capacity) {
        if (capacity > SIZE_MAX / 2 || capacity * 2 > SIZE_MAX / sizeof(*triples)) return -1;
        size_t next_capacity = capacity * 2;
        Triple *grown = realloc(triples, next_capacity * sizeof(*triples));
        if (!grown) return -1;
        triples = grown;
        capacity = next_capacity;
    }

    char *s = copy_string(subject);
    char *p = copy_string(predicate);
    char *o = copy_string(object);
    if (!s || !p || !o) {
        free(s);
        free(p);
        free(o);
        return -1;
    }

    triples[triple_count].subject = s;
    triples[triple_count].predicate = p;
    triples[triple_count].object = o;
    ++triple_count;
    return 0;
}

int kg_add(const char *subject, const char *predicate, const char *object) {
    if (!subject || !predicate || !object) return -1;
    return add_triple(subject, predicate, object);
}

char *kg_query(const char *subject, const char *predicate, const char *object) {
    if (!triples || !subject) return NULL;
    for (size_t i = 0; i < triple_count; ++i) {
        const Triple *item = &triples[i];
        if (strcmp(item->subject, subject) == 0 &&
            (!predicate || strcmp(item->predicate, predicate) == 0) &&
            (!object || strcmp(item->object, object) == 0)) {
            return copy_string(item->object);
        }
    }
    return NULL;
}

bool kg_load(const char *filename) {
    if (!filename || (!triples && kg_init() != 0)) return false;
    FILE *file = fopen(filename, "r");
    if (!file) return false;

    char *line = NULL;
    size_t line_capacity = 0;
    size_t starting_count = triple_count;
    bool success = true;
    while (getline(&line, &line_capacity, file) != -1) {
        line[strcspn(line, "\r\n")] = '\0';
        char *subject = strtok(line, "\t");
        char *predicate = strtok(NULL, "\t");
        char *object = strtok(NULL, "\t");
        if (!subject || !predicate || !object || strtok(NULL, "\t") != NULL) {
            success = false;
            break;
        }
        if (kg_add(subject, predicate, object) != 0) {
            success = false;
            break;
        }
    }
    if (ferror(file)) success = false;
    free(line);
    if (fclose(file) != 0) success = false;
    if (!success) {
        while (triple_count > starting_count) {
            Triple *item = &triples[--triple_count];
            free(item->subject);
            free(item->predicate);
            free(item->object);
            item->subject = NULL;
            item->predicate = NULL;
            item->object = NULL;
        }
    }
    return success;
}

void kg_save(const char *filename) {
    if (!filename || !triples) return;
    FILE *file = fopen(filename, "w");
    if (!file) return;
    for (size_t i = 0; i < triple_count; ++i) {
        if (fprintf(file, "%s\t%s\t%s\n",
                    triples[i].subject, triples[i].predicate, triples[i].object) < 0) {
            break;
        }
    }
    (void)fclose(file);
}
