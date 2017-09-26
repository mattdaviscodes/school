/*
 * Name: sq_root.c
 * Purpose: Use a loop to calculate the square root of user's input
 * Author: Matt Davis
 * Created: 9/21/17
 * Last Updated: 9/25/17
 */

#include <stdio.h>
#include <math.h>

#define GOOD_ENOUGH 1e-5

int main(void)
{
    double n, guess = 1.0;

    printf("Enter a number: ");
    scanf("%lf", &n);

    // Always print 1 first -- this seems ridiculous
    printf("%10.5f\n", guess);

    while (1) {
        guess = (guess + (n / guess)) / 2.0;
        if (fabs(n - (guess * guess)) < GOOD_ENOUGH) {
            break;
        }
        printf("%10.5lf\n", guess);
    }

    printf("Estimated square root of %.5lf: %.5lf\n", n, guess);

    return 0;
}
