# Lecture[13][1] - File I/O
Date: 11/30/17

## Block I/O
The `fread` and `fwrite` functions allow a program to read and write large
blocks of data in a single step. They're used with **binary streams**, but can
also be used with text streams, if careful.

Possible use case is to save program state (e.g. "save game" function) written
to a binary file at program exit. This could then be loaded on program start.

### `fwrite`
Designed to copy an array from memory to a stream. Need:
- Address of array
- Size of each element
- Number of bytes to written
- File pointer.
Returns number of elements actually written. If return is less than 3rd arg,
the function errored.
```c
fwrite(a, sizeof(a[0]), sizeof(a) / sizeof(a[0]), fp);
```

### `fread`
Read elems in array from a stream. Very similar to `fwrite`. Return indicates
number of elems read.

## Character I/O
Similar to block I/O, except reads and writes single characters. Treats vals as
`int` not `char`, so look out. Functions can be used with binary or text
streams.
- `putchar(ch)`
- `fputc(ch)`

#### Program: [Copying a File](../fcopy.c)
