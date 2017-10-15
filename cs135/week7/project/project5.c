/*
 * Name: project5.c
 * Purpose: Count occurrences of digits 0-9 in an NxM array
 *
 *      NOTE: There really isn't any reason to read the values in as an array
 *      to accomplish this task. I've only done so here to comply with the
 *      project spec.
 *
 * Author: Matt Davis
 * Created: 10/15/17
 * Last Updated: 10/15/17
 */

#include <stdio.h>

int main(void)
{

    int rows, columns, digit;
    int counters[10] = {0};     // One element for each digit 0-9

    // Intro statment
    printf("This program counts occurrences of digits 0 through 9 in an NxM array\n");

    // Initial prompt
    printf("Enter the size of your array: ");
    scanf("%d %d", &rows, &columns);


    // Digit-by-digit input
    for (int row = 0; row < rows; row++) {

        printf("Enter row %d: ", row);

        for (int column = 0; column < columns; column++) {
            scanf("%d", &digit);
            counters[digit]++;
        }
    }

    // Output
    printf("\nTotal count for each digit:\n");
    for (int i = 0; i < 10; i++) {
        if (counters[i] != 1) {
            printf("Digit %d occurs %d times\n", i, counters[i]);
        } else {
            printf("Digit %d occurs 1 time\n", i);
        }
    }

    return 0;
}
