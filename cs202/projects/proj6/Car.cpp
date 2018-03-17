/**
 * @brief  CS-202 Project 6 - Car class implementation
 * @Author Matt Davis (mattdavis@nevada.unr.edu)
 * @date   3/17/18
 */

#include "Car.h"

/**
 * Default constructor for Car class
 */
Car::Car() {
    std::cout << "Car: Default-ctor" << std::endl;
    setThrottle(DEF_THROTTLE);
}

/**
 * Parameterized constructor for Car class
 * @param lla const float *
 */
Car::Car(const float *lla) : Vehicle(lla) {
    std::cout << "Car: Parameterized-ctor" << std::endl;
    setThrottle(DEF_THROTTLE);
}

/**
 * Copy constructor for Car class
 * @param c const Car reference
 */
Car::Car(const Car &c) {
    std::cout << "Car: Copy-ctor" << std::endl;
    setThrottle(c.m_throttle);
    SetLLA(c.GetLLA());
}

/**
 * Virtual destructor for Car class
 */
Car::~Car() {
    std::cout << "Car: Dtor" << std::endl;
}

/**
 * Assignment operator overload for Vehicle class
 *
 * If not self-assignment, copy other Vehicle's m_lla into own
 *
 * @param other const Vehicle reference
 * @return Vehicle reference
 */
Car &Car::operator=(const Car &other) {
    std::cout << "Car: Assignment" << std::endl;
    if (this != &other) {
        SetLLA(other.GetLLA());
        setThrottle(other.m_throttle);
    }
    return *this;
}

/**
 * Get car's throttle member
 * @return const int
 */
const int Car::getThrottle() const {
    return m_throttle;
}

/**
 * Set car's thottle member
 * @param throttle const int
 */
void Car::setThrottle(const int throttle) {
    m_throttle = throttle;
}

/**
 * Begin driving by setting m_throttle to throttle
 * @param throttle const int
 */
void Car::drive(const int throttle) {
    setThrottle(throttle);
}

void Car::Move(const float *lla) {
    std::cout << "Car: DRIVE to destination, with throttle @ 75" << std::endl;
    drive(75);
}




