#ifndef BINARY_NODE_
#define BINARY_NODE_

#include <memory>

template<class ItemType>
class BinaryNode {
private:
    ItemType item; // Data portion
    BinaryNode<ItemType> *leftChildPtr; // Pointer to left child
    BinaryNode<ItemType> *rightChildPtr; // Pointer to right child
public:
    BinaryNode(const ItemType &anItem);

    ItemType getItem() const;

    BinaryNode<ItemType> *getLeftChildPtr() const;
    BinaryNode<ItemType> *getRightChildPtr() const;

    void setLeftChildPtr(BinaryNode<ItemType> *leftPtr);
    void setRightChildPtr(BinaryNode<ItemType> *rightPtr);
}; // end BinaryNode

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType &anItem) : item(anItem), leftChildPtr(nullptr), rightChildPtr(nullptr) {
}

template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const {
    return item;
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const {
    return leftChildPtr;
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const {
    return rightChildPtr;
}

template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType> *leftPtr) {
    leftChildPtr = leftPtr;
}

template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType> *rightPtr) {
    rightChildPtr = rightPtr;
}


#endif