#include <cstdlib>  // atoi()

#include "Robot.h"

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
    srand(time(NULL));

    const int numScans = 9;
    const int xCoords[numScans] = {1, 157, 77, 70, 73, 99, 378, 685, 683};
    const int yCoords[numScans] = {1, 148, 274, 422, 529, 679, 607, 435, 216};
    const int poses[numScans] = {90, 90, 90, 90, 90, 90, 180, 270, 180};

    Robot bot;

    for (int i = 0; i < numScans; i++) {
        bot.setLocation(xCoords[i], yCoords[i]);
        bot.setPose(poses[i]);
        bot.scan();
    }

    bot.outputGridState();

    return 0;
}