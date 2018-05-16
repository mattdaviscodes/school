#include <iostream>
#include <fstream>

#include <vector>

#include "VectorRecursion.h"


int main() {
    // Vector creation
    std::vector<int> vecInt;

    // Vector population with input values
    std::ifstream fin("RandomData.txt");
    for (int i = 0; i < 100; i++) {
        int fin_in;
        fin >> fin_in;
        if (!fin)
            break;
        vecInt.push_back(fin_in);
    }

    std::vector<int> vecIntCpy(vecInt);

    std::cout << "SORTING" << std::endl << std::endl;
    vector_resort(vecInt, vecInt.size());

    std::cout << "SEARCHING" << std::endl;
    std::cout << "int 117 found at index " << vector_research(vecInt, 117, 0, vecInt.size()) << std::endl << std::endl;

    for (size_t i = 0; i < vecInt.size(); ++i) {
        std::cout << vecInt[i] << std::endl;
    }

    return 0;
}
