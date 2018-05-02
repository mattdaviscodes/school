//
// Created by Matthew Davis on 4/28/18.
//

#ifndef SCHOOL_STACK_H
#define SCHOOL_STACK_H

#include <iostream>

template <class T>
class Stack;

template <class T>
std::ostream & operator<<(std::ostream & os, const Stack<T> & stack);

template <class T>
class Stack {

private:


};

template <class T>
std::ostream & operator<<(std::ostream & os, const Stack<T> & stack) {
    return os;
}


#endif //SCHOOL_STACK_H
