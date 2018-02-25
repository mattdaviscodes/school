/**
 * @brief  CS-202 Composite Class ctor(s) dtor(s) and const-Qualifier(s) Sample
 * @author Christos Papachristos (cpapachristos@unr.edu)
 * @date   February, 2018
 *
 * This file shows a sample implementation of code that uses a class Department that employs a Composition relationship with a class Person for the purposes of CS-202
 */
 
#include <iostream>

#include <cstring>

#include "Department.h"
#include "Person.h"

using namespace std;

int main(){

  cout << endl << "Test Default ctor" << endl;
  Department d1;

  cout << endl << "Count of existing Person objects so far:" << endl;
  cout << Person::getCount() << std::endl;

  // the Department object is non-const and a non-const-qulified version of GetRoster exists, therefore overload resolution for GetRoster() will prefer the non-const-qualified version
  // Note: you CAN safely assign the returned pointer to a non-const one like "Person* person_const_pt = ..." here
  cout << endl << "Test Getter functions (non-const-versions)" << endl;
  Person * person_pt = d1.getRoster();
  for (size_t i=0; i<MAX_PEOPLE; ++i, ++person_pt){
    cout << endl << "Input " << i << " person data, usage: Name, Age, Gender(M/F)" << endl;
    cin >> *person_pt;
  }

  cout << endl << "Test Getter functions (const-versions)" << endl;
  // static_cast<const Department&>(d1) "temporarily converts" the Department object d1 into a const one, therefore overload resolution for GetRoster() will choose the const-qualified version
  // Note: you CANNOT assign the returned pointer to a non-const one like "Person* person_const_pt = ..." because that would discard its const qualifiers
  const Person * const_person_pt = static_cast<const Department &>(d1).getRoster();  
  for (size_t i=0; i<MAX_PEOPLE; ++i, ++const_person_pt){
    cout << *const_person_pt << endl;
  }

  cout << endl << "Test extraction operator" << endl;
  cout << endl << "Input person data for 3 Person objects in total, usage: Name, Age, Gender(M/F)" << endl;
  cin >> d1;

  cout << endl << "Test insertion operator" << endl;
  cout << d1 << endl;

  // the Department object is non-const, and therefore overload resolution will prefere the non-const-qualified variant of GetRoster()
  // Note: you CAN now use the returned non-const-Reference to mutate the private data members of the Department (i.e. the corresponding Person object within the m_roster array)
  cout << endl << "Test operator[] overload (non-const-version)" << endl;
  cout << "Input 2nd person data";
  cin >> d1[1];

  // this time we produce a const Department* which is const-qualified (even though the underlying object is not an originally constant object) and the const-qualified variant of GetRoster() is selected
  // Note: you CANNOT use the returned const-Reference to mutate the corresponding Person object, but you can still use other const-qualified functions or functions working with const-qualified objects
  cout << endl << "Test operator[] overload (const-version)" << endl;
  const Department * d_pt = &d1;
  cout << "Output 2nd person data";
  cout << (*d_pt)[1] << endl;
    
  cout << endl <<"Test class Department done" << endl;
  
  return 0;
}

