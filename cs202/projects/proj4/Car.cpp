//
// Created by Matthew Davis on 2/20/18.
//

#include <iostream>

#include "Car.h"
#include "Sensor.h"
#include "proj4.h"

using namespace std;


// Constructors
Car::Car() {
    setMake("\0");
    setModel("\0");
    setYear(0);
    setBasePrice(0);
    setAvailable(false);
    setOwner("\0");

    updatePrice();

};
Car::Car(const char *make, const char *model, const int year, const float baseprice, const bool available,
         const Sensor *sensors) {
    setMake(make);
    setModel(model);
    setYear(year);
    setBasePrice(baseprice);
    setAvailable(available);

    // TODO Sensors

    updatePrice();

};
Car::Car(const Car & car) {};

// Getters
char * Car::getMake() { return m_make; };
char * Car::getModel() { return m_model; };
int Car::getYear() { return m_year; };
Sensor * Car::getSensors() {return m_sensors; };
float Car::getBasePrice() {return m_baseprice; };
float Car::getFinalPrice() { return m_finalprice; };
bool Car::getAvailable() { return m_available; };
char * Car::getOwner() {return m_owner; };

// Setters
void Car::setMake(const char * make) { myStringCopy(m_make, make); };
void Car::setModel(const char * model) {myStringCopy(m_model, model); };
void Car::setYear(const int year) { m_year = year; };
void Car::setBasePrice(const float baseprice) {m_baseprice = baseprice; };
void Car::setAvailable(const bool available) {m_available = available; };
void Car::setOwner(const char * owner) { myStringCopy(m_owner, owner); };

// Operator overload
void Car::operator+(Sensor & sensor) {
    Sensor * sensors_ptr = m_sensors;

    // Iterate over car's sensors looking for an open spot (sensor type="none")
    for (int i = 0; i < MAX_SENSORS_PER_CAR; i++, sensors_ptr++) {
        if (!myStringCompare(sensors_ptr->getType(), "none")) {
            sensors_ptr->setType(sensor.getType());
            updatePrice();
            break;
        };
    }
};
void Car::operator+(const char * owner) {};
ostream & operator<<(ostream & os, const Car & car) {
    os << "Car(m_make=" << car.m_make << ", m_model=" << car.m_model << ", m_year=" << car.m_year << ", m_baseprice="
       << car.m_baseprice << ", m_finalprice=" << car.m_finalprice << ", m_available=" << boolalpha << car.m_available
       << ", m_owner=" << car.m_owner << ")";

    return os;
};

// Other
float Car::updatePrice() {
    float price = m_baseprice;
    Sensor * sensors_ptr = m_sensors;

    for (int i = 0; i < MAX_SENSORS_PER_CAR; i++, sensors_ptr++) {
        price += sensors_ptr->getExtraCost();
    }

    return m_finalprice = price;
};
void Car::print() {
};
float Car::estimateCost(const int days) {};