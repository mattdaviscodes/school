# CS 202 - Lecture 7.0 - C++ Classes - Midterm Recap
Date: 3/13/18 | [Slides](../CS202_Lecture15_[C++_Classes-Midterm_Recapitulation]_03.13.pdf)

[Prev](./lecture_6_1.md) | [Next](./lecture_7_1.md)

> CODING ON PAPER. Nitpicks not as important as proving knowledge of
subject matter.

## TO STUDY
* String manipulation functions - nail these
* Friend function insertion/extraction operator overload
    * Feel pretty shaky about the syntax here. Need work.
* Initialization lists
* Constructors
    * Default, paramaeterized, and copy. Feel pretty good about this
    but make sure to have the syntax solid.
    * Use default parameters in parameterized constructor **declaration**
        * Default parameters are not specified in constructor **definition**
* In-class operator overload -- assignment, addition, and bracket probably
    * What is difference between copy constructor and assignment operator?
    * In assignment overload, remember to check if both sides are the same
    object: `if (this != &rhs) { /* do the copy */ }`
    * Prof said assignment operator "very very important"
    * Bracket overload w/ different signatures -- by title or by index, for example
* Getters/setters -- when is a getter not appropriate/possible?
    * Has something to do with const data members - can only be set
    at declaration time. Again, touches init lists.
* Const correctness -- not as important, but should go over this
* Static class member and usage for id generation (in init lists)
* Aggregate classes - example Library contains array of Book objs
    * At instantiation of Library object, each Book in array **initialized with default constructor**
* Iterate over array via pointer manipulation
    * Fuck...
* File I/O -- go over file opening, checking for openness, iterating, and closing
* For end questions, understand how call-by-value/reference/address affect
program functionality
* If no access specifier, is everything private?
* Inheritance
* Polymorphism

### Implement Helper Functions
These will definitely be on test. Should write them, and use them in
the requested classes.
```cpp
const int STR_MAX = 255;

void strcpy(char* dst, const char* src) {
    while (*dst++ = *src++);
}

int srtlen(const char* str) {
    const char * s = str;
    for ( ; *s; ++s);
    return s - str;
}

int strcmp(const char* s1, const char* s2) {
    while (*s1 == *s2++) {
        if (!*s1++) {
            return 0;
        }
    }
    return *s1 - *--s2;
}
```

### Declare a Class and Implement Methods
Reuse as much code as possible. Setters should be used in constructors.

### Assignment operator overload
* Check for self assignment
* Returns reference to object type -- `Book&` for example
* Must return dereferenced self-pointer `return *this`

### Insertion operator overload
* Friend function, does not belong to class
    * Takes a class obj by reference
    * Function definition is not namespaced to the class
        ```cpp
            std::ostream& operator<<(...) {};       // yes
            std::ostream& Book::operator<<(...) {}; // no
        ```

