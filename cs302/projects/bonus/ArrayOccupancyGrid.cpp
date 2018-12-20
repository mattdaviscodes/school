#include "ArrayOccupancyGrid.h"

// Just forwards on to param ctor with defaults
ArrayOccupancyGrid::ArrayOccupancyGrid() : ArrayOccupancyGrid(DEFAULT_GRID_HEIGHT, DEFAULT_GRID_WIDTH) {}

ArrayOccupancyGrid::ArrayOccupancyGrid(const int height, const int width) : height(height), width(width) {
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

void ArrayOccupancyGrid::toPBM() const {
    std::ofstream outfile("./out.pgm");

    // write outfile header
    outfile << "P2" << std::endl;
    outfile << width << " " << height << std::endl;

    outfile << 255 << std::endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            double prob = grid[i][j].getProbability();

            if (prob == 0) {
                outfile << 127 << " ";
            } else if (prob > 0) {
                outfile << 255 << " ";
            } else {
                outfile << 0 << " ";
            }
        }
        outfile << std::endl;
    }
}

OccupancyGridCell& ArrayOccupancyGrid::getCell(const int x, const int y) {
    return grid[x][y];
}

int ArrayOccupancyGrid::getHeight() const {
    return height;
}

int ArrayOccupancyGrid::getWidth() const {
    return width;
}