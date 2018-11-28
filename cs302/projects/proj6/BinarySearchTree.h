/**
 * Link-based implementation of the ADT binary search tree.
 * @file BinarySearchTree.h
*/
#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "BinaryNodeTree.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcept.h"
#include <memory>

template<class ItemType>
class BinarySearchTree : public BinaryNodeTree<ItemType> {
private:
    std::shared_ptr <BinaryNode<ItemType>> rootPtr;

protected:
    //------------------------------------------------------------
    // Protected Utility Methods Section:
    // Recursive helper methods for the public methods.
    //------------------------------------------------------------
    // Places a given new node at its proper position in this binary// search tree.
    auto placeNode(std::shared_ptr <BinaryNode<ItemType>> subTreePtr,
                   std::shared_ptr <BinaryNode<ItemType>> newNode);

    // Removes the given target value from the tree while maintaining a
    // binary search tree.
    BinaryNode<ItemType>* removeValue(std::shared_ptr <BinaryNode<ItemType>> subTreePtr,
                     const ItemType target,
                     bool &isSuccessful) override;

    // Removes a given node from a tree while maintaining a binary search tree.
    auto removeNode(std::shared_ptr <BinaryNode<ItemType>> nodePtr);

    // Removes the leftmost node in the left subtree of the node
    // pointed to by nodePtr.
    // Sets inorderSuccessor to the value in this node.
    // Returns a pointer to the revised subtree.
    auto removeLeftmostNode(std::shared_ptr <BinaryNode<ItemType>> subTreePtr,
                            ItemType &inorderSuccessor);

    // Returns a pointer to the node containing the given value,
    // or nullptr if not found.
    auto findNode(std::shared_ptr <BinaryNode<ItemType>> treePtr,
                  const ItemType &target) const;

public:
    //------------------------------------------------------------
    // Constructor and Destructor Section.
    //------------------------------------------------------------
    BinarySearchTree();
    BinarySearchTree(const ItemType &rootItem);
    BinarySearchTree(const BinarySearchTree<ItemType> &tree);
    virtual ~BinarySearchTree();

    //------------------------------------------------------------
    // Public Methods Section.
    //------------------------------------------------------------
    bool isEmpty() const;
    int getHeight() const;
    int getNumberOfNodes() const;

    ItemType getRootData() const throw(PrecondViolatedExcept);
    bool setRootData(const ItemType &newData);

    bool add(const ItemType &newEntry);
    bool remove(const ItemType &target);
    void clear();

    ItemType getEntry(const ItemType &anEntry) const throw(NotFoundException);
    bool contains(const ItemType &anEntry) const;

    //------------------------------------------------------------
    // Public Traversals Section.
    //------------------------------------------------------------
    void preorderTraverse(void visit(ItemType &)) const;
    void inorderTraverse(void visit(ItemType &)) const;
    void postorderTraverse(void visit(ItemType &)) const;

    //------------------------------------------------------------
    // Overloaded Operator Section.
    //------------------------------------------------------------
    BinarySearchTree<ItemType> &
    operator=(const BinarySearchTree<ItemType> &rightHandSide);
}; // end BinarySearchTree

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(nullptr) {}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType &rootItem) {
    rootPtr = std::make_shared<BinaryNode<ItemType>>(rootItem);
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType> &tree) {
    // TODO Stub
    rootPtr = nullptr;
}

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree() {
    // TODO Stub
}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newData)
{
    auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
    rootPtr = placeNode(rootPtr, newNodePtr);
    return true;
} // end add

template<class ItemType>
auto BinarySearchTree<ItemType>::placeNode(std::shared_ptr <BinaryNode<ItemType>> subTreePtr,
                                           std::shared_ptr <BinaryNode<ItemType>> newNode) {
    if (subTreePtr == nullptr) {
        return newNode;
    } else if (subTreePtr->getItem() > newNode->getItem()) {
        tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNode);
        subTreePtr->setLeftChildPtr(tempPtr);
    } else {
        tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNode);
        subTreePtr->setRightChildPtr(tempPtr);
    }
    return subTreePtr;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::removeValue(std::shared_ptr <BinaryNode<ItemType>> subTreePtr, const ItemType target,
                                             bool &isSuccessful) {
    if (subTreePtr == nullptr) {
        isSuccessful = false;
    } else if (subTreePtr->getItem() == target) {
        // Item is in the root of some subtree
        subTreePtr = removeNode(subTreePtr); // Remove the item
        isSuccessful = true;
    } else if (subTreePtr->getItem() > target) {
        // Search the left subtree
        tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
        subTreePtr->setLeftChildPtr(tempPtr);
    } else {
        // Search the right subtree
        tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
        subTreePtr->setRightChildPtr(tempPtr);
    }
    return subTreePtr;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::removeLeftmostNode(std::shared_ptr <BinaryNode<ItemType>> subTreePtr,
                                                    ItemType &inorderSuccessor) {
    if (nodePtr->getLeftChildPtr() == nullptr) {
        // This is the node you want; it has no left child, but it might have a right subtree
        inorderSuccessor = nodePtr->getItem();
        return removeNode(nodePtr);
    } else {
        tempPtr = removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor);
        nodePtr->setLeftChildPtr(tempPtr);
        return nodePtr;
    }
}

template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType &target) {
    isSuccessful = false;
    rootPtr = removeValue(rootPtr, target, isSuccessful);
    return isSuccessful;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::findNode(std::shared_ptr <BinaryNode<ItemType>> treePtr,
                                          const ItemType &target) const {
    if (subTreePtr == nullptr) {
        return nullptr; // Not found
    } else if (subTreePtr->getItem() == target) {
        return subTreePtr; // Found
    } else if (subTreePtr->getItem() > target) {
        // Search left subtree
        return findNode(subTreePtr->getLeftChildPtr(), target);
    } else {
        // Search right subtree
        return findNode(subTreePtr->getRightChildPtr(), target);
    }
}

#endif