# CS 202 - Lecture 10.0 - Dynamic Data Structures (part 1)
Date: 4/10/18 | [Slides](../CS202_Lecture19_[Dynamic_Data_Structures_(Pt.1)]_04.05.pdf)

[Prev](./lecture_9_1.md) | [Next](./lecture_10_1.md)

> Didn't get very far into last lecture's slides, so Christos is
just using the same deck. The slides link above is correct.

## Linked-Lists

### Nodes
Class containing a data point and a pointer to the next node int the
list. If the next pointer is NULL, then this is the last node in the
list.

### The Head Pointer
The entire list is generally represented by a single pointer to a Node
object. This is the **head pointer**. Because each node is linked to
the next, it is possible to access any point in the list by beginning at
the head pointer and following the chain.
