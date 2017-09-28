# Chapter 6: Loops

### The `while` Statement
Simplest and most fundamental of all C loops.

```c
while (i < n)   // controlling expression
    i = i * 2;  // loop body
```
When executed, control expression is evaluated first. If evals to non-zero (true), loop body is executed. Then control tested again, and loop continues as such. While loops will usually have some sort of terminating condition. In the example above, when `i` has been incremented enough, it is eventually greater than `n`, so the loop terminates. However, sometimes it is desirable to write an infinite loop.
```c
while (1)
    // runs forever
```
The body of a while loop may not be executed at all. For example:
```c
int i = 5;
while (i > 5)
    // Never executes, as i is not greater than 5
```

#### Program: [Printing a Table of Squares](./programs/squares.c)

### The `do` Statement
Closely related to `while` statement. Only real difference is that the controlling expression is tested _after_ each execution of the loop body. This means that `do` statements are good for when we need to ensure that we'll execute the loop body **at least once**.

```c
i = 10;
do {
    // something
    --i;
} while (i > 0);
```

========

Skipping quite a bit of chapter, as it was covered verbatim in class

========

### The Comma Operator
> WTF is this? Seems pointless.

```
expr1, expr2
```
Evaluated in two steps: first, `expr1` is evaluated. **Its value is discarded**. Then `expr2` is evaluated, and its value **is the value of the entire expression**. `expr1` should always have a side effect, otherwise including it serves no purpose.

One common real-world usage is in the initialization portion of a `for` loop. For example:
```c
for (sum = 0, i = 1, i <= n; i++) {
    sum += i;
}
```

## Exiting from a Loop

### The `break` Statement
Often used to transfer control out of `switch` statements. Can also be used to jump out of `while`, `do`, or `for` loops.
```c
// Increments until a prime number is found, then exits
for (d = 2; d < n; d++){
    if (n % d == 0) {
        break;  
    }
}
```
Particularly useful for writing loops in which the exit point is in the middle of the body, rather than at the beginning or end. Often used for loops which read user input, then terminate once some condition is met.
```c
while (1) {     // infinite loop
    printf("Enter a number (enter 0 to stop): ");
    scanf("%d", %n);
    if (n == 0) {
        break;  // breaks once condition is met
    }
}
```
`break` statement breaks out of **innermost** enclosing statement. If statements are nested, `break` won't get us out of everything, only to the next level up.
```c
while (...) {
    switch (...) {
        ...
        break   // breaks out of switch, but still in while loop
        ...
    }
}
```

### The `continue` Statement
Related to `while` but it doesn't not actually remove control from a loop. `break` moves us to a point just after the completion of a loop, but `continue` moves us to the point **just before the loop completes**. If we need a loop which will skip some or all of the loop body based on a given expression, we can test for that expression, then `continue` if it evaluates to true. If evals to false, then the entire loop body is still executed.

### The `goto` Statement
Like `while` and `continue` in that it transfers control, but unlike those statements, `goto` can transfer to anywhere in the containing function, as long as that location is marked with a label.
```c
while (...) {
    switch (...) {
        ...
        goto loop_done;
        ...
    }
}
loop_done: ...
```
Helpful because it can get us all the way back out of nested loops if needed. However it is rarely used in everyday C programming.

#### Program: [Balancing a Checkbook](./programs/checking.c)
Had some trouble while doing this problem with runaway prompts. The things I isolated were:
- No `break` statements in `switch` cases
- Including newline characters in `scanf` calls
