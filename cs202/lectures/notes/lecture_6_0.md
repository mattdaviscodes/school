# CS 202 - Lecture 6.0 - C++ Classes - Polymorphism (part 1)
Date: 3/6/18 | [Slides](../CS202_Lecture13_[C++_Classes-Polymorphism_(Pt.1)]_03.06.pdf)

[Prev](./lecture_5_1.md) | [Next](./lecture_6_1.md)

## Polymorphism
**Polymorphism** means "the ability to take many forms." Allows a single
behavior to take on many type-dependent forms. Grants an ability to
manipulate Objects in a type-independent way.


### Polymorphism and Inheritance
Pointers of a Base-Class Type are used to address common ancestors
from a class hierarchy.

```cpp
SUV suv1;
Car * = &suv1;  // Car type pointer pointing to SUV type
```

We must store an array of all available cars, which may be of varying
types, all of which descend from type Car. We cannot keep SUV and Jeep
objects in the same array -- C++ arrays may only hold one type of data.

If instead, we store an array of Car pointer objects, each of which may
point to any of its descendant types, we route around the problem
entirely. These pointers hold the memory address of their derived
class objects. It's then trivial to dereference these pointers to get
to the objects themselves.

### Polymorphism and Methods
Refers to the ability to associate many meanings to one function name,
by means of **late binding** (or dynamic binding). Implemented through
the use of the `virtual` keyword.

The `virtual` keyword indicates that something is not concretely
defined. It's a property that "should be there" -- we can use it before
it is fully defined. The specific implementation of a function only
needs to be looked up at runtime, instead of compile time.

> Is this how Python and other modern languages handle interpretation?

```cpp
/*
 * Parent class with no draw() method. What would that
 * method even do? We don't have enough information
 * to do what's needed without knowing the context
 * (i.e. the specific subclass)
 */
class GeometricFigure {
public:

    /*
     * Move figure to center of screen, erease, and redraw. Problem
     * becuase center() would have to call draw() -- which draw()
     * since we're implementing base-class behavior? Must call the
     * appropriate draw() function depending on which object type
     * is calling the function.
     */
    void center() {
        m_center.x = Screen.x;
        m_center.y = Screen.y;

        /*
         * Incomplete call to draw(). We don't have enough
         * information to corectly execute the behavior.
         */
        draw();
    }

    /*
     * Here, draw() just acts as a placeholder so the compiler
     * knows to wait until runtime to look up specifically which
     * child class's draw() method to call.
     */
    virtual void draw();

protected:
    Point m_center;
}

/*
 * Two subclasses of GeometricFigure, both define draw()
 * method. These two methods must do two very different
 * things.
 */
class Rectangle : public GeometricFigure {
public:
    void draw();

private:
    int m_height;
    int m_width;
}

class Circle : public GeometricFigure {
public:
    void draw();

private:
    int m_radius;
}

int main() {
    GeometricFigure g;
    Rectangle r;
    Circle c;

    r.center();     // Uses Rectangle::draw()
    c.center();     // Uses Circle::draw()

    /*
     * This call uses the
     */
    g.center();

    return 0;
}
```

Many of the problems above could be solved by moving the `center()`
function to the child classes, but this violates the code-reuse
expectation. It is also difficult to extend -- if we define a *new*
class `Triangle` which subclasses `GeometricFigure`, then we again have
to define yet another `center()` method.

We could also have added a `draw()` function to the parent class, which
the subclasses would then extend. This is a better solution than moving
`center()` to the children, but it's still imperfect. Each child would
have to first call the parent class's `draw()` function and then perform
the class-specific functionality.