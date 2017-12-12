#include <stdio.h>
#include <stdlib.h>

#define TEXTFILE "file.txt"
#define BINFILE "file.dat"

int main(void)
{
    FILE *fp;
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    fp = fopen(BINFILE, "wb");
    fwrite(arr, sizeof(int), sizeof(arr), fp);

    fclose(fp);
    return 0;
}
