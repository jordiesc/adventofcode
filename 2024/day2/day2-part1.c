#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strtok()
#include "readfile.h"


int main() {
    int **data = NULL; // Pointer to dynamically allocated 2D array
    int numrows = 0;
    read_data(&data, &numrows, "input_test.txt");
    printf("Number of rows after read_data: %d\n", numrows);
    print_data(data, numrows);

    // Free the allocated memory
    for (int i = 0; i < numrows; i++) {
        free(data[i]);
    }
    free(data);

    return 0;
}



