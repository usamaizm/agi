#ifndef IO_MODULE_H_
#define IO_MODULE_H_

#include "module.h" // Include the header file for the generic module

// Define the configuration structure for I/O module
typedef struct {
    int io_type;          // Type of I/O (e.g., console, file, etc.)
    const char* description;   // Description of the I/O device
} IOConfig;

// Add a blank line for readability
// Declaration of the initialization function for I/O module
Module init_io_module();

#endif // IO_MODULE_H_