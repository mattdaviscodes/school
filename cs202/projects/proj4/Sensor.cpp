//
// Created by Matthew Davis on 2/20/18.
//

#include "Sensor.h"

// Constructors
Sensor::Sensor() {

};
Sensor::Sensor(const char * type) {

};
Sensor::Sensor(const Sensor & sensor) {

};

// Static Getters
int Sensor::getGPSCnt() { return gps_cnt; };
int Sensor::getCameraCnt() { return camera_cnt; };
int Sensor::getLidarCnt() { return lidar_cnt; };
int Sensor::getRadarCnt() { return radar_cnt; };

// Static Re-setters
void Sensor::resetGPSCnt() { gps_cnt = 0; };
void Sensor::resetCameraCnt() { camera_cnt = 0; };
void Sensor::resetLidarCnt() { lidar_cnt = 0; };
void Sensor::resetRadarCnt() { radar_cnt = 0; };
