// Excercise for Lecture[7][0]

#include <stdio.h>

#define INVESTED 100
#define RATES 5

int main(void)
{
    int low_rate, years;

    printf("Enter an interest rate: ");
    scanf("%d", &low_rate);

    printf("Enter number of years: ");
    scanf("%d", &years);

    // Display table header
    printf("Years\t");
    for (int i = 0; i < RATES; i++) {
        printf("%d%%\t", rate + i);
    }
    printf("\n");

    // Display table
    for (int year = 1; year <= years; year++) {
        printf("%d\t", year);
        for (int rate = low_rate; rate < low_rate + RATES; rate++) {
            printf("%.2f\n", );
        }
    }
}
