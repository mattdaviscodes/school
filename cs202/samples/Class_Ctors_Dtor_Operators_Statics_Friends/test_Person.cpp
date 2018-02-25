/**
 * @brief  CS-202 Class ctor(s) dtor(s) static(s) friend(s) Sample
 * @author Christos Papachristos (cpapachristos@unr.edu)
 * @date   February, 2018
 *
 * This file shows a sample implementation of code that uses a class Person that employs C++ class Constructors, Destructors, static Members, and friend(s) for the purposes of CS-202
 */
 
#include <iostream>

#include <cstring>  // remember, you are not supposed to use system built-in cstring header, at this point you are still implementing your own C-string functions 

// include class Person header (which holds all Declarations related with this class)
#include "Person.h"

using namespace std;

int main(){

  cout << endl << "Test Default ctor" << endl;
  Person p1;  

  cout << endl << "Test Getter functions" << endl;
  cout << p1.GetName() << " , " << p1.GetAge() << " , " << p1.GetGender() << endl;

  cout << endl << "Test Parametrized ctor" << endl;
  Person p2("Maria",25,'F');
 
  cout << endl << "Test insertion operator" << endl;
  cout << p2 << endl;


  cout << endl << "Count of valid Person objects so far:" << endl;
  cout << Person::GetCount() << endl;


  cout << endl << "Test Copy ctor" << endl;
  Person p3(p2);
  cout << p3 << endl;

  cout << endl << "Test Setter functions" << endl;
  p3.SetName("Hellen");
  p3.SetAge(33);
  cout << p3 << endl;


  cout << endl << "Test assignment operator" << endl;
  
  Person p4_male("John",20,'M');
  cout << p4_male << endl;
  p4_male = p3;
  cout << p4_male << endl;
  
  Person p4_female("Natasha",45,'F');
  cout << p4_female << endl;
  p4_female = p3;
  cout << p4_female << endl;


  cout << endl << "Test copy-initialization" << endl;
  Person p5 = p4_male;
  cout << p5 << endl;


  cout << endl << "Count of valid Person objects so far:" << endl;
  cout << Person::GetCount() << endl;


  cout << endl << "Test operator+ overload" << endl;
  p5 = p4_male + 5;
  cout << p5 << endl;
  p5 = p4_male + " Jr";
  cout << p5 << endl;
  p5 = (p5 + " the 3rd") + 10;
  cout << p5 << endl;

  cout << endl << "Test class Person done" << endl;

  return 0;
}

