# Lecture[5][0]: Mid-term Review
Date: 10/3/17

### Identifiers
What is legal and what is not?

```c
100_bottles                 // Illegal, can't lead with number
_100_bottles                // Legal, leading underscore is fine
one_hundred_bottles         // Legal
_bottles_by_the_hundred     // Legal
```

From Ch 2.7: An identifier may contain letters, digits, and underscores. **Must
begin with a letter or underscore**. May not begin with a digit.

### Operator Precedence and Associativity
Will definitely be on test. "Spend a lot of time," Erin said. We'll be
evaluating a lot of these problems.

From Ch 4.1: Arithmetic operator precedence
| Precedence | Header Two     |
| :------------- | :------------- |
| Item One       | Item Two       |

### Evaluating Expressions (!!!)
Show output of program fragments. I need some work here.
```c
144 / 1.2       // 120.0
1.4 * 7 / 2     // 4.9
1 / 2 * 3       // 0
7 % 4           // 3
(7.0 * 2) / 15  // 0.93333
```
More. All variables `int`.
```c
i = 7, j = 8;
i *= j + 1;
// i == 63, j == 8

i = j = k = 1;
i += j += k;
// i == 3, j == 2, k == 1

i = 10; j = 5;
printf("%d", i ++ - ++j);   // Prints 4
// i == 11, j == 6

i = 7;
j = 3 * i-- + 2;
//i == 6, j == 23
```

### Logical Expressions
Show output produced by code fragments. All vars `int`. Feel confident here.
```c
i = 10; j = 5;
// !i < j == 1

i = 2; j = 1;
// !!i + !j == 1

i = 5; j = 0; k = -5;
// i && j || k == 1

i = 1; j = 2; k = 3;
// i < j || k == 1

i = 3; j = 4; k = 5;
// i < j || ++j < k == 1
// i == 3, j == 4, k == 5

i = 7; j = 8; k = 9;
// i - 7 && j ++ < k == 0
// i == 7, j == 8, k == 9
```

### `scanf` (!!!)
Why does `scanf` behave the way it does?
```c
int i;
float x, y;

scanf("%f%d%f\n", &x, &i, &y);
// User enters 12.3 45.6 789
// x == 12.3, i == 45, y == 0.600000
// WHAT THE FUCK. Why? Something about the buffer.
```
Need to revisit how the `scanf` buffer works.

From Ch 3.2: `scanf` ignores whitespace.

### `printf` (!!!)
Look up precision, padding, justification, other shit like that.
```c
printf("%06d,%5d", 86, 1040);
```

Format strings take this format:
```
%m.pX
```
- m: minimum field width
    - Minimum number of chars to print. If X is int and m > number of chars
    required to represent number, will left-pad with spaces.
- p: precision
    - Depends on X. If X is int, will result in zero-padding the left-hand side of the number. If X is float, will print trailing zeros.
- X: conversion specifier
    - d, e, f, g, etc. Tells `printf` what type of variable to expect.

A minus sign (-) before m will force left-justification. Decimal point only
required if p is set.

### Loops
Be able to trace and show what happens each loop.
```c
i = 1;
while (i < 128) {
    printf("%d", i);
    i *= 2;
}
// 128 is not printed in loop

for (i = 10; i >= 1; i /=2) {
    printf("%d", i++);
}
// Woah...
// Infinite loop: 10 5 4 3 2 1 1 1 1 1 1 1 1 1...
```
