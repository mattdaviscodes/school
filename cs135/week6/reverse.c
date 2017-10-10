// Reverse an array

#include <stdio.h>

#define ARRAY_LEN 10

int main(void)
{
    int arr[ARRAY_LEN];

    printf("Enter %d numbers: ", ARRAY_LEN);
    for (int i = 0; i < ARRAY_LEN; i++) {
        scanf("%d", &arr[i]);
    }


    printf("In reverse order: ");
    for (int i = ARRAY_LEN - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}
