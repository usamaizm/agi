#ifndef DATA_H
#define DATA_H

// Define your data structures or types here

// Define a struct called DataItem to store data information
typedef struct {
    int id;               // Unique identifier for the data item
    const char* name;     // Name of the data item
    double value;         // Value associated with the data item
} DataItem;               // Represents a data item in the program

#endif // DATA_H