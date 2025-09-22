#include "../include/myfilefunctions.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Function to count lines, words, and characters in a file
int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (!file || !lines || !words || !chars) return -1; // Check for null pointers

    *lines = *words = *chars = 0;  // Initialize counts to zero
    char c;
    int in_word = 0;               // Flag to track when inside a word

    // Read file character by character
    while ((c = fgetc(file)) != EOF) {
        (*chars)++;                 // Increase character count

        if (c == '\n') (*lines)++; // Count new lines

        // Check for spaces, tabs, or new lines to separate words
        if (c == ' ' || c == '\n' || c == '\t') {
            in_word = 0;            // Not inside a word
        } else if (!in_word) {
            (*words)++;             // Starting a new word
            in_word = 1;            // Inside a word now
        }
    }

    return 0; // Success
}

// Function to search for a specific word/phrase in a file
int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (!fp || !search_str || !matches) return -1; // Check for invalid input

    size_t capacity = 10;                           // Initial array size
    size_t count = 0;                               // Number of matches found
    char** results = malloc(capacity * sizeof(char*)); // Allocate memory for results
    if (!results) return -1;

    char buffer[1024];  // Buffer to read each line

    // Read file line by line
    while (fgets(buffer, sizeof(buffer), fp)) {
        // Check if the search string exists in the current line
        if (strstr(buffer, search_str)) {
            if (count >= capacity) {                // Resize array if full
                capacity *= 2;
                results = realloc(results, capacity * sizeof(char*));
                if (!results) return -1;
            }
            results[count] = strdup(buffer);        // Save the matching line
            count++;
        }
    }

    *matches = results; // Pass back the array of matches
    return count;       // Return number of matching lines
}
