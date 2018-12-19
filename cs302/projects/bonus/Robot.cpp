#include "Robot.h"

Robot::Robot() : location(std::make_pair(DEFAULT_X, DEFAULT_Y)), pose(DEFAULT_POSE) {

}

Robot::Robot(const int x, const int y) : location(std::make_pair(x, y)), pose(DEFAULT_POSE) {

}

Robot::Robot(const int x, const int y, const int currPose) : location(std::make_pair(x, y)), pose(currPose) {

}

std::pair<int, int> Robot::getLocation() const {
    return location;
}

int Robot::getPose() const {
    return pose;
}

void Robot::setLocation(const int x, const int y) {
    location = std::make_pair(x, y);
}

void Robot::setPose(const int currPose) {
    pose = currPose;
}

void Robot::scan() {
    for (auto angle : RAY_ANGLES) {
        int trueAngle = (angle + pose) % 360;
        std::vector<std::pair<int, int>> ray = tracer.trace(trueAngle, location.first, location.second);
    }
}

bool Robot::getCellReading(const int x, const int y) {
    const OccupancyGridCell cell = grid[x][y];
    const double randNum = doubleRand();

    if (cell.isOccupied()) {
        return randNum <= OCCUPIED_CONFIDENCE;
    } else {
        return randNum <= FREE_CONFIDENCE;
    }
}

double doubleRand() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}