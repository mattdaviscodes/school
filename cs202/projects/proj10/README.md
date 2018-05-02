# Project 10
Submitted: 5/1/18

### Purpose
Practice implementing templated classes in C++ by creating two versions
of a Stack class -- one array-based, the other node-based. This project
presented a good opportunity to explore another common data structure --
having previously completed linked list and queue projects -- as well
as learn the ins and outs of templating.

I'm realizing that templated classes, which I thought were a more
obscure part of the language, are likely widely used. In personal
research I saw lots of references to `std::vector` which purported to
be a built-in data structure of indefinite length that can hold any
type of data. It has to be a template! `std::vector<int>` stores
ints and `std::vector<MyClass>` stores objects of type MyClass. Cool.

### Design Choices
Again, I prefer the node-based implementation of these two. It just
makes more sense to me. However, I did appreciate some of the smaller
efficiences of the array-based variant. The `clear()` method, for
instance, was much more simple as an array. Just set m_top to 0, no
need to free any memory or change what is stored in m_container.

Copying and assigning were surprisingly cumbersome for the node-based
variant. Since I wanted to leverage my `push()` method in
the copy and assignment methods, this means that I had to iterate over
the entire chain of nodes multiple times, each iteration stopping one
node earlier than that last. In large data sets, this could get really
expensive.

### Output Observations
Not many observations here. The code ran as expected. I had a bit of
trouble getting the ArrayStack default MAX_STACKSIZE to work -- I wasn't
sure where to put it. Once I got that working, the project went pretty
smoothly.

Templates are cool. I'm eager to see how they are used in professional
C++ code.