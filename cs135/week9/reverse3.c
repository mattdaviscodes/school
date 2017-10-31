// Reverse a series of numbers, using pointers
// In-class practice 10/31/17

#include <stdio.h>

int main(void)
{

    int num_numbers;

    printf("How many numbers do you want to reverse? ");
    scanf("%d", &num_numbers);

    int arr[num_numbers];
    printf("Enter %d numbers: ", num_numbers);
    for (int *p = arr; p < arr + num_numbers; p++) {
        scanf("%d", p);
    }

    printf("In reverse order: ");
    for (int *p = &arr[num_numbers - 1]; p >= arr; p--) {
        printf("%d ", *p);
    }
    printf("\n");

    return 0;
}
