### C Knowledge
Mostly stuff from first test. Should review. What are valid data types. How
many times does loop execute. What does snippet print. Etc.

### Arrays
Know how to write initializers -- one liners that create variable and also set
values.
```c
_Bool times[24][60] = {[1][24]=1, [15][30]=1};
```

Iterate over arrays, working with the data throughout. Example: iterate over int
array, incrementing each value in array by 3.

### Functions
Write prototypes, asshole.

```c
// A function named f that takes as parameters 2 ints values x and y and returns
// a value of type float.
float f(int x, int y);

// A function named g that takes two chars a and b returns positive int
unsigned int g(char a, char b);
```

### Pointers
Write a void function that takes in two char pointers and swaps the values of the chars inside them.
```c
void swap(char *a, char *b)
{
    char tmp;
    tmp = *char1;
    *char1 = *char2;
    *char2 = tmp;
}
```

### Functional programming
Write a program to take 10 ints, store in 2x5 array, sum all ints using
function and return sum.

```c
// Do that shit

#include <stdio.h>

#define ROWS 2
#define COLS 5

int add_nums(int arr[ROWS][COLS], int rows, int cols);

int main(void)
{
    int arr[ROWS][COLS];

    printf("Enter 10 integers: ");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Sum: %d\n", add_nums(arr, ROWS, COLS));

    return 0;
}

int add_nums(int arr[ROWS][COLS], int rows, int cols)
{
    int sum = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
    }

    return sum;
}
```
