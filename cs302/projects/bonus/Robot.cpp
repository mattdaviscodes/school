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
        std::vector<std::pair<int, int>> ray = tracer.trace(trueAngle, location.second, location.first);
        updateCellsInRay(ray);
    }
}

bool Robot::getCellReading(const int x, const int y) {
    const OccupancyGridCell &cell = grid.getCell(x, y);
    return getCellReading(cell);
}

bool Robot::getCellReading(const OccupancyGridCell& cell) {
    const double randNum = doubleRand();

    if (cell.isOccupied()) {
        return randNum <= OCCUPIED_CONFIDENCE;
    } else {
        return randNum > FREE_CONFIDENCE;
    }
}

void Robot::updateCellsInRay(const std::vector<std::pair<int, int>> ray) {
    for (auto pair : ray) {
        // Stop when we hit the grid bounds
        if (pair.first < 0 || pair.first > grid.getHeight() || pair.second < 0 || pair.second > grid.getWidth())
            return;

        bool reading = getCellReading(pair.first, pair.second);
        updateGridCell(pair.first, pair.second, reading);

        // Need to stop traversing ray after first obstacle hit
        if (reading)
            return;
    }
}

double doubleRand() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}

void Robot::updateGridCell(const int x, const int y, const bool reading) {
    OccupancyGridCell &cell = grid.getCell(x, y);
    updateGridCell(cell, reading);
}

void Robot::updateGridCell(OccupancyGridCell &cell, const bool reading) {
    if (reading) {
        cell.updateProbability(OCCUPIED_CONFIDENCE);
    } else {
        cell.updateProbability(-FREE_CONFIDENCE);
    }
}

void Robot::outputGridState() const {
    grid.toPBM();
}