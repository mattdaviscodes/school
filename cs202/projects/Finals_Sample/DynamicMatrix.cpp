/**
 * @brief  CS-202 Finals Sample
 * @author Christos Papachristos (cpapachristos@unr.edu)
 * @date   May, 2018
 *
 * This file shows a sample implementation of the DynamicMatrix Class required for the Finals Sample of CS-202
 */

#include <iostream>

class DynamicMatrix {

 public:
  // 1) instatiates a [0]x[0] NULL matrix
  DynamicMatrix();  
  // 2) instatiates a [rows]x[cols] matrix with all elements set to [value]
  DynamicMatrix(size_t rows, size_t cols, int value=0);  
  // 3) instantiates via matrix copy
  DynamicMatrix(const DynamicMatrix & other);  
  // 4) destroys matrix and deallocates dynamic memory
  ~DynamicMatrix(); 

  // 5) assignment operator
  DynamicMatrix & operator=(const DynamicMatrix & rhs);  
  // 6) parenthesis operator, to be used for [row],[col] indexing
  int & operator()(size_t row_pos, size_t col_pos);
  // 7) checks if two matrices are by-size-and-by-value equal
  bool operator==(const DynamicMatrix & rhs) const; 
  // 8) adds two matrices if they are of equal size and returns a temporary with their sum
  const DynamicMatrix operator+(const DynamicMatrix & rhs) const;

  // 9) transposes a matrix and returns result as a temporary
  DynamicMatrix transpose() const;

  // i) extraction operator friend non-member function
  friend std::istream & operator>>(std::istream & is, DynamicMatrix & dm);
  // ii) insertion operator friend non-member function
  friend std::ostream & operator<<(std::ostream & os, const DynamicMatrix & dm);

 private:
  size_t m_rows;
  size_t m_cols;
  int ** m_matrix;
};


DynamicMatrix::DynamicMatrix()
  : m_matrix( NULL ),  //initialize pointer(s) to NULL
    m_rows( 0 ),  //defensive strategy sometimes desired (here rows and cols are anyway inaccessible)
    m_cols( 0 )   //defensive strategy sometimes desired (here rows and cols are anyway inaccessible)
{

}

DynamicMatrix::DynamicMatrix(size_t rows, size_t cols, int value)
  : m_rows(rows),
    m_cols(cols)
{ 
  if (m_cols && m_rows){  //allocate only when it makes sense
    m_matrix = new(std::nothrow) int * [m_rows];
    if (m_matrix){
      for (size_t i=0; i<m_rows; ++i){
        m_matrix[i] = new(std::nothrow) int [m_cols]; 
        if (m_matrix[i]){
          for (size_t k=0; k<m_cols; ++k){  //only assign values to the row we have just allocated (no [j][i] over [m_rows][m_cols], because some rows have not been allocated yet) 
            m_matrix[i][k] = value;
          }
        }
        else{  //row allocation failed, cleanup everything (could retry too)
          for (; i>=0; --i){
            delete [] m_matrix[i];
	  }
          delete [] m_matrix;
          m_rows = 0;
          m_cols = 0;
          break;
        }
      }
    }
    else{
      m_rows = 0;
      m_cols = 0;
      m_matrix = NULL;
    }
  }
  else{
    m_matrix = NULL;
  }
}

DynamicMatrix::~DynamicMatrix()
{
  for (size_t i=0; i<m_rows; ++i){
    delete [] m_matrix[i];
  }
  delete [] m_matrix;
}

DynamicMatrix::DynamicMatrix(const DynamicMatrix & other)
  : m_rows(other.m_rows),
    m_cols(other.m_cols)
{ 
  if (m_cols && m_rows){  //allocate only when it makes sense
    m_matrix = new(std::nothrow) int * [m_rows];
    if (m_matrix){
      for (size_t i=0; i<m_rows; ++i){
        m_matrix[i] = new(std::nothrow) int [m_cols]; 
        if (m_matrix[i]){
          for (size_t k=0; k<m_cols; ++k){  //only assign values to the row we have just allocated (no [j][i] over [m_rows][m_cols], because some rows have not been allocated yet) 
            m_matrix[i][k] = other.m_matrix[i][k];
          }
        }
        else{  //row allocation failed, cleanup everything (could retry too)
          for (; i>=0; --i){
            delete [] m_matrix[i];
	  }
          delete [] m_matrix;
          m_rows = 0;
          m_cols = 0;
          break;
        }
      }
    }
    else{
      m_rows = 0;
      m_cols = 0;
      m_matrix = NULL;
    }
  }
  else{
    m_matrix = NULL;
  }
}

