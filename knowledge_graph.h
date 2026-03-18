#ifndef KNOWLEDGE_GRAPH_H
#define KNOWLEDGE_GRAPH_H

#include <stdbool.h>
#include <stddef.h>  // for size_t

int kg_init(void);                    // 0 on success
bool kg_load(const char* filename);   // true if loaded successfully
void kg_save(const char* filename);
int kg_add(const char* subject, const char* predicate, const char* object);
char* kg_query(const char* subject, const char* predicate, const char* object);  // returns object or NULL; caller frees?
void kg_cleanup(void);

#endif