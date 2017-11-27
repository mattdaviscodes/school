#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[]);

int main(void)
{
    int a[3] = {10, 20, 30};
    print_array(a);

    return 0;
}

void print_array(int arr[])
{
    for (int i = 0; i <= sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
