#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "module.h"  // Include the header file for the generic module

// Define the LanguageConfig structure
typedef struct {
    const char* language_type;  // Type of language (e.g., English, Spanish, etc.)
    int version;  // Version of the language
} LanguageConfig;

// Declaration of the language module initialization function
Module init_language_module();

// Declaration of function to execute language processing tasks
void execute_language_tasks(Module language_module);

// Declaration of function to free memory for the language module
void free_language_module(Module language_module);

#endif // LANGUAGE_H
