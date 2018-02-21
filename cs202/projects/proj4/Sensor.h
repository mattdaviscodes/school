//
// Created by Matthew Davis on 2/20/18.
//

#ifndef SCHOOL_SENSOR_H
#define SCHOOL_SENSOR_H

const int MAX_CSTRING_SIZE = 256;


class Sensor {

public:
    // Constructors
    Sensor();                       // Default
    Sensor(const char * type);      // Parameterized
    Sensor(const Sensor & sensor);  // Copy

    // Getters

    // Setters

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

protected:

private:
    char m_type[MAX_CSTRING_SIZE];
    float m_extracost;
    static int gps_cnt;
    static int camera_cnt;
    static int lidar_cnt;
    static int radar_cnt;

};


#endif //SCHOOL_SENSOR_H
