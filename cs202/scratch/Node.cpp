//
// Created by Matthew Davis on 2/7/18.
//

#include <iostream>
#include "Node.h"

using namespace std;

Node::Node() {
    data = 0;
    next = NULL;
}

Node::Node(int x) {
    setData(x);
    next = NULL;
}

int Node::getData() {
    return data;
}

void Node::setData(int x) {
    data = x;
}

void Node::output() {
    cout << "Node(data=" << getData() << ", next=" << next << ")" << endl;
}

Node *Node::getNext() {
    return next;
}

void Node::setNext(Node *node) {
    next = node;
}

/* BEGIN LINKED LIST */
LinkedList::LinkedList(Node *head) {
    head = head;
}

Node *LinkedList::getHead() {
    return head;
}

Node *LinkedList::getTail() {
    Node *current = head;

    while (current->getNext() != NULL) {
        cout << "ding" << endl;
        current = current->getNext();
    }



    return current;
}

void LinkedList::append(Node *node) {
    Node *tail = getTail();
    tail->setNext(node);
}

//void LinkedList::output() {
//    Node *current = head;
//    cout << "LinkedList: ";
//
//    do {
//        current->output();
//    } while (current = current->getNext());
//
//}

void LinkedList::output() {
    cout << head << endl;
}