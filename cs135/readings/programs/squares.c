/* Prints a table of squares using a qhile statement */

#include <stdio.h>

int main(void)
{
    int i, n;
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    i = 1;
    while (i <= n) {
        printf("%10d%10d\n", i, i * i);
        i++;
    }

    return 0;
}
