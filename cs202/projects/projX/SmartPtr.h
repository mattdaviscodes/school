#ifndef SMARTPTR_H_
#define SMARTPTR_H_

#include "DataType.h"

class SmartPtr {

  public:
  
    SmartPtr( );
    SmartPtr( DataType * data );
    SmartPtr( const SmartPtr & other );
    
    ~SmartPtr( );
  
    SmartPtr & operator=( const SmartPtr & rhs );

    DataType & operator*( );
    DataType * operator->( );

  private:
    
    size_t * m_refcount;
    DataType * m_ptr;

};

#endif //SMARTPTR_H_
