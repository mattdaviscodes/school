# CS 302 - Project 3
Date: 10/15/18 | Author: Matt Davis | [Assignment](./cs302-hw3.pdf)

### Exercise 1
The ADT SL_PriorityQueue should provide the following functionality:

1. Check if queue is empty
2. Add item to queue
3. Remove an item from the queue
4. Peek at the front of the queue

[UML - SL_PriorityQueue](./SL_PriorityQueue_uml.png)


### Exercise 2
Not included.

### Exercise 3
In the example given, using a priority queue makes sense because it is
guaranteed that each collision is recorded only once and in the order
of occurrence. We could then process these events however necessary. If
we instead used a non-priority queue, it is possible that some collision
B might be registered before another collision A (when the true order
was A, then B) meaning that the rebounds caused by collision B preceeded
those caused by A. This would have a cascading effect, invalidating the
entire simulation. Further, by using an unordered queue, we would be
required to track all balls at all times, moving very slowly through
time in order to keep close track of collisions. This would look
something like:

- Advance time
- For each ball, check for collision with any other ball. Assuming
standard 15 ball game, this is 105 checks per click
- Record any collisions


