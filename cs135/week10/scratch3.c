#include <stdio.h>

int read_line(char str[], int n);

int main(void)
{
    int n = 5;
    char str[n];

    printf("%d\n", read_line(str, n));

    return 0;
}

int read_line(char str[], int n)
{
    int len = 0;

    gets(str);
    for (int i = 0; i < n; i++) {
        if (str[i] != '\0') {
            len++;
            continue;
        }
        break;
    }

    return len;
}
