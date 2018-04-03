# CS 202 - Lecture[0][0]
Date: 1/23/18

## Projects
Project due every week. Projects are assigned on Thursdays. Due date is
Wednesday, the week after the project was assigned.

## C++ Basic Info
Created in 1979, Bell Labs, Bjarne Stroustrup. Same place UNIX and C created.
Added object oriented features to C. Later standardized with several ISO specs.
Greatly influced Java development.

## Procedural vs Object-Oriented
PROCEDURAL: Functions are linked together hierarchically. focused on the
question "what should the program do next?" Large amount of data/tasks makes
projects difficult to maintain.

Object-Oriented: Objects are most important unit. Programs are structured as a
graph. Data and operations are bound to each other. Object is a self-defined
entitiy within a program, not just representing a set of functionality, but a
unified pack of data *and* functionality. Entire program is a sequence of
interactions between objects.

> Christos is pretty emphatic that OO is better than procedural. There's
probably more to this argument.

> Is procedural programming also called functional programming?

## Classes
C++ classes are very similar to C structs. Basic idea is to encapsulate related
data and functionality within a discreet unit. Made up of a type, attributes
(data), and operations (functionality). Common uses for classes are to
represent an object in the physical world -- Person, Airplane, Book, etc. Can
also be used to encapsulate representations of data -- String, ComplexNumber,
etc.

Classes are the blueprints for **objects**, which are instances of a class.

## Objects
If we have one Class BankAccount, we may have multiple different instances of
the class, called BankAccount objects. Example: AccountA, AccountB, and
AccountC are all BankAccount objects and share much of the same functionality,
but likely differ in their underlying data -- name, balance, and interest rate.

## Interpreters, Compilers, and Hybrids
Interpreted languages such as Javascript and Ruby translate source code into
binary and executes it. Good for small, easy to write programs. The interpreter
is a program unique to each platform.

Compiled languages such as C and C++ rely on platform-dependent compilers,
which digest source code and outputs binary machine code, which may be executed
independently of the source code.

Some languages such as Java and Python are even stranger, turning source code
into bytecode... missed the rest of his sentence.

## C++ Syntax (vs Python)
```cpp
#include <iostream> using namespace std;

int main() {
    int quotient;
    cout << "hello, world" <, endl;
    quotient = 3/4;
    if (quotient == 0) {
        cout << "3/4 == 0" ;
    } else {
        cout << "3/4 != 0" ;
    }
    return 0;
}
```
