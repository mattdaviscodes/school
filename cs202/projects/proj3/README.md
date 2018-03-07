# Project 3
Submitted: 2/13/18

### Purpose
This program allows users to input structured rental car and rental
agency data from a [file](Agencies.txt) into an array of RentalAgency
structs. Each struct contains some descriptive information about the
agency, as well as an array of RentalCar class objects which contain
the actual data about the car -- make, model, year, etc.

Users are shown a simple menu with options to perform various tasks --
find the most expensive car, estimate cost to rent a car for N days.

### Design Choices
As with the last assignment, I chose to keep my `main()` function fairly
simple. I used the fewest number of top-level variables I could, and
the most important of these is `RentalAgency agencies[3]`, an array
of RentalAgency structs which serves as the basis for the entire
program. Since this struct contains within it all of the RentalCar
data for a given agency, this was the simplest way of managing the data.

The bulk of the main program is a while loop which displays a menu, gets
an action from the user, then executes the action via a switch
statement. Each case (except for the exit case) in the switch executes
a single function which takes one argument, the array of agencies.

This project also presented the opportunity to write a wide variety
of functions. I further explored functions with default parameters and
overloaded functions, which I began exploring in Project 2. I also wrote
a number of helper methods which simplified code blocks in certain
places and hid some more complex functionality away as much as possible.
I found that this was particularly useful when a complex process needed
to be executed iteratively. For example, instead of having a single
function to read in all of the agencies from a file, I wrote one function
which would read in *only one* agency from a file, then wrote a helper
function that would handle the file opening and iterations, calling
the former function when it was time to do the file read.

### Problems
As these programs grow, I have more and more trouble knowing where to
put things. Header files are a good place to store related code, but
my main file ([proj3.cpp](.proj3.cpp) in this case) always seems to
act as a catchall for the things that don't really fit. These include
helper functions to read and write files or get integers from the user.
They also include the requisite string manipulation functions (which
I haven't used much here). Where should it all go?

A few of these functions have return types of RentalCar or RentalAgency,
which makes me think they should live in their respective header files,
even though they aren't class methods. I even attempted moving one of
these to [RentalAgency.h](.RentalAgency.h), but the function I wanted
to move depended on *another* helper function which really didn't belong
in that file, so I left it as it was.