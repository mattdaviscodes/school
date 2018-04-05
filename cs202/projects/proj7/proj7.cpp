//
// Created by Matthew Davis on 4/2/18.
//

#include <iostream>
#include <cstring>

#include "MyString.h"

int main() {
    //(1)
    std::cout << "Testing default constructor" << std::endl;
    std::cout << "=================" << std::endl;
    MyString ms_default;
    std::cout << std::endl;

    //(2)
    std::cout << "Testing parameterized constructor" << std::endl;
    std::cout << "=================" << std::endl;
    MyString ms_parametrized("MyString parametrized constructor!");
    std::cout << std::endl;

    //(3)
    std::cout << "Testing copy constructor" << std::endl;
    std::cout << "=================" << std::endl;
    MyString ms_copy(ms_parametrized);
    std::cout << std::endl;

    //(4)
    std::cout << "Testing destructor" << std::endl;
    std::cout << "=================" << std::endl;
    MyString * ms_Pt = new MyString("MyString to be deleted...");
    delete ms_Pt;
    ms_Pt = NULL;
    std::cout << std::endl;

    //(5),(6)
    std::cout << "Testing size and length methods" << std::endl;
    std::cout << "=================" << std::endl;
    MyString ms_size_length("Size and length test");
    std::cout << ms_size_length.size() << std::endl;
    std::cout << ms_size_length.length() << std::endl;
    std::cout << std::endl;

    //(7)
    std::cout << "Testing c_str method" << std::endl;
    std::cout << "=================" << std::endl;
    MyString ms_toCstring("C-String equivalent successfully obtained!");
    std::cout << ms_toCstring.c_str() << std::endl;
    std::cout << std::endl;

    //(8)
    std::cout << "Testing comparison operator" << std::endl;
    std::cout << "=================" << std::endl;
    MyString ms_same1("The same"), ms_same2("The same");
    if (ms_same1==ms_same2) {
        std::cout << "Same success" << std::endl;
    }
    MyString ms_different("The same (NOT)");
    if (!(ms_same1==ms_different)) {
        std::cout << "Different success" << std::endl;
    }
    std::cout << std::endl;

    //(9)
    std::cout << "Testing assignment operator" << std::endl;
    std::cout << "=================" << std::endl;
    MyString ms_assign("Before assignment");
    std::cout << ms_assign << std::endl;
    ms_assign = MyString("After performing assignment");
    std::cout << ms_assign << std::endl;
    std::cout << std::endl;

    //(10)
    std::cout << "Testing concatentation operator" << std::endl;
    std::cout << "=================" << std::endl;
    MyString ms_append1("The first part");
    MyString ms_append2(" and the second");
    MyString ms_concat = ms_append1+ ms_append2;
    std::cout << ms_concat << std::endl;
    std::cout << std::endl;

    //(11)
    std::cout << "Testing bracket operator" << std::endl;
    std::cout << "=================" << std::endl;
    MyString ms_access("Access successful (NOT)");
    ms_access[17] = 0;
    std::cout << std::endl;

    //12
    std::cout << "Testing insertion operator" << std::endl;
    std::cout << "=================" << std::endl;
    std::cout << ms_access << std::endl;
    std::cout << std::endl;

    std::cout << "-- END TESTS --" << std::endl;
    std::cout << std::endl;
    return 0;
}