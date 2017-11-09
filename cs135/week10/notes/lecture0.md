# Lecture[10][0] - Strings
Date: 11/7/17

## Midterm Stuff
Gotta go write some code. It's the only way to study. Just do practice problems
from end of book chapters.

Read carefully -- understand what is given and what still needs to be done. Don't do any more or less than necessary. (Understand the difference between
programs, statements, functions, etc.)

Material is not cumulative -- will not be asked questions that we would have
been asked on the first test. However, material from last test is considered
known, and will be required to complete *this* test.

Must know:
- Trace loops
- Type specifiers (long, long long, short, etc)
- How to capture repeated user entry    (DO ONE OF THESE)
- Arrays
    - Single- and multi-dimensional
    - Declaring
    - Initializing in different ways -- all one val, specific vals, loops
    - Accessing and processing array elements (single and nested)
    - **Don't forget `sizeof` operator**
- Functions
    - Declarations
    - Parameters -- pass by value concept
    - Prototypes (same as Declarations) -- format and when to use them
    - How to use array args
    - Writing and tracing code
- Pointers
    - Basics -- Address of and indirection operators (`&` and `*`)
    - Initializing
    - Returning
    - Pointer arithmetic (usually used with arrays and loops)
    - How to match return and parameter types
    - **SCOPE** -- should not return a pointer to function's local var

## Strings
Arrays of characters terminated by a null character '\0'. They come in `string
constant` and `string variable` flavors. C library provides a collection of
functions to work with strings.

### String Literals
Sequence of characters enclosed within double quotes. May contain escape
sequences.

May use the backslash character to continue to next line to make it more
readable. When printed, it will appear as one line. A better way to do the same
thing is to close one string with the end quote, then immediately open another
on the same line.

#### Length and Storage
A string literal of length n will need n+1 bytes of memory, one to store each
character, and one to store null terminator. Null character is a byte whose bits
are all zero.

Stored as an array. Compiler treats it as pointer of type `char *`. Both `printf`
and `scanf` expect a value of type `char *` as their first arg.

#### Operations
Can use a string literal wherever C allows a `char *` pointer.
```c
char *p;
p = "abc";
```
This assignment makes p point to the first char of the string "abc". Just like
arrays, we can also subscript strings.
```c
p[1] == 'b' // True
```

IMPORTANT: Attempting to modify a string literal causes undefined behavior.
Trouble abounds, traveler. That's why, in some cases, it's better to use...

### String Variables
Any one-dimensional array of characters can be used to store a string. A string
must be terminated by a null character. In this case, it can be hard to tell
whether it is being used as a string or not. Always always always must deal
properly with null character.

**Not all character arrays are strings. The null-terminator turns a character
array into a string.**

#### Length
When declaring a string variable, must always create an array big enough to hold
biggest-possible string INCLUDING null-terminator.
```c
#define STR_LEN 80
char str[STR_LEN + 1];  // +1 for null-terminator
```

#### Initialization
If string is too short to fill allowed space, compiler will add as many null
characters as necessary to fill array.

## Reading and Writing Strings
Writing uses `printf` or `puts`. Reading uses `scanf` or `gets`.

And a bunch of other shit. Lecture was going way to fast to take notes. Fuck.
