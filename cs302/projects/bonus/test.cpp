#include "ArrayOccupancyGrid.h"
#include "OccupancyGridCell.h"
#include "Raytracer.h"

const int GRID_HEIGHT = 1000;
const int GRID_WIDTH = 1000;

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

//    float m = std::tan(degreesToRadians(30));
//    std::cout << m * 100<< std::endl;

    Raytracer rt;
    std::vector<std::pair<int, int>> vec = rt.trace(240, 500, 500);


//    int i = 0;
//    std::cout << vec[i].first << std::endl;

    std::cout << "STEP\tX\tY" << std::endl;
    int counter = 1;
    for (auto i = vec.begin(); i != vec.end(); i++) {
        std::cout << counter++ << "\t" << i->first << "\t" << i->second << std::endl;
    }

//    std::vector<std::pair<int, int>> test;
//    test.push_back(std::make_pair(0, 1));
//    test.push_back(std::make_pair(1, 2));
//    test.push_back(std::make_pair(2, 3));
//
//    for (auto i = test.begin(); i != test.end(); i++) {
//        std::cout << i->first << std::endl;
//    }




//    double rise = 0, run = 0;
//    std::cout << "Degrees" << "\t" << "Rise" << "\t\t" << "Run" << std::endl;
//    for (int i = 0; i <= 90; i += 5) {
//        rt.getRiseRun(i, rise, run);
//        std::cout << i << "\t" << rise << "\t\t" << run << std::endl;
//    }

//    std::cout << std::tan(degreesToRadians(90)) << std::endl;

//    const int RUN = 1;
//    const float RISE = 0.5774;
//    double fracpart, intpart, totalRise;
//
//    std::cout << "STEP" << "\t" << "X" << "\t" << "Y" << "\t" << "REMAINING" << "\t" << std::endl;
//    for (int i = 1; i <= 10; i++) {
//        totalRise = RISE * i;
//        fracpart = modf(totalRise, &intpart);
//
//        std::cout << i << "\t" << RUN * i << "\t" << intpart << "\t" << fracpart << "\t" << std::endl;
//    }

//    std::cout << 1 / 0.5774 << std::endl;
//    std::cout << 2 / 1.1548 << std::endl;
//    std::cout << 1.7322 / 3 << std::endl;
//    std::cout << 2.3096 / 4 << std::endl;
//    std::cout << 2.887 / 5 << std::endl;
//    std::cout << 3.4644 / 6 << std::endl;
//    std::cout << 4.0418 / 7 << std::endl;
//    std::cout << 4.6192 / 8 << std::endl;
//    std::cout << 5.1966 / 9 << std::endl;
//    std::cout << 5.774 / 10 << std::endl;


    return 0;
}