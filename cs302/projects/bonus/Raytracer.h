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
        double rise, run, totalX, totalY;

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
        if (theta == 90) {
            rise = 1;
            run = 0;
            return;
        } else if (theta == 270) {
            rise = -1;
            run = 0;
            return;
        }

        rise = std::tan(degreesToRadians(theta));
        run = 1;

        std::cout << "RISE: " << rise << " RUN: " << run << std::endl;

        // If abs(rise) is greater than run, scale rise to 1 and run proportionately
        // The two specific theta checks protect against floating point precision errors
        // which cause the rise > run comparison to succeed incorrectly -- they should be equal
        if ((std::abs(rise) > run) && theta != 315 && theta != 135) {
            run = 1 / rise;
            rise = 1;
        } else if (theta > 90 && theta < 270) {
            rise *= -1;
            run *= -1;
        }

        std::cout << "RISE: " << rise << " RUN: " << run << std::endl;
    }
};

#endif