#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    printf("--- Testing String Functions ---\n");

    char str1[50] = "Hello";
    char str2[50] = "World";

    // Test mystrlen
    printf("Length of str1: %d\n", mystrlen(str1));

    // Test mystrcat
    mystrcat(str1, str2);
    printf("Concatenated string: %s\n", str1);

    // Test mystrcpy
    char copy[50];
    mystrcpy(copy, str1);
    printf("Copied string: %s\n", copy);

    // Test mystrncpy
    char partialCopy[10];
    mystrncpy(partialCopy, str1, 5);
    partialCopy[5] = '\0';  // Ensure null-terminated
    printf("First 5 characters copied: %s\n", partialCopy);

    printf("\n--- Testing File Functions ---\n");

    // Open file for reading
    FILE *file = fopen("test.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    // Test wordCount
    int lines, words, chars;
    if (wordCount(file, &lines, &words, &chars) == 0) {
        printf("Lines: %d, Words: %d, Characters: %d\n", lines, words, chars);
    }
    rewind(file); // Reset file pointer for next test

    // Test mygrep
    char** matches;
    int match_count = mygrep(file, "Hello", &matches);
    if (match_count > 0) {
        printf("\nFound %d matching lines:\n", match_count);
        for (int i = 0; i < match_count; i++) {
            printf("%s", matches[i]); // Print each matching line
            free(matches[i]);         // Free each line after printing
        }
        free(matches); // Free the matches array
    } else {
        printf("\nNo matches found.\n");
    }

    fclose(file); // Close the file
    return 0;
}
