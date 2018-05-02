//
// Created by Matthew Davis on 4/30/18.
//

#include "ArrayStack.h"
#include "NodeStack.h"

int main() {
    std::cout << "============================\n"
              << "||    NODE STACK TESTS    ||\n"
              << "============================" << std::endl << std::endl;

    std::cout << "DEFAULT CTOR\n"
              << "no output expected\n"
              << "==================" << std::endl;
    NodeStack<int> ns_default_int;
    NodeStack<double> ns_default_dbl;
    std::cout << ns_default_int << std::endl;
    std::cout << ns_default_dbl << std::endl;

    std::cout << "PARAMETERIZED CTOR\n"
              << "==================" << std::endl;
    NodeStack<int> ns_param_int(2, 2);
    NodeStack<double> ns_param_dbl(2, 2.2);
    std::cout << ns_param_int << std::endl << std::endl;
    std::cout << ns_param_dbl << std::endl << std::endl;

    std::cout << "COPY CTOR\n"
              << "=========" << std::endl;
    NodeStack<int> ns_copy_int(ns_param_int);
    NodeStack<double> ns_copy_dbl(ns_param_dbl);
    std::cout << ns_copy_int << std::endl << std::endl;
    std::cout << ns_copy_dbl << std::endl << std::endl;

    std::cout << "ASSIGNMENT OPERATOR\n"
              << "===================" << std::endl;
    NodeStack<int> ns_assign_int;
    NodeStack<double> ns_assign_dbl;
    ns_assign_int = ns_param_int;
    ns_assign_dbl = ns_param_dbl;
    std::cout << ns_assign_int << std::endl << std::endl;
    std::cout << ns_assign_dbl << std::endl << std::endl;

    std::cout << "PUSH AND POP\n"
              << "============" << std::endl;
    ns_assign_int.push(3);
    ns_assign_dbl.pop();
    std::cout << ns_assign_int << std::endl << std::endl;
    std::cout << ns_assign_dbl << std::endl << std::endl;

    std::cout << "============================\n"
              << "||   ARRAY STACK TESTS    ||\n"
              << "============================" << std::endl << std::endl;

    std::cout << "DEFAULT CTOR\n"
              << "no output expected\n"
              << "==================" << std::endl;
    ArrayStack<int> as_default_int;
    ArrayStack<double> as_default_dbl;
    std::cout << as_default_int << std::endl;
    std::cout << as_default_dbl << std::endl;

    std::cout << "PARAMETERIZED CTOR\n"
              << "==================" << std::endl;
    ArrayStack<int> as_param_int(2, 2);
    ArrayStack<double> as_param_dbl(2, 2.2);
    std::cout << as_param_int << std::endl << std::endl;
    std::cout << as_param_dbl << std::endl << std::endl;

    std::cout << "COPY CTOR\n"
              << "=========" << std::endl;
    ArrayStack<int> as_copy_int(as_param_int);
    ArrayStack<double> as_copy_dbl(as_param_dbl);
    std::cout << as_copy_int << std::endl << std::endl;
    std::cout << as_copy_dbl << std::endl << std::endl;

    std::cout << "ASSIGNMENT OPERATOR\n"
              << "===================" << std::endl;
    ArrayStack<int> as_assign_int;
    ArrayStack<double> as_assign_dbl;
    as_assign_int = as_param_int;
    as_assign_dbl = as_param_dbl;
    std::cout << as_assign_int << std::endl << std::endl;
    std::cout << as_assign_dbl << std::endl << std::endl;

    std::cout << "PUSH AND POP\n"
              << "============" << std::endl;
    as_assign_int.push(3);
    as_assign_dbl.pop();
    std::cout << as_assign_int << std::endl << std::endl;
    std::cout << as_assign_dbl << std::endl << std::endl;

    return 0;
}