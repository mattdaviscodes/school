/**
 * @brief  CS-202 Finals Sample
 * @author Christos Papachristos (cpapachristos@unr.edu)
 * @date   May, 2018
 *
 * This file shows a sample implementation of the Book Class required for the Finals Sample of CS-202
 */

#include <iostream>
#include <cstring>

using namespace std;

///////////////////////////HELPERS/////////////////////////////
class Cover{
  friend std::ostream & operator<<(std::ostream & os, const Cover & cover){ os << (cover.m_hard?"hardcover":"paperback"); return os; }
  friend std::istream & operator>>(std::istream & is, Cover & cover){ cin >> cover.m_hard; return is; }
  public:
   Cover() : m_hard( false ) { }
   Cover(bool hard) : m_hard( hard ) { }
   bool getValue() const { return m_hard; }
  private:
   bool m_hard;  
};
class Client{
  friend std::istream & operator>>(std::istream & is, Client & client){ if (client.m_name){ cin >> client.m_name; } return is; }
  friend std::ostream & operator<<(std::ostream & os, const Client & client){ os << client.m_name; return os; }
  public:
   Client() : m_name( NULL ) { }
   Client(const char * name){ m_name = new char[ strlen(name)+1 ]; strcpy(m_name,name); }
   Client(const Client & other){ m_name = new char[ strlen(other.m_name)+1 ]; strcpy(m_name,other.m_name); }
   ~Client(){ delete [] m_name; }
   Client & operator=(const Client & rhs){ delete [] m_name; m_name = new char[ strlen(rhs.m_name)+1 ]; strcpy(m_name,rhs.m_name); } 
   const char * getName() const { return m_name; }
  private:
    char * m_name;
};


////////////////////////////BOOK//////////////////////////////
class Book {
  friend std::ostream & operator<<(std::ostream & os, const Book & book);
  public:
    Book();
    Book(const char * title, const Cover & cover=Cover(), const Client * client=NULL, size_t serial=count);
    Book(const Book & other);
    ~Book();
    Book & operator=(const Book & rhs);
    const Cover & getCover() const;
    void setCover(const Cover & cover);
    const Client * getClient() const;
    void setClient(const Client * client); 
    void serialize(std::ostream & os) const;
  private:
    char * m_title;
    Cover m_cover;
    const Client * m_client;
    const size_t m_serial;
    static size_t count;
};

size_t Book::count = 0;

Book::Book() 
  : m_title( NULL ),
    m_client(NULL),
    m_serial( count++ )
{
}

Book::Book(const char * title, const Cover & cover, const Client * client, size_t serial)
  : m_client( client ), 
    m_serial( count = serial>count?serial:count ),  //set static to the greater value, and initialize const member
    m_cover( cover )
{
  m_title = new char [ strlen(title)+1 ];
  strcpy(m_title, title);
  ++count;  //increment at the end, constructor done & no exceptions occurred
}

Book::Book(const Book & other) 
  : m_client( other.m_client ),
    m_serial( count ),
    m_cover( other.m_cover )
{
  m_title = new char [ strlen(other.m_title)+1 ];
  strcpy(m_title, other.m_title);
  ++count;  //increment at the end, constructor done & no exceptions occurred
}

Book::~Book(){
  //cover is class member object (composition) – will be automatically destroyed  
  //m_client is pointer to external object (aggregation) – no deleting this
  delete [] m_title; //m_title uses dynamic memory - delete
  //--count;  //no decrement, used to generate unique increasing serial(s)
}

Book & Book::operator=(const Book & rhs){
  if (this != &rhs){  // check for self-assignment
    delete [] m_title;  // first deallocate dynamic memory in assignment
    m_title = NULL;  // and re-set pointers to NULL
    m_title = new char [ strlen(rhs.m_title)+1 ];
    strcpy(m_title, rhs.m_title);
    m_client = rhs.m_client;
  }
  return *this;
}

const Cover & Book::getCover() const{
	return m_cover;
}
void Book::setCover(const Cover& cover){
	m_cover = cover;
}
const Client * Book::getClient() const{
	return m_client;
}
void Book::setClient(const Client * client){
	m_client = client;
}

void Book::serialize(std::ostream & os) const{
  os << m_serial<<":"<<m_title<<"("<<m_cover<<")";
  if (m_client){ os << " client:"<< *m_client; }  //m_client is a pointer! cout call has to dereference it like: *m_client 
}

std::ostream & operator<<(std::ostream & os, const Book & book){
  book.serialize(os);
  return os;
}

////////////////////////////MAIN//////////////////////////////
int main()
{
   // Note: Aggregation - Client is object that lives outside of Book class
   Client jDoe("John Doe");
   // Note: Composition - Cover is object that lives inside of Book class. Also, Client is passed by address-of (constructor accepts const Client*)
   Book myBook("LOTR ROTC", Cover(true), &jDoe, 999); //setting 999 for serial will also move count jump to 999
	
   cout << myBook << endl; 
 
   // Assignment copy object will have an increased serial, and point to same client
   Book bookCopy = myBook;
 
   cout << bookCopy << endl;

   // Default book will have almost everything (except the const member serial) uninitialized
   Book defaultBook;
   
   cout << defaultBook << endl; 
   
   return 0;
}

