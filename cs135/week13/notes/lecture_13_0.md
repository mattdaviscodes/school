# Lecture[13][0] - File I/O
Date: 11/28/17

To date, we've only run programs that store data in memory. This is very
fragile. One way around this problem is storing data in files, which means
that we need to be able to read from and write to files. Enter: File I/O.

### Topics Covered
- Streams, the `FILE` type, input and output redirection, and the difference
between text files and binary files
- Functions designed specifically for use with files (open, close, etc)
- Functions that read and write unformatted data (chars, lines, blocks)

### Streams
The term **stream** means any source of input or any destination for output.
Many small programs obtain all their input from one stream and write all output
to another stream. Larger programs need additional streams. Streams often
represent files stored on various media. However they could also be network
ports or printers.

#### Standard Streams and redirection
`stdin`, `stdout`, and `stderr` are all very common and come from `<stdio.h>`.
**Input Redirection** is allows us to store commands in a file that will be
used as the requested input in a command line program.
```
$ demo < in.dat
```
**Output Redirection** is the same, but in reverse. All print statements go to
the specified file instead of the screen.
```
$ demo > out.dat
```
Input and output redirection can be combined.

Big problem with redirection is that it sends ALL prints to the file, but
sometimes we still need to communicate with user via the screen. In this case,
we can use the third stream `stderr` to communicate with user.

### Text files vs Binary files
`<stdio.h>` supports two kinds of files: text and binary.

Text files are divided into lines, terminated by a special line-end
character.. They are intended for humans, and thus, should be readable.
(NOTE: Different operating systems use different line end characters. Beware.)
They also usually contain a end-of-file (EOF) marker.

Binary files are intended for computers, and are not meant to be read by
humans. They are much more space efficient.

### Working with files: Open, Close, Write, Append
Accessing a stream is done through a **file pointer**, which has type
`FILE *`. Type declared in `<stdio.h>`. Certain streams are represented by
file pointers with standard names. Additional file pointers can be declared
as needed.
```c
FILE *fp1, *fp2;
```

#### Mode strings for text files
- "r" - Open for reading
- "w" - Open for writing
- "a" - Open for appending
- "r+" - Open for reading AND writing, starting at beginning
- "w+" - Read and write, truncate if file exists
- "a+" - Read and write, append if exists

Binary files have all the same modes, but a "b" must be appended to the mode.

#### Program: [Checking Whether a File Can Be Opened](../canopen.c)
Write program to take list of command line args as filenames. Test if each can
be opened for reading and print results to screen.
