/*
 * Name: sq_root.c
 * Purpose: Use a loop to calculate the square root of user's input, extra credit
 * Author: Matt Davis
 * Created: 9/21/17
 * Last Updated: 9/26/17
 */

#include <stdio.h>
#include <math.h>

#define GOOD_ENOUGH 1e-5

int main(void)
{
    float n, guess = 1.0, last_guess;
    int counter = 0;

    printf("Enter a number: ");
    scanf("%f", &n);

    // Always print 1 first -- this seems ridiculous
    printf("%d\t%.5f\n", counter, guess);

    while (1) {
        counter++;
        last_guess = guess;
        guess = (guess + (n / guess)) / 2.0;
        if (fabs(n - (guess * guess)) < GOOD_ENOUGH || last_guess == guess) {
            break;
        }
        printf("%d\t%.5f\n", counter, guess);
    }

    printf("Estimated square root of %.5f: %.5f\n", n, guess);

    return 0;
}
