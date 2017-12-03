/*
 * Name: planets_sort.c
 * Purpose: Sort arrays alphabetically or reverse-alpha depending on CLAs
 * Author: Matt Davis
 * Date: 11/30/17
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int string_compare(char *str1, char *str2);

int main(int argc, char *argv[])
{
    int order;
    char *tmp;
    char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter",
                       "Saturn", "Uranus", "Neptune", "Pluto"};

    if (argc != 3 || strcmp(argv[1], "-o") != 0 || (*argv[2] != 'a' && *argv[2] != 'r')) {
        printf("Usage: ./planets -o [a | r]\n");
        exit(EXIT_FAILURE);
    }

    // Set order depending on CLA
    if (*argv[2] == 'a') {
        order = 0;
    } else {
        order = 1;
    }

    // Sort depending on order
    for (int i = 0; i < sizeof(planets) / sizeof(planets[0]); i++) {
        for (int j = sizeof(planets) / sizeof(planets[0])- 1; j > i; j--) {
            if (string_compare(planets[j], planets[j-1]) == order) {
                tmp = planets[j];
                planets[j] = planets[j-1];
                planets[j-1] = tmp;
            }
        }
    }

    // Print the damn thing
    printf("The planets in %salphabetical order are: ", (order == 1) ? "reverse " : "");
    for (int i = 0; i < sizeof(planets) / sizeof(planets[0]); i++) {
        printf("%s", planets[i]);

        // Comma separate all except last in list
        if (i != sizeof(planets) / sizeof(planets[0]) - 1) {
            printf(", ");
        }
    }
    printf("\n");

    return 0;
}

/*
 * Function: string_compare
 * ---------------------
 *      Compare two strings.
 *
 *      Returns:
 *          0  : str1 is prior to str2 alphabetically
 *          1  : str2 is prior to str1 alphabetically
 *          -1 : str1 and str2 are identical
 */
int string_compare(char *str1, char *str2)
{

    while (1) {

        // Check for end of strings
        if (*str1 == '\0') {
            if (*str2 == '\0') {
                return -1;
            }
            return 0;
        } else if (*str2 == '\0') {
            if (*str1 == '\0') {
                return -1;
            }
            return 1;
        }

        // Evaluate alphebetic order
        if (tolower(*str1) < tolower(*str2)) {
            return 0;
        } else if (tolower(*str1) > tolower(*str2)) {
            return 1;
        }

        str1++;
        str2++;
    }

    return 0;

}
