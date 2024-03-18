#ifndef SPEECH_H
#define SPEECH_H

#include "module.h"  // Include the header file for the generic module

// Define the SpeechModule structure
typedef struct {
    // Define speech module-specific data structures or variables if needed
    // For example:
    // const char* voice;
} SpeechModule;

// Declaration of the speech module initialization function
// This function initializes a new instance of the speech module.
Module init_speech_module();

// Declaration of function to process speech
// This function processes input speech using the provided speech module.
void process_speech(Module speech_module, const char* input);

// Declaration of function to free memory for the speech module
// This function frees the memory allocated for the speech module.
void free_speech_module(Module speech_module);

#endif  // SPEECH_H