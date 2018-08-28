/**
 * @brief  CS-202 Finals Sample
 * @author Christos Papachristos (cpapachristos@unr.edu)
 * @date   May, 2018
 *
 * This file shows a sample implementation of the ChildrenBook Class required for the Finals Sample of CS-202
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
    virtual void serialize(std::ostream & os) const;  /*making this virtual causes dynamic binding to work*/
  protected:
    char * m_title;  /*moved to protected access*/
    Cover m_cover;  /*moved to protected access*/
    const size_t m_serial;  /*moved to protected access*/
    static size_t count;  /*moved to protected access*/
  private:
    const Client * m_client;
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

Book::~Book()
{
  //cover is class member object (composition) – will be automatically destroyed  
  //m_client is pointer to external object (aggregation) – no deleting this
  delete [] m_title; //m_title uses dynamic memory - delete
  //--count;  //no decrement, used to generate unique increasing serial(s)
}

Book& Book::operator=(const Book & rhs){
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
void Book::setCover(const Cover & cover){
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


//////////////////////////CHILDRENBOOK////////////////////////////
class ChildrenBook : public Book{
  friend std::ostream & operator<<(std::ostream & os, const ChildrenBook & childrenbook);
  public:
    ChildrenBook();
    ChildrenBook(const char * title, bool graphic, const Cover& cover=Cover(), const Client * client=NULL, size_t serial=count);
    ChildrenBook(const ChildrenBook & other);
    ~ChildrenBook();
    ChildrenBook & operator=(const ChildrenBook & rhs);
    bool getGraphic() const;
    void setGraphic(const bool & graphic);
    virtual void serialize(std::ostream& os) const;  /*making the base class method virtual causes dynamic binding to work*/
  private:
    bool m_graphic;
};

ChildrenBook::ChildrenBook()
  : Book( )
{
   // count increases when base class constructor gets called
}

ChildrenBook::ChildrenBook(const char * title, bool graphic, const Cover & cover, const Client * client, size_t serial)
  : Book(title, cover, client, serial), //use base class parametrized constructor with arguments (passing them along)
    m_graphic(graphic)
{
  // count increases when base class constructor gets called
}

ChildrenBook::ChildrenBook(const ChildrenBook & other) 
  : Book(other.m_title, other.m_cover, other.getClient(), other.m_serial), //have to use getClient() because m_client is private, not protected
    m_graphic(other.m_graphic)
{
  // count increases when base class constructor gets called
}

ChildrenBook::~ChildrenBook()
{
  // has no dynamic memory to manage, base class destructor will get automatically called right after
}

ChildrenBook & ChildrenBook::operator=(const ChildrenBook & rhs){
  if (this != &rhs){  // check for self-assignment
    //handle base class members
    delete [] m_title;  // first deallocate dynamic memory in assignment
    m_title = NULL;  // and re-set pointers to NULL
    m_title = new char [ strlen(rhs.m_title)+1 ];
    strcpy(m_title, rhs.m_title);
    setClient(rhs.getClient());
    //handle derived class members
    m_graphic = rhs.m_graphic;
  }
  return *this;
}

void ChildrenBook::serialize(std::ostream & os) const{
  os << m_serial<<":"<<m_title<<"("<<m_cover<<","<<(m_graphic?"graphic":"novel")<<")"; 
  if (getClient()){ os << " client:"<< *getClient(); }  //m_client is a pointer, and it is also private (not protected)
}

std::ostream & operator<<(std::ostream & os, const ChildrenBook & childrenbook){
  childrenbook.serialize(os);
  return os;
}


////////////////////////////MAIN//////////////////////////////
int main()
{
   Client jDoe("John Doe");
   Book myBook("LOTR ROTC", Cover(true), &jDoe, 999); 

   Client jDoeJr("John Doe Jr");
   ChildrenBook myChildBook("LOTR comic", true, Cover(false), &jDoeJr);
   
   Book * book_Pt;
   
   book_Pt = &myBook;
   cout << *book_Pt << endl;
   
   book_Pt = &myChildBook;
   cout << *book_Pt << endl; /*this uses the friend operator<< function which is not a member function (and hence cannot be a virtual one)*/
                             /*however if the Base class method is virtual (dynamic binding) then the Derived class method override will be called */
   
   return 0;
}

