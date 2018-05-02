/**
 * @brief  CS-202 Project 10 - NodeStack class
 * @Author Matt Davis (mattdavis@nevada.unr.edu)
 * @date   5/1/18
 */

#ifndef SCHOOL_NODESTACK_H
#define SCHOOL_NODESTACK_H

#include <iostream>

template <class T>
class NodeStack;

template <class T>
std::ostream & operator<<(std::ostream & os, const NodeStack<T> & stack);

template <class T>
class Node {
    friend class NodeStack<T>;

public:
    Node() {
        m_next = NULL;
        m_data = T();
    };
    Node(const T & data, Node * next = NULL) {
        m_next = next;
        m_data = data;
    };

    T & data() {
        return m_data;
    };
    const T & data() const {
        return m_data;
    };

private:
    Node * m_next;
    T m_data;
};

template <class T>
class NodeStack {
    friend std::ostream & operator<< <> (std::ostream & os, const NodeStack<T> & stack);

public:
    NodeStack() {
        m_top = NULL;
    }

    NodeStack(size_t count, const T & value) {
        m_top = NULL;

        for (int i = 0; i < count; i++) {
            push(value);
        }
    }

    NodeStack(const NodeStack & other) {
        Node<T> * curr;
        size_t size = other.size();

        m_top = NULL;

        while (size) {
            curr = other.m_top;
            for (int i = 0; i < size - 1; i++) {
                curr = curr->m_next;
            }
            push(curr->data());
            size--;
        }
    }

    ~NodeStack() {
        clear();
    }

    NodeStack & operator=(const NodeStack & rhs) {
        if (this != &rhs) {

            // Make sure to clean up whatever lhs is
            // currently holding
            clear();

            Node<T> * curr;
            size_t size = rhs.size();

            m_top = NULL;

            while (size) {
                curr = rhs.m_top;
                for (int i = 0; i < size - 1; i++) {
                    curr = curr->m_next;
                }
                push(curr->data());
                size--;
            }
        }

        return *this;
    }

    T & top() {
        return m_top->data();
    }

    const T & top() const {
        return m_top->data();
    }

    void push(const T & value) {
        if (empty()) {
            m_top = new Node<T>(value);
        } else {
            m_top = new Node<T>(value, m_top);
        }
    }

    void pop() {
        if (!empty()) {
            Node<T> * tmp = m_top;
            m_top = m_top->m_next;
            delete tmp;
        }
    }

    size_t size() const {
        Node<T> * curr = m_top;

        size_t size = 0;
        while (curr) {
            size++;
            curr = curr->m_next;
        }

        return size;
    };

    bool empty() const {
        return m_top == NULL;
    }

    bool full() const {
        return false;
    }

    void clear() {
        Node<T> * curr = m_top;
        while(curr) {
            pop();
            curr = curr->m_next;
        }
    }

    void serialize(std::ostream & os) const {
        Node<T> * curr = m_top;

        size_t i = size() - 1;
        while (curr) {
            os << i << ": " << curr->data();

            if (curr->m_next) {
                os << std::endl;
            }

            curr = curr->m_next;
            i--;
        }
    }

private:
    Node<T> * m_top;

};

template <class T>
std::ostream & operator<<(std::ostream & os, const NodeStack<T> & stack) {
    stack.serialize(os);
    return os;
}


#endif //SCHOOL_NODESTACK_H
