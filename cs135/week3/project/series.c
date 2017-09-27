/*
 * Name: series.c
 * Purpose: Compute following mathematical series for input n
 *
 *      S = 1^2 - 2^s + 3^s - 4^2 + ... + (-1)^n+1 * n^2
 *
 * Author: Matt Davis
 * Created: 9/26/17
 * Last Updated: 9/26/17
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    int n, result = 0, i;

    printf("Enter an integer number: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        result += pow(-1, i + 1) * pow(i, 2);
    }

    printf("The value of the series is: %d\n", result);

    return 0;
}
