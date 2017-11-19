# Lecture[11][0] - Strings
Date: 11/16/17

## String Idioms

### Searching for the end of a string
Can increment the string pointer until the null character is found. Null char
is falsey.
```c
char *s;
// ... make a string...
while (*s)
    s++;
```

### String Concatenation
Requires a two-step algorithm. Step 1: Locate the `null` character at end of string 1 and make `p` point to it. Step 2: Copy characters one by one from string 2 to where `p` is pointing.

### Copying a String
Can be done in a bodyless while loop.
```c
while (*p++ = *s++)
    ;
```

## Arrays of Strings
2d Character arrays.
```c
char names[][6] = {"Matt", "Arnold", "Tim"};
```
Stored like below, with _ equaling '\0'
```
M a t t _ _
A r n o l d
T i m _ _ _
```

This is pretty wasteful, however. Lots of wasted null space. Instead we can use
a 1d array of char pointers, each of which points to a null-terminated char
array (string).
```c
char *names[] = {"Matt", "Arnold", "Tim"};
```
The tradeoff here is that the former can be variable (as long as the array size
is large enough to accept largest possible input) while the latter is essentially
constant.

## Command Line Args
CLAs require that main define two parameters:
```c
int main(int argc, char *argv[])
{
    ...
}
```
- argc: Number of arguments
- argv: Array of pointers to command line args (stored as strings)

argv[0] is ALWAYS the name of the program. It's the first line of our command.
argv[argc] is always a null pointer -- a special pointer that points to nothing.

CLAs can be accessed using a loop that examines each arg in the argv array. Or
increment a pointer.

#### Program: [Checking Planet Names](../planet.c)
Check a series of strings to see which ones are names of planets. My solutions
doesn't work, but it compiles. Almost had it in time.

## C String Library
Direct attempts to compare strings or concatenate them using operators will fail.
```c
str1 += str2;   // Fails
str1 == str2;   // Fails
```

To use the string library, must include `string.h` in programs. This gives us
access to `strcopy()`, which takes two char arrays and appends the second to
the first. Has no way to check if everything will fit in the size of str1. Safer
to user `strncopy()` which is also provided by `string.h`.

## Low-Level Programming: Bitwise Operators
Not very applicable to this class, but worth touching on. Used much more in
hardware.
