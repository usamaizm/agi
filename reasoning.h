#ifndef REASONING_H
#define REASONING_H

#include <stddef.h>  // Include standard library for size_t (optional)
#include "module.h"  // Include the header file for the generic module (if needed)

// Define the ReasoningModule structure
typedef struct {
    void* context;  // Context of the current execution environment (optional)
    int type;       // Type of reasoning task to be executed (e.g. inference, abduction, etc.)
} ReasoningModule;

// Declaration of the reasoning module initialization function
// Returns a pointer to a newly initialized ReasoningModule
ReasoningModule* init_reasoning_module();

// Declaration of function to execute reasoning tasks
// Takes a pointer to a ReasoningModule as input
void execute_reasoning_tasks(ReasoningModule* reasoning_module);

// Declaration of function to free memory for the reasoning module
// Takes a pointer to a ReasoningModule as input
void free_reasoning_module(ReasoningModule* reasoning_module);

#endif // REASONING_H