/**
 * @brief  CS-302 Project 1 - LinkedList class
 * @Author Matt Davis (mattdavis@nevada.unr.edu)
 * @date   9/10/18
 */

#ifndef SCHOOL_LINKEDLIST_H
#define SCHOOL_LINKEDLIST_H

#include <iostream>

template<class T>
class LinkedList;

template<class T>
std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list);

template<class T>
class Node {
    friend class LinkedList<T>;

public:
    Node() : m_next(NULL), m_data(T()) {}

    Node(const T data) : m_next(NULL), m_data(data) {}

    T &data() {
        return m_data;
    }

    Node<T> *next() {
        return m_next;
    }

private:
    Node<T> *m_next;
    T m_data;
};

template<class T>
class LinkedList {
    friend std::ostream &operator<<<>(std::ostream &os, const LinkedList<T> &list);

public:
    LinkedList() : pfirst(NULL), plast(NULL), m_len(0) {}

    void push(const T &item) {
        if (m_len == 0) {
            pfirst = new Node<T>(item);
            plast = pfirst;
        } else {
            Node<T> *tmp = plast;
            plast = new Node<T>(item);
            tmp->m_next = plast;
        }

        m_len++;
    }

    bool pop() {
        Node<T> *curr = pfirst;
        Node<T> *prev = NULL;

        if (m_len == 0) {
            return false;
        }

        while (curr->m_next) {
            prev = curr;
            curr = curr->m_next;
        }

        prev->m_next = NULL;
        plast = prev;
        m_len--;
        delete curr;

        return true;
    }

    int len() {
        return m_len;
    }

    void set_last(const Node<T> * last) {
        plast = last;
    }

private:
    Node<T> *pfirst;
    Node<T> *plast;
    int m_len;
};

template<class T>
std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list) {
    Node<T> *curr = list.pfirst;

    while (curr != NULL) {
        os << curr->data() << " ";
        curr = curr->next();
    }
    return os;
}

#endif //SCHOOL_LINKEDLIST_H
