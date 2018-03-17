/**
 * @brief  CS-202 Project 6 Test Driver
 * @Author Christos Papachristos (cpapachristos@unr.edu)
 * @date   March, 2018
 *
 * This file is a test driver for the Polymorphic classes prescribed in Project 6 of CS-202
 */
 
#include <iostream>

#include "Car.h"

using namespace std;

int main(){

  cout << "\n" <<
          "////////////////////////////////\n" <<
          "/////   Constructor Tests  /////\n" <<
          "////////////////////////////////" << endl;

  cout << endl << "Testing Derived Default ctor" << endl;
  Car c1;
  
  cout << endl << "Testing Derived Parametrized ctor" << endl;
  float lla_rno[3] = {39.54, 119.82, 4500.0};
  Car c_rno(lla_rno);

  cout << endl << "Testing Derived Copy ctor" << endl;
  Car c_cpy( c_rno );  

  cout << endl << "Testing Derived Assignment operator" << endl;
  c1 = c_cpy;

  cout << "\n" <<
          "/////////////////////////////////\n" <<
          "/////   Polymorphism Tests  /////\n" <<
          "/////////////////////////////////" << endl;

  cout << endl << "Testing VIRTUAL Move Function for DERIVED Class Objects" << endl;
  float lla_new[3] = {37.77, 122.42, 52.0};
  c1.Move( lla_new );  

  cout << endl << "Testing Insertion operator<< Overload for BASE Class Objects" << endl;
  cout << c_rno << endl;


  // Just setting some distinct values to our objects again here
  float lla_ny[3] = {40.71, 74.00, 10.0};
  c1.SetLLA( lla_ny );
  float lla_la[3] = {34.05, 118.24, 71.01};
  c_cpy.SetLLA( lla_la );


  cout << "\n" <<
          "///////////////////////////////////////////////////\n" <<
          "/////   Polymorphic Base Class Pointer Tests  /////\n" <<
          "///////////////////////////////////////////////////" << endl;

  Vehicle* vehicles_array[3];
  vehicles_array[0] = &c1;
  vehicles_array[1] = &c_rno;
  vehicles_array[2] = &c_cpy;

  cout << endl << "Testing VIRTUAL Move Function on Base Class Pointers" << endl;
  for (int i=0; i<3; ++i){
    vehicles_array[i]->Move( lla_new );
  }

  cout << endl << "Testing Insertion operator<< Overload for Base Class Pointers" << endl;
  for (int i=0; i<3; ++i){
    cout << *vehicles_array[i] << endl;
  }

  cout << "\n" <<
          "////////////////////////////\n" <<
          "/////    Tests Done    /////\n" <<
          "////////////////////////////" << endl;

  return 0;
  
}
