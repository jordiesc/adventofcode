#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strtok()
#include "readfile.h"


int comparatorIncreasing(int a, int b);
int comparatorDecreasing(int a, int b);
int loop_over_row(int *data);
int loop_over_rows(int **data, int numrows);


int main() {
    int **data = NULL; // Pointer to dynamically allocated 2D array
    int numrows = 0;
    /* read_data(&data, &numrows, "input_test-part1.txt"); */
    read_data(&data, &numrows, "input.txt");
    printf("Number of rows after read_data: %d\n", numrows);
    print_data(data, numrows);
    
    int suma = loop_over_rows(data,numrows);
    printf(" numer of problem %d \n",suma);

    // Free the allocated memory
    for (int i = 0; i < numrows; i++) {
        free(data[i]);
    }
    free(data);

    return 0;
}

int comparatorIncreasing(int a, int b) {
    if (a < b && b-a>=1 && b-a<=3) {
        return 1;
    } else {
        return 0;
    }
}

int comparatorDecreasing(int a, int b) {
    if (a > b && a-b>=1 && a-b<=3) {
        return 1;
    } else {
        return 0;
    }
}

int loop_over_rows(int **data, int numrows) {
    int sum = 0;
    for (int i=0; i < numrows; i++) {
        int *row = data[i];
        sum = sum + loop_over_row(row);
    }
    return sum;
}    
// loop on a row and return 1 if is O and 0 otherwise
// The levels are either all increasing or all decreasing.
//Any two adjacent levels differ by at least one and at most three
int loop_over_row(int *data) {
    int isSafe = 0;
    //supose that the first number is increasing or decreasing
    int isIncreasing = 1;
    int isDecreasing = 1;
   for (int i = 0; i < MAX_NUMBERS_PER_LINE; i++) {
        int next = i+1;
        if (next > MAX_NUMBERS_PER_LINE) {
            break;
        } 
        if (data[next] == 0 || data[i] == 0) {
            break;
        }
        //due to the isDecreasing both isDecreasing only in the first iteration are evaluated both
       if (isIncreasing )
           isIncreasing = comparatorIncreasing(data[i], data[next]);
       if (isDecreasing )
           isDecreasing = comparatorDecreasing(data[i], data[next]);
       // it cant be both increasing and decreasing
       if (isIncreasing && isDecreasing) {
           isSafe = 0;
           break;
       }
    }// at least on all iterations isIncreasing or isDecreasing is true
    if (isIncreasing || isDecreasing) {
        isSafe = 1;
    }    
    return isSafe;
}
