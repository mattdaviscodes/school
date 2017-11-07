#include <stdio.h>

int main(void)
{
    int a, b, *c;

    a = 1;
    b = 2;

    printf("%d, %d\n", a, b);

    c = &a;
    &a = &b;
    &b = c;

    printf("%d, %d\n", a, b);

    return 0;
}
