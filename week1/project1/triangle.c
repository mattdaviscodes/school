/*
 * Name: triangle.c
 * Purpose: Compute area and perimeter of right triangle
 * Author: Matt Davis
 * Created: 9/5/17
 * Last Updated: 9/5/17
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    // Declare needed variables
    int leg_a, leg_b, leg_c, area, perimeter;

    // Prompt user for input
    printf("This program computes the area and perimeter of a right triangle.\n");
    printf("Enter the value of leg a: ");
    scanf("%d", &leg_a);
    printf("Enter the value of leg c: ");
    scanf("%d", &leg_c);

    // Calculate unknown values
    leg_b = sqrt(pow(leg_c, 2) - pow(leg_a, 2));
    area = 0.5 * leg_a * sqrt(pow(leg_c, 2) - pow(leg_a, 2));
    perimeter = leg_a + sqrt(pow(leg_c, 2) - pow(leg_a, 2)) + sqrt(pow(leg_c, 2));

    // Print computed outputs
    printf("The area of the triangle is %d.\n", area);
    printf("The perimeter of the triangle is %d.\n", perimeter);

    return 0;

}
