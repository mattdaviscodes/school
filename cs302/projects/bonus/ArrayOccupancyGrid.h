#ifndef SCHOOL_ARRAY_OCCUPANCY_GRID_H
#define SCHOOL_ARRAY_OCCUPANCY_GRID_H

#include <iostream>
#include <fstream>
#include <cmath>

#include "OccupancyGridInterface.h"
#include "OccupancyGridCell.h"

void getXYStep(const float m) {

}

class ArrayOccupancyGrid : public OccupancyGridInterface {
private:
    int height;
    int width;

    OccupancyGridCell*** grid;

public:
    ArrayOccupancyGrid(const int height, const int width) : height(height), width(width) {
        grid = new OccupancyGridCell**[height];
        for (int i = 0; i < height; i++) {
            grid[i] = new OccupancyGridCell*[width];
            for (int j = 0; j < width; j++) {
                if (i >= 250 && i <= 500 && j >= 250 && j <= 500) {
                    grid[i][j] = new OccupancyGridCell(i, j, true);
                } else {
                    grid[i][j] = new OccupancyGridCell(i, j);
                }
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
                outfile << !grid[i][j]->isOccupied() << " ";
            }
            outfile << std::endl;
        }
    }

    void raytrace(const int x, const int y, const int degrees) {
        float m = std::tan(degrees);
    }

    // TODO: Clean up on destroy
    // ~ArrayOccupancyGrid();

    int getGridSize() const {
        return height * width;
    }
};

#endif