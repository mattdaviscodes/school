/**
 * @brief  CS-202 Composite Class ctor(s) dtor(s) and const-Qualifier(s) Sample
 * @author Christos Papachristos (cpapachristos@unr.edu)
 * @date   February, 2018
 *
 * This file shows a sample declaration for a class Person that will be used by a class Department in a Composition relationship for the purposes of CS-202
 */
 
#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>

const int DEFAULT_AGE = 0;

const char DEFAULT_GENDER = '-';

const char GENDER_MALE = 'M';
const char GENDER_FEMALE = 'F';

class Person{

  friend std::ostream & operator<<(std::ostream & os, const Person & person);
  friend std::istream & operator>>(std::istream & is, Person & person);

  public:
    Person();
    Person(const char * name, int age=DEFAULT_AGE, char gender=DEFAULT_GENDER);
    Person(const Person& other);
   
    ~Person();

    Person & operator=(const Person & rhs);  

    Person & operator+(int years); 
    Person & operator+(const char * name_suffix); 

    const char * getName() const;
    void setName(const char * name);
    int getAge() const;
    void setAge(int age);
    char getGender() const;
    void setGender(char gender);

    static int getCount();   

  private:
    bool ParameterValidation() const;
    char m_name[255];
    int m_age;
    /*const*/ char m_gender;
    
    static int s_count;
};

#endif //PERSON_H_

