#include "output.h"

Module* initOutputModule() {
    // Allocate memory for the output module
    Module* outputModule = malloc(sizeof(Module));

    // Initialize module ID and name
    outputModule->OUTPUT_MODULE_ID = 1;
    snprintf(outputModule->name, sizeof(outputModule->name), "Output Module");

    return outputModule;
}

void displayOutput(const Module* outputModule) {
    // Improved formatting string to handle longer module names and display name length
    printf("Displaying output for module ID: %d, Name: %s (%zu bytes)\n",
           outputModule->OUTPUT_MODULE_ID, outputModule->name, strlen(outputModule->name));
}

void freeOutputModule(Module* outputModule) {
    free(outputModule); // Free allocated memory for the output module
}