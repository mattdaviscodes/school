#include <iostream>
#include <string.h>

using namespace std;

class MyException{
 public:
  MyException(const char * s) : m_info(s){ }
  void SetInfo(const char * s){ m_info = s; }
 friend std::ostream & operator<<(std::ostream& os, const MyException & e){
	os << e.m_info;
	return os;
 }
 private: 
  std::string m_info;
};

class A{
  public:
    A(){ cout << "A" << endl; }
	~A(){ cout << "~A" << endl; }
};

int main()
{
   
  try{
    A anA;
  
    try{
      A anotherA;
	 
  	  //error detected
  	  throw MyException("Something awful happened here...");
    }
    catch(MyException & e){
	  cerr << e << endl;
	  e.SetInfo( "It's been taken care of!" );
  	  throw; 
    }
  }
  catch(const MyException & e){
    cerr << e << endl;
  }  

  return 0;
}

