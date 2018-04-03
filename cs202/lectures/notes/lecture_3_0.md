# CS 202 - Lecture[3][0] - C++ Classes - Constructors (part 2)
Date: 2/13/18 | [Slides](../slides/CS202_Lecture7_[C++_Classes-Constructors_(Pt.2)]_02.13.pdf)

## Constructors contd

### The Copy Constructor
Responsible for creating a new object from an existing object.
```cpp
Date(const Date &);

Date::Date(const Date & other_date) {
    // Since this method is a constructor, it has direct access to the
    // instantiated object's internal data. It also has direct access
    // to the Date object passed in. As such, copying is easy.
    m_month = other_date.m_month;
    m_day = other_date.m_day;
    m_year = other_date.m_year;
}
```

The compiler will implicitly provide a copy constructor if
none is specified. Must be careful, though. Most data members will be
handled appropriately by default copy constructor -- floats, ints, etc
will all be copied to new object. Pointers will also be copied
over, but this can trip us up, because it means we now have two discreet
objects, with their own sets of data (although that data is identical at
the time of copy) that point to *one single external memory address*.
Therefore, if we copy Car1 to Car2, then change the char * string at
Car2->name, Car1->name *will also be changed*. Must be careful. This is
called a **shallow copy**.

To get around this, we must explicitly implement a **deep copy**
constructor.

```cpp
Car::Car(const Car & other_car) {
    name = (char*)malloc(NAME_LEN); // Allocation for new pointer
    strcpy(name, other_car.name);   // Copies values pointed by other_car.name to new car's name
    // More copy construct stuff...
}
```

> I read about this. Something about the rule-of-three, I think. It said
if you find that you need a copy constructor, than you most likely need
these other two kinds. Can't remember what they were, though.

### Initialization Lists
**Initialization lists** are another way to define a constructor. Can
be used to initialize data members of instantiated object *before we
enter the body of constructor method*.

```cpp
Date::Date(int month, int day, int year) :
    m_month(month),
    m_day(day),
    m_year(year)
{
    // Overloaded constructor statements
}
```

One important benefit of this is that we can instantiate an object with
constant data members. In the old method of object construction, an int
member variable is first constructed and empty -- `int i;` -- then a
passed-in value is assigned to that int `i = 3;`. This counts as an
alteration of the int, so it cannot be const. Using an initialization
list allows us to pass the value directly to the int at instantiation
time, which allows us to make it const -- `const int i = 3;`.

```cpp
Date::Date(int const_thing) :
    m_const_thing(const_thing)      // This works
{
    m_const_thing = const_thing;    // Assignment to const fails
}
```

## Destructors
Called when a class goes out-of-scope or is freed from the heap by
`delete`. Not necessary in simple classes, but have to take care of
cleaning up resources that won't automatically go away.

We won't be using these immediately, according to Christos.

Has the method name `~ClassName()`, and has no return type. Can have one
or none in Class, not multiple.

Destructor will automatically be called as objects go out of scope. Will
also call the destructors of any data member objects. However, will not
follow member pointers to destruct pointed-to objects.

## Static Members
The `static` denotes a piece of data that will only be allocated once
per program run and will persists until the program exits.

### Static Variables
Local scope, but persist in memory.

```cpp
int nonStaicLocal() {
    int a = 0;          // Destroyed when function returns
}

int staticLocal() {
    static int a = 0;   // Persists across function calls
}
```

> This would be good for creating function counters. If we need to track
how many times a certain function is called, we could create a static
int in that function and increment it each time the function runs. Could
also use this method to give all objects of the same class unique IDs.

### Static and Classes
All class objects share the same (one and only copy of) data. If one
object modifies it, all objects will see the change. *Not bound to a
specific object, but mark a state of the class itself.*

Useful for the reasons I listed above. :-)

---BEGIN 2/15 LECTURE---

When used in a class, static variables belong to the class, not any one
object.

```cpp
class MyClass {
    public:
        int m_i;
        static int s_i;
}

MyClass mc;

mc.m_i;         // legal
MyClass.m_i;    // compiler error
MyClass.s_i;    // legal
mc.s_i;         // legal, I think
```

In order to track counts of active objects using static class members,
it's important to include the proper logic in constructors and
destructors. To keep a count of the total objects created, all
constructors for that class must incremement the static variable.
Careful! This includes copy constructors. In order to track the count
of *active* objects of the class, we must decrement the counter in the
class destructor.

### Static Methods
Static methods are just like regular functions, except they are housed
inside the class's namespace. Like regular functions, they *cannot*
access class members

### Static Member Definition
Regular class memebers are allocated at object instantiation. Static
members don't belong to a single object, though. They are not allocated
by default. In a class, only *declaring* a static variable value is not
enough. We must *define* it also.

```cpp
// Car.h
class Car {
    private:
        static int s _carFactoryCnt;    // Not enough alone
}

// Car.cpp
int Car::s_carFactoryCnt = 0;           // This line required to initialize value
```