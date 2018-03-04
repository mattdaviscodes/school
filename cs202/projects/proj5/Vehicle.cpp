//
// Created by Matthew Davis on 3/4/18.
//

#include "Vehicle.h"

int Vehicle::s_idgen = 0;

Vehicle::Vehicle() : m_vin(s_idgen++) {
    std::cout << "Vehicle #" << m_vin << ": Default-ctor" << std::endl;
}

// If vin is greater than any previously used vin, use it, otherwise generate one
Vehicle::Vehicle(const int vin, const float *lla) : m_vin(validateVIN(vin) ? vin : s_idgen++) {
    std::cout << "Vehicle #" << m_vin << ": Parameterized-ctor" << std::endl;
    setLLA(lla);
}

Vehicle::Vehicle(const Vehicle &vehicle) : m_vin(s_idgen++) {
    std::cout << "Vehicle #" << m_vin << ": Copy-ctor" << std::endl;
    setLLA(vehicle.m_lla);
}

Vehicle::~Vehicle() {
    std::cout << "Vehicle #" << m_vin << ": Dtor" << std::endl;
}

Vehicle &Vehicle::operator=(const Vehicle &rhs) {
    std::cout << "Vehicle #" << m_vin << ": Assignment" << std::endl;
    if (this != &rhs) {
        setLLA(rhs.m_lla);
    }
    return *this;
}

const float *Vehicle::getLLA() const {
    return m_lla;
}

int Vehicle::getVIN() const {
    return m_vin;
}

int Vehicle::getIdgen() {
    return s_idgen;
}

bool Vehicle::validateVIN(const int vin) {

    // Only ever allow vins to get bigger
    if (vin >= s_idgen) {
        s_idgen = vin;
        return true;
    }

    return false;
}

void Vehicle::setLLA(const float *lla) {
    for (int i = 0; i < LLA_LEN; i++) {
        m_lla[i] = lla[i];
    }
}

void Vehicle::setLLA(const int lat, const int lng, const int alt) {
    m_lla[0] = lat;
    m_lla[1] = lng;
    m_lla[2] = alt;
}

void Vehicle::move(const float *lla) {
    std::cout << "Vehicle #" << m_vin << ": CANNOT MOVE - I DON'T KNOW HOW" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Vehicle &vehicle) {
    std::cout << "Vehicle # << " << vehicle.m_vin << " @ [" << vehicle.m_lla[0] << ", " << vehicle.m_lla[1] << ", " << vehicle.m_lla[2] << "]"
              << std::endl;
    return os;
}