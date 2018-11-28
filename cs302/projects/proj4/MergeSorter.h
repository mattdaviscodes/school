#ifndef SCHOOL_MERGESORTER_H
#define SCHOOL_MERGESORTER_H

#include "SorterInterface.h"

class MergeSorter : public SorterInterface<int> {
public:
    MergeSorter(const int maxSize);

    // Methods from interface below
    int readFromFile(const std::string &filename);
    bool writeToFile(const std::string &filename) const;
    void sort(int *array, int first, int last, int &comparisons, int &swaps);

    void show() const;
    int *getArr() const;
    int getSize() const;

private:
    int *arr;
    int size;
    int maxSize;

    void merge(int *array, int first, int mid, int last, int &comparisons, int &swaps);
};

#endif //SCHOOL_MERGESORTER_H