# CS 302 - Project 7
Date: 12/1/18 | Author: Matt Davis | [Assignment](./cs302-hw7.pdf)

### Exercise 1
The focus on this project was gaining experience with the STL via
practice with heaps. We were to generate random values to be added
to a heap and manipulated.

I re-used some code I'd written for [project 5](../proj5/) to generate
the random values. I also wrote a helper function for displaying a
vector along with a descriptive label.

The project was very straight forward. The only problem I faced was
that `std::sort_heap` sorts to a minheap, while `std::make_heap` sorts
to a maxheap. A comparator -- a function which compares two values for
the purpose of sorting -- may be passed to `std::sort_heap`, which would
have solved my problem, but it was much easier to just re-use `std::make_heap`.
I don't know if this causes any performance issues, but it's unimportant
while processing such a small input.

The code is here: [proj7.cpp](./proj7.cpp). Build with `make`.

Representative output can be found here: [proj7.out](./proj7.out). Please
note that I generated this output using an input of only 11 integers which
makes the file far more readable. If you build and run the program, you
will see output containing the full 100 integers.

