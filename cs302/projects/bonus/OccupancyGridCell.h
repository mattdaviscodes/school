#ifndef SCHOOL_OCCUPANCY_GRID_CELL_H
#define SCHOOL_OCCUPANCY_GRID_CELL_H

const int DEFAULT_PROB = 0;
const bool DEFAULT_OCC = false;

class OccupancyGridCell {
private:
    // Location of cell in grid
    int x;
    int y;

    // -1 to 1 representing confidence in occupancy or vacancy
    float probability;

    // True occupancy state of cell
    bool occupied;

public:
    OccupancyGridCell(const int x, const int y) : x(x), y(y), probability(DEFAULT_PROB), occupied(DEFAULT_OCC) {}
    OccupancyGridCell(const int x, const int y, const float prob) : x(x), y(y), probability(prob), occupied(DEFAULT_OCC) {}
    OccupancyGridCell(const int x, const int y, const bool occ) : x(x), y(y), probability(DEFAULT_PROB), occupied(occ) {}
    OccupancyGridCell(const int x, const int y, const float prob, const bool occ) : x(x), y(y), probability(prob), occupied(occ) {}

    int getX() { return x; }
    int getY() { return y; }
    float getProbability() { return probability; }
    bool isOccupied() { return occupied; }

    void setProbability() { probability = probability; }
};

#endif