/**
 * @brief  CS-202 Project 6 - Car class definition
 * @Author Matt Davis (mattdavis@nevada.unr.edu)
 * @date   3/17/18
 */

#ifndef SCHOOL_CAR_H
#define SCHOOL_CAR_H

#include "Vehicle.h"

const int DEF_THROTTLE = 0;

class Car : public Vehicle {
public:
    Car();
    Car(const float *lla);
    Car(const Car &c);

    virtual ~Car();

    Car &operator=(const Car &other);

    const int getThrottle() const;
    void setThrottle(const int throttle);

    void drive(const int throttle);
    virtual void Move(const float *lla);

private:
    int m_throttle;
};


#endif //SCHOOL_CAR_H
