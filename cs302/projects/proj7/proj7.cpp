#include <iostream>
#include <algorithm>

const int NUM_VALS = 100;
const int MIN_VAL = 1;
const int MAX_VAL = 200;

int randIntBetween(const int min, const int max);
int meanOfVector(std::vector<int> &vec);
void printVector(std::vector<int> &vec, const char *label);

int main() {
    // 1. Make a heap consisting of 100 random integers
    std::vector<int> vec;
    srand(time(NULL));
    for (int i = 0; i < NUM_VALS; i++) {
        vec.push_back(randIntBetween(MIN_VAL, MAX_VAL));
    }
    printVector(vec, "INITIAL RANDOM VALUES");
    std::make_heap(vec.begin(), vec.end());
    printVector(vec, "INITIAL MAX HEAP");

    // 2. Add a new value that is the mean of the random values you
    // created in the previous step. Floor the value if needed.
    int vecMean = meanOfVector(vec);
    vec.push_back(vecMean);
    std::push_heap(vec.begin(), vec.end());
    printVector(vec, "ADD FLOORED MEAN VALUE");

    // 3. Delete the maximum element of the heap
    std::pop_heap(vec.begin(), vec.end());
    vec.pop_back();
    printVector(vec, "DELETE MAX ELEMENT");

    // 4. Sort the heap
    std::make_heap(vec.begin(), vec.end());
    printVector(vec, "RESORT HEAP");

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

int meanOfVector(std::vector<int> &vec) {
    int mean = 0;
    for (int i = 0; i < vec.size(); i++) {
        mean += vec[i];
    }
    return mean / vec.size();
}

void printVector(std::vector<int> &vec, const char *label) {
    std::cout << label << std::endl;
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl << std::endl;
}