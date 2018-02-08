//
// Created by Matthew Davis on 2/7/18.
//

#ifndef SCHOOL_NODE_H
#define SCHOOL_NODE_H


class Node {
//    private:
//

    public:
    int data;
    Node* next;
    Node();
    Node(int x);
    int getData();
    void setData(int x);
    void output();
    Node* getNext();
    void setNext(Node* node);
};

class LinkedList {
//    private:
//    Node* head;

    public:
    Node* head;
    LinkedList(Node* head);
    Node* getHead();
    Node* getTail();
    void append(Node* node);
    void output();
};


#endif //SCHOOL_NODE_H
