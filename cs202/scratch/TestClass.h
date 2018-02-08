//
// Created by Matthew Davis on 2/7/18.
//

#ifndef SCHOOL_TESTCLASS_H
#define SCHOOL_TESTCLASS_H


class TestClass {
    public:
    TestClass();
    TestClass(int y);
    int getX();
    void setX(int y);
    void output();
    void incrementX();

    private:
    int x;
};



#endif //SCHOOL_TESTCLASS_H
