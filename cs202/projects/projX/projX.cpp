/**
 * @brief  CS-202 Project X - Test driver for SmartPtr class
 * @Author Matt Davis (mattdavis@nevada.unr.edu)
 * @date   4/10/18
 */

#include <iostream>

#include "SmartPtr.h"
#include "DataType.h"

int main() {
    std::cout << "##################\n"
              << "## CONSTRUCTORS ##\n"
              << "##################" << std::endl;
    SmartPtr sp1;   // Default-ctor

    // These will fail on deletion, because the two SPs
    // can't know that the other exists without using
    // the copy constructor. Instead, they assume they
    // are the only pointer to DT, and the first to be
    // destroyed also destroys DT, leaving the second
    // SP to fail on destruction because DT is gone.
    DataType * dtp1 = new DataType;
    SmartPtr sp2(dtp1);
    // SmartPtr sp3(dtp1);

    SmartPtr sp4(sp2);


    std::cout << std::endl
              << "##################\n"
              << "##  ASSIGNMENT  ##\n"
              << "##################" << std::endl;


    // The line below behaves strangely. Instead of calling the assignment
    // operator as expected, it calls the copy constructor. This has
    // something to do with "copy-initialization" and maybe "elision."
    // Not sure. More here: https://stackoverflow.com/a/1051468/8290310
    // SmartPtr sp5 = sp2;

    // These lines behave as expected, calling first the default ctor
    // then the assignment operator
    SmartPtr sp5;
    sp5 = sp2;

    std::cout << std::endl
              << "##################\n"
              << "##  STAR/ARROW  ##\n"
              << "##################" << std::endl;

    DataType * dtp2 = new DataType(5, 10.0);
    SmartPtr sp6(dtp2);
    std::cout << *sp6 << std::endl;
    sp6->setIntVal(3);
    std::cout << *sp6 << std::endl;

    std::cout << std::endl
              << "##################\n"
              << "##  DESTRUCTOR  ##\n"
              << "##################" << std::endl;

    // It is possible to call an object's destructor
    // directly, but it's probably a bad idea. In the
    // case below, sp5 will be destroyed twice, once
    // when I call the destructor, and once when the
    // object goes out of scope. This results in
    // undefined behavior. https://stackoverflow.com/a/11884236/8290310
    // sp5.~SmartPtr();


    return 0;
}