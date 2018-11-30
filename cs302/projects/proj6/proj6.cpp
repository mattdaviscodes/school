#include "BinarySearchTree.h"

#include <iostream>
#include <fstream>
#include <string>

const int NUM_VALS = 100;
const int MIN_VAL = 1;
const int MAX_VAL = 200;

int randIntBetween(const int min, const int max);

int main() {
    BinarySearchTree<int> bst;
    int rand_num;

    std::ofstream outfile;
    std::string filename = "generated_numbers.txt";
    outfile.open(filename);

    srand(time(NULL));
    for (int i = 0; i < NUM_VALS; i++) {
        rand_num = randIntBetween(MIN_VAL, MAX_VAL);
        outfile << rand_num << std::endl;
        bst.add(rand_num);
    }

    std::cout << "HEIGHT: " << bst.getHeight() << std::endl;
    bst.preorderTraverse();
    bst.inorderTraverse();
    bst.postorderTraverse();

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