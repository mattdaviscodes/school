// Make a copy of a file

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    int ch;

    if (argc != 3) {
        printf("Usage: ./fcopy.c f1 f2\n");
        exit(EXIT_FAILURE);
    }

    if ((fp1 = fopen(argv[1], "r")) == NULL) {
        printf("File %s cannot be opened.\n", argv[1]);
        fclose(fp1);
        exit(EXIT_FAILURE);
    } else if ((fp2 = fopen(argv[2], "w")) == NULL) {
        printf("File %s cannot be opened.\n", argv[2]);
        fclose(fp1);
        fclose(fp2);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(fp1)) != EOF) {
        fputc(ch, fp2);
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}
