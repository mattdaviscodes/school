//
// Created by Matthew Davis on 2/24/18.
//

#include <fstream>

#include "Agency.h"
#include "proj4.h"

using namespace std;

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
    ifstream inf;
    char filename[MAX_CSTRING_SIZE];

    cout << "Infile name: ";
    cin >> filename;

    inf.open(filename);
    if (inf) {
        inf >> *this;
    } else {
        cerr << "Unable to open file " << filename << endl;
    }

    inf.close();
}

void Agency::printAllData() {
    cout << *this;
}

void Agency::printSensorCounts() {
    char sensorType[MAX_CSTRING_SIZE];
    int sensorCount = 0, gpsCount = 0, cameraCount = 0, lidarCount = 0, radarCount = 0;
    Car * inventory_ptr = m_inventory;
    Sensor * sensors_ptr;

    for (int i = 0; i < INVENTORY_SIZE; i++,  inventory_ptr++) {      // For Each Car

        sensors_ptr = inventory_ptr->getSensors();

        for (int j = 0; j < inventory_ptr->getSensorCount(); j++, sensors_ptr++) {   // For Each Sensor

            // Track total number of sensors in inventory
            sensorCount++;

            // Track number of each type of sensor also
            myStringCopy(sensorType, sensors_ptr->getType());
            if (!myStringCompare(sensorType, "gps")) {
                gpsCount++;
            } else if (!myStringCompare(sensorType, "camera")) {
                cameraCount++;
            } else if (!myStringCompare(sensorType, "lidar")) {
                lidarCount++;
            } else if (!myStringCompare(sensorType, "radar")) {
                radarCount++;
            }
        }
    }

    cout << "Total Sensors: " << sensorCount << endl;
    cout << "GPS: " << gpsCount << " | " << "Camera: " << cameraCount << " | " << "Lidar: " << lidarCount << " | "
         << "Radar: " << radarCount << endl;
}

void Agency::findMostExpensiveCar() {
    Car * mostExpensiveCar;
    Car * inventory_ptr = m_inventory;

    for (int i = 0; i < INVENTORY_SIZE; i++, inventory_ptr++) {
        if (inventory_ptr->getAvailable()) {

            // If we haven't found an mostExpensive car yet, take the first available.
            // Otherwise, replace if current car is more expensive.
            if (!mostExpensiveCar || (inventory_ptr->getFinalPrice() > mostExpensiveCar->getFinalPrice())) {
                mostExpensiveCar = inventory_ptr;
            }
        }
    }

    if (mostExpensiveCar) {
        cout << "Most expensive available car: " << endl;
        cout << *mostExpensiveCar << endl;
        mostExpensiveCar->promptRent();
    } else {
        cout << "Sorry, there are no available cars." << endl;
    }
}

void Agency::printAvailableCars() {
    Car * inventory_ptr = m_inventory;

    cout << "Available cars: " << endl;
    for (int i = 0; i < INVENTORY_SIZE; i++, inventory_ptr++) {
        if (inventory_ptr->getAvailable()) {
            cout << *inventory_ptr << endl;
        }
    }
}

// Friends
std::istream& operator>>(std::istream& is, Agency& agency) {
    is >> agency.m_name >> agency.m_zipcode;

    for (int i = 0; i < INVENTORY_SIZE; i++) {
        is >> agency[i];
    }
    return is;
}

std::ostream & operator<<(std::ostream & os, Agency & agency) {
    os << agency.m_name << " " << agency.m_zipcode << endl;

    for (int i = 0; i < INVENTORY_SIZE; i++) {
        os << agency[i] << endl;
    }

    return os;
}