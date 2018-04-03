# CS 202 - Lecture 8.0 - Dynamic Memory (part 1)
Date: 3/27/18 | [Slides](../CS202_Lecture16_[Dynamic_Memory_(Pt.1)]_03.27.pdf)

[Prev](./lecture_7_0.md) | [Next](./lecture_8_1.md)

## Memory Management

### Program Data
**Automatic storage duration** describes memory automatically created
at function entry and automatically freed at function exit. Pertains to
object declared in function block scope and in parameter lists.

**Static storage duration** takes place at compile-time before the
associated program is executed and covers the entire program lifetime.
This includes global variables, `static` local and member variables, and
virtual function tables (polymorphism).

**Dynamic storage duration** covers explicit, programmer-made allocation
and deallocation calls. Happens at run-time per request, using C++
memory management functions. These functions are generally NOT `malloc`
and `free` from C, although these functions are still available via the
`<cstdlib>` library. C++ instead uses the `new` and `delete` functions.

**Thread-local storage duration**, which will not be covered here
further, is allocated when a thread begins and deallocated when the
thread ends. Each thread has its own instance of the object(s).

### Memory Allocation
**Static allocation** and deallocation happens at compile time. Related
to **static binding** which also occurs at compile-time.Conversely,
**dynamic allocation** is performed at run-time based on the code.

### Static Allocation
Allocation handled automatically by compiler at compile-time. Global
variables, local variables, everything in `main()`, and more are
included here. No need to directly create or destroy memory -- this is
all handled by the compiler.

*Most* memory falls in this bucket. Obviously, it's all we've used so
far in the class.

This is convenient, but it leaves some functionality to be desired. What
if we need a container -- an array, for example -- that must grow
dynamically based on user input? Declaring huge arrays "just in case" is
inelegant at best.

### The Stack
Part of the programs **virtual memory**. It is used to hold all
necessary information about the active functions (at run-time). It
includes all local variables include parameters and return addresses.
The stack provides very fast memory allocation, but at the cost of
strict size limitations and some other constraints. It is used for
short-lived, "small" data.

### Dynamic Allocation
Handled by the programmer explicitly at run-time. Programmer requests
allocation of a specific size of memory from the system. The system
returns the starting address of the allcoated memory. This can be used
to access the memory. Also used to deallocate the memory later, which
is required.

### The Heap
A special part of the program's virtual memory which is unused by the
program functions and reserved for dynamically allocated objects. All
`new` variables will consume memory from the heap and future calls to
`new` will fail if the heap is full. The heap is significantly slower
than the stack, but it's *much* larger -- gigabytes.

Must always check if a call to `new` has succeeded -- it is a *request*
and is not guaranteed to work. Must also always deallocated heap
memory. Although the heap is much larger than the stack, overflows are
still possible, especially if working with very large data and failing
to deallocate the memory.

### Program Memory
Program is given a discrete block of memory from the system, and this
block is divided into a number of discrete subsections. There are
sections for compiled text, data, dynamic memory, stack memory, and
more.

## Dynamic Memory Allocation

### The Basics
There is no named object or variable, but instead all operations are
performed on pointers. Allocation merely reserved memory space and
returns the address of that space. It is marked as containing a
specific type (`int`, `double`, etc) as all pointers we've seen thus far
are marked.

The `new` operator allocates memory space and `delete` frees it.

```cpp
void * operator new (std::size_t count);
void * operator new [] (std:: size_t count);

void operator delete (void * ptr);
void operator delete [] (void * ptr);
```

> NOTE: Had to look up `void *` here. It's just a "general" pointer
which is unaware of the type it is pointing to and thus can point to
any type.

### The `new([])` Expression
The `new` *expression* is different than the `new` *operator*, although
the former uses the latter.