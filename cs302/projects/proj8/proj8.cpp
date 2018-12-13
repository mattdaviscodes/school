#include <iostream>

#include "LeftLeaningRedBlackTree.h"

const int NUM_VALS = 10;
const int MIN_VAL = 1;
const int MAX_VAL = 100;

int randIntBetween(const int min, const int max);

int main() {
    LeftLeaningRedBlackTree<int> llrbt;
    int toInsert, toDelete;

    srand(time(NULL));
    for (int i = 0; i < NUM_VALS; i++) {
        toInsert = randIntBetween(MIN_VAL, MAX_VAL);
        if (i == 4) {
            toDelete = toInsert;
        }
        std::cout << "INSERTING " << toInsert << std::endl;
        llrbt.add(toInsert);
        llrbt.preorderTraverse();
        std::cout << std::endl;
    }

    std::cout << "DELETING " << toDelete << std::endl;
    llrbt.remove(toDelete);
    llrbt.preorderTraverse();

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