#ifndef RAYTRACER_SCHOOL_
#define RAYTRACER_SCHOOL_

#include <vector>
#include <utility>  // std::pair
#include <cmath>    // tan
#include <math.h> // PI

const int MAX_STEPS = 10;

class Raytracer {
private:

    double degreesToRadians(double angle_in_degrees){
        return angle_in_degrees * (M_PI / 180.0);
    }

public:
    std::vector<std::pair<int, int>> trace(const double theta, const int startX, const int startY) {
        std::vector<std::pair<int, int>> coordPairs;
        int step = 1;
        int x, y;
        double rise, run;

        getRiseRun(theta, rise, run);

        while (step <= MAX_STEPS) {
            // Intentionally truncate to int
            x = run * step + startX;
            y = rise * step + startY;

            coordPairs.push_back(std::make_pair(x, y));
            step++;
        }

        return coordPairs;
    }

    void getRiseRun (int theta, double &rise, double &run) {
        // This is such a hack. Hard coding specific angles that were giving me trouble.
        switch (theta) {
            case 0  : rise = 0; run = 1; return;
            case 45 : rise = 1; run = 1; return;
            case 90 : rise = 1; run = 0; return;
            case 135: rise = 1; run = -1; return;
            case 180: rise = 0; run = -1; return;
            case 225: rise = -1; run = -1; return;
            case 270: rise = -1; run = 0; return;
            case 315: rise = -1; run = 1; return;
        }

        rise = std::tan(degreesToRadians(theta));
        run = 1;

        // If theta is in quadrant 2 or 3, we flip the signs of rise and run so ray oriented correctly
        if (theta > 90 && theta < 270) {
            rise = -rise;
            run = -run;
        }

        // If abs(rise) is greater than run, scale rise to 1 and run proportionately
        // The two specific theta checks protect against floating point precision errors
        // which cause the rise > run comparison to succeed incorrectly -- they should be equal
        if ((std::abs(rise) > std::abs(run))) {
            double oldRise = rise;
            if (rise >= 0) {
                rise = 1;
                run = (run * rise) / oldRise;
            } else {
                rise = -1;
                run = (run * rise) / oldRise;
            }
        }
    }
};

#endif