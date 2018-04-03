# CS 202 - Lecture 5.0 - C++ Classes - Inheritance (part 1)
Date: 2/27/1 | [Slides](../slides/CS202_Lecture11_[C++_Classes-Inheritance_(Pt.1)]_02.27.pdf)

[Prev](./lecture_4_1.md) | [Next](./lecture_5_1.md)

> NOTE: This is the lecture we were supposed to cover on 2/22. We spent
that session going over other things, so the previous lecture notes are
blank. This is intentional.

### Overview
- Class / Object Relationships
  - Inheritance
  - Composition
  - Aggregations
- Inheritance Concepts and Practice
- Class Hierarchies
- Handling Access

## Inheritance

### Code Reuse
Important to successful coding -- increases efficiency and decreases
opportunity for error. In addition to functions and classes, one
way to reuse as much code as possible is **inheritance**.

### Object Relationships
One object can *use* another object. `Car` refuels from `GasStation`.
This type of relationship is usually a function.

Objects can *have* (or incorporate) another object. `Car` incorporates
`Sensor`.

Finally, an object can be a *kind of* another object. `Car` is a
`Vehicle`. This is inheritance.

### Inheritance relationship
Inheritance relationships provide code reuse by **base classes**
sharing a related set of methods and data with their **derived
classes**.

Syntax example:
```cpp
class BaseClass {
    public:
        // operations
    private:
        // data
};

class DerivedClass : public BaseClass {
    public:
        // operations
    private:
        // data
};
```


### Inheritance Example

```cpp
class Vehicle {
    public:
        // functions
    private:
        // data
        int     m_numAxles;
        int     m_numWheels;
        int     m_maxSpeed;
        double  m_weight;
}

class Car : public Vehicle {
    public:
        // functions
    private:
        int     m_numSeats;
        double  m_MPG;
        string  m_color;
        string  m_fuelType;
}

class Bus : public Vehicle {
    // etc
}
class Plane : public Vehicle {
    // etc
}
class SpaceShuttle : public Vehicle {
    // etc
}
```

### Inheritance - Detailed
Abstraction is useful for sharing similarities while retaining
difference between base and derived classes. Also allows grouping
classes into related families -- improving readability and
understandability.

**Multiple inheritance** is possible, which allows a derived class to
inherit from more than one base class. NOTE: We will not use this in
CS-202, but good to see. Example:
```cpp
class Car : public Vehicle,     // Comma-separated list of bases
            public DMVRegistrable {

    // All the normal shit

}
```

Inherited classes use a **access specifier** -- public, private, and
protected. NOTE: Will use nothing but public for class.
- Public: Everything that is aware of Base(Parent) and Derived(Child)
is also aware that Derived Inherits from Base
- Protected: see slides -- very uncommon according to prof
- Private: see slides

### Class Hierarchies
Derived classes can themselves act as base clasess for further derived
classes. `SUV` can inherit from `Car` which itself inherits from
`Vehicle`. The deeper we go in this inheritance hierarchy, the more
specialized we expect the derived classes to be.

Here we see the use of the `protected` access specifier for the first
time. Anything in a base class marked `protected` is essentially
`private` to the outside world. However, any classes that inherit from
this base can access the `protected` data and methods directly. Anything
marked `private` in a base class is inaccessible to base classes.

```cpp
class Base {
    public:
        int m_public;

    protected:
        int m_protected;

    private:
        int m_private
}

class Derived : public Base {
    public:
        void tryToAccess();
}

void Derived::tryToAccess() {
    cout << m_public;       // legal
    cout << m_protected;    // legal
    cout << m_private;      // illegal
}

void main() {
    Base b;
    Derived d;

    cout << b.m_public;     // legal
    cout << b.m_protected;  // illegal
    cout << b.m_private;    // illegal

    cout << d.m_public;     // legal
    cout << d.m_protected;  // illegal
    cout << d.m_private;    // illegal
}
```

### Method Inheritance
Derived or child classes can **use**, **extend**, or **replace** the
parent class behaviors.

```cpp
class Vehicle {
    public:
        double getSpeed();
        bool refuel();
}

class Car : public Vehicle {
    public:
        double getSteeringWheelAngle();
        bool refuel();
}

int main() {
    Car c;
    Vehicle v;

    v.getSpeed();               // legal, obviously
    c.getSpeed();               // calls Vehicle.getSpeed() as-is

    v.getSteeringWheelAngle();  // illegal
    c.getSteeringWheelAngle();  // legal

    v.refuel();                 // legal, doesn't interact with Car.refuel
    c.refuel();                 // legal, doesn't interact with Vehicle.refuel
}
```

### Handling Access
A subclass can override the access specification of methods/data in
the parent class. See slides for example.

## Method Overriding

###

## Composition
Ex: A `Car` incorporates (has, owns, etc) a `Chassis`.

### Composition Relationship
In the example below, the car object inherits from vehicle and
incorporates chassis. If car is destroyed, so is chassis. `Car` class
has a **lifetime-responsibility** for its chassis -- the latter
cannot live without the former.
```cpp
class Chassis {
    public:
        // functions
    private:
        //data
        char m_material[MAT_LEN];
        double m_weight;
        double m_maxLoad;
}

class Car : public Vehicle {
    public:
        // functions
    private:
        // made-with (composition)
        Chassis m_chassis;
}
```


## Aggregations
Ex: A `Car` can use a `Driver`.

### Aggregation Relationship
In the example below, car may or may not be linked with driver. Much
like a SQL relationship. Driver is only **associated to** car, but can
exist without car, and the inverse is true also. This relationship
is specified in the class definition using pointers.

```cpp
class Driver : public Person {
    public:
        // functions
    data:
        // data
        Date m_licenseExpire;
        char m_licenseType[LIC_MAX];
}

class Car : public Vehicle {
    public:
        // functions
    private:
        // has-with (aggregation)
        Driver * m_driver;
}
```


