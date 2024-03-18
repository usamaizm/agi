#ifndef IO_H
#define IO_H

#include "module.h"  // Include necessary headers

// Define the IOConfig structure
typedef struct {
    int io_type;  // Type of I/O (e.g., console, file, network, etc.)
    const char* description;  // Description of the I/O device or system
} IOConfig;

// Declaration of the I/O module initialization function
Module init_io_module();

#endif  // IO_H
