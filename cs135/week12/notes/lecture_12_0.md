# Lecture[12][0] - Dynamic Memory Allocation
Date: 11/21/17

Up until now, we haven't been required to allocate our own memory. Declaring
a variable (array, int, etc) handles the memory allocation for us. Once it's
been declared, it's fixed and cannot be altered later. This is where Dynamic
Memory Allocation comes in

### Functions
The <stdlib.h> header declares three functions:
1. `malloc` - Allocates block of memory but doesn't initialize
2. `calloc` - Allocates memory and clears it
3. `realloc` - Resized a previously allocated block of memory

All of these return a pointer.

### Using `malloc` to Allocate Memory
Prototype:
```c
void *malloc(size_t size);
```
If for any reason the memory cannot be allocated, `malloc` will return a null
pointer.

## Dynamically Allocated Strings

### using `malloc` to Allocated Memory for a String
Allocates memory for a string of n characters:
```c
char *p;
p = malloc(n + 1);  // Leaves room for Null character
```
Memory locations are not initialized here.

## Dynamically Allocated Arrays
