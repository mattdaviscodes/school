# Lecture[3][0] Notes
Date: 9/19/17

## The `while` Statement
```
while (expression)    <- Controlling expression
    {statement(s)}    <- Loop body
```

#### Common pitfall
A `while` statement with a semicolon after the controlling expression will not execute the following statement.

#### Infinite Loops
Some loops never terminate, either intentionally or by accident. Pitfall above can cause an infinite loop.


### Program: Printing a Table of Squares

```c

while (counter <= input)
{
    printf("%d\t%d\n", counter, counter * counter);
    counter++;
}
```

## The `for` Statement
Also called count-controlled loops

```
expr1   <- Initialize
expr2   <- Termination
expr3   <- Control

for(expr1; expr2; epxr3)
    statement
```
```c
for (i=10; i>0; i--)
{
    printf("%d", i);
}

```

These loops can usually be transposed easily to a `while` loop. Benefit of `for` loop is concision, but it can only be used when we know when loop will terminate.

#### Omitting Expression in a `for` Statement
First arg in `for` loop (initializer) can be omitted. This works:
```c
i = 10;
for (; i < n; i--)
{
    // Statement
}

```
This, too.
```c
for (i = 10; i < n;)
{
    // Decrementer inside loop
}
```
Why the fuck? Just write the whole thing and make the intent clear.

> ### `for` Statement in C99
> In C99, variables can be declared _inside_ a loops initilization. This controls the scope.
> ```c
> for (int i = 0; i < n; i++);
> ```

### The Comma Operator
Used to "glue" two expression together to form a single expression. However, we discard the result of the first expression
```
expr1 , expr2
```
```c
i = 1, j = 5;
++i, i + j;
// Evaluates to 7, i will be 2
```
`i` is incremented, then `i + j` is evaluated

### Ues of Comma Operator
Usful in `for` statements
- To have two (or more) initilization expressions
- To increment several variables each time

## The `do` Statement
```
do statement while(expression);
```
Used when we need to execute `statement` at least one time. Guaranteed one run through, because `expression` is evaluated _after_ `statement` is executed.

```c
int i, n;
// print and scan to get n

i = 0;
do {
    n /= 10;
    i++;
} while(n > 0);

// print output
```

## The `switch` Statement
Alternative to cascaded `if` statements. It is easier to read and faster than `if` statements.

```c
switch (grade) {
    case 4: printf("Excellent");
            break;
    // etc
}
```
