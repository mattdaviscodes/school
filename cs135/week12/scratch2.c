#include <stdio.h>
#include <stdlib.h>

int get_num_elems(void);

int main(void)
{
    int n;

    n = get_num_elems();

    return 0;
}

int get_num_elems(void)
{
    int n;

    printf("Enter total number of elements: ");
    scanf("%d", &n);

    return n;
}
