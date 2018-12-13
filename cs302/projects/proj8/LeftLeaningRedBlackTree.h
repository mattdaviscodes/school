#ifndef LEFT_LEANING_RED_BLACK_TREE_SCHOOL
#define LEFT_LEANING_RED_BLACK_TREE_SCHOOL

#include "RedBlackNode.h"
#include <algorithm>
#include <memory>
#include <iostream>
#include <string>

std::string enumToString(const Color color);

template<class ItemType>
void debugNode(const RedBlackNode<ItemType> *node);


template<class ItemType>
class LeftLeaningRedBlackTree
{
private:
    RedBlackNode<ItemType> *rootPtr;

protected:
    //------------------------------------------------------------
    // Protected Utility Methods Section:
    // Recursive helper methods for the public methods.
    //------------------------------------------------------------
    // Places a given new node at its proper position in this binary
    // search tree.
    RedBlackNode<ItemType> *placeNode(RedBlackNode<ItemType> *subTreePtr, RedBlackNode<ItemType> *newNode);

    RedBlackNode<ItemType> *insertRec(RedBlackNode<ItemType> *subtree, RedBlackNode<ItemType> *node);
    RedBlackNode<ItemType> *deleteRec(RedBlackNode<ItemType> *subtree, const ItemType& entry);
    RedBlackNode<ItemType>* leftRotate(RedBlackNode<ItemType> *node);
    RedBlackNode<ItemType>* rightRotate(RedBlackNode<ItemType> *node);

    RedBlackNode<ItemType>* findMin(RedBlackNode<ItemType>* node);
    RedBlackNode<ItemType>* deleteMin(RedBlackNode<ItemType>* node);

    RedBlackNode<ItemType>* moveRedLeft(RedBlackNode<ItemType>* node);
    RedBlackNode<ItemType>* moveRedRight(RedBlackNode<ItemType>* node);

    RedBlackNode<ItemType>* fixUp(RedBlackNode<ItemType>* node);

    bool isRed(RedBlackNode<ItemType> *node) const;

    void flipColors(RedBlackNode<ItemType> *node);

    int getHeightFromNode(RedBlackNode<ItemType> *subTreePtr) const;

    void preorderTraverseFromNode(RedBlackNode<ItemType> *subTreePtr) const;
    void inorderTraverseFromNode(RedBlackNode<ItemType> *subTreePtr) const;
    void postorderTraverseFromNode(RedBlackNode<ItemType> *subTreePtr) const;

public:
    //------------------------------------------------------------
    // Constructor and Destructor Section.
    //------------------------------------------------------------
    LeftLeaningRedBlackTree();

    //------------------------------------------------------------
    // Public Methods Section.
    //------------------------------------------------------------
    int getHeight() const;

    bool add(const ItemType& newEntry);
    void remove(const ItemType& entry);

    //------------------------------------------------------------
    // Public Traversals Section.
    //------------------------------------------------------------
    void preorderTraverse() const;
    void inorderTraverse() const;
    void postorderTraverse() const;
}; // end LeftLeaningRedBlackTree

template<class ItemType>
LeftLeaningRedBlackTree<ItemType>::LeftLeaningRedBlackTree() : rootPtr(nullptr) {
}

template<class ItemType>
bool LeftLeaningRedBlackTree<ItemType>::add(const ItemType &newEntry) {
    RedBlackNode<ItemType> *newNodePtr = new RedBlackNode<ItemType>(newEntry);
    rootPtr = insertRec(rootPtr, newNodePtr);
    rootPtr->setColor(BLACK);
    return true;
}

template<class ItemType>
void LeftLeaningRedBlackTree<ItemType>::remove(const ItemType &entry) {
    rootPtr = deleteRec(rootPtr, entry);
}

