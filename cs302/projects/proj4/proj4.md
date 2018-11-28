# CS 302 - Project 4
Date: 10/19/18 | Author: Matt Davis | [Assignment](./cs302-hw4.pdf)

### Tested Algorithms
1. Selection Sort
2. Merge Sort

### Case 1
I wrote [genRand.cpp](./genRand.cpp) to generate random integers to be
used in the following tests. The script accepts command line arguments
which enable it to pseudo-randomly generate any number of integers
between a set of minimum and maximum bounds. Generated data can be found
in the [data](./data) directory.

Example usage:

```
// generate 100 ints between 0 and 1 million
$ ./genRand 0 1000000 100
```

Compile the genRand script with the following command:

```
$ g++ -Wall -std=c++11 genRand.cpp -o genRand
```


### Case 2
I originally chose to implement Quick Sort, but ran into some diffuculty,
so I fell back to Merge Sort. I was pretty shocked how drastic the
difference between Merge and Selection was with the largest data set.

Build the code with `make`. Note that the driver is not very intelligent --
in order to test the different algorithms and inputs, you must make slight
changes to the code itself by uncommenting some lines and commenting others.
I hope this is okay, given that parsing command line args is not the focus
of the assignment.

Data below.

| Algorithm Name | Complexity |
|----------------|------------|
| Selection Sort | O(n^2)     |
| Merge Sort     | O(logn)    |


UNSORTED

| Size   | Selection Sort | Merge Sort |
|--------|----------------|------------|
| 1000   | 0.0019s        | 0.0002s    |
| 10000  | 0.1703s        | 0.0024s    |
| 100000 | 17.6005s       | 0.0264s    |

SORTED

| Size   | Selection Sort | Merge Sort |
|--------|----------------|------------|
| 1000   | 0.0018s        | 0.0001s    |
| 10000  | 0.1761s        | 0.0016s    |
| 100000 | 22.1685s       | 0.0193s    |

