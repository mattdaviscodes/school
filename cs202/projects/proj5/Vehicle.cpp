//
// Created by Matthew Davis on 3/4/18.
//

#include "Vehicle.h"

int Vehicle::s_idgen = 0;

Vehicle::Vehicle() {

}

Vehicle::Vehicle(const int vin, const float *lla) {

}

Vehicle::Vehicle(const Vehicle &vehicle) {

}

Vehicle::~Vehicle() {

}

Vehicle &Vehicle::operator=(const Vehicle &rhs) {
    return <#initializer#>;
}

float *Vehicle::getLLA() const {
    return nullptr;
}

int Vehicle::getVIN() const {
    return 0;
}

std::ostream &operator<<(std::ostream &os, const Vehicle &vehicle) {
    return <#initializer#>;
}

int Vehicle::getIdgen() {
    return 0;
}

void Vehicle::setLLA(const float *lla) {

}

void Vehicle::setLLA(const int lat, const int lng, const int alt) {

}

void Vehicle::setVIN(const int vin) {

}

void Vehicle::move(const float *lla) {

}
