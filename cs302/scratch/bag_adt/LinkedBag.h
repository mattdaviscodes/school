//
// Created by Matthew Davis on 9/15/18.
//

#ifndef SCHOOL_LINKEDBAG_H
#define SCHOOL_LINKEDBAG_H

#include <vector>

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
public:
    LinkedBag();
    LinkedBag(const LinkedBag<ItemType>& bag);
    virtual ~LinkedBag();   // Why is destructor virtual?
    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const ItemType& entry);
    bool remove(const ItemType& target);
    void clear();
    int getFrequencyOf(const ItemType& entry) const;
    int getIndexOf(const ItemType& entry) const;
    bool contains(const ItemType& entry) const;
    std::vector<ItemType> toVector() const;

private:
    Node<ItemType>* head;
    int itemCount;
    Node<ItemType>* getPointerTo(const ItemType& target) const; // Why private method?
};

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : head(nullptr), itemCount(0) {
}

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType> &bag) {
    Node<ItemType>* origBagPtr = bag.head;

    if (origBagPtr == nullptr) {
        // Copied bag is empty
        head = nullptr;
        itemCount = 0;
    }
    else {
        head = new Node<ItemType>(origBagPtr->getItem(), origBagPtr->getNext());
        itemCount = 1;

        Node<ItemType>* curr = head->getNext();

        while (origBagPtr = origBagPtr->getNext()) {
            // Create new node based on original bag and increment count
            curr->setNext(new Node<ItemType>(origBagPtr->getItem(), origBagPtr->getNext()));
            itemCount++;

            curr = curr->getNext();
        }
    }
}

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag() {
    clear();
}

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const {
    return itemCount;
}

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const {
    return itemCount <= 0;
}

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType &entry) {
    Node<ItemType>* curr = head;

    // Seek to end of list
    while (curr->getNext() != nullptr) {
        curr = curr->getNext();
    }

    curr->setNext(new Node<ItemType>(entry));

    return true;
}

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType &target) {
    Node<ItemType>* curr = head;
    Node<ItemType>* prev = nullptr;


    if (curr == nullptr) {
        // Emtpy list, cannot remove anything
        return false;
    }

    while (curr != nullptr) {
        if (curr->getItem() == target) {
            if (prev == nullptr) {
                // Removing head of list

            }
        }
    }
}

template<class ItemType>
void LinkedBag<ItemType>::clear() {
    Node<ItemType> *curr = head;
    Node<ItemType> *prev = nullptr;

    while (curr != nullptr) {
        prev = curr;
        curr = curr->getNext();

        delete prev;
    }

    itemCount = 0;
}

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType &entry) const {
    Node<ItemType>* curr = head;

    while (curr != nullptr) {
        if (curr->getItem() == entry) {
            return true;
        }
    }

    return false;
}

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType &entry) const {
    Node<ItemType>* curr = head;
    int freq = 0;

    while (curr != nullptr) {
        if (curr->getItem() == entry) {
            freq++;
        }
    }

    return freq;
}

template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const {
    Node<ItemType>* curr = head;
    std::vector<ItemType> bagContents;

    while (curr != nullptr) {
        bagContents.push_back(curr->getItem());
    }

    return bagContents;
}

#endif //SCHOOL_LINKEDBAG_H
