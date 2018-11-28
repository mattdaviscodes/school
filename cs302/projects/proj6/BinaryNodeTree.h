#ifndef BINARY_NODE_TREE_
#define BINARY_NODE_TREE_

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcept.h"
#include "NotFoundException.h"

template<class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType> {
private:
    std::shared_ptr <BinaryNode<ItemType>> rootPtr;
protected:
    // PROTECTED UTILITY METHODS SECTION: RECURSIVE HELPER METHODS FOR THE PUBLIC METHODS
    int getHeightHelper(std::shared_ptr <BinaryNode<ItemType>> subTreePtr) const;
    int getNumberOfNodesHelper(std::shared_ptr <BinaryNode<ItemType>> subTreePtr) const;

    // Recursively adds a new node to the tree in a left/right fashion to keep tree balanced
    auto balancedAdd(std::shared_ptr <BinaryNode<ItemType>> subTreePtr,
                     std::shared_ptr <BinaryNode<ItemType>> newNodePtr);

    // Removes the target value from the tree
    virtual BinaryNode<ItemType>* removeValue(std::shared_ptr <BinaryNode<ItemType>> subTreePtr,
                             const ItemType target, bool &isSuccessful);

    // Copies values up the tree to overwrite value in current node until a leaf is reached.
    // the leaf is then removed, since its value is stored in the parent.
    auto moveValuesUpTree(std::shared_ptr <BinaryNode<ItemType>> subTreePtr);

    // Recursively searches for target value.
    virtual BinaryNode<ItemType>* findNode(std::shared_ptr <BinaryNode<ItemType>> treePtr,
                          const ItemType &target, bool &isSuccessful) const;

    // Copies the tree rooted at treePtr and returns a pointer to the root of the copy
    auto copyTree(const std::shared_ptr <BinaryNode<ItemType>> oldTreeRootPtr) const;

    // Recursively deletes all nodes from the tree
    void destroyTree(std::shared_ptr <BinaryNode<ItemType>> subTreePtr);

    // Recursive traversal helper methods
    void preorder(void visit(ItemType &), std::shared_ptr <BinaryNode<ItemType>> treePtr) const;
    void inorder(void visit(ItemType &), std::shared_ptr <BinaryNode<ItemType>> treePtr) const;
    void postorder(void visit(ItemType &), std::shared_ptr <BinaryNode<ItemType>> treePtr) const;

public:
    // CONSTRUCTOR AND DESTRUCTOR SECTION
    BinaryNodeTree();
    BinaryNodeTree(const ItemType &rootItem);
    BinaryNodeTree(const ItemType &rootItem,
                   const std::shared_ptr <BinaryNodeTree<ItemType>> leftTreePtr,
                   const std::shared_ptr <BinaryNodeTree<ItemType>> rightTreePtr);
    BinaryNodeTree(const std::shared_ptr <BinaryNodeTree<ItemType>> &tree);
    virtual ~BinaryNodeTree();

    // PUBLIC BINARY_TREE_INTERFACE METHODS SECTION
    bool isEmpty() const;
    int getHeight() const;
    int getNumberOfNodes() const;
    ItemType getRootData() const throw(PrecondViolatedExcept);
    bool add(const ItemType &newData); // Adds an item to the tree
    bool remove(const ItemType &data); // Removes specified item from the tree
    void clear();
    ItemType getEntry(const ItemType &anEntry) const throw(NotFoundException);
    bool contains(const ItemType &anEntry) const;

    // PUBLIC TRAVERSAL SECTION
    void preorderTraverse(void visit(ItemType &)) const;
    void inorderTraverse(void visit(ItemType &)) const;
    void postorderTraverse(void visit(ItemType &)) const;

    // OVERLOADED OPERATOR SECTION
    BinaryNodeTree &operator=(const BinaryNodeTree &rightHandSide);
}; // end BinaryNodeTree

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr) {
} // end default constructor

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType &rootItem)
        : rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr)) {
} // end constructor

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType &rootItem,
               const std::shared_ptr <BinaryNodeTree<ItemType>> leftTreePtr,
               const std::shared_ptr <BinaryNodeTree<ItemType>> rightTreePtr)
        : rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem,
                                                         copyTree(leftTreePtr->rootPtr),
                                                         copyTree(rightTreePtr->rootPtr))) {
} // end constructor

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const std::shared_ptr <BinaryNodeTree<ItemType>> &tree) {
    rootPtr = copyTree(tree.rootPtr);
}

template<class ItemType>
auto BinaryNodeTree<ItemType>::copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const {
    std::shared_ptr<BinaryNode<ItemType>> newTreePtr;

    // Copy tree nodes during a preorder traversal
    if (oldTreeRootPtr != nullptr)
    {
        // Copy node
        newTreePtr = std::make_shared<BinaryNode<ItemType>>(oldTreeRootPtr->getItem(), nullptr, nullptr);
        newTreePtr->setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
        newTreePtr->setRightChildPtr(copyTree(oldTreeRootPtr->getRightChildPtr()));
    } // end if
// Else tree is empty (newTreePtr is nullptr)
    return newTreePtr;
} // end copyTree

template<class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
    if (subTreePtr != nullptr)
    {
        destroyTree(subTreePtr->getLeftChildPtr());
        destroyTree(subTreePtr->getRightChildPtr());
        subTreePtr.reset(); // Decrement reference count to node
    } // end if
} // end destroyTree

template<class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
    if (subTreePtr == nullptr)
        return 0;
    else
        return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                       getHeightHelper(subTreePtr->getRightChildPtr()));
} // end getHeightHelper

template<class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData)
{
    auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
    rootPtr = balancedAdd(rootPtr, newNodePtr);
    return true;
} // end add

template<class ItemType>
auto BinaryNodeTree<ItemType>::balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                           std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
    if (subTreePtr == nullptr) {
        return newNodePtr;
    } else {
        auto leftPtr = subTreePtr->getLeftChildPtr();
        auto rightPtr = subTreePtr->getRightChildPtr();
        if (getHeighetHelper(leftPtr) > getHeightHelper(rightPtr)) {
            rightPtr = balancedAdd(rightPtr, newNodePtr);
            subTreePtr->setRightChildPtr(rightPtr);
        } else {
            leftPtr = balancedAdd(leftPtr, newNodePtr);
            subTreePtr->setLeftChild(leftPtr);
        } // end if
        return subTreePtr;
    }
} // end balancedAdd

template<class ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const {
    if (treePtr != nullptr) {
        inorder(visit, treePtr->getLeftChildPtr());
        ItemType theItem = treePtr->getItem();
        visit(theItem);
        inorder(visit, treePtr->getRightChildPtr());
    } // end if
} // end inorder

#endif