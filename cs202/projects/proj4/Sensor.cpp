//
// Created by Matthew Davis on 2/20/18.
//

#include <iostream>

#include "Sensor.h"
#include "proj4.h"

using namespace std;

// Define static variables
int Sensor::gps_cnt = 0;
int Sensor::camera_cnt = 0;
int Sensor::lidar_cnt = 0;
int Sensor::radar_cnt = 0;

// Constructors
Sensor::Sensor() {
    setType("none");
};
Sensor::Sensor(const char * type) {
    setType(type);
};
Sensor::Sensor(const Sensor & sensor) {
    setType(sensor.m_type);
};

// Getters
char * Sensor::getType() { return m_type; };
float Sensor::getExtraCost() { return m_extracost; };

// Setters
void Sensor::setType(const char * type) {

    // Hacked switch statement to track
    // instantiated sensors of each type.
    if (!myStringCompare(type, "gps")) {
        Sensor::gps_cnt++;
        setExtraCost(SENSOR_COST_GPS);
    } else if (!myStringCompare(type, "camera")) {
        Sensor::camera_cnt++;
        setExtraCost(SENSOR_COST_CAMERA);
    } else if (!myStringCompare(type, "lidar")) {
        Sensor::lidar_cnt++;
        setExtraCost(SENSOR_COST_LIDAR);
    } else if (!myStringCompare(type, "radar")) {
        Sensor::radar_cnt++;
        setExtraCost(SENSOR_COST_RADAR);
    } else {
        // "none" type
        setExtraCost(SENSOR_COST_NONE);
    }

    // No error checking, so we'll have problems if
    // type is an invalid string
    myStringCopy(m_type, type);
};
void Sensor::setExtraCost(const float extracost) { m_extracost = extracost; };

// Static Getters
int Sensor::getGPSCnt() { return Sensor::gps_cnt; };
int Sensor::getCameraCnt() { return Sensor::camera_cnt; };
int Sensor::getLidarCnt() { return Sensor::lidar_cnt; };
int Sensor::getRadarCnt() { return Sensor::radar_cnt; };

// Static Re-setters
void Sensor::resetGPSCnt() { Sensor::gps_cnt = 0; };
void Sensor::resetCameraCnt() { Sensor::camera_cnt = 0; };
void Sensor::resetLidarCnt() { Sensor::lidar_cnt = 0; };
void Sensor::resetRadarCnt() { Sensor::radar_cnt = 0; };

// Operator overload
ostream & operator<<(ostream & os, const Sensor & sensor) {
    os << "Sensor(m_type=" << sensor.m_type << ", m_extracost=" << sensor.m_extracost << ", gps_cnt="
       << Sensor::getGPSCnt() << ", camera_cnt=" << Sensor::getCameraCnt() << ", lidar_cnt=" << Sensor::getLidarCnt()
       << ", radar_cnt=" << Sensor::getRadarCnt() << ")";

    return os;
};

// Overload comparison operator as non-member function
bool operator ==(Sensor & s1, Sensor & s2) {
    return !myStringCompare(s1.getType(), s2.getType());
}
