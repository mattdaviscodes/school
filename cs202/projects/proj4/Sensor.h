//
// Created by Matthew Davis on 2/20/18.
//

#ifndef SCHOOL_SENSOR_H
#define SCHOOL_SENSOR_H

#include <iostream>

#include "proj4.h"

using namespace std;

const int MAX_CSTRING_SIZE = 256;
const float SENSOR_COST_GPS = 5.0;
const float SENSOR_COST_CAMERA = 10.0;
const float SENSOR_COST_LIDAR = 15.0;
const float SENSOR_COST_RADAR = 20.0;
const float SENSOR_COST_NONE = 0.0;

class Sensor {

public:
    // Constructors
    Sensor();                       // Default
    Sensor(const char * type);      // Parameterized
    Sensor(const Sensor & sensor);  // Copy

    // Getters
    char * getType();
    float getExtraCost();

    // Setters
    void setType(const char * type);
    void setExtraCost(const float extracost);

    // Static Getters
    static int getGPSCnt();
    static int getCameraCnt();
    static int getLidarCnt();
    static int getRadarCnt();

    // Static Re-setters
    static void resetGPSCnt();
    static void resetCameraCnt();
    static void resetLidarCnt();
    static void resetRadarCnt();

    // Operator overload
    friend ostream & operator<<(ostream & os, const Sensor & sensor);

protected:

private:
    char m_type[MAX_CSTRING_SIZE];
    float m_extracost;
    static int gps_cnt;
    static int camera_cnt;
    static int lidar_cnt;
    static int radar_cnt;

};

// Overload comparison operator as non-member function
bool operator ==(Sensor & s1, Sensor & s2);


#endif //SCHOOL_SENSOR_H
