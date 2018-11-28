#include <iostream>

#include "LinkedSortedList.h"

template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList <ItemType> &aList) {
    headPtr = copyChain(aList.headPtr);
    itemCount = aList.itemCount;
}

template<class ItemType>
auto LinkedSortedList<ItemType>::copyChain(const std::shared_ptr <Node<ItemType>> &origChainPtr) {
    std::shared_ptr <Node<ItemType>> copiedChainPtr; // Initial value is nullptr
    if (origChainPtr != nullptr) {
        // Build new chain from given one
        // Create new node with the current item
        copiedChainPtr = std::make_shared < Node < ItemType >> (origChainPtr->getItem());
        // Make the node point to the rest of the chain
        copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));
    } // end if
    return copiedChainPtr;
} // end copyChain

template<class ItemType>
bool LinkedSortedList<ItemType>::insertSorted(const ItemType &anEntry) {
    auto newNodePtr(std::make_shared < Node < ItemType >> (anEntry));
    auto prevPtr = getNodeBefore(anEntry);
    if (isEmpty() || (prevPtr == nullptr)) // Add at the beinning
    {
        newNodePtr->setNext(headPtr);
        headPtr = newNodePtr;
    } else {
        auto aftPtr = prevPtr->getNext();
        newNodePtr->setNext(aftPtr);
        prevPtr->setNext(newNodePtr);
    } // end if
    itemCount++;
    return true;
} // end insertSorted

template<class ItemType>
auto LinkedSortedList<ItemType>::getNodeBefore(const ItemType &anEntry) const {
    auto curPtr = headPtr;
    std::shared_ptr <Node<ItemType>> prevPtr;
    while ((curPtr != nullptr) && (anEntry > curPtr->getItem())) {
        prevPtr = curPtr;
        curPtr = curPtr->getNext();
    } // end while
    return prevPtr;
} // end getNodeBefore