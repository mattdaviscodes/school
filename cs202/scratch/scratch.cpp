//
// Created by Matthew Davis on 2/1/18.
//



#include <iostream>
#include "Node.h"

using namespace std;

int main() {
    Node head(1), tail(2);
    head.setNext(&tail);
    head.output();
    tail.output();

    LinkedList ll(&head);
    ll.getHead();
//    ll.getTail();
    cout << (ll.head == NULL) << endl;
//    cout << *(ll.head).data << endl;
    Node *test = ll.head;
    cout << *test << endl;

//    int i = 5;
//    int &i_ref = i;
//    int *i_ptr = &i;
//    int *i_ptr2 = i_ptr;
//    int *&i_ptr_ref = i_ptr;
//
//    cout << i << endl;
//    cout << i_ref << endl;
//    cout << i_ptr << endl;
//    cout << i_ptr2 << endl;
//    cout << i_ptr_ref << endl;
//    cout << endl;
//
//    i = 6;
//    cout << i << endl;
//    cout << i_ref << endl;
//    cout << i_ptr << endl;
//    cout << i_ptr2 << endl;
//    cout << i_ptr_ref << endl;


    return 0;
}