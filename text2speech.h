#ifndef TEXT2SPEECH_H
#define TEXT2SPEECH_H

// Include necessary headers
#include "module.h"

// Define the Text2SpeechModule structure
typedef struct {
    void* speech_engine_settings;  // Pointer to speech engine settings or resources
} Text2SpeechModule;

// Function declarations

/**
 * @brief Initialize the text-to-speech module.
 * 
 * @param module Pointer to the Text2SpeechModule structure.
 */
void initialize_text2speech(Text2SpeechModule* module);

/**
 * @brief Convert text to speech using the text-to-speech engine.
 * 
 * @param module Pointer to the Text2SpeechModule structure.
 * @param text The text to be converted to speech.
 */
void convert_text_to_speech(Text2SpeechModule* module, const char* text);

/**
 * @brief Cleanup resources used by the text-to-speech module.
 * 
 * @param module Pointer to the Text2SpeechModule structure.
 */
void cleanup_text2speech(Text2SpeechModule* module);

#endif  // TEXT2SPEECH_H