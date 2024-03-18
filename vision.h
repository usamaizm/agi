#ifndef VISION_H
#define VISION_H

// Include necessary headers
#include <stdlib.h>

// Define the ConfiguredVision structure to hold vision configuration settings
typedef struct {
    int height;  // Height of the vision output
    int width;   // Width of the vision output
    // Add more configuration settings as needed
} ConfiguredVision;

// Define the VisionModule structure to encapsulate vision-related functionalities
typedef struct {
    ConfiguredVision *visionConfig;  // Pointer to the configured vision settings
} VisionModule;

// Function declarations

// Function to configure vision settings and update the output structure
void config_vision(ConfiguredVision *output);

// Function to initialize a new instance of the VisionModule structure
Module init_vision_module();

#endif  // VISION_H