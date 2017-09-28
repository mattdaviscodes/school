# Chapter 7: Basic Types
NOTE: Skipping most of this chapter because we went over most of it in class.

## Type Definitions
Just as `#define` can be used to create a macro to be used in a program, `typedef`
can be used declare a custom data type. This is called **type definition**.

```c
// Declare an integer data type called Bool
typedef int Bool;
```

Capitalization of the custom data type name is the standard convention. The `Bool`
data type can now be used anywhere in the file just like a built-in data type
would be used. Compiler will treat it as a synonym for `int`.

### Advantages of Type Definitions
Readability and understandability are high on the list of benefits. For example,
this...

```c
typedef float Dollars;
Dollars cash_in, cash_out;
```
... is much more obvious than...
```c
float cash_in, cash_out;
```
... although they are functionally identical.

As with a macro, another benefit is maintainability. If the underlying data type
needs to be changed, `typedef` creates a singular point which needs to be edited,
instead of needing to make the same change throughout the code.

Relatedly, portability is also a consideration. Different machines handle data
types differently. If we need to port to a different system and we've used `typedef`
to create our own data types, it's very easy to change those types to use a
different underlying type, say from int to long for more constricted systems.
Note that this doesn't solve all problems -- at the very least, calls to `printf`
and `scanf` will need to be changed to use the correct placeholders. More changes
will likely be needed.

## The `sizeof` Operator
Allows a program to determine how much memory is required to store a value of
a given type. Returns an unsigned integer, the number of bytes required.

```
sizeof ( type-name )

```

Can also be applied to constants, variables, and expressions. All of these
are valid:

```c
sizeof(int);

char c = 'c';
sizeof(c);

int a = 1, b = 2;
sizeof(a + b);
```

> NOTE: Parentheses not strictly required. Just use them always anyways.
