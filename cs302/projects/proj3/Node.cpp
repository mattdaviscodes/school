/** @file Node.cpp */
#include "Node.h"

template<class ItemType>
Node<ItemType>::Node() : next(nullptr) {
} // end default constructor
template<class ItemType>
Node<ItemType>::Node(const ItemType &anItem) : item(anItem), next(nullptr) {
} // end constructor
template<class ItemType>
Node<ItemType>::Node(const ItemType &anItem, Node <ItemType> *nextNodePtr) :
        item(anItem), next(nextNodePtr) {
} // end constructor
template<class ItemType>
void Node<ItemType>::setItem(const ItemType &anItem) {
    item = anItem;
} // end setItem
template<class ItemType>
void Node<ItemType>::setNext(Node <ItemType> *nextNodePtr) {
    next = nextNodePtr;
} // end setNext
template<class ItemType>
ItemType Node<ItemType>::getItem() const {
    return item;
} // end getItem
template<class ItemType>
Node <ItemType> *Node<ItemType>::getNext() const {
    return next;
} // end getNext