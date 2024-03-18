#ifndef AUDIO_H
#define AUDIO_H

#include "module.h"  // Include reasoning module header file (as per the other modules)

// Define the AudioConfig structure
typedef struct {
    int sample_rate;  // Sample rate (e.g., samples per second)
    int channels;  // Number of audio channels (e.g., mono, stereo)
} AudioConfig;

// Declaration of the audio module initialization function
Module init_audio_module();

#endif  // AUDIO_H
