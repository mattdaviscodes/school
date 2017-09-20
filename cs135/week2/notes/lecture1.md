# Lecture[2][1] Notes
Date: 9/14/17

## Evaluating Logical Expressions

### Statements with multiple logical expressions
This example came up in class and caused quite a bit of discussion.
```c
int i = 1, j =1, k = 1;

printf("%d\n",++i || ++j && ++k);
printf("%d %d %d\n", i, j, k);
```
```
1
211
```
Brings up questions of operator precedence. Seems like second line should print `222` if `&&` takes precedence over `||`, but that's not what we see. Relevant SO thread [here](https://stackoverflow.com/questions/17432730/precedence-of-over).

### The `if` Statement
```
if (expression) <-- evaluates to T or F, 1 or 0
    statement
else
    statement
```
#### The Dangling `else` Problem
If curly braces are omitted, `else` refers to immediately previous `if`. Very easy to create hard to find bugs this way.

```c
int y = 0, x = 1, result;

if (y != 0)
    if (x != 0)
        result = x / y;
else
    printf("Error: y is equal to 0\n");
```
Logically, we see that the designer wants to fire the error message in the else statement if y = 0, but in fact this doesn't happen. The `else` is associated with the second `if`, despite whitespace and indentation. This compiles, runs, and prints nothing. Alignment and whitespace don't matter to compiler. It's much better to be explicit, by using curly braces always.

### Cascaded `if` Statements
```
if (expression)
    statement
else if (other expression)
    statement
else
    statement
```

## Iteration Statements

### The `while` Loop

```
T minus 10 and counting.
T minus 9 and counting.
...
T minus 1 and counting.
```
The above is very easy with a while loop.
```
while (expression)  <- Control
    statement(s)    <- Loop body
```
Statement body executes over and over again until expression evaluates to false.
