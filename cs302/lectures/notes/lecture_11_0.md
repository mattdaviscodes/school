# CS 202 - Lecture 11.0 - Dynamic Data Structures (part 3)
Date: 4/17/18 | [Slides](../CS202_Lecture22_[Dynamic_Data_Structures_(Pt.4)]_4.16.pdf)

[Prev](./lecture_10_1.md) | [Next](./lecture_11_1.md)

## Queue

> Much of last lecture regarded queues. I'm summarizing here.

A queue is another specialized data structure, like a linked list.
Queues get their name and the concepts for much of their functionality
from real-world queues or lines. Elements are added only at the end
of the queue, and removed only from from the front, like customers
in line at the store. Adding and removing are called **enqueueing** (or
pushing) and **dequeueing** (or popping) respectively.

Like a linked list, a queue is often made of nodes, with each node
containing some piece of data as well as a pointer to the next node
in the queue. This way, the developer can traverse the queue from back
to front. Unlike a linked list, however, a queue's middle nodes (the
ones that aren't the front or the back) are inaccessible.

> Does this mean they're really just linked lists that we're imposing
some restrictions on that don't actually exist in the code? Nodes
in the middle aren't truly inaccessible. This is just a construct.

## Array-Based Queue
Like a linked list, queues can also be implemented on top of standard
arrays instead of using a node-based structure.

