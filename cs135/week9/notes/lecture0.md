# Lecture[9][0] Notes - Pointers Cont
Date: 10/31/17

## Pointers as Arguments
Pointers can be used to modify the arguments passed to a function. By passing
a pointer -- called **passing by reference**, as opposed to passing by value --
we can modify the value pointed to by the pointer directly.

```c
void max_min(int a[], int n, int *max, int *min)
{    
    *max = a[0];
    *min = a[0];

    for (int i = 0; i < n; i++) {
        if (a[i] > *max) {
            *max = a[i];
        } else if (a[i] < *min) {
            *min = a[i];
        }
    }
}
```

### Pointers as Return Values
The `const` keyword may be used to protect the values of pointer values when
passed in. When passing a pointer to a function, it's often assumed that we will
modify the value pointed to, but that's not always true. Good to use `const`
here to document the code.

```c
int *max(const int *a, const int *b)
{
    if (*a > *b) {
        return a;
    } else {
        return b;
    }
}
```

IMPORTANT: Do not return pointer to a function's local variables. Those variables
disappear when the function returns, so the pointer will be invalid.

## Pointers and Arrays
Pointer arithmetic may be performed to iterate over arrays in place of
subscription, as we usually do.
```c
int a[5] = {1, 2, 3, 4, 5};
int *p = &a[0]; // int *p = a also legal

printf("%d\n", a[2]);
// Prints 3
printf("%d\n", p+2);
// Prints 3, as a[2] is two memory addresses greater than a[0]
// and p is equal to &a[0].
```

#### Program: [Reversing a Series of Numbers (Revisited)](../reverse3.c)
Same as the problem we've written a few times now, but this time we used
pointer variables to drive our loops instead of array subscription. Pretty
cool, actually. 
