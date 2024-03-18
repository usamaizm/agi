#ifndef INPUT_H_
#define INPUT_H_

#include "module.h" // Include the header file for the generic module

typedef struct {
    int input_type;        // Type of input (e.g., keyboard, mouse, etc.)
    const char* description;   // Description of the input device
} InputConfig;

Module init_input_module(); // Declaration of the input module initialization function

#endif // INPUT_H_