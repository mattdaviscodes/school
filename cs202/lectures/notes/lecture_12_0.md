# CS 202 - Lecture 12.0 - C++ Templates (part 1)
Date: 4/24/18 | [Slides](../CS202_Lecture22_[Templates_(Pt.1)]_04.19.pdf)

[Prev](./lecture_11_1.md) | [Next](./lecture_12_1.md)

## Abstraction
Information hiding (via classes/structs) and conceptual types are
the two types of abstraction we've used so far. Templates present
a third type.

Take the following example.

```cpp
void Swap(int & v1, int & v2) {
    // Swap integer values
}
```

This code takes two integer references and swaps them. It's strongly
bound to the Integer data type. Passing this function floats will
cause a program failure. If we want to use this function on floats,
we need to write an overload of the function above which takes floats
instead of ints. This burden grows depending on how many types we wish
the function to take.

Enter templates.

Templates enable the developer to write functions and classes that use
generic inputs and types. Using a template, `Swap` only needs to be
written once.

