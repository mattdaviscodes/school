# Lecture[4][0] - Data Types
Date: 9/26/17

## Integer Types

### Signed Integers
Sign indicates if int is positive or negative. First bit of integer is called `sign bit` and is 1 if negative and 0 if positive. Signed ints allow for positive and negative numbers, while unsigned ints do not. Tradeoff is that we sacrifice one bit (one power of 2) to indicated sign.

> Probably best to avoid unsigned integers as much as possible. Dangers usually outweigh benefits.

## Floating Types
Three total floating types:
- `float` Single-precision
- `double` Double-precision
- `long double` Extended-precision

C Standard does not state how much precision these provide. Most modern computers follow IEEE Standard 754. Numbers are stored in a form of scientific notation -- each number has a **sign**, **exponent**, and **fraction**.

> Probably a bad idea to use floating point values in conditional statements due to precision.

Must prepend use `%lf` to `scanf` doubles. Stands for long float. Not necessary in `printf`.

## Character types
- `ASCII`
- `latin-1`
- `UTF-8`

Too much to note during lecture. Go read about this shit. Especially UTF-8.

### Character Sets
`char` data type used to store characters. Must use single quotes in assignment.

Can also do operations/arithmetic on characters.

Can be signed and unsigned. What?

`printf` and `scanf`, use `%c`. Warning: `scanf` for chars doesn't skip whitespace, as it is a valid character. Can also use `getchar` and `putchar`, which are builtin variables.

### Problem: [Determining Length of Message](../msg_length.c)
Wrote a program to accept user input string and count characters. I used `getchar` in a while loop without storing the character retrieved as we don't actually need it. All the loop does is increment the counter for each result of `getchar` that is not a newline.

## Type Conversions
Implicit type conversion happens when the operands of an arithmetic or logical expression do not have the same type.
```c
4 + 3.5f;   // Cast to double. Compiler warning.
```
Also happens when expression on right side of assignment does not match variable type.
```c
int i;
i = 3.5;    // Truncates to 3
```
If types differ in expression, result will cast to **narrowest** type which will accommodate both values.

## Casting
Gives us a greater degree of control over type conversion. Comes in form `(type-name) expression`
```c
float f = 1.5;
int i = (int) f;
```
C regards cast statements -- `(type-name)` -- as a unary operator. Takes precedence over binary operators.

Casts are sometimes used to avoid overflow.
```c
long i;
int j = 1000;
i = (long) j * j; // Casts first j as long, so full result is promoted to long.
```

## Constants
Numbers that appear in the text of a program. Often called *magic numbers*, and are discouraged because they hide meaning and are prone to bug generation. Much better to define as macro and give the thing a name.
