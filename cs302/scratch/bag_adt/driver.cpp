#include <iostream>
#include <vector>

#include "ArrayBag.h"

int main() {
    ArrayBag<int> bag;
    std::cout << bag.isEmpty() << std::endl;

    std::vector<int> bagItems = bag.toVector();
    std::cout << bagItems.size() << std::endl;

    bag.add(1);
    bag.add(2);
    bag.add(3);
    bag.add(3);
    bag.add(3);
    bag.add(3);
    bag.add(3);
    std::cout << bag.getCurrentSize() << std::endl;

    bag.remove(5);
    std::cout << bag.getCurrentSize() << std::endl;

    bag.remove(1);
    std::cout << bag.getCurrentSize() << std::endl;

    while (bag.remove(3)) {
    }
    std::cout << bag.getCurrentSize() << std::endl;

    bag.add(3);
    bag.add(3);
    bag.add(3);
    std::cout << bag.getCurrentSize() << std::endl;

    bag.clear();
    std::cout << bag.getCurrentSize() << std::endl;

    bag.add(1);
    bag.add(2);
    std::cout << bag.getCurrentSize() << std::endl;

    return 0;
}