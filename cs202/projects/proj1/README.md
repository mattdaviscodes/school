# Project 1
Submitted: 1/29/18

### Purpose
This program allows the user to specify the names of input and output text files which will be read from and
written to, respectively. The input file -- [Names.txt](Names.txt), for example -- contains a list of names,
delimited by newline characters. The program reads these names into a two-dimensional array and prints the array
to the console. Then a copy of the array is sorted alphabetically and *this* array is printed to the console,
preceeded by each name's original index.

### Design choices
- **Sort**: I chose to use bubble sort, as I read it was the easiest to implement.
- **Original index**: I decided to first read the file into one 2d array, then copy that array over to another. I
sorted the copy and used the original to find each name's original index. This isn't very space efficient, but it
works.

### Problems
I had a hard time with the string compare function. My original attempt is below:

```cpp
int myStringCompare(const char str1 [], const char str2 [])
{
    int diff = 0;

    for (int i = 0; i < NAMES_IN_FILE; i++) {
        diff = str1[i] - str2[i];
        if (diff != 0) {
            break;
        }
    }

    return diff;
}
```

Somehow, this function would correctly sort the array when combined with my bubble sort function, but it failed when
trying to find the original index of a name in the input array. I still don't understand why. I doubled back, rewrote
the function from the ground up, and it works now.

### Misc
The spec calls for the function `int myStringLength(const char str [])`, which I wrote, but couldn't find any use for.
The implementation is still in the project, but it's just sitting there. Not sure what the intended use was.