// agi.h

#ifndef AGI_H
#define AGI_H

#include "language.h"
#include "vision.h"
#include "audio.h"
#include "io.h"
#include "reasoning.h"
#include "knowledge_graph.h"

// Define the AGI structure
typedef struct agi {
    Module language;
    Module vision;
    Module audio;
    Module io;
    Module reasoning;
    KnowledgeGraph kg;
} agi;

// Function prototypes for AGI system initialization and execution
agi init_agi();
void run_agi(agi agi);

#endif  // AGI_H
