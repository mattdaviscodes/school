#include <stdio.h>
#include <stdlib.h>

#define FILENAME "test"

int main(void)
{
    int a = 5;
    FILE *fp;

    fp = fopen(FILENAME, "wb");

    fwrite(&a, sizeof(int), 1, fp);

    fclose(fp);

    return 0;
}
