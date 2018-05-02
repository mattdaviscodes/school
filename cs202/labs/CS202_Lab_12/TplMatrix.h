//
// Created by Matthew Davis on 4/26/18.
//

#ifndef SCHOOL_TPLMATRIX_H
#define SCHOOL_TPLMATRIX_H

#include <iostream>

template <class T>
class TplMatrix;

template <class T>
std::ostream & operator<<(std::ostream & os, const TplMatrix<T> & matrix);

template <class T>
class TplMatrix {

    friend std::ostream & operator<< <> (std::ostream & os, const TplMatrix<T> & matrix) ;

public:
    TplMatrix(size_t cols, size_t rows, T value=T())
        : m_cols(cols),
          m_rows(rows)
    {
        if (m_cols && m_rows){  //allocate only when it makes sense
            m_matrix = new(std::nothrow) T * [m_rows];
            if (m_matrix){
                for (size_t i=0; i<m_rows; ++i){
                    m_matrix[i] = new(std::nothrow) T [m_cols];
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

    TplMatrix(const TplMatrix<T> & other) {

    }

    ~TplMatrix() {

    }

    TplMatrix<T> & operator=(const TplMatrix<T> & rhs) {
        return *this;
    }

    const TplMatrix<T> operator+(const TplMatrix<T> & rhs) const {
        return TplMatrix<T>(0, 0);
    }

    TplMatrix<T> transpose() const {
        return TplMatrix<T>(0, 0);
    }

    void serialize(std::ostream& os) const {
        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < m_cols; j++) {
                os << m_matrix[i][j] << " ";
            }
            os << std::endl;
        }
    }

private:
    size_t m_cols;
    size_t m_rows;
    T ** m_matrix;
};

template <class T>
std::ostream & operator<<(std::ostream & os, const TplMatrix<T> & matrix) {
    matrix.serialize(os);
    return os;
}



#endif //SCHOOL_TPLMATRIX_H
