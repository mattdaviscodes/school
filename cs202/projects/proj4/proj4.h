//
// Created by Matthew Davis on 2/20/18.
//

#ifndef SCHOOL_PROJ4_H
#define SCHOOL_PROJ4_H

#include <iostream>

using namespace std;

// Custom string functions required by project spec
size_t myStringLength(const char * str);
int myStringCompare(const char * str1, const char * str2);
char *myStringCopy(char * destination, const char * source);
char * myStringCat(char * destination, const char * source);

/*
 * Find the length of a string, not including the null-terminator
 */
size_t myStringLength(const char * str) {
    size_t i = 0;

    while (*str++) {
        i++;
    };

    return i;
}

/*
 * Compare two strings. Return -1 of str1 is less than str2, 1 if the opposite, 0 if they're identical
 */
int myStringCompare(const char * str1, const char * str2) {
    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }

    return *str1 - *str2;
}

/*
 * Copy a source string to a destination string
 */
char *myStringCopy(char * destination, const char * source) {
    while ((*destination++ = *source++))
        ;

    return destination;
}

/*
 * Concatenate a source string onto the end of a destination string
 */
char *myStringCat(char * destination, const char * source) {
    // Find end of destination
    while (*destination) {
        destination++;  // Leaves destination pointing to null character
    }

    // Copy source onto end of destination
    while ((*destination++ = *source++))
        ;

    return destination;
}

#endif //SCHOOL_PROJ4_H
