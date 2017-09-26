# Lecture[3][1] Notes
Date: 9/21/17

## Conditional Operator: `?`
Also called a **ternary operator**. Compresses if-else statements nicely. Probably only use with _very_ simple statements, otherwise line will get too long/confusing.

`expr1 ? expr2 : expr3` - reads as if expr1 then expr2 else expr3. This is referred to as a **conditional expression**.

```c
int i, j, k;

i = 1;
j = 2;
k = i > j ? i : j;          // k is now 2
k = (i >= 0 ? i: 0) + j;    // k is now 3
```
Best to use sparingly. Often used in return statements.
```c
return i > j ? i : j;
```

## The `break` and `continue` Statements

### `break`
Normal exit point for loop is at beginning or end. Using `break` makes it possible to exit in the middle of a loop. Can also have multiple exit points.

> Holding off on notes. I already took notes on the readings.

## Interactive Programs
Present user with list of commands to choose from. User enters command (maybe some error checking happens), the desired operation is executed, then the user is prompted **again** for input. Usually there is an exit command, also. 
