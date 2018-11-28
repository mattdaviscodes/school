//--------------------------------------------------------------------
//
//  StackLinked.h
// 
//  Class declaration for the linked implementation of the Stack ADT
//
//--------------------------------------------------------------------

#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

const int EMPTY_STACK = -1;

template<typename DataType>
class StackArray : public Stack<DataType> {
public:
    StackArray(int maxNumber = Stack<DataType>::MAX_STACK_SIZE);

    StackArray(const StackArray &other);

    StackArray &operator=(const StackArray &other);

    ~StackArray();

    void push(const DataType &newDataItem) throw(logic_error);

    DataType pop() throw(logic_error);

    void clear();

    bool isEmpty() const;

    bool isFull() const;

    void showStructure() const;

private:
    int maxSize;
    int top;
    DataType *dataItems;
};

template<typename DataType>
StackArray<DataType>::StackArray(int maxNumber) : maxSize(maxNumber), top(EMPTY_STACK) {
    dataItems = new DataType[maxSize];
};

template<typename DataType>
StackArray<DataType>::StackArray(const StackArray &other) : maxSize(other.maxSize), top(other.top) {
    dataItems = new DataType[maxSize];
    for (int i = 0; i < top; i++) {
        dataItems[i] = other.dataItems[i];
    }
}

template<typename DataType>
StackArray<DataType>& StackArray<DataType>::operator=(const StackArray &other) {
    if (this != other) {
        delete dataItems;
        maxSize = other.maxSize;
        top = other.top;
        dataItems = new DataType[maxSize];
        for (int i = 0; i < top; i++) {
            dataItems[i] = other.dataItems[i];
        }
    }
    return this;
}

template<typename DataType>
StackArray<DataType>::~StackArray() {
    delete dataItems;
}

template<typename DataType>
void StackArray<DataType>::push(const DataType &newDataItem) throw(logic_error) {
    if (isFull()) {
        throw logic_error("Canot push() to full stack");
    }

    dataItems[++top] = newDataItem;
}

template<typename DataType>
DataType StackArray<DataType>::pop() throw(logic_error) {
    if (isEmpty()) {
        throw logic_error("Cannot pop() from empty stack");
    }

    top--;
    return dataItems[top + 1];
}

template<typename DataType>
void StackArray<DataType>::clear() {
    top = EMPTY_STACK;
}

template<typename DataType>
bool StackArray<DataType>::isEmpty() const {
    return top == EMPTY_STACK;
}

template<typename DataType>
bool StackArray<DataType>::isFull() const {
    return top == maxSize - 1;
}

template<typename DataType>
void StackArray<DataType>::showStructure() const {
    if (isEmpty()) {
        std::cout << "Empty Stack";
    } else {
        for (int i = 0; i <= top; i++) {
            std::cout << dataItems[i] << " ";
        }
    }

    std::cout << std::endl;
}

#endif        //#ifndef STACKARRAY_H
