#ifndef REASONING_H
#define REASONING_H

// Define the ReasoningModule structure
typedef struct {
    void* context;  // Context of the current execution environment (optional)
    int type;       // Type of reasoning task to be executed (e.g. inference, abduction, etc.)
} ReasoningModule;

// Declaration of the reasoning module initialization function
Module init_reasoning_module();

// Declaration of function to execute reasoning tasks
void execute_reasoning_tasks(Module reasoning_module);

// Declaration of function to free memory for the reasoning module
void free_reasoning_module(Module reasoning_module);

#endif // REASONING_H
