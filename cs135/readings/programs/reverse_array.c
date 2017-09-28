// Reverse a user-supplied array

#include <stdio.h>

int main(void)
{
    int a[10];

    printf("Enter 10 numbers: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }

    printf("In reverse order:");
    for (int i = 10 - 1; i >= 0; i--) {
        printf(" %d", a[i]);
    }
    printf("\n");   // Ensure newline at end of loop
    
    return 0;
}
