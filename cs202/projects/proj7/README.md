# Project 6
Submitted: 3/17/18

### Purpose
For this project, we are given a complete primary source file
[proj6.cpp](proj6.cpp) which will act as a test driver for the project.
The source file contains a number of references to unimplemented
`Vehicle` and `Car` classes. These classes exhibit common inheritance
and polymorphic functionality, which is explored throughout the
project.

### Output Observations
Once the two required classes have been implemented, we are required
to run the test driver and observe the output.

#### Constructor Observations
- The Vehicle (parent) constructor is called before the Car (child)
constructor. This is as expected. Both use the default constructor,
even though no explicit call to `Vehicle::Vehicle()` is ever made.
- The parameterized constructors are called in the same order: parent
then child. However, this time we used an explicit call to the parent
class.
- The `Car`'s copy constructor calls Vehicle's base constructor. This is
surprising to me, although I don't know how else it could work.
- `Car`'s assignment operator never calls Vehicle's assignment operator.
Again, this is logical, but not what I expected. The assignment often
*feels* like another constructor, but it is not. This object had already
been constructed, and now is just being altered by the assignment.

#### Polymorphism Observations
- Calling `Car::move()` does not call `Vehicle::move()` as expected
- Calling `Vehicle`'s insertion operator overload does not interact
with `Car` at all. This makes sense -- we didn't write any insertion
operator code for `Car`.
- Calling `move()` via a `Vehicle` pointer acts as expected - `Car::move()`
is called and `Vehicle::move()` is not. This is because we specified that
all children of `Vehicle` *must* override `move()`.
- Calling the insertion operator overload on a `Vehicle` class pointer
does not interact with `Car`. By itself, this seems obvious, but next
to the `move()` call it is interesting. Beacuse `move()` is defined as
`virtual` and the insertion operator overload is not, it seems like
we might run some `Car` code. This is not the case.

#### Destructor Obvservations
- The only objects ever created were of type `Car`. When these objects
are destroyed, they first destroy themselves -- the derived class --
then call the destructors of the parent class. It's interesting that
construction flows downward, but destruction flows upward.