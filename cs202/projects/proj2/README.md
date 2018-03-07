# Project 2
Submitted: 2/5/18

### Purpose
This program allows the user to input structured rental car data from
a [file](Cars.txt) into an array of structs. Each struct contains
the car's make and model, year, price to rent, and availability. Users
are then presented with a menu of possible actions to take, such as
sort cars by price, show available cars, and rent a car.

### Design Choices
I chose to make my cars array a top-level variable -- it is declared
in `main()` -- however, all actions performed on this array happen in
functions that map to the user's menu options. This means that nearly
every function I wrote takes an array of Car structs as an argument.
For example:

```cpp
void showAvailableCars(const Car cars[]);
void bubbleSortCars(Car cars[]);
void rentCar(Car cars[]);
```
I believe this was the right choice, as it kept my `main()` function
very simple. It declares a few necessary top-level variables the
enters a loop which first gets a desired action (an integer) from the
user, then executes the associated function via a switch statement.

I also used this project as an excuse to try out some architectural
elements I hadn't used before -- namely header files, function
overloading, and default arguments. None of these were really *required*
for the project, but it was good practice. Coming from a mostly
Python background, the default arguments made perfect sense, as they
mapped very closely to Python's kwargs construct. Function overloading
felt foreign, however. It seems like a lot of duplicate code.

### Problems
One small problem I had was a bug in my `rentCar()` function which
would leave a car's availability unchanged even though I was explicitly
setting the rented car's availability to false. The code looked something
like this:

```cpp
void rentCar(Car cars[]) {
    Car car;
    int i;

    i = getCarIndexFromUser();  // Not a real function
    car = cars[i];

    car.availability = false;   // This wasn't working
}
```

I eventually realized that this is because I was changing the availability
of a completely different car variable, not the car in my cars array,
which is the authoritative copy. I fixed the problem by making `car` a
reference:

```cpp
void rentCar(Car cars[]) {
    int i;

    i = getCarIndexFromUser();
    Car & car = cars[i];

    car.availability = false;   // Works now
}
```

### Possible Enhancements
I wrote a `getIntBetween()` helper function because I was often
requesting integers from the user and had to make sure they fell within
a certain range. The function I wrote works pretty well, but totally
falls apart if the user enters some non-integer -- it enters a really
ugly infinite loop, printing another entry prompt each time through. If
I had more time, I'd like to fix that.