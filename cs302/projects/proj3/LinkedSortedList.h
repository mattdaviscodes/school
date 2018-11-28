#ifndef LINKED_SORTED_LIST_
#define LINKED_SORTED_LIST_

#include <memory>
#include "SortedListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class LinkedSortedList : public SortedListInterface<ItemType> {
private:
    std::shared_ptr <Node<ItemType>> headPtr; // Pointer to first node in chain
    int itemCount; // Current count of list items

    // Locates the node that is before the node that should or does contain the given entry
    auto getNodeBefore(const ItemType &anEntry) const;
    // Locate the node at a given position within the chain
    auto getNodeAt(int position) const;
    // Returns a pointer to a copy of the chain to which origChainPtr points
    auto copyChain(const std::shared_ptr <Node<ItemType>> &origChainPtr);

public:
    LinkedSortedList();
    LinkedSortedList(const LinkedSortedList<ItemType> &aList);
    virtual ~LinkedSortedList();

    bool insertSorted(const ItemType &newEntry);
    bool removeSorted(const ItemType &anEntry);
    int getPosition(const ItemType &anEntry);

    // following methods are the same as given in ListInterface
    bool isEmpty() const;
    int getLength() const;
    bool remove(int position);
    void clear();
    ItemType getEntry(int position) const throw(PrecondViolatedExcept);
};

template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList() : headPtr(nullptr), itemCount(0) {

}

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

#endif