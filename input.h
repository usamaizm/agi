#ifndef INPUT_H
#define INPUT_H

#include "module.h"  // Include the header file for the generic module

// Define the InputConfig structure
typedef struct {
    int input_type;  // Type of input (e.g., keyboard, mouse, etc.)
    const char* description;  // Description of the input device
} InputConfig;

// Declaration of the input module initialization function
Module init_input_module();

#endif  // INPUT_H
