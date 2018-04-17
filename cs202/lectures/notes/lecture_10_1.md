# CS 202 - Lecture 10.1 - Dynamic Data Structures (part 3)
Date: 4/12/18 | [Slides](../CS202_Lecture21_[Dynamic_Data_Structures_(Pt.3)]_04.12.pdf)

[Prev](./lecture_10_0.md) | [Next](./lecture_11_0.md)

### Linked List Operations
A singly-linked list uses a control loop to iterate over. This is called
**traversal**.

```cpp
for (Node* curr = list.m_head; curr != NULL; curr->m_next) {
    // Do stuff to each node
}
```

Insertion into a linked list depends on the developer carefully tracking
each node. To insert into position `k`, the next pointer of the node
in position `k-1` must be rerouted from the existing node at `k` and
pointed to the inserted node. Then the inserted node must point to the
old node at `k` making it now `k+1`. Special care needs to be taken
when inserting at the beginning or end of the list.

Deletion is simple. To delete node at position `k`, point the next
pointer of `k-1` to `k+1`, routing around `k` entirely. Then `k`
must be deleted from memory.

## Array-Based Linked Lists

### Elements
An item of the array-based linked list is