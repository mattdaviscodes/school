#ifndef SCHOOL_SELECTIONSORTER_H
#define SCHOOL_SELECTIONSORTER_H

#include "SorterInterface.h"

class SelectionSorter : public SorterInterface<int> {
public:
    SelectionSorter(const int maxSize);

    // Methods from interface below
    int readFromFile(const std::string &filename);
    bool writeToFile(const std::string &filename) const;
    void sort(int &comparisons, int &swaps);

    void show() const;

private:
    int *arr;
    int size;
    int maxSize;

    int findIndexOfLargest(const int maxIndex, int &comparisons) const;
};

#endif //SCHOOL_SELECTIONSORTER_H