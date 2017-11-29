// Test file io

#include <stdio.h>

#define FILE_NAME "test1.txt"

int main(int argc, char *argv[])
{
    FILE *fp;

    fp = fopen(FILE_NAME, "r");

    fclose(fp);

    return 0;
}
