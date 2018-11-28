#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>

int randIntBetween(const int min, const int max);

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cout << "Usage: ./genRand min max count" << std::endl;
        return -1;
    }

    int min = 0;
    int max = 0;
    int count = 0;
    try {
        min = std::stoi(argv[1]);
        max = std::stoi(argv[2]);
        count = std::stoi(argv[3]);
    } catch (const std::invalid_argument &ia) {
        std::cout << "ERROR: All command line arguments must be integers" << std::endl;
        std::cout << "Usage: ./genRand min max count" << std::endl;
        return -2;
    }

    // Seed rng
    srand(time(NULL));

    std::ofstream outfile;
    std::string filename = "output_" + std::to_string(count) + ".txt";
    outfile.open(filename);

    for (int i = 0; i < count; i++) {
        outfile << randIntBetween(min, max) << std::endl;
    }

    return 0;
}

/**
 * Generate a random integer between min (inclusive) and max (exclusive)
 * @return Generated int
 */
int randIntBetween(const int min, const int max) {
    int diff = max - min;
    return (rand() % diff) + min;
}