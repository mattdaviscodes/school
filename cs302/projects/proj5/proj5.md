# CS 302 - Project 5
Date: 11/13/18 | Author: Matt Davis | [Assignment](./cs302-hw5.pdf)

### Exercise 1
I decided to implement the array-based queue because I usually select
the link-based versions, so I wanted to try something else. For our
limited purpose, I believe it's the better implementation to use as
it emphasizes speed, and if we're running multiple trials, we want the
program to execute faster. The only problem I see here is that it's
possible that the customer count can exceed the queue capacity, in which
case the program fails.

The code is here: [QueueArray.cpp](./QueueArray.cpp),
[storesim.cpp](./storesim.cpp). Build with `make`.
It is also still possible to build the test program by running
`make test`.

Example output can be found here: [storesim.out](./storesim.out)

Data below.

| Time (minutes | Total number of customers served | Average wait | Longest wait |
|---------------|----------------------------------|--------------|--------------|
| 30            | 24                               | 2.4          | 5            |
| 60            | 33                               | 1.4          | 3            |
| 120           | 94                               | 1.9          | 4            |
| 480           | 345                              | 1.9          | 6            |

