# Lecture[2][0] Notes
Date: 9/12/17

## Expressions (cont)

### Lvalues

Left side of assignment operator is called lvalue. It's the thign we're storing data inside of.

`i = 1;` lvalue is i

### Compound assignment

`i = i + 2` is similar to `i += 2`

Works for all arithmetic operations.
* `+=`
* `-=`
* `%=`
* etc

### Increment and Decrement operators
++ is the increment operator, adds 1 to operand. -- is the opposite.

Operator can come before or after operand, which changes function a little. `++i` increments immediately and `i++` increments after the statement has executed. See slides for examples.


### Exercises
```c
i = 7; j = 8;
i *= j + 1;
printf("%d %d", i, j);
```
`63 8`

```c
i = j = k = 1;
i += j += k;
printf("%d %d %d", i, j, k);
```
`3 2 1`

```c
i = 1; j = 2; k = 3;
i -= j -= k;
printf("%d %d %d", i, j, k);
```
`2 -1 3`

```c
i = 2; j = 1; k = 0;
i *= j *= k;
printf("%d %d %d", i, j, k);
```
`0 0 0`

```c
i = 10; j = 5;
printf("%d", i++ - ++j);
printf("%d %d", i, j);
```
`4`

`11 6`

```c
i = 7; j = 8;
printf("%d", i++ - --j);
printf("%d %d", i, j);
```
`0`
`8 7`

## Logical Expressions

### Statements
* if
* while
* break
* goto
