#ifndef SPEECH_H
#define SPEECH_H

#include "module.h"  // Include any necessary headers

// Define the SpeechConfig structure
typedef struct {
    int rate;  // Speech rate (e.g., samples per second)
    const char* language;  // Speech language (e.g., English, Spanish, etc.)
} SpeechConfig;

// Declaration of the speech module initialization function
Module init_speech_module();

#endif  // SPEECH_H
