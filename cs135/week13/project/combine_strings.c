/*
 * Name: combine_strings.c
 * Purpose: Practice string functions and command line args
 * Author: Matt Davis
 * Date: 11/29/17
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 30
#define INTERSPERSE 1
#define WIDEN_STARS 2

char *intersperse(const char *str1, const char *str2);
char *widen_stars(const char *str1, const char *str2);

int main(int argc, char *argv[])
{
    char str1[MAX_STR_LEN], str2[MAX_STR_LEN];
    char *result;
    char command;

    if (argc != 2) {
        printf("Usage: ./combine_strings [-i | -w]\n");
        return -1;
    } else if (!strcmp(argv[1], "-i") && !strcmp(argv[1], "-w")) {
        printf("Usage: ./combine_strings [-i | -w]\n");
        return -2;
    }

    printf("Please enter a string of maximum %d characters: ", MAX_STR_LEN);
    fgets(str1, 100, stdin);
    printf("Please enter a string of maximum %d characters: ", MAX_STR_LEN);
    fgets(str2, 100, stdin);


    switch (argv[1][1]) {
        case 'i':
            result = intersperse(str1, str2);
            break;
        case 'w':
            result = widen_stars(str1, str2);
            break;
    }

    printf("The combined string is: %s\n", result);

    free(result);

    return 0;
}

/*
 * Function: intersperse
 * ---------------------
 *      Concatenate two strings, alternating characters from str1 and str2.
 */
char *intersperse(const char *str1, const char *str2)
{
    char *result, *cursor;

    result = malloc(strlen(str1) + strlen(str2) + 1);
    if (result == NULL) {
        printf("Error: malloc failed in intersperse\n");
        exit(EXIT_FAILURE);
    }

    cursor = result;

    while (*str1 != '\0' || *str2 != '\0') {
        if (*str1 != '\0') {
            *cursor++ = *str1++;
        }

        if (*str2 != '\0') {
            *cursor++ = *str2++;
        }
    }

    *cursor = '\0';

    return result;
}

/*
 * Function: widen_stars
 * ---------------------
 *      Concatenate two strings, placing a '*' between each char.
 */
char *widen_stars(const char *str1, const char *str2)
{
    char *result, *cursor;

    result = malloc((strlen(str1) + strlen(str2)) * 2 + 1);
    if (result == NULL) {
        printf("Error: malloc failed in intersperse\n");
        exit(EXIT_FAILURE);
    }

    cursor = result;

    while (*str1 != '\0') {
        *cursor++ = *str1++;
        *cursor++ = '*';
    }

    while (*str2 != '\0') {
        *cursor++ = *str2++;
        *cursor++ = '*';
    }

    *--cursor = '\0';

    return result;
}
