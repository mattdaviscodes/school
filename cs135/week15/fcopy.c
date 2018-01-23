#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    int ch;

    // Ensure proper usage
    if (argc != 3) {
        printf("Usage: ./filecopy.c file1 file2\n");
        exit(EXIT_FAILURE);
    }

    // Ensure both files can be opened
    if ((fp1 = fopen(argv[1], "r")) == NULL) {
        fclose(fp1);
        printf("Failed to open file %s in read mode.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((fp2 = fopen(argv[2], "w")) == NULL) {
        fclose(fp1);
        fclose(fp2);
        printf("Failed to open file %s in write mode.\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    // Copy file1 to file2
    // THIS IS INCORRECT
    // while ((*fp1++ = *fp2++))
    //     ;
    while ((ch = fgetc(fp1))) {
        fputc(ch, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
