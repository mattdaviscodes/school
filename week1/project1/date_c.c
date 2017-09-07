/*
 * Name: date.c
 * Purpose: Print user-inputted dates in tabular format
 * Author: Matt Davis
 * Created: 9/5/17
 * Last Updated: 9/5/17
 */

#include <stdio.h>

int main(void)
{
    // Declare needed variables
    int d1, d2, d3, d4, m1, m2, m3, m4, y1, y2, y3, y4;

    // Prompt user for input
    printf("Enter date 1 (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &d1, &m1, &y1);
    printf("Enter date 2 (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &d2, &m2, &y2);
    printf("Enter date 3 (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &d3, &m3, &y3);
    printf("Enter date 4 (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &d4, &m4, &y4);

    // Print computed outputs
    printf("\n\n");     // Not sure if required, but conforms to spec
    printf("Year\tMonth\tDay\n");
    printf("%.4d\t%.2d\t%.2d\n", y1, m1, d1);
    printf("%.4d\t%.2d\t%.2d\n", y2, m2, d2);
    printf("%.4d\t%.2d\t%.2d\n", y3, m3, d3);
    printf("%.4d\t%.2d\t%.2d\n", y4, m4, d4);

    return 0;

}
