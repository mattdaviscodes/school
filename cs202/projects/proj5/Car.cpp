/**
 * @brief  CS-202 Project 5 - Car class implementation
 * @Author Matt Davis (mattdavis@nevada.unr.edu)
 * @date   3/5/18
 */

#include <cstring>

#include "Car.h"

/**
 * Default constructor for Car
 */
Car::Car() {
    std::cout << "Car #" << m_vin << ": Default-ctor" << std::endl;
    m_throttle = DEFAULT_THROTTLE;
}

/**
 * Parameterized constructor for Car
 * @param license const char * license plates
 * @param vin const in vin number
 * @param lla float array [lat, lng, alt]
 */
Car::Car(const char *license, const int vin, const float *lla) : Vehicle(vin, lla) {
    std::cout << "Car #" << m_vin << ": Parameterized-ctor" << std::endl;
    setPlates(license);
}

/**
 * Copy constructor for Car
 * @param car A Car object to copy
 */
Car::Car(const Car &car) : Vehicle(car) {
    std::cout << "Car #" << m_vin << ": Copy-ctor" << std::endl;
    setPlates(car.m_plates);
}

/**
 * Destructor for Car
 */
Car::~Car() {
    std::cout << "Car #" << m_vin << ": Dtor" << std::endl;
}

/**
 * Assignment operator overload for Car
 * @param rhs Car object to assign into lhs
 * @return lhs Car object
 */
Car &Car::operator=(const Car &rhs) {
    std::cout << "Car #" << m_vin << ": Assignment" << std::endl;
    if (this != &rhs) {
        setLLA(rhs.m_lla);
        setPlates(rhs.m_plates);
    }
    return *this;
}

/**
 * Get car's m_plates property
 * @return char * m_plates
 */
const char *Car::getPlates() const {
    return m_plates;
}

/**
 * Get car's m_throttle property
 * @return int m_throttle
 */
int Car::getThrottle() const {
    return m_throttle;
}

/**
 * Set car's m_plates property
 * @param plates char * license plates
 */
void Car::setPlates(const char *plates) {
    strcpy(m_plates, plates);
}

/**
 * Set car's m_throttle property
 * @param throttle int throttle
 */
void Car::setThrottle(const int throttle) {
    m_throttle = throttle;
}

/**
 * Just calls setThrottle
 * @param throttle
 */
void Car::drive(const int throttle) {
    setThrottle(throttle);
}

/**
 * Print formatted output and call drive()
 * @param lla
 */
void Car::move(const float *lla) {
    std::cout << "Car #" << m_vin << ": DRIVE to destination, with throttle @ 75" << std::endl;
    drive(75);
};

/**
 * Insertion operator overload for custom object output
 * @param os output stream
 * @param car Car object
 * @return output stream
 */
std::ostream &operator<<(std::ostream &os, const Car &car) {
    std::cout << "Vehicle #" << car.m_vin << " Plates: " << car.m_plates << ", Throttle: " << car.m_throttle << " @ [" << car.m_lla[0]
              << ", " << car.m_lla[1] << ", " << car.m_lla[2] << "]" << std::endl;
    return os;
}