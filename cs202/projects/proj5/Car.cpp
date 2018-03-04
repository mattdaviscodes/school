//
// Created by Matthew Davis on 3/4/18.
//

#include "Car.h"

Car::Car() {

}

Car::Car(const char *license, const int vin, const float *lla) {

}

Car::Car(const Car &car) {

}

Car::~Car() {

}

Car &Car::operator=(const Car &car) {
    return <#initializer#>;
}

char *Car::getPlates() const {
    return nullptr;
}

int Car::getThrottle() const {
    return 0;
}

void Car::setPlates(const char *plates) {

}

void Car::setThrottle(const int throttle) {

}

void Car::drive(const int throttle) {

}

void Car::move(const float *lla) {
    Vehicle::move(lla);
};