template<class ItemType>
RedBlackNode<ItemType>* LeftLeaningRedBlackTree<ItemType>::deleteRec(RedBlackNode<ItemType> *subtree,
                                                                     const ItemType &entry) {
    if (entry < subtree->getItem()) {
        if (subtree->getLeftChildPtr() != nullptr) {
            if (!isRed(subtree->getLeftChildPtr()) && !isRed(subtree->getLeftChildPtr()->getLeftChildPtr())) {
                subtree = moveRedLeft(subtree);
            }
            subtree->setLeftChildPtr(deleteRec(subtree->getLeftChildPtr(), entry));
        }
    } else {
        if (isRed(subtree->getLeftChildPtr())) {
            subtree = rightRotate(subtree);
        }

        if (entry == subtree->getItem() && subtree->getRightChildPtr() == nullptr) {
            delete subtree;
            return nullptr;
        }

        if (subtree->getRightChildPtr() != nullptr) {
            if (!isRed(subtree->getRightChildPtr()) && !isRed(subtree->getRightChildPtr()->getLeftChildPtr())) {
                subtree = moveRedRight(subtree);
            }

            if (entry == subtree->getItem()) {
                subtree->setItem(findMin(subtree->getRightChildPtr())->getItem());
                subtree->setRightChildPtr(deleteMin(subtree->getRightChildPtr()));
            } else {
                subtree->setRightChildPtr(deleteRec(subtree->getRightChildPtr(), entry));
            }
        }
    }

    return fixUp(subtree);
}

template<class ItemType>
RedBlackNode<ItemType>* LeftLeaningRedBlackTree<ItemType>::findMin(RedBlackNode<ItemType>* node) {
    while (node->getLeftChildPtr() != nullptr) {
        node = node->getLeftChildPtr();
    }

    return node;
}

template<class ItemType>
RedBlackNode<ItemType>* LeftLeaningRedBlackTree<ItemType>::deleteMin(RedBlackNode<ItemType>* node) {
    if (node->getLeftChildPtr() == nullptr) {
        delete node;
        return nullptr;
    }

    if (!isRed(node->getLeftChildPtr()) && !isRed(node->getLeftChildPtr()->getLeftChildPtr())) {
        node = moveRedLeft(node);
    }

    node->setLeftChildPtr(deleteMin(node->getLeftChildPtr()));

    return fixUp(node);
}

template<class ItemType>
RedBlackNode<ItemType>* LeftLeaningRedBlackTree<ItemType>::moveRedLeft(RedBlackNode<ItemType>* node) {
    flipColors(node);

    if (node->getRightChildPtr() != nullptr && isRed(node->getRightChildPtr()->getLeftChildPtr())) {
        node->setRightChildPtr(rightRotate(node->getRightChildPtr()));
        node = leftRotate(node);

        flipColors(node);
    }

    return node;
}

template<class ItemType>
RedBlackNode<ItemType>* LeftLeaningRedBlackTree<ItemType>::moveRedRight(RedBlackNode<ItemType>* node) {
    flipColors(node);

    if (node->getLeftChildPtr() != nullptr && isRed(node->getLeftChildPtr()->getLeftChildPtr())) {
        node = rightRotate(node);
        flipColors(node);
    }

    return node;
}

template<class ItemType>
RedBlackNode<ItemType>* LeftLeaningRedBlackTree<ItemType>::fixUp(RedBlackNode<ItemType>* node) {
    if (isRed(node->getRightChildPtr())) {
        node = leftRotate(node);
    }

    if (isRed(node->getLeftChildPtr()) && isRed(node->getLeftChildPtr()->getLeftChildPtr())) {
        node = rightRotate(node);
    }

    if (isRed(node->getLeftChildPtr()) && isRed(node->getRightChildPtr())) {
        flipColors(node);
    }

    return node;
}

template<class ItemType>
RedBlackNode<ItemType>* LeftLeaningRedBlackTree<ItemType>::insertRec(RedBlackNode<ItemType> *subtree, RedBlackNode<ItemType> *node) {
    // Special case for inserting a leaf.  Just return the pointer;
    // the caller will insert the new node into the parent node.
    if (subtree == nullptr) {
        return node;
    }

    if (node->getItem() < subtree->getItem()) {
        subtree->setLeftChildPtr(insertRec(subtree->getLeftChildPtr(), node));
    } else {
        subtree->setRightChildPtr(insertRec(subtree->getRightChildPtr(), node));
    }

    if (isRed(subtree->getRightChildPtr()) && !isRed(subtree->getLeftChildPtr())) {
        subtree = leftRotate(subtree);
    }

    if (isRed(subtree->getLeftChildPtr()) && isRed(subtree->getLeftChildPtr()->getLeftChildPtr())) {
        subtree = rightRotate(subtree);
    }

    if (isRed(subtree->getLeftChildPtr()) && isRed(subtree->getRightChildPtr())) {
        flipColors(subtree);
    }

    return subtree;
}

template<class ItemType>
bool LeftLeaningRedBlackTree<ItemType>::isRed(RedBlackNode<ItemType> *node) const {
    if (node != nullptr) {
        return node->getColor() == RED;
    }

    return false;   // null pointers are BLACK
}

