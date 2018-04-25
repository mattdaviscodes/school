//
// Created by Matthew Davis on 4/23/18.
//

#include "ArrayQueue.h"

ArrayQueue::ArrayQueue() {
    m_front = 0;
    m_back = 0;
    m_size = 0;
}

ArrayQueue::ArrayQueue(size_t count, const DataType &value) {
    m_front = 0;
    m_back = 0;
    m_size = 0;

    for (int i = 0; i < count; i++) {
        push(value);
    }
}

ArrayQueue::ArrayQueue(const ArrayQueue &other) {
    // Data is initialized as if the array
    // is empty (which it is at this point).
    // Both m_front and m_back are assigned
    // other.m_front, which means that the
    // AQ we're making will begin placing
    // data in the same place as other. After
    // all pushes are complete, the arrays
    // will be identical.
    m_front = other.m_front;
    m_back = other.m_front;
    m_size = 0;

    for (int i = 0; i < other.m_size; i++) {
        push(other.m_array[i + other.m_front]);
    }
}

ArrayQueue::~ArrayQueue() {
    
}

ArrayQueue &ArrayQueue::operator=(const ArrayQueue &rhs) {
    if (this != &rhs) {

        // Make sure to clean up whatever lhs is
        // currently holding
        clear();

        m_front = rhs.m_front;
        m_back = rhs.m_front;
        m_size = 0;

        for (int i = 0; i < rhs.m_size; i++) {
            push(rhs.m_array[i + rhs.m_front]);
        }
    }

    return *this;
}

//DataType &ArrayQueue::front() {
//    return <#initializer#>;
//}

//const DataType &ArrayQueue::front() const {
//    return <#initializer#>;
//}

//DataType &ArrayQueue::back() {
//    return <#initializer#>;
//}

//const DataType &ArrayQueue::back() const {
//    return <#initializer#>;
//}

void ArrayQueue::push(const DataType &value) {
    if (m_size != ARRAY_MAX) {

        if (!empty()) {
            m_back = (m_back + 1) % ARRAY_MAX;
        }


        m_array[m_back] = value;
        m_size++;
    }
}

void ArrayQueue::pop() {
    if (!empty()) {
        m_front++;
        m_size--;
    }
}

size_t ArrayQueue::size() const {
    return 0;
}

bool ArrayQueue::empty() const {
    return m_size == 0;
}

bool ArrayQueue::full() const {
    return m_size == ARRAY_MAX;
}

void ArrayQueue::clear() {
    m_front = 0;
    m_back = 0;
    m_size = 0;
}

void ArrayQueue::serialize(std::ostream &os) const {
    for (int i = 0; i < m_size; i++) {
        os << i << ": " << m_array[i + m_front];

        if (i != m_size - 1) {
            os << std::endl;
        }
    }
}

std::ostream &operator<<(std::ostream &os, const ArrayQueue &arrayQueue) {
    arrayQueue.serialize(os);
    return os;
}