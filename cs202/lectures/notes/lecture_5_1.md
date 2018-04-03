# CS 202 - Lecture 5.0 - C++ Classes - Inheritance (part 2)
Date: 3/1/18 | [Slides](../CS202_Lecture12_[C++_Classes-Inheritance_(Pt.2)]_03.01.pdf)

[Prev](./lecture_5_0.md) | [Next](./lecture_6_0.md)

> Didn't take many notes today. I wrote some sample code while he
was talking instead in order to test out some strategies. I'll
paste below.

```cpp
#include <iostream>
#include <stdexcept>

using namespace std;

/*
 * ========
 * VEHICLE
 * ========
 */

class Vehicle {
public:
    Vehicle() {
        s_vehicleCount++;
    };
    void print() {
        cout << "Vehicle.print()" << endl;
    };
    int getVehicleCount() {
        return s_vehicleCount;
    };
    void overrideMe() {
        throw logic_error("Child class must implement this method");
    }

private:
    static int s_vehicleCount;    // Track total number of vehicles
};

int Vehicle::s_vehicleCount = 0;


/*
 * ========
 * CAR
 * ========
 */

class Car : public Vehicle {
public:
    Car() {
        s_carCount++;
    };
    void print() {
        cout << "Car.print()" << endl;
    };
    int getCarCount() {
        return s_carCount;
    };
    void overrideMe() {
        cout << "Function Vehicle.overrideMe() successfully overridden!" << endl;
    }

private:
    static int s_carCount;
};

int Car::s_carCount = 0;

/*
 * ========
 * TRUCK
 * ========
 */
class Truck : public Car {
public:
    Truck() {
        s_truckCount++;
    }
    void print() {
        cout << "Truck.print()" << endl;
    }
    int getTruckCount() {
        return s_truckCount;
    }

private:
    static int s_truckCount;
};

int Truck::s_truckCount = 0;

int main() {
    Vehicle v;
    Car c;
    Truck t;

    v.print();
    c.print();
    t.print();

    cout << "Total vehicles: " << v.getVehicleCount() << endl;
    cout << "Total cars: " << c.getCarCount() << endl;
    cout << "Total trucks: " << t.getTruckCount() << endl;

//    v.overrideMe(); Breaks script intentionally
    c.overrideMe();
    t.overrideMe();

    return 0;
}

```

## Inheritance (cont'd)

### Method Overriding
Completely eliminates parent method's functionality and replaces with
custom functionality unique to the child class. Functions which hope
to override a parent's function must use the exact same function
signature.

## Polymorphism
The ability to take many forms.