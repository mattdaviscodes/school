#ifndef SCHOOL_ARRAY_OCCUPANCY_GRID_H
#define SCHOOL_ARRAY_OCCUPANCY_GRID_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

#include "OccupancyGridInterface.h"
#include "OccupancyGridCell.h"

const int DEFAULT_GRID_WIDTH = 1000;
const int DEFAULT_GRID_HEIGHT = 1000;

class ArrayOccupancyGrid : public OccupancyGridInterface {
private:
    int height;
    int width;

    std::vector<std::vector<OccupancyGridCell>> grid;

public:
    // Just forwards on to param ctor with defaults
    ArrayOccupancyGrid() : ArrayOccupancyGrid(DEFAULT_GRID_HEIGHT, DEFAULT_GRID_WIDTH) {}

    ArrayOccupancyGrid(const int height, const int width) : height(height), width(width) {
        for (int i = 0; i < height; i++) {
            grid.push_back(std::vector<OccupancyGridCell>());
            for (int j = 0; j < width; j++) {
                // TODO - These probably shouldn't be hardcoded. Maybe add a function called addKnownObstacle?
                OccupancyGridCell newCell(i, j);
                if (i >= 250 && i <= 500 && j >= 250 && j <= 500) {
                    newCell.setOccupied(true);
                }
                grid[i].push_back(newCell);
            }
        }
    }

    void toPBM() const {
        std::ofstream outfile("./out.pbm");

        // write outfile header
        outfile << "P1" << std::endl;
        outfile << width << " " << height << std::endl;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                outfile << !grid[i][j].isOccupied() << " ";
            }
            outfile << std::endl;
        }
    }

    std::vector<OccupancyGridCell> operator[](int i) {
        return grid[i];
    }

    // TODO: Clean up on destroy
    // ~ArrayOccupancyGrid();

    int getGridSize() const {
        return height * width;
    }
};

#endif