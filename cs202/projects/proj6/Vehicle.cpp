/**
 * @brief  CS-202 Project 6 - Car class implementation
 * @Author Matt Davis (mattdavis@nevada.unr.edu)
 * @date   3/17/18
 */

#include "Vehicle.h"

/**
 * Default constructor for Vehicle class
 */
Vehicle::Vehicle() {
    std::cout << "Vehicle:Default-ctor" << std::endl;
}

/**
 * Parameterized constructor for Vehicle class
 *
 * Copies param lla into member m_lla index by index
 * @param lla const float
 */
Vehicle::Vehicle(const float *lla) {
    std::cout << "Vehicle:Parameterized-ctor" << std::endl;
    SetLLA(lla);
}

/**
 * Copy constructor for Vehicle class
 *
 * Copies Vehicle v's m_lla member into own m_lla
 * @param v const Vehicle reference
 */
Vehicle::Vehicle(const Vehicle &v) {
    std::cout << "Vehicle:Copy-ctor" << std::endl;
    SetLLA(v.m_lla);
}

/**
 * Virtual destructor for Vehicle class
 */
Vehicle::~Vehicle() {
    std::cout << "Vehicle: Dtor" << std::endl;
}

/**
 * Assignment operator overload for Vehicle class
 *
 * If not self-assignment, copy other Vehicle's m_lla into own
 *
 * @param other const Vehicle reference"
 * @return Vehicle reference
 */
Vehicle &Vehicle::operator=(const Vehicle &other) {
    std::cout << "Vehicle: Assignment" << std::endl;
    if (this != &other) {
        SetLLA(other.m_lla);
    }
    return *this;
}

/**
 * Get vehicle's m_lla member
 * @return const float *
 */
const float *Vehicle::GetLLA() const {
    return m_lla;
}

/**
 * Set vehicle's m_lla member
 * @param lla const float *
 */
void Vehicle::SetLLA(const float *lla) {
    arrayCopy(m_lla, lla, LLA_LEN);
}

/**
 * Print Vehicle's data
 *
 * @param os std::ostream reference
 */
void Vehicle::serialize(std::ostream &os) {
    os << "Vehicle @ [";
    arrayPrint(os, m_lla, LLA_LEN);
    os << "]" << std::endl;
}

/**
 * Call Vehicle v's serialize method
 * @param os std::ostream reference
 * @param v Vehicle reference
 */
std::ostream &operator<<(std::ostream &os, Vehicle &v) {
    v.serialize(os);
    return os;
}

/* HELPERS */

/**
 * Copy src into float by len
 * @param dest float *
 * @param src const float *
 * @param len const int
 */
void arrayCopy(float * dest, const float * src, const int len) {
    for (int i = 0; i < len; i++) {
        *dest++ = *src++;
    }
}

/**
 * Print a comma-delimited list of arr members to os
 * @param os std::ostream reference
 * @param arr const float *
 * @param len const int
 */
void arrayPrint(std::ostream &os, const float * arr, const int len) {
    for (int i = 0; i < len; i++) {
        os << arr[i];

        // Comma delimit list, no trailing comma
        if (i != len -1) {
            os << ", ";
        }
    }
}