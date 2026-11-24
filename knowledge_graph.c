#include "knowledge_graph.h"

#include <errno.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

static int decode_field(char *field) {
    char *read_pos = field;
    char *write_pos = field;
    while (*read_pos) {
        if (*read_pos != '\\') {
            *write_pos++ = *read_pos++;
            continue;
        }
        ++read_pos;
        if (!*read_pos) return -1;
        switch (*read_pos++) {
            case '\\': *write_pos++ = '\\'; break;
            case 't': *write_pos++ = '\t'; break;
            case 'n': *write_pos++ = '\n'; break;
            case 'r': *write_pos++ = '\r'; break;
            default: return -1;
        }
    }
    *write_pos = '\0';
    return 0;
}

static int parse_record(char *line, bool escaped) {
    char *first = strchr(line, '\t');
    if (!first) return -1;
    *first++ = '\0';
    char *second = strchr(first, '\t');
    if (!second) return -1;
    *second++ = '\0';
    if (strchr(second, '\t')) return -1;
    if (escaped && (decode_field(line) != 0 ||
                    decode_field(first) != 0 ||
                    decode_field(second) != 0)) return -1;
    return kg_add(line, first, second);
}

int kg_load(const char *filename) {
    if (!filename || (!triples && kg_init() != 0)) return -1;
    FILE *file = fopen(filename, "r");
    if (!file) return errno == ENOENT ? 0 : -1;

    char *line = NULL;
    size_t line_capacity = 0;
    size_t starting_count = triple_count;
    bool success = true;
    bool first_line = true;
    bool escaped_format = false;
    ssize_t length;

    while ((length = getline(&line, &line_capacity, file)) != -1) {
        while (length > 0 && (line[length - 1] == '\n' || line[length - 1] == '\r'))
            line[--length] = '\0';
        if (first_line) {
            first_line = false;
            if (strcmp(line, "# AGI-KG 1") == 0) {
                escaped_format = true;
                continue;
            }
        }
        if (parse_record(line, escaped_format) != 0) {
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
        return -1;
    }
    return 1;
}

static int write_escaped(FILE *file, const char *value) {
    for (const unsigned char *p = (const unsigned char *)value; *p; ++p) {
        const char *escape = NULL;
        switch (*p) {
            case '\\': escape = "\\\\"; break;
            case '\t': escape = "\\t"; break;
            case '\n': escape = "\\n"; break;
            case '\r': escape = "\\r"; break;
            default:
                if (fputc(*p, file) == EOF) return -1;
                continue;
        }
        if (fputs(escape, file) == EOF) return -1;
    }
    return 0;
}

int kg_save(const char *filename) {
    if (!filename || !triples) return -1;
    size_t filename_length = strlen(filename);
    if (filename_length > SIZE_MAX - sizeof(".tmp.XXXXXX")) return -1;
    char *temporary = malloc(filename_length + sizeof(".tmp.XXXXXX"));
    if (!temporary) return -1;
    (void)snprintf(temporary, filename_length + sizeof(".tmp.XXXXXX"),
                   "%s.tmp.XXXXXX", filename);

    int fd = mkstemp(temporary);
    if (fd < 0) {
        free(temporary);
        return -1;
    }
    FILE *file = fdopen(fd, "w");
    if (!file) {
        (void)close(fd);
        (void)unlink(temporary);
        free(temporary);
        return -1;
    }

    int status = fputs("# AGI-KG 1\n", file) == EOF ? -1 : 0;
    for (size_t i = 0; status == 0 && i < triple_count; ++i) {
        const Triple *item = &triples[i];
        if (write_escaped(file, item->subject) != 0 ||
            fputc('\t', file) == EOF ||
            write_escaped(file, item->predicate) != 0 ||
            fputc('\t', file) == EOF ||
            write_escaped(file, item->object) != 0 ||
            fputc('\n', file) == EOF) status = -1;
    }
    if (status == 0 && fflush(file) != 0) status = -1;
    if (status == 0 && fsync(fd) != 0) status = -1;
    if (fclose(file) != 0) status = -1;
    if (status == 0 && rename(temporary, filename) != 0) status = -1;
    if (status != 0) (void)unlink(temporary);
    free(temporary);
    return status;
}
