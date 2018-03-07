# Project 5
Submitted: 3/6/18

### Purpose
For this project, we are given a complete primary source file
[proj5.cpp](proj5.cpp) which will act as a test driver for the project.
The source file contains a number of references to unimplemented
`Vehicle` and `Car` classes. In the project, we explored inheritance,
method overriding, and unique ID generation using static members.

### Output Observations
Once the two required classes have been implemented, we are required
to run the test driver and observe the output.

#### Vehicle Class Observations
- The default constructor appropriately assigns the first value of
s_idgen to m_vin. However, it leaves m_lla uninitialized, which results
in undefined behavior. This is to spec, but it might be better to
avoid printing the object before initializing this data.
- Insertion operator override functions as expected.
- Parametrized constructor functions as expected -- assigns 99 into
m_vin because it is greater than or equal to the current value of
s_idgen, and is therefore valid.
- First pass, copy constructor failed because I forgot to increment
s_idgen after assigning the value passed to the constructor. Fixed
the problem, and now functions appropriately.
- I'm not sure about the assignment operator. The observed functionality
of assigning Vehicle #100 into Vehicle #0 is that the float m_lla is
changed appropriately, but the m_vin property is left untouched. I *think*
this is correct, and I'm leaving it as-is, but it's possible that the
class is supposed to generate a new vin number.
- Move function performs as expected

#### Car Class Observations
- Default constructor works -- next available value of s_idgen assigned
into m_vin
- Insertion operator also works -- again, uninitialized values look wrong
but perform to spec
- Parameterized constructor works, as does assignment
- The move function seems wrong -- again I think I've written the code
to spec, so I'm leaving it, but it strikes me as off. The spec says
that Car.move() should first produce a printed output claiming the
car is moving at speed 75, THEN call drive(75). I originally wrote the
code to print the current speed dynamically, but this showed speed 0
since the drive function hadn't been called yet. So instead I've
hardcoded both instances of speed 75 in this function.