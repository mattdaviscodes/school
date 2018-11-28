//
// Created by Matthew Davis on 9/15/18.
//

#ifndef SCHOOL_NODE_H
#define SCHOOL_NODE_H


template<class ItemType>
class Node {
public:
    Node();
    Node(const ItemType& item);
    Node(const ItemType& item, Node<ItemType>* next);
    void setItem(const ItemType& item);
    void setNext(Node<ItemType>* next);
    ItemType getItem() const;
    Node<ItemType>* getNext() const;

private:
    ItemType item;
    Node<ItemType>* next;
};

template<class ItemType>
Node<ItemType>::Node() : next(nullptr) {
}

template<class ItemType>
Node<ItemType>::Node(const ItemType &item) : item(item), next(nullptr) {
}

template<class ItemType>
Node<ItemType>::Node(const ItemType &item, Node<ItemType> *next) :
        item(item), next(next) {
}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType &item) {
    item = item;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType> *next) {
    next = next;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const {
    return item;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
    return next;
}]


#endif //SCHOOL_NODE_H
