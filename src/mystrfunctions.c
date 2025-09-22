#include "../include/mystrfunctions.h"

// Function to find the length of a string
int mystrlen(const char* s) {
    int len = 0;              // Counter for length
    while (s[len] != '\0') {  // Loop until we reach the null terminator
        len++;
    }
    return len;               // Return the total length
}

// Function to copy one string into another
int mystrcpy(char* dest, const char* src) {
    if (!dest || !src) return -1;  // Check for null pointers

    while (*src) {     // Copy each character from src to dest
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';      // Add null terminator at the end
    return 0;
}

// Function to copy at most 'n' characters from one string to another
int mystrncpy(char* dest, const char* src, int n) {
    if (!dest || !src || n < 0) return -1;  // Check for invalid input

    int i = 0;
    while (i < n && src[i] != '\0') {  // Copy until 'n' or end of src
        dest[i] = src[i];
        i++;
    }

    // Fill the rest with null characters if needed
    while (i < n) {
        dest[i] = '\0';
        i++;
    }
    return 0;
}

// Function to append (join) one string to another
int mystrcat(char* dest, const char* src) {
    if (!dest || !src) return -1;  // Check for null pointers

    while (*dest) dest++;          // Move to the end of the first string

    while (*src) {                  // Copy each character from src
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';                  // Add null terminator at the end
    return 0;
}
