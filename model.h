#ifndef MODEL_H
#define MODEL_H

#include <memory>  // Include smart pointer header

// Define the ReasoningModule structure (example)
typedef struct {
    // Reasoning module details...
} ReasoningModule;

// Define the Model structure with its members
typedef struct {
    const char* modelName;  // Name of the model using camelCase
    std::unique_ptr<ReasoningModule> reasoningModulePtr;  // Smart pointer to the reasoning module
} Model;  // Represents a model used in the AGI system

// Declare function prototypes for the Model
void initModel(std::unique_ptr<Model>* modelPtr);  // Initialize a model using smart pointer
void destroyModel(Model* model);  // Destroy a model and free associated memory using camelCase

#endif // MODEL_H