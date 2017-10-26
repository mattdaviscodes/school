# Lecture[8][1] Notes - Recursion/Pointers
Date: 10/26/17

## Recursion
A function is **recursive** if it calls itself. Following func calculates *n!*
recursively. Note that the **termination condition** or **base case** (the case where the recursion stops) must be checked first.

Generally, the argument against recursion has to do with performance. It's
wasteful to call the same function over and over when the same work can almost
always be done with a loop.
```c
int fact(int n)
{
    if (n <= 1) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}
```
Another example. Raise `x` to the power of `n` recursively.
```c
int power(int x, int n)
{
    if (n == 0) {
        return 1;
    } else {
        return x * power(x, n - 1);
    }
}
```
Fibonacci.
```c
int fib(int n)
{
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fib(n-1) + fib(n-2);
    }
}
```

## Pointers

### Pointer Variables
Most modern computers divide memory into bytes (each comprising 8 bits). These
bytes can be addressed. These are **pointers**. These pointers may be stored in
**pointer variables** (usually referred to just as pointers). That way, a
program can just hand around the address of data instead of the data itself.

Declared using the `*` or *star* character.

```c
int *p;     // Pointer variable pointing to object of type int
int i, *p;  // This also works, but seems less readable
```

To find the address of a variable, use the `&` or *address* operator. To get the
value that a pointer points to, use again the `*` operator, called the
*indirection* operator in this case.

```c
int i, *p;          // p points nowhere yet
p = &i;             // store the address of i in the variable p
printf("%d", *p)    // print the value of i, using the address stored in p
```
