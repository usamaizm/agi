```c
// vision.c

#include "vision.h"  // Include the header file for the vision module

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
    vision_module.vision = malloc(sizeof(ConfiguredVision));
    config_vision((ConfiguredVision *) vision_module.vision);

    return vision_module;
}
```
