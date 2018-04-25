#include <iostream>

#include <iostream>

#include "DataType.h"

using namespace std;


class Node{

  friend class Queue;      //allows direct accessing of link m_next from queue class (otherwise, link remains inaccessible outside of Node)

  public:
    Node() 
     : m_next(NULL) { }
    Node(const DataType & data, Node * next = NULL)
     : m_next(next) , m_data(data) { }	    	
    Node(const Node & other)
     : m_next(other.m_next) , m_data(other.m_data) { }

    DataType & data(){       //by-Reference access to data (allows mutation/writing)
      return m_data;    	
    }    	
    const DataType & data() const{   //by-const-Reference access to data (read-only)
      return m_data;    	
    }
 
  private:    
    Node * m_next; 						
    DataType m_data;	
};


class Queue{
	
  friend std::ostream& operator<<(std::ostream& os, const Queue& queue);

  public:    
  
    Queue() : 
      m_front(NULL),
      m_back(NULL)
    {
    }
    
    void push(const DataType & value); 	       
    void pop();
	void serialize(std::ostream & os) const; //helper, called by the const-qualified queue object passed to operator<<	

  private:

    Node * m_front, * m_back;
		
};

void Queue::push(const DataType & value){
  /* Your implementation here */
    Node *newNode = new Node(value);
    std::cout << "t2.2" << std::endl;
    m_back->m_next = newNode;
    std::cout << "t2.3" << std::endl;
    m_back = newNode;
}

void Queue::pop(){
    Node * delPt = m_front;
    m_front = m_front->m_next;
    delete delPt;
}

void Queue::serialize(std::ostream & os) const{
    Node *curr = m_front;
    while (curr) {
        os << curr->data();
        curr = curr->m_next;

        if (curr) {
            os << std::endl;
        }
    }
}

std::ostream & operator<<(std::ostream & os, const Queue & queue){
    queue.serialize(os);
    return os;
}


int main(){
	
	Queue queue;


    for (size_t i=0; i<10; ++i){
      DataType dt_i(i, 0.1*i);
      queue.push( dt_i );
	}
    cout << endl << queue << endl;

	for (size_t i=0; i<5; ++i){
      queue.pop( );	
	}
    cout << endl << queue << endl;

}

