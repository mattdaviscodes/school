#include <string>
#include <iostream>
#include <fstream>

#include "MergeSorter.h"

MergeSorter::MergeSorter(const int maxSize) : size(0), maxSize(maxSize) {
    arr = new int[maxSize];
}

int MergeSorter::readFromFile(const std::string &filename) {
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

bool MergeSorter::writeToFile(const std::string &filename) const {
    std::ofstream outfile;
    outfile.open(filename);
    for (int i = 0; i < size; i++) {
        outfile << arr[i] << std::endl;
    }
    return true;
}

// MERGE SORT
void MergeSorter::sort(int *array, int first, int last, int &comparisons, int &swaps) {
    if (first < last) {
        int mid = first + (last - first) / 2;
        sort(array, first, mid, comparisons, swaps);
        sort(array, mid + 1, last, comparisons, swaps);
        merge(array, first, mid, last, comparisons, swaps);
    }
}

void MergeSorter::merge(int *array, int first, int mid, int last, int &comparisons, int &swaps) {
    int i, j, k;
    int n1 = mid - first + 1;
    int n2 = last - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        swaps++;
        L[i] = array[first + i];
    }
    for (j = 0; j < n2; j++) {
        swaps++;
        R[j] = array[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = first;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            swaps++;
            array[k] = L[i];
            i++;
        } else {
            swaps++;
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        comparisons++;
        swaps++;
        array[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        comparisons++;
        swaps++;
        array[k] = R[j];
        j++;
        k++;
    }
}

void MergeSorter::show() const {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int *MergeSorter::getArr() const {
    return arr;
}

int MergeSorter::getSize() const {
    return size;
}