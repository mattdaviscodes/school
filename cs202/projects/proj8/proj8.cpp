#include <iostream>

#include "ArrayList.h"
#include "NodeList.h"

using namespace std;

int main() {
    DataType dt1(1, 2.0);
    DataType dt2(2, 4.0);
    DataType dt3(3, 6.0);
    DataType dt4(4, 8.0);
    DataType dt5(5, 10.0);
    NodeList nl(5, dt1);
    Node *tmp = NULL;

    nl[0] = dt2;
    nl[3] = dt3;

    std::cout << nl << std::endl;

    std::cout << std::endl << "INSERTING BEFORE" << std::endl << std::endl;

    nl.insertBefore(dt2, dt4);
    std::cout << nl << std::endl;

    std::cout << std::endl << "DELETING" << std::endl << std::endl;

    while ((tmp = nl.erase(dt1)));

    std::cout << nl << std::endl;

    std::cout << std::endl << "CLEARING" << std::endl << std::endl;

    NodeList nl2;
    nl.clear();
    std::cout << nl << std::endl;

    return 0;

}
