#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void get_digits(const char *str, char *digits);
void sort_char(char *a, char *b, char *c, char *d);
int *init_array(int rows);

int main(int argc, char *argv[])
{
    // char digits[100];
    // char *str = "CS135 2017";
    // printf("Str: %s\n", str);
    // get_digits(str, digits);
    // printf("Digits: %s\n", digits);

    // char a = 'z', b = 'a', c = 'e', d = 'b';
    // printf("a=='%c', b=='%c', c=='%c', d=='%c'\n", a, b, c, d);
    // sort_char(&a, &b, &c, &d);
    // printf("a=='%c', b=='%c', c=='%c', d=='%c'\n", a, b, c, d);

    int *my_array;
    my_array = init_array(3);

    return 0;
}

void get_digits(const char *str, char *digits)
{
    char c;

    while ((c = *str++)) {
        // if (isdigit(c)) {
        //     *digits++ = c;
        // }
        isdigit(c) && (*digits++ = c);
     }

     *digits++ = '\0';
}

void sort_char(char *a, char *b, char *c, char *d)
{
    char tmp;
    int change_made;

    do {
        change_made = 0;

        if (*a > *b) {
            tmp = *a;
            *a = *b;
            *b = tmp;
            change_made = 1;
        }

        if (*b > *c) {
            tmp = *b;
            *b = *c;
            *c = tmp;
            change_made = 1;
        }

        if (*c > *d) {
            tmp = *c;
            *c = *d;
            *d = tmp;
            change_made = 1;
        }

    } while(change_made == 1);
}

int *init_array(int rows)
{
    const int cols = 3;
    int *arr = (int *)malloc(rows * cols * sizeof(int));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(arr + (i * cols) + j) = i + 1 + j;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(arr + (i * cols) + j));
        }
        printf("\n");
    }

    return arr;
}
