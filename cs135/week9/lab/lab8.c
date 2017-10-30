/*
 * Name: lab8.c
 * Author: Matt Davis
 * Purpose: Practice functions
 * Date: 10/30/17
 */

#include <stdio.h>

// Prototypes
int digit(int n, int k);

int main(void)
{
    int n, k;

    printf("Enter two positive integers (n, k): ");
    scanf("%d, %d", &n, &k);
    printf("The k=%d digit of %d is: %d\n", k, n, digit(n, k));

    return 0;
}

int digit(int n, int k)
{
    int digit;

    for (int i = 0; i < k; i++) {
        digit = n % 10;
        n /= 10;
        if (n == 0) {
            return -1;
        }
    }

    return digit;
}
