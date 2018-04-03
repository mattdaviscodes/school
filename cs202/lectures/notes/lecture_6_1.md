# CS 202 - Lecture 6.1 - C++ Classes - Polymorphism (part 2)
Date: 3/8/18 | [Slides](../CS202_Lecture14_[C++_Classes-Polymorphism_(Pt.2)]_03.08.pdf)

[Prev](./lecture_6_0.md) | [Next](./lecture_7_0.md)


## Polymorphism cont'd
**Polymorphism** means "the ability to take many forms." Allows a single
behavior to take on many type-dependent forms. Grants an ability to
manipulate Objects in a type-independent way.

### `virtual` Functions and Covariant `return` Types
Overriding `virutal` class functions does not allow changing the
`return` type. Any call to a base class method should be directly
replaceable by a call to a derived class method with no change to the
calling code. Implicit casting is not allowed.

```cpp
class B {
    int f();
    virtual int f2();
}

class D : public B {
    double f();
    virtual double f2();
}

int main() {
    B * b_pt;
    D * d_pt;

    double d = d_pt->f();   // perfectly normal, d.f returns double
    doubla b = b_pt->f();   // legal, implicit conversion from int to double

    double d2 = d_pt->f2(); // legal still
    double b2 = b_pt->f2(); // illegal, compiler can't know what will be returned
}
```

One exception to this rule is **covariant** return types. I have no
fucking clue what this means, because the professor won't slow the fuck
down.

## Abstract Classes
A type that cannot be instantiated directly, whereas a **concrete** type
may be.

Example: Vehicle is an abstract concept, we don't have enough information
to create one direclty. But a Car is much more concrete that carries
enough context to create one.

### `virtual` Functions and Classes
