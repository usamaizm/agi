// module.h

#ifndef MODULE_H
#define MODULE_H

// Define the Module structure
typedef struct Module {
    // Add members relevant to the module
    // For example:
    int id;
    char name[50];
    // Add other data members as needed
} Module;

// Declare functions related to module initialization or operations
Module init_language_module();
Module init_vision_module();
Module init_reasoning_module();
Module init_knowledge_graph();

#endif  // MODULE_H