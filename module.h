#ifndef MODULE_H
#define MODULE_H

#include <stdio.h>  // Include necessary headers
#include <dlfcn.h>  // Include dynamic linking functions (dlopen, dlsym, dlclose)

// Define a standardized module interface
typedef struct {
    void (*init)(void);      // Function to initialize the module
    void (*execute)(void);   // Function to execute tasks using the module
    void (*cleanup)(void);   // Function to clean up resources after execution
} ModuleInterface;

// Define a structure to represent modules
typedef struct {
    const char* name;        // Name of the module
    ModuleInterface interface;  // Interface containing function pointers
    void* handle;            // Handle for dynamic linking
} ModuleContext;  // Renamed from Module to ModuleContext as suggested

// Function to dynamically load a module and initialize it
ModuleContext* load_module(const char* module_name);

// Function to execute tasks using the loaded module
void execute_tasks(ModuleContext* module);

// Function to unload a module and clean up resources
void unload_module(ModuleContext* module);

#endif // MODULE_H