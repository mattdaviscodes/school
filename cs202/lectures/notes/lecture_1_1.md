# CS 202 - Lecture[0][0]
Date: 2/1/17 | [Slides](../slides/CS202_Lecture4_[C++_Structs]_02.01.pdf)

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

### Nested Structures

### Arrays of Structs

### Struct Arrays in Structs

### Structs and Functions





