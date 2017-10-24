/*
 * Name: lab7.c
 * Author: Matt Davis
 * Purpose: Compute area and vol of prism using functions
 * Date: 10/23/17
 */

#include <stdio.h>

// Prototypes
int compute_area(int l, int w, int h);
int compute_volume(int l, int w, int h);

int main(void)
{

    int length, width, height;

    do {
        printf("Enter the dimensions of the square prism (l, w, h): ");
        scanf("%d, %d, %d", &length, &width, &height);
    } while(length <= 0 || width <= 0 || height <= 0);

    printf("The area of the prism is: %d\n", compute_area(length, width, height));
    printf("The volume of the prism is: %d\n", compute_volume(length, width, height));

    return 0;
}

int compute_area(int l, int w, int h)
{
    return 2 * (w * l + h * l + h * w);
}

int compute_volume(int l, int w, int h)
{
    return l * w * h;
}
