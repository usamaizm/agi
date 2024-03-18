#include "module.h"
#include "vision.h"

typedef struct {
    int height;
    int width;
} ConfiguredVision;

void config_vision(ConfiguredVision *output) {
    output->height = 320;
    output->width = 480;
}

Module init_vision_module() {
    Module vision_module;
    vision_module.type = "Vision";
    vision_module.functions = NULL;  // Placeholder for vision-specific functions
    vision_module.vision = malloc(sizeof(ConfiguredVision));
    config_vision((ConfiguredVision *) vision_module.vision);

    return vision_module;
}
