#ifndef SCHOOL_OCCUPANCY_GRID_INTERFACE_H
#define SCHOOL_OCCUPANCY_GRID_INTERFACE_H

class OccupancyGridInterface {
    // Grid dimension getters
    virtual int getGridSize() const = 0;
//    virtual int getGridHeight() const = 0;
//    virtual int getGridWidth() const = 0;
};

#endif