//
// Created by Matthew Davis on 3/4/18.
//

#include <cstring>

#include "Car.h"

Car::Car() {
    std::cout << "Car #" << m_vin << ": Default-ctor" << std::endl;
    m_throttle = DEFAULT_THROTTLE;
}

Car::Car(const char *license, const int vin, const float *lla) : Vehicle(vin, lla) {
    std::cout << "Car #" << m_vin << ": Parameterized-ctor" << std::endl;
    setPlates(license);
}

Car::Car(const Car &car) : Vehicle(car) {
    std::cout << "Car #" << m_vin << ": Copy-ctor" << std::endl;
    setPlates(car.m_plates);
}

Car::~Car() {
    std::cout << "Car #" << m_vin << ": Dtor" << std::endl;
}

Car &Car::operator=(const Car &rhs) {
    std::cout << "Car #" << m_vin << ": Assignment" << std::endl;
    if (this != &rhs) {
        setLLA(rhs.m_lla);
        setPlates(rhs.m_plates);
    }
    return *this;
}

const char *Car::getPlates() const {
    return m_plates;
}

int Car::getThrottle() const {
    return m_throttle;
}

void Car::setPlates(const char *plates) {
    strcpy(m_plates, plates);
}

void Car::setThrottle(const int throttle) {
    m_throttle = throttle;
}

void Car::drive(const int throttle) {
    setThrottle(throttle);

}

void Car::move(const float *lla) {
    std::cout << "Car #" << m_vin << ": DRIVE to destination, with throttle @ " << m_throttle << std::endl;
    drive(75);
};

std::ostream &operator<<(std::ostream &os, const Car &car) {
    std::cout << "Vehicle #" << car.m_vin << " Plates: " << car.m_plates << ", Throttle: " << car.m_throttle << " @ [" << car.m_lla[0]
              << ", " << car.m_lla[1] << ", " << car.m_lla[2] << "]" << std::endl;
    return os;
}