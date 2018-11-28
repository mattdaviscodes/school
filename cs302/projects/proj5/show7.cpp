//--------------------------------------------------------------------
// show7.cpp: includes implementation of showStructure
//--------------------------------------------------------------------

//--------------------------------------------------------------------

template < class DT >
void Queue<DT>:: showStructure () const

// Linked list implementation. Outputs the elements in a queue. If
// the queue is empty, outputs "Empty queue". This operation is
// intended for testing and debugging purposes only.

{
    QueueNode<DT> *p;   // Iterates through the queue

    if ( isEmpty() )
	cout << "Empty queue" << endl;
    else
    {
	cout << "Front\t";
	for ( p = front ; p != 0 ; p = p->next )
	{
	    if( p == front ) 
	    {
		cout << '[' << p->dataItem << "] ";
	    }
	    else
	    {
		cout << p->dataItem << " ";
	    }
	}
	cout << "\trear" << endl;
    }
}

//--------------------------------------------------------------------

template <typename DataType>
void QueueArray<DataType>::showStructure() const 
// Array implementation. Outputs the data items in a queue. If the
// queue is empty, outputs "Empty queue". This operation is intended
// for testing and debugging purposes only.

{
    int j;   // Loop counter

    if ( front == -1 )
       cout << "Empty queue" << endl;
    else
    {
       cout << "Front = " << front << "  Back = " << back << endl;
       for ( j = 0 ; j < maxSize ; j++ )
           cout << j << "\t";
       cout << endl;
       if ( back >= front )
          for ( j = 0 ; j < maxSize ; j++ )
              if ( ( j >= front ) && ( j <= back ) )
                 cout << dataItems[j] << "\t";
              else
                 cout << " \t";
       else
          for ( j = 0 ; j < maxSize ; j++ )
              if ( ( j >= front ) || ( j <= back ) )
                 cout << dataItems[j] << "\t";
              else
                 cout << " \t";
       cout << endl;
    }
}

