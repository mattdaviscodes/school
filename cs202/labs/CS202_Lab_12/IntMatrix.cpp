#include <iostream>

#include "IntMatrix.h"

IntMatrix::IntMatrix(size_t cols, size_t rows, int value)
  : m_cols(cols),
    m_rows(rows)
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

IntMatrix::~IntMatrix()
{
  for (size_t i=0; i<m_rows; ++i){
    delete [] m_matrix[i];
  }
  delete [] m_matrix;
}

IntMatrix::IntMatrix(const IntMatrix & other)
  : m_cols(other.m_cols),
    m_rows(other.m_rows)
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

IntMatrix & IntMatrix::operator=(const IntMatrix & rhs)
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
        m_matrix = new(std::nothrow) int* [m_rows];
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


void IntMatrix::serialize(std::ostream & os) const{ 
  for (size_t j=0; j<m_rows; ++j){	
    os << "[";
    for (size_t i=0; i<m_cols; ++i){
      os << " " << m_matrix[j][i];  
    }
    os << " ]";
    os << std::endl;
  }
  return os; 
}

std::ostream & operator<<(std::ostream & os, const IntMatrix & im){ 
  im.serialize();
  return os; 
}


const IntMatrix IntMatrix::operator+(const IntMatrix & rhs) const{
  if (m_cols && m_cols==rhs.m_cols && m_rows && m_rows==rhs.m_rows){  //have to have same size
    IntMatrix this_cpy = *this;  //create a different temporary local object, allocation handled by ctor
    for (size_t j=0; j<m_rows; ++j){	
      for (size_t i=0; i<m_cols; ++i){
        this_cpy.m_matrix[j][i] += rhs.m_matrix[j][i];  
      }
    } 
    return this_cpy;
  }
  else{  
    return IntMatrix(0,0);  // 0-rows 0-cols marked object (invalid state)
  }
}

IntMatrix IntMatrix::transpose() const{
  if (m_cols && m_rows){
    IntMatrix transpose(m_rows, m_cols);  //create a different temporary local object, allocation handled by ctor
    for (size_t j=0; j<m_rows; ++j){	
      for (size_t i=0; i<m_cols; ++i){
        transpose.m_matrix[i][j] = m_matrix[j][i];
      }
    } 
    return transpose;
  }
  else{ 
    return IntMatrix(0,0);  // 0-rows 0-cols marked object (invalid state)
  }
}

