# Project 7
Submitted: 4/4/18

### Purpose
The purpose of this project was to gain hands-on experience dealing with
dynamic memory by creating a custom implementation of the string class.
We were given a complete [class header](MyString.h) and were required
to write the class's implementation, as well as a test program to
flex the class a little.

### Design Choices
The project was fairly straightforward, so there wasn't much room for
creative thinking. The only significant choice I had to make was how
the class would choose how much memory to allocate. Originally, I'd
planned on using some sort of chunking algorithm which would have a
chunk size -- 50 characters, for example -- and would allocate the
fewest chunks required to fit the string. This seemed unnecessarily
rigid, and I had no qualitative way to decide how big the chunks should
be.

Then I thought I'd follow a similar process, but use an increasing chunk
size algorithm. Something like starting at 2^1, check if an allocation
of that size would fit the input. If not, increase by a power of 2.
Repeat until the input fits. However, this also felt sort of pointless.

Finally, I decided to just make the allocation fit the input exactly.
This class is limited enough in scope that I think this naive approach
makes sense. If the class was meant to handle more intense manipulation,
that probably wouldn't work, and would be an obvious place for
optimization.

### Output Observations

- Constructors behave as expected. The default constructor is all but
useless, though. Attempting to `cout` an object created with the default
constructor will result in a seg fault.
- Destructor works well, farming out all deallocation work to
`buffer_deallocate()`. This is good from a DRY standpoint, but violates
Chris's recommendation in lecture to avoid unnecessarily setting pointers
to null if they're being destroyed anyway.
- `size()` and `length()` do as they should, although they will nearly
always be different only by 1, since allocation happens according to
the input string, +1 char for the null terminator. The only time this
is not true is if we use the bracket notation to prematurely terminate
the string (which happens in this test driver)
- `c_str()` good, although I'm not positive I wrote this correctly. I
just return a reference to `m_buffer`. The method was expected to return
a pointer, and I couldn't create a local var and return a pointer to
that. I think this is the only other option.