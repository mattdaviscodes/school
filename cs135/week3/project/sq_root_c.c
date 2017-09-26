/*
 * Name: sq_root_c.c
 * Purpose: Use a loop to calculate the square root of user's input, extra credit
 * Author: Matt Davis
 * Created: 9/22/17
 * Last Updated: 9/22/17
 */

#include <stdio.h>
#include <math.h>

#define GOOD_ENOUGH 0.00001

int main(void)
{
    float n, root, last_guess, guess = 1.0;
    int counter = 0;

    printf("Enter a number: ");
    scanf("%f", &n);

    // Calc actual root of input
    root = sqrt(n);

    // Always print 1.0 as first guess
    printf("%d%10.5f\n", counter, guess);

    do {

        counter++;
        last_guess = guess;
        guess = (guess + (n / guess)) / 2.0;
        printf("%d%10.5f\n", counter, guess);

    } while(
        // Is this formatting standard?
        // guess != last_guess &&
        (guess > root + GOOD_ENOUGH || guess < root - GOOD_ENOUGH)
    );

    printf("Estimated square root of %.5f: %.5f\n", n, guess);

    return 0;
}
