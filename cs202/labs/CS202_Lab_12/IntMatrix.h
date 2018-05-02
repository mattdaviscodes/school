#ifndef INTMATRIX_H_
#define INTMATRIX_H_

#include <iostream>

class IntMatrix {
 
 friend std::ostream & operator<<(std::ostream & os, const IntMatrix & im);

 public:
  IntMatrix(size_t cols, size_t rows, int value=0);
  IntMatrix(const IntMatrix & other);
  ~IntMatrix();

  IntMatrix & operator=(const IntMatrix & rhs);
 
  const IntMatrix operator+(const IntMatrix & rhs) const;
  
  IntMatrix transpose() const;
  
  void serialize(std::ostream& os) const;
  
 private:
  size_t m_cols;
  size_t m_rows;
  int ** m_matrix;
};

#endif //INTMATRIX_H_
