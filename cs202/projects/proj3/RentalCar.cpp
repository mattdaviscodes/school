/**
 * @brief  CS-202 Project 3 - RentalCar class implementation
 * @Author Matt Davis (mattdavis@nevada.unr.edu)
 * @date   2/8/18
 *
 */

#include <iostream>

#include "RentalCar.h"

using namespace std;

// This is strange. I declared and defined this function in
// proj3.cpp. According to the project spec, I'm not allowed
// to use <cstring>, so I need to use this function in this
// file. According to this SO thread
// (https://stackoverflow.com/questions/10584344/cant-access-function-from-main-file-from-header-file-c)
// I can just drop ANOTHER declaration in this file and it
// will work. I don't know why, though.
char *myStringCopy(char * destination, const char * source);


// Constructors
RentalCar::RentalCar() {
    m_year = -1;
    myStringCopy(m_make, "NOMAKE");
    myStringCopy(m_model, "NOMODEL");
    m_price = 0;
    m_available = false;
}

RentalCar::RentalCar(int year, const char *make, const char *model, float price, bool available) {
    m_year = year;
    myStringCopy(m_make, make);
    myStringCopy(m_model, model);
    m_price = price;
    m_available = available;
}

// Getters
int RentalCar::getYear() const {
    return m_year;
}

char *RentalCar::getMake() {
    return m_make;
}

char *RentalCar::getModel() {
    return m_model;
}

float RentalCar::getPrice() const {
    return m_price;
}

bool RentalCar::getAvailable() const {
    return m_available;
}

// Setters
void RentalCar::setYear(int year) {
    m_year = year;
}

void RentalCar::setMake(char *make) {
    myStringCopy(m_make, make);
}

void RentalCar::setModel(char *model) {
    myStringCopy(m_model, model);
}

void RentalCar::setPrice(float price) {
    m_price = price;
}

void RentalCar::setAvailable(bool available) {
    m_available = available;
}

// Other methods
void RentalCar::print() const {
    cout << m_year << " " << m_make << " " << m_model << ", Price: $" << m_price << ", Available: " << boolalpha
         << m_available << endl;
}

void RentalCar::estimateCost(int days) const {
    cout << "Estimated cost to rent the " << m_make << " " << m_model << " for " << days << " days: $" << m_price * days
         << endl;
}
