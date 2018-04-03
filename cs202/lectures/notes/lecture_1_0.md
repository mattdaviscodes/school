# CS 202 - Lecture[0][0]
Date: 1/30/18

## Functions
Building blocks of larger programs. Allows programmer to break program
into discrete blocks that serve a specific purpose.

NOTE: Functions in C++ can only `return` one value.

### Parts
- Prototype (declaration)
- Implementation (definition)
- Call

### Prototype
Information for compiler to properly interpret calls. These are usually
kept either in a header file or before `main()` in a one-file program.
```cpp
// <return type> <function name> (<parameters>);
int squareNumber(int n);
```

### Implementation
Actual code for function. Definition must match prototype, and be placed
after `main()`. All functions are equal, no function *needs* to be
contained inside another. `return` statement sends data back to caller.

```cpp
int squareNumber(intn ) {
    int answer = n * n;
    return answer;
}
```

### Call
How function is used by program. Transfers execution control to the
function.

```cpp
int tenSquared = sqareNum(10);
```

### `return` Statements
Transfers control back to the calling function. Void functions are
special -- no value is passed back, but the function has some side
effect. Return statements are optional in the case of void functions,
but are required for all other functions.

`return` is typically the last statement in a definition. However, it
is possible (and often desirable) to have multiple return statements
which may be scattered throughout function definition.

### Parameters / Arguments
**Parameters** are formal variables, as it appears in a function prototype.
They are part of the function signature. **Arguments** as the actual
values passed to a function.

```cpp
doubleprecisionSum(double a, double b);  // a and b are parameters
precisionSum(0.1 * 1000000, 1e-3);       // these numbers are args
```

### Pre- and Post-Conditions
Conditions include assumptions about program state, not just the input
and output. Usually contained in a comment above function prototypes.

```cpp
// Function name: showInterest
// Pre-condition: balance is nonnegative
// Post-condition: amount of interest on given balance, at given rate
void showInterest(double balance, double rate);
```

### `main()` Function
Special function, serves as entry point for program. Each program
**required** to have exactly one function called `main()`. Should return
an integer value (return 0 on successful completion, non 0 on fail).

### Pass-by-Reference Functions
Provides direct access to caller's actual argument. Caller's data can be
modified by funciton.

```cpp
void squareThisNumber(int& n);
```

### `const`-Reference Parameters
Calling by reference arguments is inherently dangerous. Data can be
changed, which is sometimes not desirable. In this case, we should pass
const reference to "protect" data.

```cpp
void sendConstRef(const int &par1, const in &par2);
```

No changes allowed inside function body, arguments are "read-only."

NOTE: Calling functions this way can result in a funciton signature
than a regular reference. They are **different functions** even though
they have the same name.

```cpp
// These are different
void doThing(int &a);
void doThing(const int &a);
```

## Pointers

### Addresses
Each variable has an **address** which is where the data "lives" in
memory. Usually represented as a hexadecimal value. Is the location
of the data's **starting** memory location.

In the pass-by-value model, when a variable is passed to a function as
an argument, a new copy is created and scoped to that function. These
variables (outside and inside of function) are identical except for
their addresses which represent unique locations in memory.

The **address-of operator** is `&`.

```cpp
int n = 5;
cout << n;  // 5
cout << &n; // 0x1015
```

### Pointers
A variable whose value hold the address of something somewhere in
memory.

```cpp
int x = 37;
int * ptr;

cout << "x is " << x << endl;       // x is 37
cout << "ptr is " << ptr << endl;   // ptr is 0x7ffedcaba5c4
```

Pointers allow functions to modify multiple ags, use and modify arrays
as args, and increase program efficiency. Also allow creation and
handling of dynamic objects.

### Declaration
Like any other variable, each pointer has a type, name, and value. The
type here is especially important -- a pointer of type int cannot point
to a variable of type char. Dumb ass.

### Value
Pointer values are memory addresses. Pointers themselves have addresses,
where the pointer itself is stored in memory. This is **different** than
the value of the pointer, which is the address that the pointer **points
to**.

### Dereference operator
To get the value that a pointer points to, we use the derefence operator
`*`.

```cpp
int n = 5;
int *ptr = &n;
cout << ptr << endl;    // 0x1015
cout << *ptr << endl;   // 5
```


