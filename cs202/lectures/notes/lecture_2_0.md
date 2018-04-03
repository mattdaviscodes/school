# CS 202 - Lecture[2][0] - Intro to C++ Classes
Date: 2/6/18 | [Slides](../slides/CS202_Lecture5_[C++_Classes_(Introduction)]_02.06.pdf)

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
Standards for coding with classes. IDEs can sometimes save time with
smart features - real-time search for declaration, auto-completion, etc.

Class names always begin with a capital letter and follow camel case.
Best to use descriptive names for classes: Car, Dog, Student.

Class data (member variables) always begin with `m_`, which stands for
"member". Example: `float m_mileage`. Class methods should begin with
capital letters. Example: `AddGas()`.

### Encapsulation
Encapsulation is a main principle of object-oriented design. It's a form
of information hiding and abstraction. Data and functions that act
on that data are located *in the same place*. They are **encapsulated**
within the class. The goal of this is to separate the interface from
the implementation, so someone can use the code without any knowledge
of how it works.

NOTE: Data is almost always stored in the private scope of a class. It
is intentionally hidden. It is usually exposed through methods, which
means that the developer can control what a user can and cannot see.

### Class Components
- **Member variables**: What data must be stored?
- **Methods**: How does the user need to interact with stored data?
- **Constructor(s)**: How do you build an instance?
- **Destructor**: How do you clean up after an instance is destroyed?

### Examples
Class methods declaration and implementation:
```cpp
// Represents a day of the year
class DayOfYear             // Class declaration
{
    public:
        void output();
        int m_month;
        int m_day;
};

// Output method - displays a DayOfYear
void DayOfYear::output()    // Method implementation out of declaration
{
    cout << m_month << "/" << m_day;
}
```

In the example above, usually the class would live in its own file(s).
The declaration goes in **header files** -- `DayOfYear.h`. The class
definition goes in a **source file** -- `DayOfYear.cpp`.

Classes are instantiated by using a constructor. The class's *default*
constructor works exactly the same as creating an object of any other
class.

```cpp
int main()
{
    DayOfYear july4th;

    july4th.m_month = 7;
    july4th.m_day = 4;
}
```

Can also create pointers to class variables.
```cpp
int main()
{
    DayOfYear* july4th_Pt;

    july4th_Pt->m_month =7; // Note use of arrow operator
    july4th_Pt->m_day = 4;
}
```

If we have an object of a class, use **dot operator** to access members.
If we have a *pointer* to an object of a class, use the **arrow operator**
to access members. The arrow operator is just a combination of the
dereference operator and dot operator.

```cpp
    DayofYear * july4th_Pt;

    // These are equal
    july4th_Pt->m_month;
    *july4th_Pt.m_month;
```

### A Class's Place
A class is a fully-fledged data type, just like `int` and `double`.
Therefore, we can have function parameters of a class type. These
support all the standard passing rules: pass by value, reference, and
pointer.

### Coupling
Refers to how much components depend on each other's implementation
details -- how much work is it to remove one component and replace it
with another? Example: placing a new battery in a car vs placing a new
engine in a car. Object-oriented design seeks to reduce coupling as much
as possible.

### Protection Mechanisms
The keyword `const` my be appended to member functions in order to
"promise" the the function won't change member data.

```cpp
class DayOfYear
{
    public:
        void printDay() const;  // printDay() will not alter data
        void shiftNextDay();    // shiftNextDay() MIGHT alter data
}
```