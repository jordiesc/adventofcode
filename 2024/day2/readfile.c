#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strtok()
#include "readfile.h"

int read_data(int ***data, int *numrows, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int rows = *numrows;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        int *row = calloc(MAX_NUMBERS_PER_LINE, sizeof(int)); // Allocate memory and initialize to 0
        if (row == NULL) {
            perror("Error allocating memory");
            fclose(file);
            return 1;
        }

        int cols = 0;
        char *token = strtok(line, " \t\n");
        while (token != NULL) {
            row[cols++] = atoi(token); // Convert token to integer
            token = strtok(NULL, " \t\n");
        }

        // Resize the data array to hold the new row
        int **temp = realloc(*data, (rows + 1) * sizeof(int *));
        if (temp == NULL) {
            perror("Error reallocating memory");
            free(row);
            fclose(file);
            return 1;
        }
        *data = temp;
        //the () are needed otherwise the [] takes precedence
        (*data)[rows++] = row; // Add the new row to the data array
    }

    *numrows = rows;
    fclose(file);

    return 0;
}

int print_data(int **data, int numrows) {
    printf("Number of rows: %d\n", numrows);
    for (int i = 0; i < numrows; i++) {
        for (int j = 0; j < MAX_NUMBERS_PER_LINE; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
    return 0;
}

