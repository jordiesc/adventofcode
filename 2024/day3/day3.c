// C program to read a file using fgetc()
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
# define MAX_CHARS 1024

void find_matches(const char *pattern, const char *string);

int main() {
    // Opening file
    FILE *fptr;


    // Character buffer that stores the read character
    // till the next iteration
    char *buffr;
    char *fullcontent;
        buffr = (char *) malloc(MAX_CHARS * sizeof(char));
    size_t llargada = 0;

    // Opening file in reading mode
    fptr = fopen("input.txt", "r");

    while (fgets(buffr, sizeof(buffr), fptr) != NULL) {
        fullcontent = realloc(fullcontent, llargada + strlen(buffr) + 1);
        fullcontent = strcpy(fullcontent, buffr);
        /* printf("%s",fullcontent); */
    }    
    
    // Print the file content
    printf("%s",fullcontent);
    const char *string = "mul(12,34) don't() undo() mul(56,78) something_else";
    const char *pattern = "mul\\([0-9]+,[0-9]+\\)|don't\\(\\)|undo\\(\\)";
    /* const char *pattern = "mul\\([0-9]+,[0-9]+\\)"; */
    find_matches(pattern, string);
    find_matches(pattern,fullcontent);
    free(fullcontent);
    free(buffr);

    // Closing the file
    fclose(fptr);
    return 0;
}


void find_matches(const char *pattern, const char *string) {
    regex_t regex;
    regmatch_t pmatch[1]; // Array to hold match information
    const char *cursor = string; // Pointer to track the search position
    //
    printf("Input string: %s\n", string);

    // Compile the regex pattern
    if (regcomp(&regex, pattern, REG_EXTENDED)) {
        fprintf(stderr, "Could not compile regex\n");
        return;
    }

    // Search for matches
    while (regexec(&regex, cursor, 1, pmatch, 0) == 0) {
        // pmatch[0] contains the start and end offsets of the match
        int start = pmatch[0].rm_so;
        int end = pmatch[0].rm_eo;

        printf("Match found: ");
        for (int i = start; i < end; i++) {
            putchar(cursor[i]);
        }
        putchar('\n');

        // Move the cursor forward to continue the search
        cursor += end;

        // Stop if the match length is 0 (to prevent infinite loop for empty matches)
        if (end == 0) {
            cursor++;
        }
    }

    // Free the regex object
    regfree(&regex);
}

int main_other() {
    const char *string = "abc123abc456abc";
    const char *pattern = "abc";

    find_matches(pattern, string);

    return 0;
}

