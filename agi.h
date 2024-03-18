#ifndef AGI_H
#define AGI_H

#include "language.h"
#include "vision.h"
#include "audio.h"
#include "io.h"
#include "reasoning.h"
#include "knowledge.h" // Updated header name

// Define the AGI structure
typedef struct {
    Module language;
    Module vision;
    Module audio;
    Module io;
    Module reasoning;
    Knowledge kg; // Updated member name
} AGI;

// Function prototypes for AGI system initialization and execution
AGI init_agi();
void run_agi(AGI agi);

#endif  // AGI_H