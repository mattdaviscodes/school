#ifndef LEFT_LEANING_RED_BLACK_TREE_SCHOOL
#define LEFT_LEANING_RED_BLACK_TREE_SCHOOL

#include "RedBlackNode.h"
#include <algorithm>
#include <memory>
#include <iostream>
#include <string>

std::string enumToString(const Color color);


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

    void insertFixup(RedBlackNode<ItemType> *node);
    void leftRotate(RedBlackNode<ItemType> *node);
    void rightRotate(RedBlackNode<ItemType> *node);

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

    RedBlackNode<ItemType> *add(const ItemType& newEntry);

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

/**
 * @return The parent of the node created (nullptr if root)
 */
template<class ItemType>
RedBlackNode<ItemType> * LeftLeaningRedBlackTree<ItemType>::add(const ItemType &newEntry) {
    RedBlackNode<ItemType> *newNodePtr = new RedBlackNode<ItemType>(newEntry);
    RedBlackNode<ItemType> *curr = rootPtr;
    RedBlackNode<ItemType> *prev = nullptr; // Always points to parent of current node

    // Go down tree until a leaf is reached, at which point prev is the parent of node to be inserted
    while (curr != nullptr) {
        prev = curr;
        if (newNodePtr->getItem() > curr->getItem()) {
            curr = curr->getRightChildPtr();
        } else {
            curr = curr->getLeftChildPtr();
        }
    }

    newNodePtr->setParentPtr(prev);

    if (prev == nullptr) {
        // Tree was empty, set new node to be root
        rootPtr = newNodePtr;
        rootPtr->setColor(BLACK);
    } else if (newNodePtr->getItem() > prev->getItem()) {
        prev->setRightChildPtr(newNodePtr);
    } else {
        prev->setLeftChildPtr(newNodePtr);
    }

    // Fix any inconsistencies that could have been introduced by adding thew new red node
    insertFixup(newNodePtr);

    return prev;
}

template<class ItemType>
void LeftLeaningRedBlackTree<ItemType>::insertFixup(RedBlackNode<ItemType> *node) {
    RedBlackNode<ItemType> *curr = node;
    RedBlackNode<ItemType> *parent = nullptr;
    RedBlackNode<ItemType> *grandparent = nullptr;
    RedBlackNode<ItemType> *uncle = nullptr;
    Color tmpColor;

    while ((curr != rootPtr) && (curr->getColor() != BLACK) && curr->getParentPtr()->getColor() == RED) {
        parent = curr->getParentPtr();
        grandparent = parent->getParentPtr();

        if (parent == grandparent->getLeftChildPtr()) {
            uncle = grandparent->getRightChildPtr();

            if (uncle != nullptr && uncle->getColor() == RED) {
                grandparent->setColor(RED);
                parent->setColor(BLACK);
                uncle->setColor(BLACK);
                curr = grandparent;

                // Does this make it left leaning?
                if (isRed(curr->getRightChildPtr()) && !isRed(curr->getLeftChildPtr())) {
                    leftRotate(curr);
                }
                if (isRed(curr->getLeftChildPtr()) && isRed(curr->getLeftChildPtr()->getLeftChildPtr())) {
                    rightRotate(curr);
                }
                if (isRed(curr->getLeftChildPtr()) && isRed(curr->getRightChildPtr())) {
                    flipColors(curr);
                }
            } else {
                if (curr == parent->getRightChildPtr()) {
                    leftRotate(parent);
                    curr = parent;
                    parent = curr->getParentPtr();
                }

                rightRotate(grandparent);
                tmpColor = parent->getColor();
                parent->setColor(grandparent->getColor());
                grandparent->setColor(tmpColor);
                curr = parent;

                // Does this make it left leaning?
                if (isRed(curr->getRightChildPtr()) && !isRed(curr->getLeftChildPtr())) {
                    leftRotate(curr);
                }
                if (isRed(curr->getLeftChildPtr()) && isRed(curr->getLeftChildPtr()->getLeftChildPtr())) {
                    rightRotate(curr);
                }
                if (isRed(curr->getLeftChildPtr()) && isRed(curr->getRightChildPtr())) {
                    flipColors(curr);
                }
            }
        } else {
            uncle = grandparent->getLeftChildPtr();

            if (uncle != nullptr && uncle->getColor() == RED) {
                grandparent->setColor(RED);
                parent->setColor(BLACK);
                uncle->setColor(BLACK);
                curr = grandparent;

                // Does this make it left leaning?
                if (isRed(curr->getRightChildPtr()) && !isRed(curr->getLeftChildPtr())) {
                    leftRotate(curr);
                }
                if (isRed(curr->getLeftChildPtr()) && isRed(curr->getLeftChildPtr()->getLeftChildPtr())) {
                    rightRotate(curr);
                }
                if (isRed(curr->getLeftChildPtr()) && isRed(curr->getRightChildPtr())) {
                    flipColors(curr);
                }
            } else {
                if (curr == parent->getLeftChildPtr()) {
                    rightRotate(parent);
                    curr = parent;
                    parent = curr->getParentPtr();
                }

                leftRotate(grandparent);
                tmpColor = parent->getColor();
                parent->setColor(grandparent->getColor());
                grandparent->setColor(tmpColor);
                curr = parent;

                // Does this make it left leaning?
                if (isRed(curr->getRightChildPtr()) && !isRed(curr->getLeftChildPtr())) {
                    leftRotate(curr);
                }
                if (isRed(curr->getLeftChildPtr()) && isRed(curr->getLeftChildPtr()->getLeftChildPtr())) {
                    rightRotate(curr);
                }
                if (isRed(curr->getLeftChildPtr()) && isRed(curr->getRightChildPtr())) {
                    flipColors(curr);
                }
            }
        }
    }

    rootPtr->setColor(BLACK);
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
void LeftLeaningRedBlackTree<ItemType>::leftRotate(RedBlackNode<ItemType> *node) {
    RedBlackNode<ItemType> *right = node->getRightChildPtr();
    node->setRightChildPtr(right->getLeftChildPtr());

    if (node->getRightChildPtr() != nullptr) {
        node->getRightChildPtr()->setParentPtr(node);
    }

    right->setParentPtr(node->getParentPtr());

    if (node->getParentPtr() == nullptr) {
        rootPtr = right;
    } else if (node == node->getParentPtr()->getLeftChildPtr()) {
        node->getParentPtr()->setLeftChildPtr(right);
    } else {
        node->getParentPtr()->setRightChildPtr(right);
    }

    right->setLeftChildPtr(node);
    node->setParentPtr(right);
}

template<class ItemType>
void LeftLeaningRedBlackTree<ItemType>::rightRotate(RedBlackNode<ItemType> *node) {
    RedBlackNode<ItemType> *left = node->getLeftChildPtr();
    node->setLeftChildPtr(left->getRightChildPtr());

    if (node->getLeftChildPtr() != nullptr) {
        node->getLeftChildPtr()->setParentPtr(node);
    }

    left->setParentPtr(node->getParentPtr());

    if (node->getParentPtr() == nullptr) {
        rootPtr = left;
    } else if (node == node->getParentPtr()->getLeftChildPtr()) {
        node->getParentPtr()->setLeftChildPtr(left);
    } else {
        node->getParentPtr()->setRightChildPtr(left);
    }

    left->setRightChildPtr(node);
    node->setParentPtr(left);
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

#endif