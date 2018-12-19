#ifndef ROBOT_SCHOOL_
#define ROBOT_SCHOOL_

#include <vector>
#include <utility>  // std::pair
#include <cstdlib>
#include <ctime>
#include <random>

#include "ArrayOccupancyGrid.h"
#include "Raytracer.h"

const int DEFAULT_X = 0;
const int DEFAULT_Y = 0;
const int DEFAULT_POSE = 0;

const int RAY_DISTANCE = 50;
const std::vector<int> RAY_ANGLES = {90, 75, 60, 45, 30, 15, 0, 345, 330, 315, 300, 285, 270};

const double OCCUPIED_CONFIDENCE = 0.9;
const double FREE_CONFIDENCE = 0.7;

// Get random double in range 0.0 to 1.0
double doubleRand();

class Robot {
private:
    ArrayOccupancyGrid grid;

    Raytracer tracer;

    // Current location of robot pair(xCoord, yCoor)
    std::pair<int, int> location;

    // Current pose of robot in degrees
    int pose;

protected:
    void updateGridCell(const int x, const int y);
    bool getCellReading(const int x, const int y);

public:
    Robot();
    Robot(const int x, const int y);
    Robot(const int x, const int y, const int currPose);

    std::pair<int, int> getLocation() const;
    int getPose() const;

    void setLocation(const int x, const int y);
    void setPose(const int currPose);

    void scan();
};

#endif