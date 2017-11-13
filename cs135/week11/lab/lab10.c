/*
 * Name: lab10.c
 * Author: Matt Davis
 * Purpose: Practice strings
 * Date: 11/13/17
 */

#include <stdio.h>

#define MAX_CHARS 40

int main(void)
{
    char str[MAX_CHARS + 1], even[MAX_CHARS / 2 + 1], odd[MAX_CHARS / 2 + 1];
    char *strPtr, *evenPtr = even, *oddPtr = odd;
    int index;

    printf("Enter a string (%d characters maximum): ", MAX_CHARS);
    gets(str);

    for (strPtr = str; *strPtr != '\0'; strPtr++) {
        index = strPtr - str;
        if (index % 2 == 0) {
            *evenPtr = *strPtr;
            evenPtr++;
        } else {
            *oddPtr = *strPtr;
            oddPtr++;
        }
    }

    // Ensure null-termination
    *evenPtr = *oddPtr = '\0';

    printf("The even string is: ");
    puts(even);

    printf("The odd string is: ");
    puts(odd);


    return 0;
}
