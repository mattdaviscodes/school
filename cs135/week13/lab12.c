/*
 * Name: lab12.c
 * Purpose: Practice command line args
 * Author: Matt Davis
 * Date: 11/27/17
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int min_chars;

    printf("Ener an integer: ");
    scanf("%d", &min_chars);

    for (int i = 1; i < argc; i++) {
        if (strlen(argv[i]) >= min_chars){
            printf("%s has at least %d characters\n", argv[i], min_chars);
        }
    }

    return 0;
}
