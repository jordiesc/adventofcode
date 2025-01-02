// C program to read a file line by line

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef WIDTH
#define WIDTH 10
//#define WIDTH 140
#endif

#ifndef HEIGHT
//#define HEIGHT 140
#define HEIGHT 10
#endif


int main()
{
    FILE* file = fopen("input-test.txt", "r");

    // Buffer to store each line of the file.
    char line[WIDTH];
    char buffer[WIDTH+2]; //one position for the \n and one for the \0 at the end
    char* fileInChar[HEIGHT];

    int i = 0;

    // Check if the file was opened successfully.
    if (file != NULL) {
        // Read each line from the file and store it in the
        // 'line' buffer.
    while (fgets(buffer, WIDTH+2, file) && i < HEIGHT) {
            printf("la ieslmia inea %d  linea es : %s \n",i,buffer);
            fileInChar[i] = calloc(WIDTH, sizeof(char));
            for (int j = 0; j < WIDTH; j++) {
                fileInChar[i][j] = buffer[j];
            }

            i++;

        }

        fclose(file);
    }
    else {
        fprintf(stderr, "Unable to open file!\n");
    }

    for (int i = 0; i < HEIGHT; i++) {
        printf("%s", fileInChar[i]);
        free(fileInChar[i]);
    } 

    return 0;
}
