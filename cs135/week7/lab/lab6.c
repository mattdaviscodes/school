/*
 * Name: lab6.c
 * Author: Matt Davis
 * Purpose: Count occurrances of characters in input
 * Date: 10/16/17
 */

#include <stdio.h>
#include <ctype.h>

#define PERIOD '.'
#define ALPHABET_LENGTH 26

int main(void)
{

    char c;
    int arr[ALPHABET_LENGTH] = {0};

    printf("Enter a sentence (end by '.'): ");

    while (c = getchar()) {

        if (c == PERIOD) {
          break;
        }

        c = tolower(c);
        if (c >= 'a' && c <= 'z') {
            arr[c - 'a']++;
        }
    }

    for (int i = 0; i < ALPHABET_LENGTH; i++) {
        if (arr[i] > 0) {
            printf("Occurrences of '%c': %d\n", i + 'a', arr[i]);
        }
    }

    return 0;
}
