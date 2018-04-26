# Project 9
Submitted: 4/25/18

### Purpose
Practice two variations of the queue data structure. A queue functions
much like a linked list -- it has a front and back, is generally only
traversed in one direction, and can be a holding place for many other
types of data. The main difference between the two is that a queue
operates under stricter logical confines than a regular linked list. A
queue only allows data to be added to the back of the list, and only
removed (and thus acted upon) from the front of the list. It functions
like a line at a store.

### Design Choices
We implemented the same functionality twice, once via a node-based
method, then array-based.

As with the last project, I prefer the node-based implementation. Although
the developer incurs the burden of managing dynamic memory, they are not
restricted by and upper limit to the number of data points that can
be stored. (At least not by the program.) Futher, memory allocation can
be frustrating, but usually only at two points in a program: construction
and destruction. Everything else works fairly logically. In contrast,
an array-based implementation which allows a rolling index can cause
a lot of unnecessary problems. It's easy to get mixed up by indexing
incorrectly into the stored data if the front, back, and size are not
properly tracked.

### Output Observations
After the last project, there weren't many surprises here. The queue
functions very similarly to the more-generic linked list structures we
built in project 8.

The constraints placed on accessing the data actually simplified things
a bit. Instead of having to deal with some branching code to handle
insertion into the middle of the list, pushing became very easy. Just
always add new stuff to the back, and update any necessary tracking
data accordingly. Popping data was similarly simplified -- take from
the front, update the trackers. This simplification was probably most
noticeable in the constructors, where nearly all work was offloaded
to the push function. If push is implemented correctly, it handles
the two possible cases (empty list and non-empty list) as well as any
other functionality like memory allocation. All the constructors have
to do is iterate and call push as many times as necessary.