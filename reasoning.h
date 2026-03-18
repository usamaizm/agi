#ifndef REASONING_H
#define REASONING_H

#include <stdbool.h>
#include <stddef.h>  // for size_t

/**
 * Perform one step of reasoning.
 * - Uses current knowledge_graph state.
 * - Allocates and sets *derived to a new string summary/conclusion/hypothesis (caller must free).
 * - Sets *derived_len to strlen(*derived).
 * - Returns 0 on success (produced output), non-zero on failure/no derivation.
 */
int reasoning_step(char** derived, size_t* derived_len);

#endif