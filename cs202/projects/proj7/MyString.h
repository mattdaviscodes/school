/**
 * @brief  CS-202 Project 7 MyString class header
 * @Author Christos Papachristos (cpapachristos@unr.edu)
 * @date   March, 2018
 *
 * This file is the header file with the declaration of the Dynamic Allocation MyString class prescribed in Project 7 of CS-202
 */
 
#ifndef MYSTRING_H_
#define MYSTRING_H_

#include <iostream>
#include <cstring>

class MyString{

  public:
    MyString();							            //(1)
    MyString(const char * str);						    //(2)
    MyString(const MyString & other_myStr);				    //(3)
    ~MyString();							    //(4)

    size_t size() const;					            //(5)
    size_t length() const;						    //(6)
    const char* c_str() const;						    //(7)
    
    bool operator== (const MyString & other_myStr) const;	            //(8)
    MyString & operator= (const MyString & other_myStr);		            //(9)
    MyString operator+ (const MyString & other_myStr) const;	            //(10)
    char & operator[] (size_t index);					    //(11a)
    const char & operator[] (size_t index) const;			    //(11b)
    
friend std::ostream & operator<<(std::ostream & os, const MyString & myStr);   //(12)

  private:
    void buffer_deallocate();						    //(13)
    void buffer_allocate(size_t size);					    //(14)

    char * m_buffer;
    size_t m_size;
};

#endif //MYSTRING_H_

