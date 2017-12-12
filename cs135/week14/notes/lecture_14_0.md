# Lecture[14][0] - Writing Large Programs
Date: 11/7/17

Right now, all programs are small, maybe a few functions and a main(). The nature
of this business is that complexity grows. Better get used to it. Enter, multi-
file programs.

### Source Files
Groups sets of related functions. Uses the .c extension. Each source file in a
program contains part of the program.

One source file in a program **must** contain main functions, which serves as
the starting point for the program. The file may contain other functions that
are not called from other files in the program.

NOTE: We *already* do this. Every time we #include something.

### Header Files
Each source file foo.c will have a matching **header file** foo.h that contains:
- Prototypes for the functions defined in foo.c
- Definitions of variables, macros to be shared with other .c files
Functions to be used only within foo.c should not be declared in foo.h. For example,
some small utility function that is important to the functionality to the full
library should only be included in foo.c.

foo.h will be included in each source file that needs to call a function defined
in foo.c, including foo.c.

### Advantages of Splitting a Program
Grouping related functions and variables into a single file helps clarify the
structure of the program.

### The `#include` Directive
Tells the preprocessor to insert the contents of the included file into the main
file. Has two primary forms.
1. Use angle brackets for standard libraries.
2. Use double quotes for external libraries.
```c
#include <stdio.h>
#include "myfile.h"
```

### Makefiles
A Makefile is in charge of telling the compiler how to connect source files and
header files.
code
```
main: main.o hello.o
    gcc -o main main.o hello.o

main.o: main.c hello.h
    gcc -c main.c

hello.o: hello.c hello.h
    gcc-c hello.c
```
