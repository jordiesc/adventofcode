#ifndef FILEREAD_H
#define FILEREAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strtok()

#define MAX_LINE_LENGTH 1024
#define MAX_NUMBERS_PER_LINE 10

int read_data(int ***data, int *numrows, char *filename);
int print_data(int **data, int numrows);

#endif
