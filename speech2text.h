#ifndef SPEECH_2_TEXT_H
#define SPEECH_2_TEXT_H

// Include any necessary headers

// Define the Speech2TextModule structure
typedef struct {
    const char* language;  // Language setting for speech-to-text conversion
    // Add more configuration settings as needed
} Speech2TextModule;

// Function declarations
void init_speech_2_text_module(Speech2TextModule *speech_2_text_module);
// Initializes the Speech2TextModule structure with default settings

char* convert_speech_to_text(const char* speech_input, Speech2TextModule *speech_2_text_module);
// Converts speech input to text using the provided Speech2TextModule settings

void free_speech_2_text_module(Speech2TextModule *speech_2_text_module);
// Frees memory allocated for the Speech2TextModule structure

#endif  // SPEECH_2_TEXT_H