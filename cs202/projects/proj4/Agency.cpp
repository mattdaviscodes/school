//
// Created by Matthew Davis on 2/24/18.
//

#include "Agency.h"
#include "proj4.h"

// Default constructor
Agency::Agency() :
    m_zipcode(DEFAULT_ZIPCODE)
{
}

// Getters
const char* Agency::getName() const {
    return m_name;
}

const int Agency::getZipcode() const {
    return m_zipcode;
}

// Setters
void Agency::setName(const char* name) {
    myStringCopy(m_name, name);
}

// Operator overload
Car & Agency::operator[](int i) {
    return m_inventory[i];
}

// Other
void Agency::readAllData() {

}

// Friends
std::istream& operator>>(std::istream& is, Agency& agency) {
    is >> agency.m_name >> agency.m_zipcode;
    return is;
}