#include <stdio.h>

#define ROWS 2
#define COLS 5

int add_nums(int arr[ROWS][COLS], int rows, int cols);

int main(void)
{
    int arr[ROWS][COLS];

    printf("Enter 10 integers: ");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Sum: %d\n", add_nums(arr, ROWS, COLS));

    return 0;
}

int add_nums(int arr[ROWS][COLS], int rows, int cols)
{
    int sum = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
    }

    return sum;
}
