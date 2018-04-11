# CS 202 - Lecture 9.1 - Dynamic Data Structures (part 1)
Date: 4/5/18 | [Slides](../CS202_Lecture19_[Dynamic_Data_Structures_(Pt.1)]_04.05.pdf)

[Prev](./lecture_9_0.md) | [Next](./lecture_10_0.md)

## Classes and Dynamic Memory (contd)
Classes can wrap dynamic memory management. A class which contains
a call to `new` (allocates memory on the heap) for one of its members
is split between auto- and dynamic-storage duration. This is what
we did in proj7. The `MyString` class contained a dynamically-allocated
char array. The `MyString` objects created were all local, on the stack.
Each object's array, however, was dynamic, and existed on the heap. This
meant we needed to take special care during construction and destruction
to properly allocate and deallocate the necessary memory.

It's *also* possible to dynamically allocate storage for an entire
object, as below:

```cpp
MyString * mystr = new MyString("This object is on the heap");
```

In this case, all data members contained within the class are allocated
on the heap, even if "normally" they'd have been on the stack with
auto-storage duration.

NOTE: In the example above, the entire `MyString` object exists on the
heap, but the pointer to that object is on the stack. This is required,
as we need some way to interact with the dynamic memory locally. This
is done through the pointer:

```cpp
MyString * mystr = new MyString("This object is on the heap");
delete mystr;
```

The call to delete above deallocates all the memory which is
automatically handled by the compiler. If that class contains any
custom memory handling (which the `MyClass` class does) then that
class's destructor is responsible for cleaning itself up.

---
>Holy shit, long lecture. Moving on to the *actual* lecture now.
---

## Dynamic Data Structures
Dynamic data structures are classes which "wrap" a data structure. They
don't really represent a logical object. They just provide a cohesive
structure for handling dynamically managed data. For example, we could
create a custom array class which can dynamically grow and shrink as
needed. This is of very little use on its own, but might be very useful
when used in another program. It could be a complete replacement for
standard arrays.

Node-based data structures, such as *Linked Lists* are a common way
of handling these problems.

## Linked Lists

### Dynamic Data Structure Paradigm
A container of elements represented as nodes. Each node contains data
as well as the address of the next node in the linked list. The linked
list also has a head node (the beginning) and sometimes a tail node.

> Christos says we won't use tail pointers in any of CS 202.

One of the benefits of linked lists is that each node is stored
independently. Unlike arrays, the full list need not be stored
contiguously in memory. Much easier to store large objects. The
downside of this that lookup can take much longer. In a contiguous
array, one lookup with an offset has to happen to find an element i.
In a linked list, this operation takes lookups equal to i, because
each is a jump to another location in memory.