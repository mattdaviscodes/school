# Lecture[15][0] - Final Review
Date: 12/12/17

#### Not On Final
- Makefiles
- Convert decimal to binary

#### Topics
- Pointers
    - Creating
    - Arithmetic
    - As function args
- Command Line Args
- Arrays
- Dynamic Memory Allocation
- FileIO
- Initializing
    - Pointers
    - Arrays
    - Strings  `char *str = "Fuckthisshit"`
- Scope
    - function
    - logical statements
    - global
- Bitwise operators (???)
    - Exclusive or, exclusive and
    - 

### Creating Pointers
```c
int i, j;
int *p;
i = 5;
p = &i; // p refers to i
j = *p; // j is the de-reference of p
```
And initialization (declaring and assigning at the same time):
```c
int i;
int *p = &i;
```

### Pointer Arithmetic
> I suggest you get pretty comfortable working with this...

```c
int a[10], *p, *q, i;
p = &a[2];
q = p + 3;  // q points to a[5], which is three indexes more than p
p += 6; // now p points to a[8], and q still points to a[5]
```

### Pointers as function args
Values can be **passed by reference** by using pointers as function args.

### Command Line Args
Make sure I can write a program which accepts file name via CLAs.

### Strings
Know various string idioms.
- Copying
- Find end of string
- Find character in string

### Copying a string
```c
while (*p++ = *s2++)
    ;
```

### Dynamic Memory Allocation
Must be able to dynamically allocate 2d array. Look for sample code on
WebCampus posted by Erin. VERY IMPORTANT.

### Bitwise Shift Operators
```c
unsigned short i = 13, j;
// i is now 13 (binary 0000000000001101)

j = i << 2;

```
