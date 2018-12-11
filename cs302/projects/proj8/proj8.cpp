#include <iostream>

#include "LeftLeaningRedBlackTree.h"

const int NUM_VALS = 10;
const int MIN_VAL = 1;
const int MAX_VAL = 100;

int randIntBetween(const int min, const int max);

int main() {
    LeftLeaningRedBlackTree<int> llrbt;

    RedBlackNode<int> node(5);

    node.setColor(BLACK);
    std::cout << node.getColor() << std::endl;

//    srand(time(NULL));
    for (int i = 0; i < 11; i++) {
        llrbt.add(randIntBetween(MIN_VAL, MAX_VAL));
        llrbt.preorderTraverse();
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