# Chapter 6: Loops

## The `while` Statement
Simplest and most fundamental of all C loops.

```c
while (i < n)   // controlling expression
    i = i * 2;  // loop body
```
When executed, control expr is evaluated first. If evals to non-zero (true), loop body is executed. Then control tested again, and loop continues as such. While loops will usually have some sort of terminating condition. In the example above, when `i` has been incremented enough, it is eventually greater than `n`, so the loop terminates. However, sometimes it is desirable to write an infinite loop.
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

#### Program: Printing a Table of Squares

[link](squares.c)
