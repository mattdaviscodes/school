//--------------------------------------------------------------------
//
//  StackArray.h
// 
//  Class declaration for the array implementation of the Stack ADT
//
//--------------------------------------------------------------------

#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

template<typename DataType>
class StackLinked : public Stack<DataType> {

public:

    StackLinked(int maxNumber = Stack<DataType>::MAX_STACK_SIZE);

    StackLinked(const StackLinked &other);

    StackLinked &operator=(const StackLinked &other);

    ~StackLinked();

    void push(const DataType &newDataItem) throw(logic_error);

    DataType pop() throw(logic_error);

    void clear();

    bool isEmpty() const;

    bool isFull() const;

    void showStructure() const;

private:

    class StackNode {
    public:
        StackNode(const DataType &nodeData, StackNode *nextPtr);

        DataType dataItem;
        StackNode *next;
    };

    StackNode *top;
};

template<class DataType>
StackLinked<DataType>::StackLinked(int maxNumber) : top(nullptr) {}

template<class DataType>
StackLinked<DataType>::StackLinked(const StackLinked &other) {
    StackNode* curr = top;
    StackNode* otherCurr = other.top;

    while (otherCurr) {
        curr = new StackNode(otherCurr->dataItem, otherCurr->next);

        if (!top) {
            top = curr;
        }

        curr = curr->next;
        otherCurr = otherCurr->next;
    }
}

template<class DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked &other) {
    if (this != other) {
        clear();
        top = other->top;
    }
    return *this;
}

template<class DataType>
StackLinked<DataType>::~StackLinked() {
    clear();
}

template<class DataType>
void StackLinked<DataType>::push(const DataType &newDataItem) throw(logic_error){
    top = new StackNode(newDataItem, top);
}

template<class DataType>
DataType StackLinked<DataType>::pop() throw(logic_error) {
    if (isEmpty()) {
        throw logic_error("Cannot pop() from empty stack.");
    }

    DataType topData = top->dataItem;
    top = top->next;

    return topData;
}

template<class DataType>
void StackLinked<DataType>::clear() {
    StackNode *curr = top;
    StackNode *prev = nullptr;

    while (curr != nullptr) {
        prev = curr;
        curr = curr->next;

        delete prev;
    }
}

template<class DataType>
bool StackLinked<DataType>::isEmpty() const {
    return top == nullptr;
}

template<class DataType>
bool StackLinked<DataType>::isFull() const {
    return false;
}

template<class DataType>
void StackLinked<DataType>::showStructure() const {
    if (isEmpty()) {
        std::cout << "Empty Stack";
    } else {
        StackNode *curr = top;
        while (curr != nullptr) {
            std::cout << curr->dataItem << " ";
            curr = curr->next;
        }
    }

    std::cout << std::endl;
}

template<class DataType>
StackLinked<DataType>::StackNode::StackNode(const DataType &nodeData, StackNode *nextPtr) :
        dataItem(nodeData), next(nextPtr) {

}


#endif        //#ifndef STACKARRAY_H

