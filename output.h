// output.h

#ifndef OUTPUT_H
#define OUTPUT_H

#include "module.h"  // Include the header file for the generic module

// Define the OutputModule structure
typedef struct OutputModule {
    // Define output module-specific data structures or variables if needed
} OutputModule;

Module init_output_module();  // Declaration of the output module initialization function
void display_output(Module output_module);  // Declaration of function to display output
// Add more output-related function prototypes as needed

#endif  // OUTPUT_H