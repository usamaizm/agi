```C
// model.h

#ifndef MODEL_H
#define MODEL_H

#include "reasoning.h" // Include reasoning module header file
#include <stddef.h> // For size_t and NULL (optional)

// Define the Model structure with its members
typedef struct Model {
    const char* name;
    ReasoningModule* reasoning_module;
} Model;

// Declare function prototypes for the Model (init_model(), destroy_model, and any additional functions as needed)
void init_model(Model** model_ptr);
void destroy_model(Model* model);

#endif // MODEL_H
```
