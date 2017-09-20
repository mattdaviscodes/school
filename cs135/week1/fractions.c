/*
 * Example: Adding Fractions
 *
 * Prompt user to enter two fractions, then display sum
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    int n1, d1, n2, d2, n3, d3;

    printf("Enter first fraction: ");
    scanf("%d/%d", &n1, &d1);
    printf("Enter second fraction: ");
    scanf("%d/%d", &n2, &d2);

    // Calc output
    n3 = n1 * d1 + n2 * d2;
    d3 = d1 * d2;
    printf("The sum is %d/%d\n", n3, d3);

    return 0;
}
