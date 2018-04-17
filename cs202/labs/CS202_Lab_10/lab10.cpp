#include <iostream>

#include "DataType.h"

using namespace std;


class Node {

public:
    Node() {
        m_data = NULL;
        m_next = NULL;
    }

    Node(DataType &data) {
        m_data = &data;
        m_next = NULL;
    }

    Node *getNext() {
        return m_next;
    }

    void setNext(Node *next) {
        m_next = next;
    }

private:
    DataType *m_data;
    Node *m_next;

};


class LinkedList {

public:

    LinkedList();

    void push_last(const DataType &value);

    size_t size() const;

private:

    Node *m_head;

};

LinkedList::LinkedList() {
    m_head = NULL;
}

void LinkedList::push_last(const DataType &value) {
    Node *curr = m_head;
    while (curr = curr->getNext()) {

    }

    curr = new Node(value);
}

size_t LinkedList::size() const {
    int i = 0;
    for (Node *curr = m_head; curr != NULL; curr = curr->getNext()) {
        i++;
    }
    return i;
}


int main() {

    LinkedList list;
    cout << endl << list.size() << endl;

    DataType dt_01(0, 1.0);
    list.push_last(dt_01);
    cout << endl << list.size() << endl;
//
//    DataType dt_12(1, 2.0);
//    list.push_last(dt_12);
//    cout << endl << list.size() << endl;
}

