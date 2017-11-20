/*
 * Name: lab11.c
 * Author: Matt Davis
 * Purpose: Practice pointers, string manipulation, and functions
 * Date: 11/20/17
 */

#include <stdio.h>
#include <string.h>

void remove_filename(char *url);

int main(int argc, char *argv[])
{
    char url[] = "http://www.knking.com/index.html";

    // Optional command line arg to try function with different
    // inputs. If no CLAs given, will default to url above.
    if (argc == 2) {
        strcpy(url, argv[1]);
    }


    printf("Before: %s\n", url);
    remove_filename(url);
    printf("After: %s\n", url);

    return 0;
}


/*
 *  Function: remove_filename
 *  -------------------------
 *      Remove a 'filename' from the end of a url by stripping the final
 *      slash and all characters following it.
 */
void remove_filename(char *url)
{
    char *last_slash;

    if ((last_slash = strrchr(url, '/'))) {
        *last_slash = '\0';
    }
}
