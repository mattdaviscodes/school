/*
 * Name: lab.c
 * Author: Matt Davis
 * Purpose: Practice pointers
 * Date: 11/6/17
 */

#include <stdio.h>

#define ARRAY_SIZE 15
// Prototypes
void swap(int *a, int *b);

int main(void)
{
    int arr[ARRAY_SIZE];

    printf("Enter %d integers:\n", ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n");

    swap(&arr[0], &arr[7]);
    swap(&arr[8], &arr[3]);
    swap(&arr[14], &arr[0]);

    printf("Swapped array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    return 0;
}

void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

// void swap(int *a, int *b)
// {
//     int *tmp;
//
//     tmp = a;
//     a = b;
//     b = tmp;
// }
