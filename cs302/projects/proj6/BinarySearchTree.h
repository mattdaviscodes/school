/** Link-based implementation of the ADT binary search tree.
@file BinarySearchTree.h */

#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include "BinaryNode.h"
#include <algorithm>
#include <memory>
#include <iostream>

template<class ItemType>
class BinarySearchTree
{
private:
    BinaryNode<ItemType> *rootPtr;

protected:
    //------------------------------------------------------------
    // Protected Utility Methods Section:
    // Recursive helper methods for the public methods.
    //------------------------------------------------------------
    // Places a given new node at its proper position in this binary
    // search tree.
    BinaryNode<ItemType> *placeNode(BinaryNode<ItemType> *subTreePtr, BinaryNode<ItemType> *newNode);

    int getHeightFromNode(BinaryNode<ItemType> *subTreePtr) const;

    void preorderTraverseFromNode(BinaryNode<ItemType> *subTreePtr) const;
    void inorderTraverseFromNode(BinaryNode<ItemType> *subTreePtr) const;
    void postorderTraverseFromNode(BinaryNode<ItemType> *subTreePtr) const;

public:
    //------------------------------------------------------------
    // Constructor and Destructor Section.
    //------------------------------------------------------------
    BinarySearchTree();

    //------------------------------------------------------------
    // Public Methods Section.
    //------------------------------------------------------------
    int getHeight() const;

    bool add(const ItemType& newEntry);

    //------------------------------------------------------------
    // Public Traversals Section.
    //------------------------------------------------------------
    void preorderTraverse() const;
    void inorderTraverse() const;
    void postorderTraverse() const;
}; // end BinarySearchTree

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(nullptr) {
}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType &newEntry) {
    BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newEntry);
    rootPtr = placeNode(rootPtr, newNodePtr);
    return true;
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::placeNode(BinaryNode<ItemType> *subTreePtr,
                                                            BinaryNode<ItemType> *newNode) {
    BinaryNode<ItemType>* tempPtr;

    if (subTreePtr == nullptr) {
        return newNode;
    }  else if (subTreePtr->getItem() > newNode->getItem()) {
        tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNode);
        subTreePtr->setLeftChildPtr(tempPtr);
    } else {
        tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNode);
        subTreePtr->setRightChildPtr(tempPtr);
    }

    return subTreePtr;
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const {
    return getHeightFromNode(rootPtr);
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeightFromNode(BinaryNode<ItemType> *subTreePtr) const {
    if (subTreePtr == nullptr) {
        // Tree is empty
        return 0;
    } else {
        int leftHeight = getHeightFromNode(subTreePtr->getLeftChildPtr());
        int rightHeight = getHeightFromNode(subTreePtr->getRightChildPtr());
        return std::max(leftHeight, rightHeight) + 1;
    }
}

template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse() const {
    std::cout << "PREORDER: ";
    preorderTraverseFromNode(rootPtr);
    std::cout << std::endl;
}

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse() const {
    std::cout << "INORDER: ";
    inorderTraverseFromNode(rootPtr);
    std::cout << std::endl;
}

template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse() const {
    std::cout << "POSTORDER: ";
    postorderTraverseFromNode(rootPtr);
    std::cout << std::endl;
}

template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverseFromNode(BinaryNode<ItemType> *subTreePtr) const {
    if (subTreePtr == nullptr) {
        return;
    }

    std::cout << subTreePtr->getItem() << " ";
    preorderTraverseFromNode(subTreePtr->getLeftChildPtr());
    preorderTraverseFromNode(subTreePtr->getRightChildPtr());
}

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverseFromNode(BinaryNode<ItemType> *subTreePtr) const {
    if (subTreePtr == nullptr) {
        return;
    }

    inorderTraverseFromNode(subTreePtr->getLeftChildPtr());
    std::cout << subTreePtr->getItem() << " ";
    inorderTraverseFromNode(subTreePtr->getRightChildPtr());
}

template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverseFromNode(BinaryNode<ItemType> *subTreePtr) const {
    if (subTreePtr == nullptr) {
        return;
    }

    postorderTraverseFromNode(subTreePtr->getLeftChildPtr());
    postorderTraverseFromNode(subTreePtr->getRightChildPtr());
    std::cout << subTreePtr->getItem() << " ";
}

#endif