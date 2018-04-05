# CS 202 - Lecture 9.0 - Classes and Dynamic Memory
Date: 4/3/18 | [Slides](../CS202_Lecture18_[C++_Classes_and_Dynamic_Memory]_04.03.pdf)

[Prev](./lecture_8_1.md) | [Next](./lecture_9_1.md)

## Classes and Dynamic Memory
Classes can wrap dynamic memory management, creating a simplified
interface. The developer should not be responsible for allocation and
deallocation of the memory for objects of these classes.

### Dynamically Allocated Class Members
Until now, constructors were mainly responsible for member
initialization. Destructors were even less useful -- the most we've done
with them were `cout` statements so we could see when the destructors
were called. The storage for all members has been allocated and
deallocated automatically for us. Once storage is dynamic, this changes,
and the constructors and destructors bear much of this burden.

Constructors with dynamic memory perform initial allocation of member
memory. We store a raw pointer as a member to retain the address
of the dynamically allocated memory. *This is a local variable like
all others, and will go away at destruction.* It must beused in our
destrocturs to deallocate any allocated memory before final cleanup.

```cpp
Car::Car(const Chassis & chass, const double * engT, int numVlv) {
    m_chassis = car.m_chassis;
}
```