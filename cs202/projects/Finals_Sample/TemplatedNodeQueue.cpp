/**
 * @brief  CS-202 Templated Node Queue Sample
 * @author Christos Papachristos (cpapachristos@unr.edu)
 * @date   May, 2018
 *
 * This file shows a sample implementation of the templated Node-based Queue Class required for the Finals Sample of CS-202
 */

#include <iostream>
using namespace std;

template <class T> class Queue;  //forward declaration of (any) class or function that will be a friend of Node
template <class T> std::ostream & operator<<(std::ostream & os, const Queue<T> & queue);  //forward declaration of (any) class or function that will be a friend of Queue

template <class T>
class Node{
friend class Queue<T>;  //declaration of templated friend class
public:
  Node() : m_next( NULL ){ }
  Node(const T & data, Node<T> * next = NULL) : m_data( data ), m_next( next ){ }
  const T & getData() const{ return m_data; }
  T & getData(){ return m_data; }
private:
  Node<T> * m_next;
  T m_data;
};

template <class T>
class Queue{
friend std::ostream & operator<< <> (std::ostream & os, const Queue<T> & queue); 
public:
  Queue();
  Queue(size_t count, const T & value=T());
  Queue(const Queue<T> & other);
  ~Queue();
  Queue<T> & operator=(const Queue<T> & other);
  const T & front() const;
  T & front();
  const T & back() const;
  T & back();
  void push(const T & value);
  void pop();
  size_t size() const;
  void clear();
  void serialize(std::ostream & os) const;
private:
  Node<T> * m_front;
  Node<T> * m_back;
};

template <class T>
Queue<T>::Queue()
  : m_front( NULL ),
    m_back( NULL )
{
}

template <class T>
Queue<T>::Queue(size_t count, const T& value)
  : m_front( NULL ),  //new in body might always fail
    m_back( NULL )  //new in body might always fail
{
  if (count){
    Node<T> * currNode = m_front = new Node<T>(value);
    while (--count){
      currNode = currNode->m_next = new Node<T>(value);
    }
    //currNode->m_next = NULL; //unnecessary, NULL-initialized by Node ctor
  }
}

template <class T>
Queue<T>::Queue(const Queue<T> & other)
  : m_front( NULL ),  //new in body might always fail
    m_back( NULL )  //new in body might always fail
{
  Node<T> * otherNode = other.m_front;
  if (otherNode){
    Node<T> * myNode = m_front = new Node<T>(otherNode->m_data);  
    while (otherNode->m_next){
      otherNode = otherNode->m_next;
      myNode = myNode->m_next = new Node<T>(otherNode->m_data); 
    }
    m_back = myNode;
  }
}

template <class T>
Queue<T>::~Queue(){
  while (m_front){ //traverse to deallocate
    Node<T> * del_Pt = m_front;
    m_front = m_front->m_next;
    delete del_Pt; 
  }
}

template <class T>
Queue<T> & Queue<T>::operator=(const Queue<T> & rhs){
  if (this != &rhs){
    clear();
    Node<T> * otherNode = rhs.m_front;
    if (otherNode){
      Node<T> * myNode = m_front = new Node<T>(otherNode->m_data);  
      while (otherNode->m_next){
        otherNode = otherNode->m_next;
        myNode = myNode->m_next = new Node<T>(otherNode->m_data); 
      }
      m_back = myNode;
    }
  }
  return *this;
}

template <class T>
const T & Queue<T>::front() const{
  return m_front->m_data;
}

template <class T>
T & Queue<T>::front(){
  return m_front->m_data;
}

template <class T>
const T & Queue<T>::back() const{
  return m_back->m_data;
}

template <class T>
T & Queue<T>::back(){
  return m_back->m_data;
}

template <class T>
void Queue<T>::push(const T& value){
  if (!m_back){ //empty back and front initialized
    m_back = m_front = new Node<T>(value);
  }
  else{ //append to back then update back 
    m_back = m_back->m_next = new Node<T>(value);
  }
}

template <class T>
void Queue<T>::pop(){
  if (m_front){
    Node<T> * del_Pt = m_front;
    m_front = m_front->m_next;
    delete del_Pt; 
    if (!m_front){ //no more elements after popping last one
      m_back = NULL;
    }
  }
}

template <class T>
size_t Queue<T>::size() const{
  size_t size = 0;
  Node<T> * trav_Pt = m_front;
  while (trav_Pt){  //traverse to count
    ++size;
    trav_Pt = trav_Pt->m_next;
  }
  return size;
}

template <class T>
void Queue<T>::clear(){
  while (m_front){ //traverse to deallocate
    Node<T> * del_Pt = m_front;
    m_front = m_front->m_next;
    delete del_Pt; 
  }
  m_front = NULL; //reset pointers to NULL
  m_back = NULL; //reset pointers to NULL
}

template <class T>
void Queue<T>::serialize(std::ostream & os) const{
  Node<T> * out_Pt = m_front;
  while (out_Pt){  //traverse to output
    os << out_Pt->getData() << " ";
    out_Pt = out_Pt->m_next;
  }
}

template <class T>
std::ostream & operator<<(std::ostream & os, const Queue<T> & queue){
  queue.serialize(os);
  return os;
}

///////////////////////////MAIN////////////////////////////
int main(){

  //Test 
  cout << "Constructing Q1" << endl;
  Queue<int> q1;
  q1.push(1);
  q1.push(2);
  q1.push(3);
  cout << "Q1_size:" << q1.size() << ", Q1:" << q1 << endl;

  cout << endl << "Constructing Q2" << endl;
  Queue<int> q2;
  q2.push(4);
  q2.push(5);
  q2.push(6);
  q2.push(7);
  cout << "Q2_size:" << q2.size() << ", Q2:" << q2 << endl;

  cout << endl << "Constructing Q3(10, 111)" << endl;
  Queue<int> q3(10, 111);
  cout << "Q3_size:" << q3.size() << ", Q3:" << q3 << endl;
  
  cout << endl << "Constructing Q4(Q2)" << endl;
  Queue<int> q4(q2);
  cout << "Q4_size:" << q4.size() << ", Q4:" << q4 << endl;

  cout << endl << "Setting Q2 = Q1" << endl;
  q2 = q1;
  cout << "Q2_size:" << q2.size() << ", Q2:" << q2 << endl;

  return 0;

}
