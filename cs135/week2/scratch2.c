// Scratch file 9/14/17

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int i = 1, j =1, k = 1;

    printf("%d\n",++i || ++j && ++k);
    printf("%d %d %d\n",i,j,k);

    return 0;
}
