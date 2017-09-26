/*
 * Name: sq_root.c
 * Purpose: Use a loop to calculate the square root of user's input
 * Author: Matt Davis
 * Created: 9/21/17
 * Last Updated: 9/22/17
 */

#include <stdio.h>
#include <math.h>

#define GOOD_ENOUGH 0.00001

int main(void)
{
    double n, root, guess = 1.0;

    printf("Enter a number: ");
    scanf("%lf", &n);

    // Calc actual root of input
    root = sqrt(n);

    // Always print 1.0 as first guess
    printf("%10.5lf\n", guess);

    do {

        guess = (guess + (n / guess)) / 2.0;
        printf("%10.5lf\n", guess);

    } while(guess > root + GOOD_ENOUGH || guess < root - GOOD_ENOUGH);

    printf("Estimated square root of %.5lf: %.5lf\n", n, guess);

    return 0;
}
