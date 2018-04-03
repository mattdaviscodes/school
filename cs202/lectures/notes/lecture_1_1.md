# CS 202 - Lecture[0][0]
Date: 2/1/18 | [Slides](../slides/CS202_Lecture4_[C++_Structs]_02.01.pdf)

## Structs
A collection of related data items. Different types allowed. Structs
are *heterogeneous* -- can be composed of different types of data --
whereas an array is homogeneous, and must only contain one data type.

> How the *hell* are python lists stored? Never thought of this before.
It's so easy in python...

Structs are used to hold data that *belongs together*. Generally
represent a logical object.

### Members
Also called fields. Individual components of a struct. They are the
data contained by a struct.

### Type Declaration
```
struct <struct-type> {
    <type> <identifier_list>;
    <type> <identifier_list>;
    ...
};
```

```cpp
struct StudentInfo {
    int id;
    int age[5];
    char gender;
    double gpa;
    // Can also hold members which are themselves structs
};
```

### Variable Declaration
Works the same as any other declaration -- data type is the name of
the struct and a variable name is given also.
```cpp
StudentInfo Student1, Student2;
```

Both of the above a variables of type `StudentInfo`.

### Member Access
The dot operator is used to access struct members. Example

```cpp
Student1.name;
Student1.age[1];
```

### Initialization
Heavily depends on struct type definition and severely comprises
maintainability. Depends on order of member definition. Might work,
but is dangerous, and is best to be avoided.

```cpp
StudentRecord Student1 = {"John Doe", 123, "CSE", 'M'};
```

### Assignment
The values contained in one struct type variable can be assigned to
another variable of the same struct type.

```cpp
StudentRecord Student2 = Student1;  // Assign existing student to new one
```

### Nested Structures
A struct type can be a member of another struct.

```cpp
struct Point {
    double x, y;
};
point P;

struct Line {
    Point p1, p2;   // Heck yeah
};
Line L;
```

It is illegal to nest a structure of some type within a
structure of the *same type*. **However**, legal to store pointer to
struct of same type.

```cpp
struct Test {
    Test t1;    // Illegal
    Test* t2;   // Legal
};
```

In the case of `t1` the compiler does not yet know how much memory to
allocate for a Test object, so it fails.

### Arrays of Structs
As stated, arrays are homogeneous, but because a struct definition
creates a new custom data type, we may create an array made up of many
instances of a struct.

```cpp
struct Point {
    double x, y;
};

Point point_array[100]; // Array of 100 Point variables
```

Also legal to store an array of structs as a member of another struct.

```cpp
struct Square {
    Point p[4];
};
Square s;   // Each Square object will contain a 4-element Point array
```

### Structs and Functions
Structs are valid function parameters and support all the call methods --
by value, by reference, by pointer.

```cpp
double points_distance(Point p1, Point p2) {
    return sqrt((p1.x-p2.x) * (p1.x - p2.x) + (p1.y-p2.y) * (p1.y-p2.y);
}

Point p1, p2;
double p12_distance = points_distance(p1, p2);
```




