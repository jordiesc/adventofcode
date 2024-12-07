#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FILEDAY1 "./file-day1"

typedef struct record {
    int left;
    int right;
}record_t;

typedef struct file_data {
    int size;
    record_t * record;
}file_data_t;

file_data_t readfile(char * filename);
int compare(const void *a, const void *b) ;
int * get_left_ordered(file_data_t data);
int * get_right_ordered(file_data_t data);
int occurences_sorted_array(int a, int * array, int size);



int part1(file_data_t data);
int part2(file_data_t data);


int main(int argc, char const *argv[])
{
    file_data_t data = readfile(FILEDAY1);
    int i;
    for(i = 0; i < data.size; i++) {
        printf("%d %d\n", data.record[i].left, data.record[i].right);
    }
    
    /*  
    *
    *           PART 1
    */

    printf("Part 1: %d\n", part1(data));


    /**
     * PART 2
     */

    printf("Part 2: %d\n", part2(data));

    return 0;

}


int part1(file_data_t data) {
    int * left = get_left_ordered(data);
    int * right = get_right_ordered(data);
    int i;
    int sum = 0;
    for(i = 0; i < data.size; i++) {
        sum = sum + abs( left[i]- right[i]);
    }
    return sum;
}

int part2(file_data_t data) {
    int * left = get_left_ordered(data);
    int * right = get_right_ordered(data);
    int i;
    int sum = 0;
    for(i = 0; i < data.size; i++) {
        sum = sum + left[i] * occurences_sorted_array(left[i], right, data.size);
    }
    
    return sum;
}



int distance(int a, int b) {
    return abs(a - b);
}

int * get_right_ordered(file_data_t data) {
    int i;
    int * left = malloc(sizeof(int) * data.size);
    for(i = 0; i < data.size; i++) {
        left[i] = data.record[i].right;
    }
    qsort(left, data.size, sizeof(int), compare);
    return left;
};
int * get_left_ordered(file_data_t data) {
    int i;
    int * left = malloc(sizeof(int) * data.size);
    for(i = 0; i < data.size; i++) {
        left[i] = data.record[i].left;
    }
    qsort(left, data.size, sizeof(int), compare);
    return left;
};

file_data_t readfile(char * filename)
{
    file_data_t data;
    FILE * file;
    int i;
    char line[1024];
    data.size = 0;
    //read a file
    file = fopen(filename, "r");
    
    if (file == NULL) {
        perror("Error opening file"); // Error handling for file not found
        exit(1);
    }

    while(fgets(line, sizeof(line), file) != NULL) {
         data.size++;
    }
    fclose(file);
    file = fopen(filename, "r");
    data.record = malloc(sizeof(record_t) * data.size);
    i = 0;
    while(fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%d %d", &data.record[i].left, &data.record[i].right);
        i++;
    }
    fclose(file);

    return data;
}

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int occurences_sorted_array(int a, int * array, int size) {
    int i;
    int count = 0;
    bool found = false;
    
    for(i = 0; i < size; i++) {
        if(array[i] == a) {
            found = true;
            count++;
        } else if(found) {
            break;
        }

    }
    //printf("count: %d\n", count);
    return count;
}

