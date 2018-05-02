//
// Created by Matthew Davis on 4/26/18.
//

#include "TplMatrix.h"

int main() {
    TplMatrix<int> t1(2, 2, 5);
    TplMatrix<double> t2(2, 2, 3.333);
    TplMatrix<char> t3(2, 2, 'A');

    std::cout << t1 << std::endl;
    std::cout << t2 << std::endl;
    std::cout << t3 << std::endl;

    t1 = t3;
    return 0;
}
