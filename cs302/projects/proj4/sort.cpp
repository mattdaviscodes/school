#include <iostream>
#include <chrono>

#include "SelectionSorter.h"
#include "MergeSorter.h"

int main() {
    // SELECTION SORT
    int comparisons = 0, swaps = 0;
    SelectionSorter ss(1000);
    ss.readFromFile("data/output_1000.txt");

    auto start = std::chrono::high_resolution_clock::now();
    ss.sort(comparisons, swaps);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;

    std::cout << "SECONDS: " << elapsed.count() << std::endl;
    std::cout << "COMPARISONS: " << comparisons << std::endl;
    std::cout << "SWAPS: " << swaps << std::endl;

    // MERGE SORT
//    int comparisons = 0, swaps = 0;
//    MergeSorter ms(1000);
//    ms.readFromFile("data/output_1000.txt");
//
//    auto start = std::chrono::high_resolution_clock::now();
//    ms.sort(ms.getArr(), 0, ms.getSize() - 1, comparisons, swaps);
//    auto end = std::chrono::high_resolution_clock::now();
//
//    std::chrono::duration<double> elapsed = end - start;
//
//    std::cout << "SECONDS: " << elapsed.count() << std::endl;
//    std::cout << "COMPARISONS: " << comparisons << std::endl;
//    std::cout << "SWAPS: " << swaps << std::endl;

    return 0;
}