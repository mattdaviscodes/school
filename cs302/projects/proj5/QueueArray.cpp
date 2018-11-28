//
// Created by Matthew Davis on 11/12/18.
//

#include "QueueArray.h"

const int EMPTY_ARRAY = -1;

template <typename DataType>
QueueArray<DataType>::QueueArray(int maxNumber) : maxSize(maxNumber), front(EMPTY_ARRAY), back(EMPTY_ARRAY) {
    dataItems = new DataType[maxNumber];
}

// NOTE: This copy ctor will not respect the position of active elements within the copied queue.
// all data will be present and position correctly relative to other data points, but it will be
// stacked at index 0 in the array. Also, any data outside of the front-back bounds will be ignored.
template <typename DataType>
QueueArray<DataType>::QueueArray(const QueueArray &other) : maxSize(other.maxSize), front(EMPTY_ARRAY), back(EMPTY_ARRAY) {
    for (int i = other.front; i <= other.back; i++) {
        enqueue(other.dataItems[i]);
    }
}

template <typename DataType>
QueueArray<DataType>& QueueArray<DataType>::operator=(const QueueArray &other) {
    if (this != other) {
        clear();
        for (int i = other.front; i <= other.back; i++) {
            enqueue(other.dataItems[i]);
        }
    }
}

template <typename DataType>
QueueArray<DataType>::~QueueArray() {
    delete[] dataItems;
}

template <typename DataType>
void QueueArray<DataType>::enqueue(const DataType &newDataItem) throw(logic_error) {
    if (isFull()) {
        throw logic_error("Cannot enqueue while queue is full");
    }

    back++;
    back %= maxSize;    // ensure index wraps around array

    dataItems[back] = newDataItem;

    if (front == EMPTY_ARRAY) {
        front = 0;
    }
}

template <typename DataType>
DataType QueueArray<DataType>::dequeue() throw(logic_error) {
    if (isEmpty()) {
        throw logic_error("Cannot dequeue while queue is empty");
    }

    int frontIndex = front; // Save before changing value

    if (front == back) {
        // dequeued from one-item queue
        clear();
    } else {
        front++;
        front %= maxSize;
    }

    return dataItems[frontIndex];
}

template <typename DataType>
void QueueArray<DataType>::clear() {
    front = EMPTY_ARRAY;
    back = EMPTY_ARRAY;
}

template <typename DataType>
bool QueueArray<DataType>::isEmpty() const {
    return front == EMPTY_ARRAY;
}

template <typename DataType>
bool QueueArray<DataType>::isFull() const {
    int indexAfterBack = (back + 1) % maxSize;
    return front == indexAfterBack;
}

template <typename DataType>
void QueueArray<DataType>::putFront(const DataType &newDataItem) throw(logic_error) {
    if (isFull()) {
        throw logic_error("Cannot enqueue while queue is full");
    }

    front--;
    if (front < 0) {
        front = maxSize - 1;    // Same wrap-around as above, but mod doesn't work with underflow
    }

    dataItems[front] = newDataItem;
}

template <typename DataType>
DataType QueueArray<DataType>::getRear() throw(logic_error) {
    if (isEmpty()) {
        throw logic_error("Cannot dequeue while queue is empty");
    }

    int backIndex = back;
    back--;
    if (back == front - 1) {
        // dequeued from one-item queue
        clear();
    } else if (back < 0) {
        back = maxSize - 1;
    }

    return dataItems[backIndex];
}

template <typename DataType>
int QueueArray<DataType>::getLength() const {
    if (isEmpty()) {
        return 0;
    } else if (front > back ) {
        return maxSize - front + back + 1;
    } else {
        return back - front + 1;
    }
}

template <typename DataType>
void QueueArray<DataType>::showStructure() const
// Array implementation. Outputs the data items in a queue. If the
// queue is empty, outputs "Empty queue". This operation is intended
// for testing and debugging purposes only.

{
    int j;   // Loop counter

    if ( front == -1 )
        cout << "Empty queue" << endl;
    else
    {
        cout << "Front = " << front << "  Back = " << back << endl;
        for ( j = 0 ; j < maxSize ; j++ )
            cout << j << "\t";
        cout << endl;
        if ( back >= front )
            for ( j = 0 ; j < maxSize ; j++ )
                if ( ( j >= front ) && ( j <= back ) )
                    cout << dataItems[j] << "\t";
                else
                    cout << " \t";
        else
            for ( j = 0 ; j < maxSize ; j++ )
                if ( ( j >= front ) || ( j <= back ) )
                    cout << dataItems[j] << "\t";
                else
                    cout << " \t";
        cout << endl;
    }
}