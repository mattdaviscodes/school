// Pascal's matrix

#include <stdio.h>

int main(void)
{

    int a[5][5] = {1};

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {
            a[i][j] = 1;
        }
    }

    for (int i = 0; i < 5; i++) {
        if (i == 0)
            continue;

        for (int j = 0; j < 5; j++) {
            if (j == 0)
                continue;

            a[i][j] = a[i-1][j] + a[i][j-1];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }



    return 0;

}
