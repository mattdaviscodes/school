/**
 * @brief  CS-202 Class ctor(s) dtor(s) static(s) friend(s) Sample
 * @author Christos Papachristos (cpapachristos@unr.edu)
 * @date   February, 2018
 *
 * This file shows a sample implementation of code for a class Person that employs C++ class Constructors, Destructors, static Members, and friend(s) for the purposes of CS-202
 */
 
#include <iostream>

#include <cstring>  // remember, you are not supposed to use system built-in cstring header, at this point you are still implementing your own C-string functions 

// include class Person header (which holds all Declarations related with this class)
#include "Person.h"  

// Definition of static member variable (remember, class Declaration holds the Declaration of member function(s), member variable(s), and you
// need to provide their Definition here in the source file (a Definition is required for all member function(s) and for all static member variable(s))   
int Person::s_count = 0; // definition also initializes static member variable to 0

// Default ctor
Person::Person() :
  m_gender(DEFAULT_GENDER)  // const variable requires definition at instantiation, do this with an initialization list
{
  // Call facilitator without checking for output (just to produce the error stream), we already know that the object will be invalid due to m_gender(DEFAULT_GENDER) 
  ParameterValidation();
  // No incrementing of count here since the object will certainly be invalid 
  //++s_count;
}

// Parametrized ctor
Person::Person(const char* name, int age, char gender) :
  m_age(age) ,  								// instantiate m_age based on passed argument for age
  m_gender(   gender == GENDER_MALE ? GENDER_MALE :				// instantiate m_gender based on passed argument for gender 
            ( gender == GENDER_FEMALE ? GENDER_FEMALE : DEFAULT_GENDER )	// (but also evaluate expression of ternary operator that only evaluates to GENDER_MALE / GENDER_FEMALE / DEFAULT_GENDER)
          )
{
  // Call facilitator to check whether the parameters are valid, will either produce error stream and directly return from ctor or allow to proceed following lines
  if (!ParameterValidation()){
    return;
  }

  // call setter function based on passed argument for name 
  SetName(name);
  
  // increment valid objects count
  ++s_count;
}

// Copy ctor
Person::Person(const Person& other) : 
  m_age(other.m_age) , 		// instantiate m_age based on pass other object's m_age
  m_gender(other.m_gender)  	// instantiate m_gender based on pass other object's m_gender
{
  // Call facilitator to check whether the parameters are valid, will either produce error stream and directly return from ctor or allow to proceed following lines
  if (!ParameterValidation()){
    return;
  }

  // call setter function based on other object's m_name 
  SetName(other.m_name);

  
  // increment valid objects count
  ++s_count;
}

// Dtor
/*Person::~Person(){
  // Call facilitator to check whether the parameters are valid, will only allow decrementing the valid Person object(s) count if the object being destroyed was originally valid and increased the count
  if (ParameterValidation()){
    --s_count;
  }
}*/

// Assignment operator
Person& Person::operator=(const Person& rhs){
  // Check for Self-Assignment
  if (this != &rhs){
    // Call facilitator to check whether the other object's parameters are valid, will produce error stream and not allow anything to proceed it not
    if (rhs.ParameterValidation()){
      // Check to see if assigning from same-constant object, otherwise produce error stream and not allow anything to proceed
      if (m_gender != rhs.m_gender){
        std::cerr << "Error assigning between incompatible Person objects, calling object unaffected" << std::endl;
      }  
      else{
        SetAge(rhs.m_age);
        SetName(rhs.m_name);
      }
    }
  }
  return *this;  //return by-Reference the calling Person object (dereferencing this (*this), i.e. the pointer to calling object)
}

// Operator+ overload (add years)
Person& Person::operator+(int years){
  m_age += years;
  return *this;  //return by-Reference the calling Person object (dereferencing this (*this), i.e. the pointer to calling object)
}

// Operator+ overload (add name_suffix)
Person& Person::operator+(const char *name_suffix){
  strcat(m_name, name_suffix);
  return *this;  //return by-Reference the calling Person object (dereferencing this (*this), i.e. the pointer to calling object)
}

// Getter
const char* Person::GetName() const{  // const member function, calling object's members cannot be modified, has to return pointer to const member data
  return m_name;
}

// Setter
void Person::SetName(const char* name){
  strcpy(m_name, name);
}

// Getter
int Person::GetAge() const{  // const member function, calling object's members cannot be modified, returns copy-of const member data (also top level cv qualifiers on non-class types ignored)
  return m_age;
}

// Setter
void Person::SetAge(int age){
  m_age = age;
}

// Getter
char Person::GetGender() const{  // const member function, calling object's members cannot be modified, returns copy-of const member data (also top level cv qualifiers on non-class types ignored)
  return m_gender;
}

// Setter for const m_gender member does not make sense
//void Person::SetGender(char gender){
//}

// Facilitator function which checks object's critical parameters to see if they are valid 
bool Person::ParameterValidation() opeconst{  // const member function, calling object's members cannot be modified
  //if (m_gender!=GENDER_MALE && m_gender!=GENDER_FEMALE){  // if the m_gender is not one of the 2 allowed options, returns false and produces error stream 
  if (m_gender==DEFAULT_GENDER){  // alternative implementation, since the default and parametrized ctor ensure that m_gender will only be one of GENDER_MALE / GENDER_FEMALE / DEFAULT_GENDER
    std::cerr << "Error in Person object: (m_gender==DEFAULT_GENDER)" << std::endl;
    return false;
  }
  return true;
}

// Static member function (only accesses and static member data i.e. s_count), returns copy-of private member variable (acts as another Getter, just for a static member)
int Person::GetCount(){
  return s_count;
}

// Not providing a Setter for this, in order to restrict modifying this count variable to the internal workings of the class
//void Person::SetCount(){
//}


// Overloading insertion operator<< function for const-Reference to (not allowed to be modified) Person objects 
std::ostream& operator<<(std::ostream& os, const Person& p){
  os << "Name: " << p.m_name << ",\tAge: " << p.m_age << ",\tGender: " << p.m_gender;  //function declared as class friend gives direct access to private data
  return os;  //return the std::ostream object by-Reference for cascading
}

// Overloading extraction operator>> function for Reference to (not allowed to be modified) Person objects 
std::istream& operator>>(std::istream& is, Person& p){
  is >> p.m_name >> p.m_age;  //function declared as class friend gives direct access to private data
  return is;  //return the std::istream object by-Reference for cascading
}
