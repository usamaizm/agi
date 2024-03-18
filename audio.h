#ifndef AUDIO_H
#define AUDIO_H

// Include necessary headers
#include <stdio.h>
#include <stdlib.h>

// Define AudioConfig structure
typedef struct {
    int sample_rate;
    int channels;
} AudioConfig;

// Function prototype for configuring audio
void configure_audio(AudioConfig *output);

// Function prototype for initializing audio module
Module init_audio_module();

#endif  // AUDIO_H