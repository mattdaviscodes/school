# CS 302 - Lecture 6 - Lists
Date: 9/17/18

[Prev](./lecture_5.md) | [Next](./lecture_7.md)

### The ADT List
- Stores items of the same type
- Operations
    - Count items
    - Add, remove items
    - Retrieve
- Different than stacks or queues because items can be added or removed
anywhere in the list, not only at beginning or end

> Is this how Python `list` is implemented?

Strange slide showing `throw` function in a function's signature. Like
this:

```c++
Class<type>::func() const throw(ExceptType) {
    // function stuff
    // throws ExceptType if necessary
}
```

Prof claims this is best practice. Never seen it before. This [SO post](https://stackoverflow.com/questions/1055387/throw-keyword-in-functions-signature)
says it's not a good idea. Hmm...

