#ifndef SCHOOL_ARRAYBAG_H
#define SCHOOL_ARRAYBAG_H

#include <vector>

#include "BagInterface.h"

template<class ItemType>
class ArrayBag : public BagInterface<ItemType> {
public:
    ArrayBag();
    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& anEntry);
    void clear();
    bool contains(const ItemType& anEntry) const;
    int getFrequencyOf(const ItemType& anEntry) const;
    int getIndexOf(const ItemType& anEntry) const;
    std::vector<ItemType> toVector() const;

private:
    static const int DEFUAULT_CAPACITY = 6;
    ItemType items[DEFUAULT_CAPACITY];
    int itemCount;
    int maxItems;
};

/**
 * NOTE TO FUTURE MATT BECAUSE HE'S DUMB
 * If the implemented of templated classes is separated from its definition (as in .h and .cpp files),
 * it is common to see undefined reference errors such as below:
 *
 *      g++ -Wall -std=c++11 -c driver.cpp -o driver.o
 *      g++ -Wall -std=c++11 -c ArrayBag.cpp -o ArrayBag.o
 *      g++ -Wall -std=c++11 driver.o ArrayBag.o  -o driver
 *   -> driver.o:(.rodata._ZTV8ArrayBagIbE[_ZTV8ArrayBagIbE]+0x10): undefined reference to `ArrayBag<bool>::getCurrentSize() const'
 *      collect2: error: ld returned 1 exit status
 *      Makefile:22: recipe for target 'driver' failed
 *      make: *** [driver] Error 1
 *
 * Most common fix for this is putting the implementation in the same file as the definition. Great
 * read here: https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor
 */

template<class ItemType>
ArrayBag<ItemType>::ArrayBag()
        : itemCount(0), maxItems(DEFUAULT_CAPACITY) {
}

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const {
    return itemCount;
}

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const {
    return itemCount <= 0;
}

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry) {
    if (itemCount < maxItems) {
        items[itemCount++] = newEntry;
        return true;
    }

    return false;
}

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType &anEntry) {
    int locatedIndex = getIndexOf(anEntry);

    if (!isEmpty() && (locatedIndex > -1)) {
        items[locatedIndex] = items[itemCount-1];
        itemCount--;
        return true;
    }

    return false;
}

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType &anEntry) const {
    return getIndexOf(anEntry) != -1;
}


template<class ItemType>
void ArrayBag<ItemType>::clear() {
    itemCount = 0;
}

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType &anEntry) const {
    int frequency = 0;
    int curIndex = 0;
    while (curIndex < itemCount) {
        if (items[curIndex] == anEntry) {
            frequency++;
        }

        curIndex++;
    }

    return frequency;
}

template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType &anEntry) const {
    int curIndex = 0;
    while (curIndex < itemCount) {
        if (items[curIndex] == anEntry) {
            return curIndex;
        }
        curIndex++;
    }

    return -1;
}

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const {
    std::vector<ItemType> bagContents;
    for (int i = 0; i < itemCount; i++) {
        bagContents.push_back(items[i]);
    }
    return bagContents;
}


#endif //SCHOOL_ARRAYBAG_H
