/**
 * @brief  CS-202 Project 10 - ArrayStack class
 * @Author Matt Davis (mattdavis@nevada.unr.edu)
 * @date   5/1/18
 */

#ifndef SCHOOL_ARRAYSTACK_H
#define SCHOOL_ARRAYSTACK_H

#include <iostream>

template <class T, size_t MAX_STACKSIZE = 1000>
class ArrayStack;

template <class T, size_t MAX_STACKSIZE>
std::ostream & operator<<(std::ostream & os, const ArrayStack<T, MAX_STACKSIZE> & stack);

template <class T, size_t MAX_STACKSIZE>
class ArrayStack {
    friend std::ostream & operator<< <> (std::ostream & os, const ArrayStack<T, MAX_STACKSIZE> & stack);

public:
    ArrayStack() {
        m_top = 0;
    }

    ArrayStack(size_t count, const T & value) {
        m_top = 0;
        for (int i = 0; i < count; i++) {
            push(value);
        }
    }

    ArrayStack(const ArrayStack & other) {
        size_t size = other.size();

        m_top = 0;
        for (int i = 0; i < size; i++) {
            push(other.m_container[i]);
        }
    }
    ~ArrayStack() {

    }

    ArrayStack &operator=(const ArrayStack & rhs) {
        if (this != &rhs) {
            clear();

            size_t size = rhs.size();
            for (int i = 0; i < size; i++) {
                push(rhs.m_container[i]);
            }
        }

        return *this;
    }

    T & top() {
        return m_container[m_top-1];
    }
    const T & top() const {
        return m_container[m_top-1];
    }

    void push(const T & value) {
        if (!full()) {
            m_container[m_top++] = value;
        }
    }
    void pop() {
        if (!empty()) {
            m_top--;
        }
    }

    size_t size() const {
        return m_top;
    }
    bool empty() const {
        return m_top == 0;
    }
    bool full() const {
        return size() >= MAX_STACKSIZE;
    }
    void clear() {
        m_top = 0;
    }
    void serialize(std::ostream & os) const {
        size_t containerSize = size();
        for (int i = containerSize - 1; i >= 0; i--) {
            os << i << ": " << m_container[i];

            if (i > 0) {
                os << std::endl;
            }
        }
    }

private:
    T m_container[MAX_STACKSIZE];
    size_t m_top;
};

template <class T, size_t MAX_STACKSIZE>
std::ostream & operator<<(std::ostream & os, const ArrayStack<T, MAX_STACKSIZE> & stack) {
    stack.serialize(os);
    return os;
}


#endif //SCHOOL_ARRAYSTACK_H
