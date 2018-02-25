/**
 * @brief  CS-202 Composite Class ctor(s) dtor(s) and const-Qualifier(s) Sample
 * @author Christos Papachristos (cpapachristos@unr.edu)
 * @date   February, 2018
 *
 * This file shows a sample declaration for a Composite class Department that "has"/"owns" (Composition relationship) an array of class Person objects for the purposes of CS-202
 * A deeper discussion of const-Qualification of member functions is also provided, with code samples and in-line comments
 */
 
#ifndef DEPARTMENT_H_
#define DEPARTMENT_H_

#include <iostream>

#include "Person.h"

const int MAX_PEOPLE = 3; 

class Department{

  // Insertion (output stream)
  friend std::ostream & operator<<(std::ostream & os, const Department & d);
  // Extraction (input stream)
  friend std::istream & operator>>(std::istream & is, Department & d);

  public:
    // No Default / Parametrized / Copy ctor or Assignment operator= provided: The compiler will synthesize a Default-ctor/ a Copy-ctor / an Assignment operator= automatically
    // Reminder: default Default-ctor will use data members' own Default-ctors, while default Copy-ctor and Assignment operator= are generated as Member-Copy ones (i.e. Shallow-Copying)

    /* SOME EXTRAS:
     *  You may in some cases wish to COMPLETELY DISALLOW any possibility of calling a class' Copy-ctor (e.g. you create a "utility" class which only implements static methods, therefore
     *  there is no sense of a class instance to exist, or you create a "singleton" class, for which only a single object can exist at any given time)
     *  In such cases you can put the Copy-ctor under the private access-specifier level -e.g. make it inaccessible from outside the class-
     *  You can do that generally with any member function but usually the consequences and additional considerations (e.g. implicit Copy-ctor calls by returning/passing by-Value,
     *  or copy-initializations ,even when the Copy-ctor is "ellided") can be hard to take care of and some times will produce warnings instead of direct compilation errors
     */

    //Department();
    //Department(params);
    //Department(const Department& other);

    //Department& operator=(const Department& rhs);


    /* const and non-const qualification of member functions produces different function signatures:
     * Therefore 2 different functions with the same name can exist (a const and a non-const qualified) and which one will be chosen when you call it depends on function overload resolution:
     * a) when called on a const object the const variant will be selected 
     *    e.g. const Department d1; d1.getRoster();  //chooses const-qualified version (d1 object is const)
     *         Department d2; const Department* d2_p=&d2; d2->getRoster();  //chooses const-qualified version (d2 object is not const, but function is called through d2_p which points to const data)
     * b) when called on a non-const object and a non-const variant exists, the non-const variant will be preferred
     *    e.g. Department d2; d2.getRoster();  //chooses the non-const-qualified version
     */

    // const-qualified getter function, way to access internal data by-const-Address
    // (ensured that underlying data cannot be mutated, via return type being pointer to const data)
    const Person * getRoster() const;

    // non-const-qualified Getter function, way to access internal data by-Address
    // (underlying data can be mutated, via return type being pointer to non-const data)
    Person * getRoster();

    // const-qualified operator[] function overload, way to access internal data by-const-Reference
    // (ensured that underlying data cannot be mutated, via return type being const-Reference)
    const Person & operator[](size_t i) const;

    // non-const-qualified operator[] function overload, way to access internal data by-Reference
    // (underlying data can be mutated, via return type being non-const Reference)
    Person & operator[](size_t i);

  private:
    // Array of class Person objects: At instatiation of a new Department object enough memory for the entire array will be allocated, and will
    // be filled with new Person objects constructed with their Default ctor method (i.e. the class Person Default ctor will be called 3 times)
    Person m_roster[MAX_PEOPLE]; 
};

#endif //DEPARTMENT_H_
