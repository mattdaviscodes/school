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

    m_finalprice = 0;   // TODO: Use updatePrice() here once implemented

};
Car::Car(const char * make, const char * model, const int year, const float baseprice, const Sensor * sensors) {

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
void Car::operator+(const Sensor & sensor) {};
void Car::operator+(const char * owner) {};

// Other
float Car::updatePrice() {};
void Car::print() {};
float Car::estimateCost(const int days) {};