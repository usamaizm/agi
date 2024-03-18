#include "audio.h"

void configure_audio(AudioConfig *output) {
    output->sample_rate = 44100; // Default sample rate
    output->channels = 2; // Default number of channels (stereo)
}

Module init_audio_module() {
    Module audio_module;
    audio_module.type = "Audio";
    audio_module.functions = NULL; // Placeholder for audio-specific functions

    // Error handling for malloc()
    AudioConfig *audio_config = malloc(sizeof(AudioConfig));
    if (audio_config == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for AudioConfig\n");
        exit(EXIT_FAILURE); // Exit the program if memory allocation fails
    }

    configure_audio(audio_config);
    audio_module.data = audio_config;
    return audio_module;
}