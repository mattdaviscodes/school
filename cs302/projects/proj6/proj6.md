# CS 302 - Project 6
Date: 11/29/18 | Author: Matt Davis | [Assignment](./cs302-hw6.pdf)

### Exercise 1
In this project, we implemented inorder, preorder, and postorder
traversal of a binary search tree. The instructions were to generate
100 random integers between 1 and 200 and add them to the BST. I re-used
some code I'd written for [project 4](../proj5/) to generate the random
values. For reference, I write the numbers to a [file](./generated_numbers.txt).

One decision I made was to diverge from the provided header file pretty
significantly. I spent three nights trying to cobble together the disparate
pieces of code shown in lecture slides, and never even got it to compile.
I thought that using the code provided would save me some time. Turns out,
it was much more effective to look critically at the assignment requirements,
and work to achieve those goals alone.

The code is here:
* [BinarySearchTree.cpp](./BinarySearchTree.cpp)
* [BinaryNode.cpp](./BinaryNode.cpp)
* [proj6.cpp](./proj6.cpp)

Build with `make`.

Representative output can be found here: [proj6.out](./proj6.out)

