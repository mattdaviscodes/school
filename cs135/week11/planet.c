// Check a series of strings to see which ones are planet names

#include <stdio.h>

// Prototypes
_Bool string_in_string_array(char *str, char *array[]);
_Bool string_compare(char *str1, char *str2);

int main(int argc, char *argv[])
{
    char *planets[] = {
        "Mercury",
        "Venus",
        "Earth",
        "Mars",
        "Jupiter",
        "Saturn",
        "Uranus",
        "Neptune"
    };

    for (int i = 1; i < argc; i++) {
        if (string_in_string_array(argv[i], planets)) {
            printf("%s is a planet\n", argv[i]);
        } else {
            printf("%s is not a planet\n", argv[i]);
        }
    }
}

_Bool string_in_string_array(char *str, char *array[])
{
    while (array) {
        if (string_compare(str, *array++)) {
            return 1;
        }
    }

    return 0;
}

_Bool string_compare(char *str1, char *str2)
{
    while (*str1++ && *str2++) {
        if (*str1 != *str2) {
            return 0;
        }
    }

    return 1;
}
