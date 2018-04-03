# CS 202 - Lecture[2][1] - C++ Classes - Constructors (part 1)
Date: 2/8/18 | [Slides](../slides/CS202_Lecture6_[C++_Classes-Constructors_(Pt.1)]_02.08.pdf)

### Class Cheatsheet
See slides for in-depth extended example of class declaration and
implementation. Some highlights:

We've already seen `public` and `private` access specifiers. `private`
is the third specifier that may be used. Skimmed over the actual use
case, but it has something to do with inheritance. I think I read that
it's the same a public, but methods and data are accessible to all
instances of that class *and all instances of child classes*.

Marking data and methods as `const` removes complexity. It's best to do
this whenever possible.

## Constructors
Constructors are special methods that "build" objects. They initialize
the object's member data.

Importantly, constructs are methods **with no return type**. This is
different than having a void return type. Also, constructor methods
must always have the same name as the class type they construct.

### Default Constructor
If no constructor method, a default constructor is defined by the
compiler. The default constructor is called when declaring an object of
a class without calling a constructor method.

```cpp
class Date {
    ...
}

int main() {
    Date d1;                // default constructor
    Date d2(11,21,1989);    // calls user-defined constructor
}
```

The default constructor will leave all data uninitialized. **Beware**.

Users may override the default constructor by defining a constructor
method which takes no arguments.

```cpp
class Date {
    int m_month;
    Date();
}
Date::Date() {
    m_month = 7;
}

int main() {
    Date d1;    // Calls defined default constructor. d1.m_month == 7
}
```

### Parameterized Constructor
Also possible to define constructor that accepts arguments, which
allows user to initialize object members with runtime variability.
```cpp
class Date {
    Date(int month);
}
Date::Date(int month) {
    m_month = month;
}

int main() {
    Date d1(5); // Calls parameterized constructor. d1.m_month == 5
}
```

Furthermore, it is possible to **overload** the constructor, allowing
many different methods by which a user may create an object. In the
examples above, the user may want to create a Date object and knows
the month and year, but not the day. Maybe just the year. All of these
scenarios may be handled by overloaded parameterized constructors.
