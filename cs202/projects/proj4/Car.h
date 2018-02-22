//
// Created by Matthew Davis on 2/20/18.
//

#ifndef SCHOOL_CAR_H
#define SCHOOL_CAR_H

#include <iostream>

#include "Sensor.h"

using namespace std;

const int MAX_SENSORS_PER_CAR = 3;

class Car {
public:
    // Constructors
    Car();

    Car(const char *make, const char *model, const int year, const float baseprice, const bool available,
        const Sensor *sensors);
    Car(const Car & car);

    // Getters
    char * getMake();
    char * getModel();
    int getYear();
    Sensor * getSensors();
    float getBasePrice();
    float getFinalPrice();
    bool getAvailable();
    char * getOwner();

    // Setters
    void setMake(const char * make);
    void setModel(const char * model);
    void setYear(const int year);
    void setBasePrice(const float baseprice);
    void setAvailable(const bool available);
    void setOwner(const char * owner);

    // Operator overload
    void operator+(Sensor & sensor);
    void operator+(const char * owner);
    friend ostream & operator<<(ostream & os, const Car & car);

    // Other
    float updatePrice();
    void print();
    float estimateCost(const int days);

private:
    char m_make[MAX_CSTRING_SIZE];
    char m_model[MAX_CSTRING_SIZE];
    int m_year;
    Sensor m_sensors[MAX_SENSORS_PER_CAR];
    float m_baseprice;
    float m_finalprice;
    bool m_available;
    char m_owner[MAX_CSTRING_SIZE];
};


#endif //SCHOOL_CAR_H
