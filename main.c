#include <stdio.h>
#include "ai.h"  // Include header file for AI module
#include "text2speech.h"  // Include header file for text-to-speech module
#include "speech2text.h"  // Include header file for speech-to-text module

int main() {
    // Initialize modules
    Module aiModule = init_ai_module();
    Module text2SpeechModule = init_text2speech_module();
    Module speech2TextModule = init_speech2text_module();

    // Sample input text
    const char* inputText = "Hello, how are you?";

    // Process input text using AI module
    process_input_text(aiModule, inputText);

    // Convert input text to speech using text-to-speech module
    convert_text_to_speech(text2SpeechModule, inputText);

    // Sample spoken text (from speech-to-text)
    const char* spokenText = "I'm doing well, thank you.";

    // Process spoken text using speech-to-text module
    process_spoken_text(speech2TextModule, spokenText);

    // Clean up and free memory for modules
    free_ai_module(aiModule);
    free_text2speech_module(text2SpeechModule);
    free_speech2text_module(speech2TextModule);

    return 0;
}