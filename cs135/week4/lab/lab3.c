/*
 * Name: lab3.c
 * Author: Matt Davis
 * Purpose: Practice logical conditions
 * Date: 9/25/17
 */

#include <stdio.h>

int main(void)
{
    int w, x, y, z;

    printf("Enter 4 integers (w, x, y, z): ");
    scanf("%d, %d, %d, %d", &w, &x, &y, &z);

    // Condition 1: the number of x is the smallest number.
    if (x < w && x < y && x < z) {
        printf("Condition 1 is true\n");
    } else {
        printf("Condition 1 is false\n");
    }

    // Condition 2: the sum of w and x is smaller than or equal to the sum of y and z.
    if (w + x <= y + z) {
        printf("Condition 2 is true\n");
    } else {
        printf("Condition 2 is false\n");
    }

    // Condition 3: all 4 integers are even numbers.
    if (w % 2 == 0 && x % 2 == 0 && y % 2 == 0 && z % 2 == 0 ) {
        printf("Condition 3 is true\n");
    } else {
        printf("Condition 3 is false\n");
    }

    return 0;
}
