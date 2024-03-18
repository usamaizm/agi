#ifndef TEXT_H
#define TEXT_H

#include "module.h"  // Include any necessary headers

// Define the TextModule structure for handling text-related operations
typedef struct {
    // Define text module-specific data structures or variables here if needed
    // For example:
    int wordCount;  // Variable to store the word count
    // Add more variables as needed for text processing
} TextModule;

// Declaration of the text module initialization function
// This function initializes a new instance of the TextModule structure and returns a Module object
Module init_text_module();

// Declaration of the function to process text (e.g., word counting, text analysis, etc.)
void process_text(Module text_module, const char* input);

// Declaration of additional text processing functions
// Example:
void format_text(Module text_module, const char* input);
void analyze_text(Module text_module, const char* input);

#endif  // TEXT_H