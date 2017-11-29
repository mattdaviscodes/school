// Test file io

#include <stdio.h>

#define FILE_NAME 'test.txt'

int main(int argc, char *argv[])
{
    FILE *fp;

    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            fp = fopen(argv[i], "r");
            if (fp != NULL) {
                printf("File %s can be opened\n", argv[i]);
            } else {
                printf("File %s cannot be opened\n", argv[i]);
            }
            fclose(fp);
        }
    }

    return 0;
}
