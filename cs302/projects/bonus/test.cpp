#include "ArrayOccupancyGrid.h"
#include "OccupancyGridCell.h"

#include <cmath>

#define PI 3.14159265359

const int GRID_HEIGHT = 1000;
const int GRID_WIDTH = 1000;

double degreesToRadians(double angle_in_degrees){
    return angle_in_degrees * (PI / 180.0);
}

/**
 * https://stackoverflow.com/questions/35807686/find-cells-in-array-that-are-crossed-by-a-given-line-segment
 *
 * This question outlines a process to use a line to find all cells intersected by that line. It talks
 * about a "parametric equation." Not sure how to solve this thing.
 *
 * https://stackoverflow.com/questions/35807686/find-cells-in-array-that-are-crossed-by-a-given-line-segment
 *
 * This link seems to describe how to solve the parametric equation for lines.
 */

int main() {
//    ArrayOccupancyGrid grid(GRID_HEIGHT, GRID_WIDTH);
//    grid.toPBM();

    float m = std::tan(degreesToRadians(30));
    std::cout << m * 100<< std::endl;

    return 0;
}