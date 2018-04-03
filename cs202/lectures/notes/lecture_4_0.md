# CS 202 - Lecture 4.1 - C++ Classes - Operators (part 2)
Date: 2/20/18 | [Slides](../slides/CS202_Lecture9_[C++_Classes-Operator(s)_(Pt.2)]_02.20.pdf)

[Prev](./lecture_3_1.md) | [Next](./lecture_4_1.md)

## Operator Overloading (contd)

### Return by-Reference - Cascading
It is very common to overload the insertion `<<` operator to allow
class data to be easily represented in text.

This is possible through a practice called **cascading**. A method which
returns a reference an argument that it received my reference -- it
returns the exact same thing it received. This is particularly useful
when writing out an output stream.

```cpp
ostream& operator<<(ostream& os, const Money& mn) {
    os << "$" << mn.m_dollars << "." << mn_m_cents;
    return os;
}

Money myMoney(99, 25);

// This is the same as...
cout << "My Money: " << myMoney << endl;

// ... this.
operator <<(operator<<(operator<<(cout, "My Money: "), myMoney), endl);
```

This can also be used for the extraction `>>` operator in order to write
to a custom object. In this case, the operator overload method must be
declared as a **friend function** in order to have direct access to the
custom object's methods and data.

### Overloading Pre-Increment Operator
Takes no arguments, making it a unary operator.

```cpp
Money Money::operator++() {
    m_cents++;
    if (m_cents == 100) {
        m_cents = 0;
        m_dollars++;
    }
    return Money(m_dollars, m_cents);
}
```

Note: this *modifies* the calling object and *returns a copy*. Seemed
strange to me at first, but it's consistent with the behavior of the
operator on built-in types.

The above code can be rewritten more concisely using the `this` keyword.

```cpp
Money Money::operator++() {
    m_cents++;
    if (m_cents == 100) {
        m_cents = 0;
        m_dollars++;
    }
    return *this;
}
```

In the second code block, `this` is dereferenced, giving us direct
access to the calling object, which we then return as a reference. The
first block, however, returns a copy of the original object, not a
reference to the object itself. In the latter example, this means
we can chain calls to the operator with the logical results, because
we're only ever dealing with the one object.

### Overloading Post-Increment Operator
Looks almost identical to pre-increment overload, except function takes
in a dummy int value. This is just a hack in the language and serves
no purpose other than telling the compiler which function is which.

```ccc
Money Money::operator++(int dummy) {
    Money moneyCopy(m_dollars, m_cents);
    m_cents++;
    if (m_cents == 100) {
            m_cents = 0;
            m_dollars++;
    }
    return moneyCopy;
}
```

First, we make a copy of the *original state* of the obj to be post-
incremented. Then we perform the increment, changing the objects values.
Finally, we *return the copy* of the object, which contains the object's
state before the increment. Looks funny, again, but it matches the
standard behavior.

As shown with the pre-increment operator, the code above can be
rewritten using the `this` keyword, which is not better or worse, just
different.


## Class Friends

### Friend Functions
Class friends can directly access private Class data. These are not
member functions -- they exist externally to the class itself. This is
an explicit exception to the normal data-hiding rules.

```cpp
class MyClass {
    friend int f(MyClass &);

    private:
    int m_data;
}

inf f(MyClass & mc) {
    return mc.m_data;   // Legal
}
```

### Friend Classes
Can also declare entire classes that are friends. These classes have
complete access to their own data as well as complete access to the data
of the class to which they are friends. This data is available directly
and via the friend class's methods.

Note: This is not a reciprocated relationship. The data sharing is
one-way.

## This

### Keyword `this`
`this` represents a pointer to the calling object. Inside a class member
function, we can address the calling object and its members by name.
The "name" we use, is `this`. Provides a way to address the entire
calling object inside a member function call.

```cpp
Money& Money::thisFunction() {
    this -> m_dollars = 1000;   // access data
    this -> setC(99);           // call a method
    return *this;
}
```

