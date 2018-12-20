#ifndef SCHOOL_OCCUPANCY_GRID_CELL_H
#define SCHOOL_OCCUPANCY_GRID_CELL_H

const double DEFAULT_PROB = 0;
const bool DEFAULT_OCC = false;

class OccupancyGridCell {
private:
    // Location of cell in grid
    int x;
    int y;

    // Logodd of combined measurements representing confidence in occupancy or vacancy
    double probability;

    // True occupancy state of cell
    bool occupied;

public:
    OccupancyGridCell(const int x, const int y) : x(x), y(y), probability(DEFAULT_PROB), occupied(DEFAULT_OCC) {}
    OccupancyGridCell(const int x, const int y, const double prob) : x(x), y(y), probability(prob), occupied(DEFAULT_OCC) {}
    OccupancyGridCell(const int x, const int y, const bool occ) : x(x), y(y), probability(DEFAULT_PROB), occupied(occ) {}
    OccupancyGridCell(const int x, const int y, const double prob, const bool occ) : x(x), y(y), probability(prob), occupied(occ) {}

    int getX() const { return x; }
    int getY() const { return y; }
    double getProbability() const { return probability; }
    bool isOccupied() const { return occupied; }

    void setProbability(const double newProb) { probability = newProb; }
    void setOccupied(const bool occ) { occupied = occ; }

    void updateProbability(double probIncrement) { probability += probIncrement; }
};

#endif