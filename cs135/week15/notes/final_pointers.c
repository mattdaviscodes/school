#include <stdio.h>

void pointer_arithmetic(void)
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *ptr = arr; // arr == location of first elem of array

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d\n", arr[i]);
    }
}

int main(int argc, char *argv[])
{
    int x = 5;
    int *px = &x;

    pointer_arithmetic();

    return 0;
}
