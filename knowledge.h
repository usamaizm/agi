#ifndef KNOWLEDGE_H
#define KNOWLEDGE_H

#include "module.h"  // Include necessary headers

// Define the KnowledgeConfig structure
typedef struct {
    int nodes;  // Number of nodes in the knowledge graph
    int edges;  // Number of edges in the knowledge graph
} KnowledgeConfig;

// Define the Knowledge structure
typedef struct {
    const char* type;  // Type of the knowledge graph
    int nodes;  // Number of nodes in the knowledge graph
    int edges;  // Number of edges in the knowledge graph
    KnowledgeConfig* config;  // Configuration for the knowledge graph
} Knowledge;  // Represents a knowledge graph with its configuration

// Declaration of the knowledge initialization function
// This function initializes the knowledge graph and returns a Knowledge struct
Knowledge init_knowledge();

// Declaration of function to store knowledge in the knowledge graph
void store_knowledge(Knowledge* knowledge, const char* data);

// Declaration of function to retrieve knowledge from the knowledge graph
void retrieve_knowledge(Knowledge* knowledge, const char* query);

#endif  // KNOWLEDGE_H