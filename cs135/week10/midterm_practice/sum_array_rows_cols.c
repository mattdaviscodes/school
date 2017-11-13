// Ch 8 problem 7
// Write a program that reads a 5 x 5 array of integers and then
// prints the row sums and the column sums

#include <stdio.h>

#define ROWS 5
#define COLS 5

int main(void)
{
    int arr[ROWS][COLS];
    int row_totals[ROWS] = {0};
    int col_totals[COLS] = {0};

    for (int i = 0; i < ROWS; i++) {
        printf("Enter row %d: ", i+1);
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            row_totals[i] += arr[i][j];
            col_totals[j] += arr[i][j];
        }
    }

    printf("\n");
    printf("Row totals: ");
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", row_totals[i]);
    }
    printf("\n");

    printf("Column totals: ");
    for (int j = 0; j < COLS; j++) {
        printf("%d ", col_totals[j]);
    }
    printf("\n");

    return 0;
}
