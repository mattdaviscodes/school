#include <iostream>
#include <string.h>

using namespace std;

void rec (int n){
  if (n < 0){  /*recursion aims to perform digit-by-digit output, but base case is never reached - infinite recursion - stack overflow (should be n<10)*/
    cout << n << endl;
  }
  else {
	rec( n / 10 );
	cout << ( n % 10 ) << endl;
  }
}


int main()
{
  rec(123);

  return 0;
}