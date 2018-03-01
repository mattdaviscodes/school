//
// Created by Matthew Davis on 2/20/18.
//

#ifndef SCHOOL_CAR_H
#define SCHOOL_CAR_H

#include <iostream>

#include "Sensor.h"

using namespace std;

const int MAX_SENSORS_PER_CAR = 3;

int getIntBetween(int min, int max);

class Car {

    friend std::istream& operator>>(std::istream& is, Car& car);

public:
    // Constructors
    Car();
    Car(const char *make, const char *model, const int year, const float baseprice, const bool available,
        Sensor *sensors);
    Car(Car & car);

    // Getters
    char * getMake();
    char * getModel();
    int getYear();
    Sensor * getSensors();
    float getBasePrice();
    float getFinalPrice();
    bool getAvailable();
    char * getOwner();
    int getSensorCount();

    // Setters
    void setMake(const char * make);
    void setModel(const char * model);
    void setYear(const int year);
    void setBasePrice(const float baseprice);
    void setAvailable(const bool available);
    void setOwner(const char * owner);

    // Operator overload
    Car& operator+(Sensor & sensor);
    Car& operator+(const char * owner);
    friend ostream & operator<<(ostream & os, const Car & car);

    // Other
    float updatePrice();
    void print();
    float estimateCost(const int days);
    void promptRent();
    void rent();

private:
    char m_make[MAX_CSTRING_SIZE];
    char m_model[MAX_CSTRING_SIZE];
    int m_year;
    Sensor m_sensors[MAX_SENSORS_PER_CAR];
    float m_baseprice;
    float m_finalprice;
    bool m_available;
    char m_owner[MAX_CSTRING_SIZE];
    int m_sensorCount;
};


#endif //SCHOOL_CAR_H
