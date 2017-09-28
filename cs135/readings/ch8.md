# Chapter 8: Arrays
Until now, all data types covered have been **scalar** -- can only store a single
value. C also supports **aggregate** variables, which can store collections of
values such as **arrays** and **structures**.

**array** is a collection of multiple values, all having the same data type. values
contained in an array are known as **elements**.

## One-Dimensional Array
Simplest kind of array. Elements are conceptually arranged one after another in
a row. Declaration of an array requires the type of the array's elements and
the number of elements.
```c
int a[10];  // Array a containing 10 int elements
```
Arrays can contain elements of any data type. Length can be specified by any
integer constant expression. Using a macro is a good idea.

> Macro here seems like overkill to me.

### Subscripting
Individual elements of arrays can be addressed by the name of the array and the
**index** (or position) of the desired element in square brackets. This is also
called **indexing**, much more commonly, I believe. We say "element at index 4,"
or "index into the array."

**Warning:** C does not protect against indexing outside of an array's bounds.

```c
int a[10];  // Array with 10 ints
a[10]++;    // Attempt to access the 11th element array
```
Undefined behavior abounds.

#### Program: [Reversing a Series of Numbers](./programs/reverse_array.c)
Cool use of `scanf` in a loop, storing successive values in an array.

### Array Initialization
Can be initialized like any other variable. Rules for this can be tricky.
```c
// Array is fully initialized with values provided
int a[5] = {1, 2, 3, 4, 5};

// Uninitialized values are set to 0. b == {1, 2, 3, 0, 0}
int b[5] = {1, 2, 3};

// c == {0, 0, 0, 0, 0}
int c[5] = {0}

// Illegal, initializer longer than array
int d[5] = {1, 2, 3, 4, 5, 6};

// Legal, explicit array length is omitted, implied by initializer.
int e[] = {1, 2, 3, 4, 5};

// Legal, f == {0, 2, 0, 4, 0}
int f[5] = {[1] = 2, [3] = 4};

// Legal, combines e and f. g == {0, 0, 3}
int g[] = {[2] = 3};

// Legal, h == {1, 2, 3, 0, 5}
int h[5] = {1, 2, [2] = 3, [4] = 5};
```

> Some of these are just stupid. Be clear.

## Multidimensional Arrays
Arrays can have more than one dimension. (As many as you'd like). Declared like
this:

```c
int m[5][9];    // m is an array containing five sub-arrays, each with 9 integers
```

Can be thought of as rows and columns, but this logic really breaks down after
3D arrays. Variable -> Row -> Matrix -> Cube -> ???. In fact, Multidimensional arrays are not stored in memory as rows and columns, but rather as successive rows.

Initialization options map directly to the rules for initializing a single dimensional array. One example below, but the other tenets above apply.

```c
int a[2][2] = {{1, 2}, {3, 4}};
```

### Constant Arrays
Using `const` keyword tells compiler that code should not alter the members.
Compiler will complain if code tries to alter the array. **This works for any variable type, not just arrays.**

Main benefit of this is clarity and integrity. Someone reading the code will see
a `const` variable and know that they shouldn't try to alter it. Also tells
compiler to protect us from accidental alterations.
