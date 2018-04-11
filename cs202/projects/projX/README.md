# Project X
Submitted: 4/10/18

### Purpose
The purpose of this extra-credit project was to further explore the
possibilities introduced by dynamic memory allocation. We wrote a
clone of C++11's `shared_pointer` class called `SmartPtr`. Our class
encapsulated a pointer to another custom data type (aptly named
`DataType`) and provided functionality very close to that of a standard
C++ pointer by overriding the star and arrow operators.

### Design Choices
As with Project 7, there was very little room for improvisation here,
as we were given a completed header file and asked to write the
accompanying implementation. If, however, I had been asked to write
the definition also, the class could have been made more robust by
allowing the pointer to point to any type of data, not just `DataType`
objects.

### Output Observations

#### Constructors
- Default ctor behaved as expected. Then things got PRETTY DANG WEIRD.
- In order to test the paramaterized ctor's functionality, I attempted
calling this code:
    ```cpp
    DataType * dtp1 = new DataType;
    SmartPtr sp2(dtp1);
    SmartPtr sp3(dtp1);
    ```
    The construction occurred as expected, but when `sp3` was destroyed,
    the program threw an error. Something about the freed memory had
    not been allocated. It took some debugging, but I learned that the
    reason for this is that `SmartPtr`'s parameterized constructor
    creates a new m_refcount each time it is called, regardless of any
    other pointers pointing to the passed-in `DataType`. This can lead
    to some trouble though, because when a `SmartPtr` is destroyed, it
    also destroys its m_refcount memory if it *believes* nothing else
    is pointing to that data. The copy ctor can handle this appropriately,
    because the newly-created object is told implicitly that another
    `SmartPtr` already exists that is pointing to the data. When calling
    the parametrized ctor on a raw pointer, however, the `SmartPtr` has
    no way of knowing whether or not another ptr already exists. So at
    program close, `sp2` deletes the memory also referenced by `sp3`,
    then `sp3` attempts to delete the already-deleted memory also,
    causing an error.

    More info here: https://stackoverflow.com/a/1051468/8290310
- Copy ctor works correctly. Nothing to see here.

#### Assignment
- At first, I attempted to use some code like this:
    ```cpp
    SmartPtr sp5 = sp2;
    ```
    I was surprised to see that this line of code calls `SmartPtr`'s
    copy ctor, not the default ctor then assignment operator as I
    expected. This has something to do with **copy-assigment** and
    maybe **elision**, although I'm not sure about the latter. This
    is the sort of thing that experience C++ devs probably side-step
    without even thinking about it, but newbies have a ton of trouble
    with. I don't imagine this will be the last time it trips me up.

#### Star and Arrow Operators
- Not much exciting here. The operators performed as expected, providing
an interface identical to that of a base C++ pointer, assuming I didn't
try anything out of the ordinary. The star operator returned a reference
to the underlying `DataPoint` while the arrow operator returned the
raw pointer.

#### Destruction
- If left alone, all objects destroy themselves in reverse-instantiation
order. This is the expected functionality.
- As the objects created via the copy ctor are destroyed, their
m_refcounts were also decremented as expected.
- I also experimented with calling the destructor explicitly on one
object, producing a surprising result. The object was destroyed as
expected, but as the program closed, an error was thrown saying that
I had attempted to destroy an already-destroyed object. The object
I'd manually destroyed was also being destroyed by the compiler as it
flowed out of scope. The most prevalent advice I saw was to just avoid
calling destructors explicitly to avoid this problem:
https://stackoverflow.com/a/11884236/8290310