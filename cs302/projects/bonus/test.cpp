#include "ArrayOccupancyGrid.h"
#include "OccupancyGridCell.h"

const int GRID_HEIGHT = 1000;
const int GRID_WIDTH = 1000;

int main() {
    ArrayOccupancyGrid grid(GRID_HEIGHT, GRID_WIDTH);
    grid.toPBM();

    return 0;
}