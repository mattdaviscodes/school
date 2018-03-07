/**
 * @brief  CS-202 Project 5 - Car class definition
 * @Author Matt Davis (mattdavis@nevada.unr.edu)
 * @date   3/5/18
 */

#ifndef SCHOOL_CAR_H
#define SCHOOL_CAR_H


#include "Vehicle.h"

const int MAX_CSTRING_SIZE = 256;

const int DEFAULT_THROTTLE = 0;

class Car : public Vehicle {

    friend std::ostream &operator<<(std::ostream &os, const Car &car);

public:
    // Constructors
    Car();
    Car(const char *license, const int vin, const float *lla);
    Car(const Car &car);

    // Destructor
    ~Car();

    // Operator overload
    Car &operator=(const Car &rhs);

    // Getters
    const char *getPlates() const;
    int getThrottle() const;

    // Setters
    void setPlates(const char *plates);
    void setThrottle(const int throttle);

    // Other
    void drive(const int throttle);
    void move(const float *lla);

private:
    char m_plates[MAX_CSTRING_SIZE];
    int m_throttle;

};


#endif //SCHOOL_CAR_H
