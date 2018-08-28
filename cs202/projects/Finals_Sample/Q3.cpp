#include <iostream>
#include <string.h>

using namespace std;

/*without BOTH of these forward declarations it will not work*/
template<class T, size_t NROWS, size_t NCOLS> class Matrix; 
template<class T, size_t NROWS, size_t NCOLS> std::ostream & operator<<(std::ostream& os, const Matrix<T,NROWS,NCOLS> & matrix);
 
template<class T, size_t NROWS=1, size_t NCOLS=1>
class Matrix{
 public:
  Matrix(){}
 friend std::ostream & operator<< <> (std::ostream & os, const Matrix<T,NROWS,NCOLS> & matrix);
 private:
  T container[NROWS][NCOLS];
};

template<class T, size_t NROWS, size_t NCOLS>
std::ostream & operator<<(std::ostream & os, const Matrix<T,NROWS,NCOLS> & matrix){
  for (size_t i=0; i<NROWS; ++i){
    for (size_t j=0; j<NCOLS; ++j){
      os  <<  matrix.container[i][j] << " ";
	}
	os << std::endl;
  }
  os << std::endl;
}

int main()
{
  Matrix<float, 10, 5> mat;
  cout << mat;

  return 0;
}
