#ifndef OUTPUT_H
#define OUTPUT_H

#include "module.h"  // Include the header file for the generic module

// Define the OutputModule structure
typedef struct {
    // Define output module-specific data structures or variables if needed
} OutputModule;

// Declaration of the output module initialization function
Module init_output_module();

// Declaration of function to display output
void display_output(Module output_module);

// Declaration of function to free memory for the output module
void free_output_module(Module output_module);

#endif  // OUTPUT_H
