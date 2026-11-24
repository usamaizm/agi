#ifndef KNOWLEDGE_GRAPH_H
#define KNOWLEDGE_GRAPH_H

#include <stddef.h>

int kg_init(void);
int kg_load(const char *filename); /* 1 loaded, 0 missing, -1 malformed or I/O error */
int kg_save(const char *filename); /* 0 on success, -1 on failure */
int kg_add(const char *subject, const char *predicate, const char *object);
char *kg_query(const char *subject, const char *predicate, const char *object); /* caller owns and must free the result */
void kg_cleanup(void);

#endif
