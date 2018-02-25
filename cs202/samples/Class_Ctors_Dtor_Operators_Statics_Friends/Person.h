/**
 * @brief  CS-202 Class ctor(s) dtor(s) static(s) friend(s) Sample
 * @author Christos Papachristos (cpapachristos@unr.edu)
 * @date   February, 2018
 *
 * This file shows a sample declaration for a class Person that employs C++ class Constructors, Destructors, static Members, and friend(s) for the purposes of CS-202
 */
 
#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>

// Constants 
const int DEFAULT_AGE = 0;

const char DEFAULT_GENDER = '-';

const char GENDER_MALE = 'M';
const char GENDER_FEMALE = 'F';

class Person{

  // Insertion (output stream)
  friend std::ostream& operator<<(std::ostream& os, const Person& person);
  // Extraction (input stream)
  friend std::istream& operator>>(std::istream& is, Person& person);

  public:
    // Default ctor
    Person();
    // Parametrized ctor
    Person(const char* name, int age=DEFAULT_AGE, char gender=DEFAULT_GENDER);
    // Copy ctor
    Person(const Person& other);
   
    // Dtor
    /*~Person();*/

    // Assignment operator
    Person& operator=(const Person& rhs);  
    // Operator+ overload for int values (add years)
    Person& operator+(int years); 
    // Operator+ overload for const char * values (add name_suffix)
    Person& operator+(const char *name_suffix); 

    // Getters / Setters
    const char* GetName() const;
    void SetName(const char* name);
    int GetAge() const;
    void SetAge(int age);
    char GetGender() const;
 
    // Static member function - Getter for private static member variable
    static int GetCount();   

  private:
    // Member variables
    bool ParameterValidation() const;
    char m_name[255];
    int m_age;
    const char m_gender;
    
    // Static member variable
    static int s_count;
};

#endif //PERSON_H_

