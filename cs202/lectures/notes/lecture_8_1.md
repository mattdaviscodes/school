# CS 202 - Lecture 8.1 - Dynamic Memory (part 2)
Date: 3/29/18 | [Slides](../CS202_Lecture17_[Dynamic_Memory_(Pt.2)]_03.29.pdf)

[Prev](./lecture_8_0.md) | [Next](./lecture_9_0.md)

## Dynamic Memory Allocation (recap)
The `new` expression attempts to allocate a memory location of the size
requested by the programmer and returns a pointer to the beginning of
that memory. The `delete` expression frees memory on the heap by
operating on a pointer, such as one returned by `new`.

A pointer on which `delete` has been called should be considered
invalid. Attempts to access the memory at this location will exhibit
undefined behavior. A standard practice to prevent against this
is to set `deleted` pointers to NULL.

```cpp
// Create
int * x = new int;

// Manipulate
*x = 5;
cout << *x + 3 << endl;     // 8

// Delete
delete(x);  // pointer now invalid, but x still contains memory location
x = NULL;   // for safety, memory location removed
```

## Dynamic Arrays

### Dynamically Allocated Array
The `[IntExp]` Array-variant of the `new` expression can be used to
allocate array sof objects/variables in Dynamic Memory.

```cpp
char * myString = new char[255];
Car * myInventory = new Car[100];
```

If the array-based `new` is used, then the array-based `delete` must
be used to free the returned memory.

```cpp
delete [] myString;
delete [] myInventory;
```

Full example:
```cpp
int * grades = NULL;    // safe practice to init pointer as NULL
int numberOfGrades;

cout << "Enter the number of grades: ";
cin >> numberOfGrades;

grades = new int[numberOfGrades];   // dynamically allocate array

if (grades) {   // Assure allocation succeeded
    for (int i = 0; i < numberOfGrades; i++) {
        cin >> grades[i];
        cout << grades[i] << " ";
    }
}

// Free memory and reset grades var
delete [] grades;
grades = NULL;
```

The above example is a bit misleading, because the `new` allocation
will actually throw an error if it fails. The proper way to implement
the above is:

```cpp
int * grades = NULL;    // safe practice to init pointer as NULL
int numberOfGrades;

cout << "Enter the number of grades: ";
cin >> numberOfGrades;

try {
    grades = new int[numberOfGrades];   // attempt dynamic allocation
    if (grades) {   // Assure allocation succeeded
        for (int i = 0; i < numberOfGrades; i++) {
            cin >> grades[i];
            cout << grades[i] << " ";
        }
    }
    // Free memory and reset grades var
    delete [] grades;
    grades = NULL;
} catch (std::bad_alloc& ex) {
    /* handle exception ex */
}
```

### Dynamically Allocated 2D Array
2D arrays are also able to be dynamically allocated. To do so, a double
pointer is used.

```cpp
// Create spaces for rows number of addresses
int ** intMatrix = new int * [rows];

// Create space for the rows themselves
for (int i = 0; i < rows; i++) {
    intMatrix[i] = new int[cols];
}
```

Full example:

```cpp
try {
    intMatrix = new int * [rows];
    for (int i = 0; i < rows; i++) {
        intMatrix[i] = NULL;
    }
    for (int i = 0; i < rows; i++) {
        try {
            intMatrix[i] = new int[cols];
        } catch (std::bad_alloc& ex) {
            for (; i >= 0; --i) {
                delete [] intMatrix[i];
                throw;
            }
        }
    }
} catch (std::bad_alloc& ex) {
    delete [] intMatrix;
}
```

## Memory Handling

### Memory Leaks
When creating objects with DMA, access is provided through the pointer
returned by the Expression `new`. Changing these pointers or allowing
them to flow out of scope will result in a **memory leak**. The memory
pointed by the lost pointers is still reserved, but it cannot be freed
anymore because the programmer no longer has access to its location.
These are **unnamed objects**, and are a common cause of memory leaks.