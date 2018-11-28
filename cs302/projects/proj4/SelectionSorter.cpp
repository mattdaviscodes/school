#include <string>
#include <iostream>
#include <fstream>

#include "SelectionSorter.h"


SelectionSorter::SelectionSorter(const int maxSize) : size(0), maxSize(maxSize) {
    arr = new int[maxSize];
}

int SelectionSorter::readFromFile(const std::string &filename) {
    std::ifstream file;
    file.open(filename);

    int i = 0;
    while (file && i < maxSize) {
        file >> arr[i];
        i++;
        size++;
    }

    return i;
}

bool SelectionSorter::writeToFile(const std::string &filename) const {
    return false;
}

void SelectionSorter::sort(int &comparisons, int &swaps) {
    for (int last = size - 1; last >= 1; last--) {
        int largest = findIndexOfLargest(last + 1, comparisons);
        std::swap(arr[largest], arr[last]);
        swaps++;
    }
}

void SelectionSorter::show() const {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int SelectionSorter::findIndexOfLargest(const int maxIndex, int &comparisons) const {
    int indexSoFar = 0;
    for (int currentIndex = 1; currentIndex < maxIndex; currentIndex++) {
        comparisons++;
        if (arr[currentIndex] > arr[indexSoFar]) {
            indexSoFar = currentIndex;
        }
    }

    return indexSoFar;
}