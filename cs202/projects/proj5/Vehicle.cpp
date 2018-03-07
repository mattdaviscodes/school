/**
 * @brief  CS-202 Project 5 - Vehicle class implementation
 * @Author Matt Davis (mattdavis@nevada.unr.edu)
 * @date   3/5/18
 */

#include "Vehicle.h"

int Vehicle::s_idgen = 0;

/**
 * Default constructor for Vehicle
 *
 * m_vin is assigned current value of s_idgen
 */
Vehicle::Vehicle() : m_vin(s_idgen++) {
    std::cout << "Vehicle #" << m_vin << ": Default-ctor" << std::endl;
}

/**
 * Parameterized constructor for Vehicle
 *
 * Assign vin to m_vin if greater than any previously used vin, otherwise generate new
 *
 * @param vin int vin number to assign
 * @param lla float array [latitude, longitude, altitude]
 */
Vehicle::Vehicle(const int vin, const float *lla) : m_vin(validateVIN(vin) ? vin : s_idgen++) {
    std::cout << "Vehicle #" << m_vin << ": Parameterized-ctor" << std::endl;
    setLLA(lla);
}

/**
 * Copy constructor for Vehicle
 *
 * m_vin is assigned current value of s_idgen
 *
 * @param vehicle A Vehicle object to copy
 */
Vehicle::Vehicle(const Vehicle &vehicle) : m_vin(s_idgen++) {
    std::cout << "Vehicle #" << m_vin << ": Copy-ctor" << std::endl;
    setLLA(vehicle.m_lla);
}

/**
 * Destructor for Vehicle
 */
Vehicle::~Vehicle() {
    std::cout << "Vehicle #" << m_vin << ": Dtor" << std::endl;
}

/**
 * Assignment operator overload for Vehicle
 *
 * Assigns rhs.m_lla to lhs.m_lla. lhs.m_vin is unchanged
 *
 * @param rhs Vehicle object to assign into lhs
 * @return lhs Vehicle object
 */
Vehicle &Vehicle::operator=(const Vehicle &rhs) {
    std::cout << "Vehicle #" << m_vin << ": Assignment" << std::endl;
    if (this != &rhs) {
        setLLA(rhs.m_lla);
    }
    return *this;
}

/**
 * Get vehicle's m_lla property
 * @return float array [latitude, longitude, altitidue]
 */
const float *Vehicle::getLLA() const {
    return m_lla;
}

/**
 * Get vehicle's m_vin property
 * @return const int vin number
 */
int Vehicle::getVIN() const {
    return m_vin;
}

/**
 * Get Vehicle class's s_idgen property
 * @return static int for id generation
 */
int Vehicle::getIdgen() {
    return s_idgen;
}

/**
 * Check if vin is valid for assignment as a vehicle's m_vin property
 *
 * If vin is greater than or equal to the current value of s_idgen, then vin
 * is a valid vin number. Assign the value of vin into s_idgen in order to
 * disallow any vins to fall between the previous value of s_idgen and its
 * new value.
 *
 * @param vin a constant int representing the vin number to check for validity
 * @return boolean true if valid else false
 */
bool Vehicle::validateVIN(const int vin) {

    // Only ever allow vins to get bigger
    if (vin >= s_idgen) {
        s_idgen = vin;
        s_idgen++;      // must increment, otherwise we might reuse vin in another vehicle
        return true;
    }

    return false;
}

/**
 * Set vehicle's m_lla property
 * @param lla float array
 */
void Vehicle::setLLA(const float *lla) {
    for (int i = 0; i < LLA_LEN; i++) {
        m_lla[i] = lla[i];
    }
}

/**
 * Set vehicle's m_lla property using discrete values
 * @param lat const int latitude
 * @param lng const int longitude
 * @param alt const int altitude
 */
void Vehicle::setLLA(const int lat, const int lng, const int alt) {
    m_lla[0] = lat;
    m_lla[1] = lng;
    m_lla[2] = alt;
}

/**
 * Base class move function -- to be overriden in child classes
 * @param lla float array
 */
void Vehicle::move(const float *lla) {
    std::cout << "Vehicle #" << m_vin << ": CANNOT MOVE - I DON'T KNOW HOW" << std::endl;
}

/**
 * Insertion operator overload for custom object output
 * @param os output stream
 * @param vehicle Vehicle object
 * @return output stream
 */
std::ostream &operator<<(std::ostream &os, const Vehicle &vehicle) {
    std::cout << "Vehicle #" << vehicle.m_vin << " @ [" << vehicle.m_lla[0] << ", " << vehicle.m_lla[1] << ", " << vehicle.m_lla[2] << "]"
              << std::endl;
    return os;
}