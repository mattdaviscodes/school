#include <iostream>
#include <string.h>

using namespace std;

int rec (int n) {
  cout << n << " ";
  if (n > 1)
    return rec (n-1) + rec (n-2);  /*recursion estimates fibonacci sequence, explanation of output sequence (4 3 2 1 0 1 2 1 0) is found at Lecture25 Slide35*/
  else
    return n;
}

int main()
{
  int r = rec(4);
  
  cout << endl << r;  /*output here is fibonacci(4) := 3*/

  return 0;
}