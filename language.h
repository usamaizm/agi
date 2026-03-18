#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <stdbool.h>
#include <stddef.h>

/**
 * Parse natural or synthetic text input into knowledge graph facts.
 * - input: text string (e.g. "Generate next hypothesis" or user input)
 * - Adds parsed triples directly to KG (via kg_add calls)
 * - Returns number of facts added, or -1 on error
 */
int language_parse(const char* input);

#endif