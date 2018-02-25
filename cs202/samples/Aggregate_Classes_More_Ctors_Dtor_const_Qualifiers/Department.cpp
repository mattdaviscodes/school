/**
 * @brief  CS-202 Composite Class ctor(s) dtor(s) and const-Qualifier(s) Sample
 * @author Christos Papachristos (cpapachristos@unr.edu)
 * @date   February, 2018
 *
 * This file shows a sample implementation for a Composite class Department that "has"/"owns" (Composition relationship) an array of class Person objects for the purposes of CS-202
 * A deeper discussion of const-Qualification of member functions is also provided, with code samples and in-line comments 
 */
 
#include "Department.h"

// Note: A const-qualified function is called on a const-qualified object, this means that within the implementation of the function the implicit "this->" that is inserted whenever you are
// referring to member variables and/or methods (e.g. to the compiler "m_roster" in fact means "this->m_roster") is treated as a pointer to a const object!
// This means that you CANNOT do the following as "this->m_roster" is also treated as a const array because "this" is const
//   Person * Department::getRoster() const{
//     return m_roster;
//   } 
// Whereas you CAN do the following because now you are returning a pointer to const data (the array of Person objects)
//   const Person * Department::getRoster() const{
//     return m_roster;
//   } 

// const-qualified Getter function, way to access internal data by-const-Address
const Person * Department::getRoster() const{
  return m_roster;
}

// Note: Here on the other hand that the implicit "this->" is no longer const-qualified you may safely return a non-const pointer to the array

// non-const-qualified Getter function, way to access internal data by-Address
Person * Department::getRoster(){
  return m_roster;
}

// const-qualified operator[] function overload, way to access internal data by-const-Reference
const Person & Department::operator[](size_t i) const{
  return m_roster[i];
}

// non-const-qualified operator[] function overload, way to access internal data by-Reference
Person & Department::operator[](size_t i) {
  return m_roster[i];
}


// Outputs the m_roster data: Exploits the fact that operator<< is oveloaded already for Person objects by the class Person itself
std::ostream & operator<<(std::ostream & os, const Department & d){
  for (size_t i=0; i<MAX_PEOPLE; ++i){
    os << d.m_roster[i] << std::endl;
  }
  return os;
}

// Inputs m_roster data: Exploits the fact that operator>> is oveloaded already for Person objects by the class Person itself
std::istream & operator>>(std::istream & is, Department & d){
  for (size_t i=0; i<MAX_PEOPLE; ++i){
    is >> d.m_roster[i];
  }
  return is;
}