template<class ItemType>
void LeftLeaningRedBlackTree<ItemType>::flipColors(RedBlackNode<ItemType> *node) {
    node->flipColor();
    node->getLeftChildPtr()->flipColor();
    node->getRightChildPtr()->flipColor();
}

template<class ItemType>
RedBlackNode<ItemType>* LeftLeaningRedBlackTree<ItemType>::leftRotate(RedBlackNode<ItemType> *node) {
    RedBlackNode<ItemType>* temp = node->getRightChildPtr();
    node->setRightChildPtr(temp->getLeftChildPtr());
    temp->setLeftChildPtr(node);
    temp->setColor(node->getColor());
    node->setColor(RED);
    return temp;
}

template<class ItemType>
RedBlackNode<ItemType>*  LeftLeaningRedBlackTree<ItemType>::rightRotate(RedBlackNode<ItemType> *node) {
    RedBlackNode<ItemType>* temp = node->getLeftChildPtr();
    node->setLeftChildPtr(temp->getRightChildPtr());
    temp->setRightChildPtr(node);
    temp->setColor(node->getColor());
    node->setColor(RED);
    return temp;
}

template<class ItemType>
RedBlackNode<ItemType>* LeftLeaningRedBlackTree<ItemType>::placeNode(RedBlackNode<ItemType> *subTreePtr,
                                                            RedBlackNode<ItemType> *newNode) {
    RedBlackNode<ItemType>* tempPtr;

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
int LeftLeaningRedBlackTree<ItemType>::getHeight() const {
    return getHeightFromNode(rootPtr);
}

template<class ItemType>
int LeftLeaningRedBlackTree<ItemType>::getHeightFromNode(RedBlackNode<ItemType> *subTreePtr) const {
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
void LeftLeaningRedBlackTree<ItemType>::preorderTraverse() const {
    std::cout << "PREORDER: ";
    preorderTraverseFromNode(rootPtr);
    std::cout << std::endl;
}

template<class ItemType>
void LeftLeaningRedBlackTree<ItemType>::inorderTraverse() const {
    std::cout << "INORDER: ";
    inorderTraverseFromNode(rootPtr);
    std::cout << std::endl;
}

template<class ItemType>
void LeftLeaningRedBlackTree<ItemType>::postorderTraverse() const {
    std::cout << "POSTORDER: ";
    postorderTraverseFromNode(rootPtr);
    std::cout << std::endl;
}

template<class ItemType>
void LeftLeaningRedBlackTree<ItemType>::preorderTraverseFromNode(RedBlackNode<ItemType> *subTreePtr) const {
    if (subTreePtr == nullptr) {
        return;
    }

    std::cout << subTreePtr->getItem() << "(" << enumToString(subTreePtr->getColor()) << ") ";
    preorderTraverseFromNode(subTreePtr->getLeftChildPtr());
    preorderTraverseFromNode(subTreePtr->getRightChildPtr());
}

template<class ItemType>
void LeftLeaningRedBlackTree<ItemType>::inorderTraverseFromNode(RedBlackNode<ItemType> *subTreePtr) const {
    if (subTreePtr == nullptr) {
        return;
    }

    inorderTraverseFromNode(subTreePtr->getLeftChildPtr());
    std::cout << subTreePtr->getItem() << "(" << enumToString(subTreePtr->getColor()) << ") ";
    inorderTraverseFromNode(subTreePtr->getRightChildPtr());
}

template<class ItemType>
void LeftLeaningRedBlackTree<ItemType>::postorderTraverseFromNode(RedBlackNode<ItemType> *subTreePtr) const {
    if (subTreePtr == nullptr) {
        return;
    }

    postorderTraverseFromNode(subTreePtr->getLeftChildPtr());
    postorderTraverseFromNode(subTreePtr->getRightChildPtr());
    std::cout << subTreePtr->getItem() << "(" << enumToString(subTreePtr->getColor()) << ") ";
}

std::string enumToString(const Color color) {
    if (color) {
        return "B";
    }
    return "R";
}

template<class ItemType>
void debugNode(const RedBlackNode<ItemType> *node) {
    if (node != nullptr) {
        std::cout << "Number: " << node->getItem() << std::endl
                  << "Color: " << enumToString(node->getColor()) << std::endl
                  << std::endl;

    }
}

#endif