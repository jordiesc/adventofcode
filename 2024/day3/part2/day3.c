// C program to read a file using fgetc()
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
# define MAX_CHARS 1024
#define ARRAY_SIZE(array) (sizeof((array)) / sizeof((array)[0]))

char** find_matches(const char *pattern, const char *string,size_t *number_matches);

enum Match_t { NUM,DONT,DO };

long parse_match(char* match, int length, enum Match_t *match_enum ); 

int main() {
    // Opening file
    FILE *fptr;


    // Character buffer that stores the read character
    // till the next iteration
    char *buffr;
    char *fullcontent = NULL ;
    buffr = (char *) malloc(MAX_CHARS * sizeof(char));
    size_t llargada = 0;
    size_t chunk = 0;
    size_t number_matches = 0;
    // Opening file in reading mode
    fptr = fopen("input.txt", "r");

    while (fgets(buffr, MAX_CHARS, fptr) != NULL) {
        
        chunk = strlen(buffr);
        fullcontent = realloc(fullcontent, (llargada + chunk)*(sizeof(char)) +1);
        strcpy(fullcontent+llargada, buffr);
        llargada += chunk;
       
          
    }    
    
    printf("%s",fullcontent);
    // Print the file content
    /* const char *string = "mul(12,34) don't() undo() mul(56,78) something_else"; */
    const char *pattern = "mul\\([0-9]+,[0-9]+\\)|don't\\(\\)|do\\(\\)";
    /* const char *pattern = "mul\\([0-9]+,[0-9]+\\)"; */
     find_matches(pattern,fullcontent,&number_matches);
    free(fullcontent);
    free(buffr);

    // Closing the file
    fclose(fptr);
    return 0;
}


char**  find_matches(const char *pattern, const char *string, size_t *number_matches) {
    regex_t regex;
    regmatch_t pmatch[1]; // Array to hold match information
    const char *cursor = string; // Pointer to track the search position
    enum Match_t match_t;
    long result = 0;
    //
    /* char **matches = NULL; */
    //
    printf("Input string: %s\n", string);

    // Compile the regex pattern
    if (regcomp(&regex, pattern, REG_EXTENDED)) {
        fprintf(stderr, "Could not compile regex\n");
        return NULL;
    }



    // Search for matches
    while (regexec(&regex, cursor, 1, pmatch, 0) == 0) {
        // pmatch[0] contains the start and end offsets of the match
        int start = pmatch[0].rm_so;
        int end = pmatch[0].rm_eo;

        char match[end-start+1];

        printf("Match found: ");
        for (int i = start; i < end; i++) {
            /* putchar(cursor[i]); */
            match[i-start] = cursor[i];
        }
        match[end-start] = '\0';
        printf("%s\n", match);
        result += parse_match(match,end-start,&match_t);
        *number_matches += 1;
        putchar('\n');

        // Move the cursor forward to continue the search
        cursor += end;

        // Stop if the match length is 0 (to prevent infinite loop for empty matches)
        if (end == 0) {
            cursor++;
        }
    }
    printf("THE number total is %ld\n",result);
    // Free the regex object
    regfree(&regex);
    return NULL;
}


long parse_match(char* match, int length, enum Match_t *match_enum ) {

    long result = 0;
    if ( strstr(match,"mul(") != NULL) {
        *match_enum = NUM;
        long a = 0;
        long b = 0;
        sscanf(match,"mul(%ld,%ld)",&a,&b);
        result = a*b;
    }
    else if ( strstr(match,"don't(") != NULL) {
        *match_enum = DONT;
        result = 0;
    }
    else if (strstr(match,"do(") != NULL) {
        *match_enum = DO;
    } else {
        return 0;
    }
    return result;

}



