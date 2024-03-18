#include <stdio.h>
#include <stdlib.h>
#include "data.h"

// Function to create a new DataItem and initialize its values
// Parameters:
//   id: Unique identifier for the data item
//   name: Name of the data item
//   value: Value associated with the data item
// Returns:
//   Pointer to the newly created DataItem
DataItem* create_data_item(int id, const char* name, double value) {
    DataItem* item = (DataItem*)malloc(sizeof(DataItem));
    if (item != NULL) {
        item->id = id;
        item->name = name;
        item->value = value;
    }
    return item;
}

// Function to print the details of a DataItem
// Parameters:
//   item: Pointer to the DataItem to be printed
void print_data_item(DataItem* item) {
    if (item != NULL) {
        printf("Data Item ID: %d\n", item->id);
        printf("Data Item Name: %s\n", item->name);
        printf("Data Item Value: %.2f\n", item->value);
    } else {
        printf("Error: Invalid DataItem\n");
    }
}

// Function to free memory allocated for a DataItem
// Parameters:
//   item: Pointer to the DataItem to be destroyed
void destroy_data_item(DataItem* item) {
    if (item != NULL) {
        free(item);
    } else {
        fprintf(stderr, "Error: Cannot destroy NULL DataItem\n");
        exit(EXIT_FAILURE);
    }
}