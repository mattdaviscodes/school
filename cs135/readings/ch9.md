# Chapter 9: Functions
Functions are the building blocks of C -- each one essentially a small program.
Helps divide programs into smaller, logical parts. The `main` function is
required in all C programs -- it is the entry point -- but this is only one
example of a possible function.

## Defining Functions
Structure of a function:
```
return-type ( parameters )
{
    body
}
```

The **return type** can be any valid C data type. This is the type of variable
that will be returned by the function. Each **parameter** must also have an
associated data type -- these are essentially variables whose initial value
will be assigned later, when the function is called. The function's **body** is
where the magic happens. It's what the function *does*.

Example function to compute average of two `double`s:
```c
double average(double a, double b)
{
    return (a + b) / 2;
}
```
The `average` function returns a value, but functions are not required to return
anything. These have a return type of `void` -- which is a type with no values.
Like if a data type was raised by animals, that would be `void`. For example:
```c
void print_count(int n)
{
    printf("T minus %d and counting\n", n);
}
```
`print_count` still *does* something -- it executes a specific call to `printf`
-- but it doesn't return anything because it doesn't need to. We don't need
anything back here, we just need the function to print something to the screen.
Note that this function doesn't have a `return` statement. This means it can't
be used in assignment, only in an expression.
```c
int x = print_count(5); // Invalid
print_count(5);         // Valid
```
`void` can also be used to specify a function which requires no arguments. For
example:
```c
void print_test(void)
{
    printf("testing...");
}

print_test();   // Call func with no args
```
#### Some finer points
- Functions may not return arrays
- Each argument must have a data type, even if all arguments are of the same type
- Variables declared in the body of a function belong exclusively to that function.
    - See **scope**.
- If a function's return type is `void`, it is legal to leave to function body
empty.
    - Can be helpful on works-in-progress to sketch out a full program by
    writing empty functions as you think through what will be needed.

### Function Calls
When using a function in a program, we say we're "calling" or "making calls
to" the function. Function calls consist of a function name, followed by a list
of arguments enclosed in parentheses. If parentheses are missing, function won't
get called, **although the program will still compile and execute**. Be warned
-- thar be bugs.
```c
average(x, y);  // Returns the results of (x + y) / 2
print_count(i); // Prints i, returns nothing
print_test();   // Prints "testing...", returns nothing
print_test;     // Compiles and runs, but does absolutely nothing
```
A function with a return value can be called like an expression, without storing
the result in a variable. All the code in the body of the function will be
executed, but the results will be discarded. If the function has some side-
effect, this can be very useful. For example, `printf` returns the number of
characters that it prints. We rarely capture this number, but if we wanted to,
we could store it in an `int` variable for later use in our program.
```c
num_chars = printf("Hi, Mom!\n");   // prints "Hi, Mom!" -- num_chars == 9
printf("Hi, Mom!\n")                // prints "Hi, Mom!" -- nothing stored
```
C allows us to put `(void)` before a function call where we are intentionally
discarding a return value. This helps readability.
```c
(void) average(x, y);   // More obvious that we don't want the return value
```

##### Program: [Testing Whether a Number Is Prime](./programs/prime.c)

## Function Declarations
Not to be confused with function *definitions*. As with variables, it is
possible to **declare** a function  (tell the compiler it exists) without
**defining** it (tell the compiler what it does). In the sample program above,
we needed to make sure the function `is_prime` was defined above the `main`
function. Declaring a function without defining it is a promise to the
compiler that this function really does exist, it just has to look a little
further into the program.

This makes good sense. It would be cumbersome to have to ensure that all
uses of a function came after their definitions. That would make it very easy
to write sloppy, disorganized code. Instead we can use declarations as
promises, and keep the bulky function definitions somewhere out of the way.

Function declarations follow this pattern. Note that we *do not* include the
body of the function here.
```
return-type function-name (parameters);
```
This is also known as a function **prototype**. It's also legal to leave
function arguments unnamed in the declaration, as long as their data-types
are provided. This is generally seen as undesirable -- better to be explicit
and include the arg names in the prototype.
```c
double average(double x, double y); // Legal
double average(double, double);     // Also legal    
```

## Arguments
Book makes a distinction between **parameters** (variables in a function
declaration) and **arguments** (expressions used when calling a function). I
don't see any problem with using "argument" for both.

Arguments are **passed by value**, meaning each arg is evaluated and its value
is assigned to the corresponding parameter (variable). This means that the
values passed in to functions are copies and cannot directly affect the inputs
themselves.

C allows functions to be called with args that don't match the types specified
by the function definition. If an `int` is passed to a function expecting a
`double`, the function will convert the input to `double` automatically.

### Array Arguments
Arrays may be passed as function args. If array is one-dimensional, the length
of the array is often omitted. In this case, the arg can be any 1d array whose
elements are of the proper type.

```c
int f(int a[]) {};  // No array length specified
```

>Book sort of waves a hand at some inconsistencies when passing in arrays. These
have something to do with pointers, but I don't really get it yet. (Chapter 12
is all about pointers.)

Calling sizeof() to find the length of an array passed to a function won't work
as expected, so lengths will need to be passed in separately if needed. This
opens the possibility of having a hardcoded array length, but calling with an
array that is actually longer or shorter than expected. Watch out.

**NOTE:** An array passed to a function can be modified in-place, unlike most
other variables. Again, has something to do with pointers.
