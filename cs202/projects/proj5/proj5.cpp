/**
 * @brief  CS-202 Project 5 Test Driver
 * @Author Christos Papachristos (cpapachristos@unr.edu)
 * @date   March, 2018
 *
 * This file is a test driver for the Inheritance classes prescribed in Project 5 of CS-202
 */
 
#include <iostream>

#include "Vehicle.h"
#include "Car.h"

using namespace std;

int main(){

  cout << "\n" <<
          "////////////////////////////\n" <<
          "/////    Base Tests    /////\n" <<
          "////////////////////////////" << endl;

  cout << endl << "Testing Base Default ctor" << endl;
  Vehicle v1;

  cout << endl << "Testing Base insertion operator" << endl;
  cout << v1 << endl;
  cout << "Base idgen: " << Vehicle::getIdgen() << endl;
  
  cout << endl << "Testing Base Parametrized ctor" << endl;
  float lla_rno[3] = {39.54, 119.82, 4500.0};
  Vehicle v99(99, lla_rno);
  
  cout << v99 << endl;
  cout << "Base idgen: " << Vehicle::getIdgen() << endl;

  cout << endl << "Testing Base Copy ctor" << endl;
  Vehicle v99_cpy( v99 );  

  cout << v99_cpy << endl;
  cout << "Base idgen: " << Vehicle::getIdgen() << endl;

  cout << endl << "Testing Base Assignment operator" << endl;
  v1 = v99_cpy;
  cout << v1 << endl;
  cout << "Base idgen: " << Vehicle::getIdgen() << endl;

  cout << endl << "Testing Base Move Function" << endl;
  float lla_new[3] = {37.77, 122.42, 52.0};
  v1.move( lla_new );  


  cout << "\n" <<
          "////////////////////////////\n" <<
          "/////   Derived Tests  /////\n" <<
          "////////////////////////////" << endl;

  cout << endl << "Testing Derived Default ctor" << endl;
  Car c1;

  cout << endl << "Testing Derived insertion operator" << endl;
  cout << c1 << endl;
  cout << "Derived idgen: " << Car::getIdgen() << endl;
  
  cout << endl << "Testing Derived Parametrized ctor" << endl;
  char plates_999[] = "Gandalf";
  Car c999(plates_999, 999, lla_rno);
  
  cout << c999 << endl;
  cout << "Derived idgen: " << Car::getIdgen() << endl;

  cout << endl << "Testing Derived Copy ctor" << endl;
  Car c999_cpy( c999 );  

  cout << c999_cpy << endl;
  cout << "Derived idgen: " << Car::getIdgen() << endl;

  cout << endl << "Testing Derived Assignment operator" << endl;
  c1 = c999_cpy;
  cout << c1 << endl;
  cout << "Derived idgen: " << Car::getIdgen() << endl;

  cout << endl << "Testing Derived Move Function" << endl;
  c1.move( lla_new );  

  cout << "\n" <<
          "////////////////////////////\n" <<
          "/////    Tests Done    /////\n" <<
          "////////////////////////////" << endl;

  return 0;
  
}
