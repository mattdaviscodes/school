/*
 * Name: lab5.c
 * Author: Matt Davis
 * Purpose: Use getchar to count whitespace chars in input
 * Date: 10/9/17
 */

#include <stdio.h>

int main(void)
{

    int spaces = 0, newlines = 0, tabs = 0;
    char c;

    printf("Enter a sentence (end by '.' or '?' or '!'):");
    
    while (c = getchar()) {
        if (c == ' ') {
            spaces++;
	} else if (c == '\n') {
	    newlines++;
	} else if (c == '\t') {
	    tabs++;
	} else if (c == '.' || c == '\?' || c == '!') {
	    break;
	}
    }

    printf("Number of space characters: %d\n", spaces);
    printf("Number of new line characters: %d\n", newlines);
    printf("Number of tabs: %d\n", tabs);

    return 0;
}
