# Lecture[6][0] - Arrays
Date: 10/10/17

Haven't we gone over all of this already? Frustrating that this class is so
disjointed. We're talking about arrays (again) in lecture, reading about
functions for homework, and still stuck on printf/scanf in lab.

#### Program: [Reversing a Series of Numbers](../reverse.c)
Practice writing and working with arrays by writing a program to take 10 ints
as input, then output the same ints in reverse order.

### Array Initialization
There are a *bunch* of ways to do this. Won't record all here. You can
explicitly supply all values, only specify some (the rest will default to 0), or
initialize all elements to the same value, as follows:
```c
int a[4] = {0}; // a == {0, 0, 0, 0}
```
