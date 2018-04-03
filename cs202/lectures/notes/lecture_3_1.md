# CS 202 - Lecture[3][1] - C++ Classes - Operators (part 1)
Date: 2/15/18 | [Slides](../slides/CS202_Lecture8_[C++_Classes-Operator(s)_(Pt.1)]_02.15.pdf)

[Prev](./lecture_3_0.md) | [Next](./lecture_4_0.md)

## Operators
C++ attempts to be very expressive with the fewest possible lines.
Operators -- +, -, =, ==, etc -- in reality just represent functions.
They are simply "called" with different syntax.

```cpp
x + 7;
```

`+` is a binary operator with `x` and `7` as its operands. It's written
this way because it is more logical to developers. However, this is
what's really happening

```cpp
+(x, y);
```

### Operators and Custom Types
It's very useful for these operators to work logically with user-defined
types. But the default behavior of these operators doesn't always work.

```cpp
myMoney = myMoney + salaryMoney;    // This makes sense
someDate = startDate + endDate;     // This doesn't
```

Further, because the representation of class member data isn't always
obvious -- money stored as separate ints for dollars and cents, for
example -- special care must be taken to ensure that these operators
work as intended.

### Overloading Operators
Operators may be overloaded in order to perform custom functionality
when operators are used. These are declared similarly to other member
functions.

### Overloading Binary Operators

The function below compares two Money objects for equality.
```cpp
bool operator ==(const Money& amt1, const Money& amt2) {
    return ((amt1.getDollars() == amt2.getDollars())
                && (amt1.getCents() == amt2.getCents()));
}
```

Note that this is the same as overloading any other functions. The
function `operator ==()` already exists, and its functionality is defined
for the event of passing in various standard data types. Our overloaded
function is only called when the signature matches what we defined,
meaning our code only runs if we pass in two Money object references.

Note also that because these are NOT class methods, they do not have
direct access to member data. We can only use public getter methods.

### Overloading Unary Operators
Works similarly to above, but is used for unary operators such as
negation.

```cpp
int x = 5;
int y = -x;         // Returns the negated value of x and stores in y
Money m1(100, 25);  // $100.25
Money m2 = -m1;     // Needs to be defined to return -$100.25
```

```cpp
const Money operator -(const Money& amt) {
    return Money(-amt.getDollars(), -amt.getCents());
}
```

### Overloading Member Method Operators
Much of this can also be translated to class methods. In the case of
overloading a binary operator such as addition as a class method,
we only need to pass in a single other class object, because the object
on which we're invoking the method already has access to itself.

Must be careful though, because it's easy to introduce ambiguity here.
For example, if we define a function which adds two Money objects and
also a Money method which adds a single Money object to itself and
returns the new object, the compiler will present a warning. It likely
won't error. Project will compile, and will try to sort through ambiguity
based on how operator function is called, which can cause unexpected
results.

### Overloading Ambiguous Operators
Sometimes need to overload `-` as a *unary* operator (negation) and
also overload `-` as a *binary* operator (subtraction). As above,
compiler will try to sort through ambiguity and will choose which to use
based on the operands/arguments passed in.

### Overloading Assignment Operator
Assignment operator is a binary operator like `+` and `-`. In order to
overload it *must be defined as a member operator*. If not specified,
this is automatically defined by compiler. Need to keep in mind the
problem of shallow- vs deep-copies.

TODO: Experiment with this. What happens if we define a copy constructor
but not a member assignment operator. Does an assignment statment call
our custom copy constructor, or does it use the default? Also experiment
with passing other types of args to these overloaded operator functions.
In the case of the `Money` class, might be useful to add an integer to
the object, instead of only adding vars of the same type together.