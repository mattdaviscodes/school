#ifndef RED_BLACK_NODE_
#define RED_BLACK_NODE_

enum Color {RED, BLACK};

template<class ItemType>
class RedBlackNode {
private:
    ItemType item; // Data portion
    RedBlackNode<ItemType> *leftChildPtr; // Pointer to left child
    RedBlackNode<ItemType> *rightChildPtr; // Pointer to right child

    RedBlackNode<ItemType> *parentPtr;

    Color color;
public:
    RedBlackNode(const ItemType &anItem);

    ItemType getItem() const;

    RedBlackNode<ItemType> *getLeftChildPtr() const;
    RedBlackNode<ItemType> *getRightChildPtr() const;
    RedBlackNode<ItemType> *getParentPtr() const;

    void setLeftChildPtr(RedBlackNode<ItemType> *leftPtr);
    void setRightChildPtr(RedBlackNode<ItemType> *rightPtr);
    void setParentPtr(RedBlackNode<ItemType> *parentPtr);



    Color getColor() const;
    void setColor(const Color newColor);
}; // end RedBlackNode

template<class ItemType>
RedBlackNode<ItemType>::RedBlackNode(const ItemType &anItem) : item(anItem), leftChildPtr(nullptr),
                                                               rightChildPtr(nullptr), parentPtr(nullptr), color(RED) {
}

template<class ItemType>
ItemType RedBlackNode<ItemType>::getItem() const {
    return item;
}

template<class ItemType>
RedBlackNode<ItemType>* RedBlackNode<ItemType>::getLeftChildPtr() const {
    return leftChildPtr;
}

template<class ItemType>
RedBlackNode<ItemType>* RedBlackNode<ItemType>::getRightChildPtr() const {
    return rightChildPtr;
}

template<class ItemType>
RedBlackNode<ItemType>* RedBlackNode<ItemType>::getParentPtr() const {
    return parentPtr;
}

template<class ItemType>
void RedBlackNode<ItemType>::setLeftChildPtr(RedBlackNode<ItemType> *leftPtr) {
    leftChildPtr = leftPtr;
}

template<class ItemType>
void RedBlackNode<ItemType>::setRightChildPtr(RedBlackNode<ItemType> *rightPtr) {
    rightChildPtr = rightPtr;
}

template<class ItemType>
void RedBlackNode<ItemType>::setParentPtr(RedBlackNode<ItemType> *parent) {
    parentPtr = parent;
}

template<class ItemType>
Color RedBlackNode<ItemType>::getColor() const {
    return color;
}

template<class ItemType>
void RedBlackNode<ItemType>::setColor(const Color newColor) {
    color = newColor;
}
#endif