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

    Robot bot;
    bot.setPose(270);
    bot.scan();
    return 0;
}