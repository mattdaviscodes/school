//
// Created by Matthew Davis on 2/7/18.
//

#include <iostream>
#include "TestClass.h"

TestClass::TestClass()
{
    x = 0;
}

TestClass::TestClass(int y)
{
    x = y;
}

int TestClass::getX()
{
    return x;
}

void TestClass::setX(int y)
{
    x = y;
}

void TestClass::output()
{
    std::cout << "TestClass(x=" << x << ")"<< std::endl;
}

void TestClass::incrementX()
{
    x++;
}