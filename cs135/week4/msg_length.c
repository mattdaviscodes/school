// Determine message length
// Lecture project: 9/26

#include <stdio.h>

int main(void)
{
    int counter = 0;

    printf("Enter a message: ");

    while (getchar() != '\n') {
        counter++;
    }

    printf("Your message was %d character(s) long.\n", counter);

    return 0;
}
