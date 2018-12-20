#ifndef SCHOOL_ARRAY_OCCUPANCY_GRID_H
#define SCHOOL_ARRAY_OCCUPANCY_GRID_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

#include "OccupancyGridCell.h"

const int DEFAULT_GRID_WIDTH = 1000;
const int DEFAULT_GRID_HEIGHT = 1000;

class ArrayOccupancyGrid {
private:
    int height;
    int width;

    std::vector<std::vector<OccupancyGridCell>> grid;

public:
    // Just forwards on to param ctor with defaults
    ArrayOccupancyGrid();
    ArrayOccupancyGrid(const int height, const int width);

    void toPBM() const;

    OccupancyGridCell& getCell(const int x, const int y);

    int getGridSize() const;

    int getHeight() const;
    int getWidth() const;
};

#endif