DynamicMatrix& DynamicMatrix::operator=(const DynamicMatrix& rhs)
{ 
  if (this != &rhs){
    if (m_cols != rhs.m_cols || m_rows != rhs.m_rows){  //allocate only when it makes sense
      for (size_t i=0; i<m_rows; ++i){  //deallocate first
        delete [] m_matrix[i];
      }
      delete [] m_matrix;
      if (rhs.m_cols && rhs.m_rows){  //allocate only when it makes sense
        m_rows = rhs.m_rows;
        m_cols = rhs.m_cols;
        m_matrix = new(std::nothrow) int * [m_rows];
        if (m_matrix){
          for (size_t i=0; i<m_rows; ++i){
            m_matrix[i] = new(std::nothrow) int [m_cols]; 
            if (!m_matrix[i]){  //row allocation failed, cleanup everything (could retry too)
              for (; i>=0; --i){
                delete [] m_matrix[i];
	      }
              delete [] m_matrix;
              m_rows = 0;
              m_cols = 0;
              break;
            }
          }
        }
        else{
          m_rows = 0;
          m_cols = 0;
          m_matrix = NULL;
        }
      }
    }
    if (m_matrix){  //reaching this far with a non-NULL pointer means allocation succeeded, or previously allocated data is maintained and will be overwritten
      for (size_t j=0; j<m_rows; ++j){	
        for (size_t i=0; i<m_cols; ++i){
          m_matrix[j][i] = rhs.m_matrix[j][i];
        }
      } 
    }
  }
  return *this;
}

int & DynamicMatrix::operator()(size_t row_pos, size_t col_pos){
  return m_matrix[row_pos][col_pos];
}

bool DynamicMatrix::operator==(const DynamicMatrix & rhs) const{
  if (m_rows!=rhs.m_rows || m_cols!=rhs.m_cols){
    return false;
  }
  for (size_t i=0; i<m_rows; ++i){	
    for (size_t j=0; i<m_cols; ++i){
      if (m_matrix[i][j] != rhs.m_matrix[i][j]){
        return false;	
      }
    }
  }
  return true;
}

const DynamicMatrix DynamicMatrix::operator+(const DynamicMatrix & rhs) const{
  if (m_cols && m_cols==rhs.m_cols && m_rows && m_rows==rhs.m_rows){  //have to have same size
    DynamicMatrix this_cpy = *this;  //create a different temporary local object, allocation handled by ctor
    for (size_t j=0; j<m_rows; ++j){	
      for (size_t i=0; i<m_cols; ++i){
        this_cpy.m_matrix[j][i] += rhs.m_matrix[j][i]; 
      }
    } 
    return this_cpy;
  }
  else{  
    return DynamicMatrix(0,0);  // 0-rows 0-cols marked object (invalid state)
  }
}

DynamicMatrix DynamicMatrix::transpose() const{
  if (m_cols && m_rows){
    DynamicMatrix transp(m_cols, m_rows);  //create a different temporary local object, allocation handled by ctor
    for (size_t j=0; j<m_rows; ++j){	
      for (size_t i=0; i<m_cols; ++i){
        transp.m_matrix[i][j] = m_matrix[j][i];
      }
    } 
    return transp;
  }
  else{ 
    return DynamicMatrix(0,0);  // 0-rows 0-cols marked object (invalid state)
  }
}

std::istream & operator>>(std::istream & is, DynamicMatrix & dm){ 
  if (!dm.m_matrix){
    std::cerr<<"Matrix is NULL, cannot Input..."<<std::endl;
    return is;
  }
  for (size_t j=0;j<dm.m_rows;++j){	
    for (size_t i=0;i<dm.m_cols;++i){
      is>>dm.m_matrix[j][i];
    }
  }
  return is;
}

std::ostream & operator<<(std::ostream & os, const DynamicMatrix & dm){
  if (!dm.m_matrix){
    std::cerr<<"Matrix is NULL, cannot Output..."<<std::endl;
    return os;
  }
  for (size_t j=0;j<dm.m_rows;++j){	
    for (size_t i=0;i<dm.m_cols;++i){
      os<<dm.m_matrix[j][i]<<" ";
    }
    os<<std::endl;
  }
  return os;
}

int main(){
  
  DynamicMatrix dynMatrix(3,5,-1);
  std::cout << "DynamicMatrix(3x5)@(-1):" << std::endl;
  std::cout << dynMatrix << std::endl;

  std::cout << "Enter elements of (3x5) matrix:" << std::endl;
  std::cin >> dynMatrix;
  std::cout << "DynamicMatrix(3x5):" << std::endl;
  std::cout << dynMatrix << std::endl;

  DynamicMatrix dynMatrixTransp = dynMatrix.transpose();
  std::cout << "DynamicMatrix(3x5) Transpose:" << std::endl;
  std::cout << dynMatrixTransp << std::endl;
  
  std::cout << "The matrix is" << (dynMatrix==dynMatrixTransp?" ":" not ") << "symmetric" << std::endl;
  	
  return 0;
}

