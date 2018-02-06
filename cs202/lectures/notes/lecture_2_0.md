# CS 202 - Lecture[2][0] - Intro to C++ Classes
Date: 2/6/17 | [Slides](../slides/CS202_Lecture5_[C++_Classes_(Introduction)]_02.06.pdf)

### Abstraction
Information hiding. Separates code use from code implementation. In
*procedural* programming, data is abstracted into structures and control
is abstracted into functions. In *object-oriented* programming, data
and control are both placed in **Classes**.

### Object Oriented Programming
- **Information hiding**: Details of how operations work are not known
to user of Class.
- **Data abstraction**: Details of how attributes are manipulated within
a class are not known to user.
- **Encapsulation**: Bring together data and operations, but keep
details hidden.

## Classes
A group of objects with similar properties, common behavior, common
relationships with other objects, and common semantics. We use classes
for abstraction purposes.

### Blueprints
Classes are blueprints for creating objects. We call object creation
**instantiation**. The blueprint defines the class's state and
attributes as **class member variables** and the class's behaviors as
**class methods**.

### Objects
An **object** is a variable of a certain class type -- an instance of
the class Car is a Car object. We can create as many instances of a
class as needed, just like we can with ints and floats, etc. The
challenge then becomes how to define class and objects that satisfy
the problem we're trying to solve.

### Class Interface
The data and functionality provided to the user by a class. The requests
you can make of an Object are determined by its interface. It's a
simplified method by which the user can create and use an object of a
class. For example, most people don't need to know how to build a car.
They only need to know how to purchase one from a dealership. The
dealership is the interface, in this case.

Interfaces are everywhere. There is massive value in removing complexity
from people's lives. Nearly every product serves as an interface to some
more complex process. *Good* prodcucts -- like good classes -- create
simple, understandable, and stable interfaces to otherwise complex
systems.

### Class Implementation
This is the actual code of the class. It's the inner workings and the
hidden data of a class. Every request made of an Object must have an
associated **method** (i.e. function) that will be called.

### Class Declaration
```cpp
class Car
{
    public:     // Protection mechanism
        bool AddGas(float gallons); // <-
        float GetMileage();         // <- Class's operations
        // other operations         // <-

    private:    // Protection mechanism
        float m_currGallons;    // <-
        float m_currMileage;    // <- Class's data
        // other data           // <-
}
```

### Class Conventions

### Encapsulation

### Class Components

### Examples