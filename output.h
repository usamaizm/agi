#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdio.h>
#include <stdlib.h>

// Define the Module structure
typedef struct {
    int OUTPUT_MODULE_ID; // Unique identifier for the output module
    char name[100]; // Increased buffer size to handle longer names
} Module;

// Declare functions related to the output module
Module* initOutputModule();
void displayOutput(const Module* outputModule);
void freeOutputModule(Module* outputModule);

#endif // OUTPUT_H