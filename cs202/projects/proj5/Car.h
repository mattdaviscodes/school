//
// Created by Matthew Davis on 3/4/18.
//

#ifndef SCHOOL_CAR_H
#define SCHOOL_CAR_H


#include "Vehicle.h"

const int MAX_CSTRING_SIZE = 256;

const int DEFAULT_THROTTLE = 0;

class Car : public Vehicle {

    friend std::ostream &operator<<(std::ostream &os, const Car &car);

public:
    Car();
    Car(const char *license, const int vin, const float *lla);
    Car(const Car &car);

    ~Car();

    Car &operator=(const Car &rhs);

    const char *getPlates() const;
    int getThrottle() const;

    void setPlates(const char *plates);
    void setThrottle(const int throttle);

    void drive(const int throttle);

    void move(const float *lla);

private:
    char m_plates[MAX_CSTRING_SIZE];
    int m_throttle;

};


#endif //SCHOOL_CAR_H
