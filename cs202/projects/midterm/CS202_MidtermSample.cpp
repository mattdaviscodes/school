/**
 * @brief  CS-202 Midterm Sample
 * @author Christos Papachristos (cpapachristos@unr.edu)
 * @date   March, 2018
 *
 * This file shows a sample implementation to address Program 1 of the Midterm Sample of CS-202
 */

#include <iostream>
#include <fstream>

using namespace std;


/*
 * Write your own C-string manipulation functions - note: these do not handle NULL pointer cases
 */
void strcpy(char * dst, const char * src){
  while (*dst++ = *src++);
}

int strcmp(const char * s1, const char * s2){
  while (*s1 == *s2++){
    if (!*s1++){
      return 0;
    }
  }
  return *s1 - *--s2;
}

int strlen(const char* str){
  const char * s = str;
  for( ; *s; ++s); 
  return s - str;
}


/*
 * Write your own array manipulation functions - note: these do not handle NULL pointer cases
 */
void intcpy(int* dst, const int* src, int size)
{
  while (--size>=0){
    *dst++ = *src++;
  }
}

int intcmp(const int * arr1, const int * arr2, int size){
  while (--size>=0){
    int res = *arr1++ - *arr2++;
    if (res){
      return res; 
    }
  }
  return 0;
}

void intprint(std::ostream& os, const int* arr, int size)
{
 while (--size>=0){
   os << *arr++;
 }
}


/*
 * Classes
 */
const int STR_MAX = 255;

/*
 * Book Class
 */
const char* BOOK_DEFAULT_TITLE = "notitle";
const int BOOK_ISBN_LEN = 13; 
const int BOOK_DEFAULT_ISBN[BOOK_ISBN_LEN] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
const char* BOOK_DEFAULT_RENTER = "norenter";

class Book {

  friend std::ostream& operator<<(std::ostream& os, const Book& b); 

  public:
	Book();
	Book(const char *title, const int *isbn=BOOK_DEFAULT_ISBN, const char *renter=BOOK_DEFAULT_RENTER); //use default parameters in parameters list
	Book(const Book &other);

        ~Book();

        Book& operator=(const Book& rhs);

	void SetTitle(const char* title);
	const char* GetTitle() const;
	void SetIsbn(const int* isbn);
	const int* GetIsbn() const;
	
	bool GetAvailable() const;
	const char* GetRenter() const;

        bool Valid() const;
	bool operator+(const char* renter);
	void Free();

        static int GetIdgen();

  private:
        const int m_id;
	char m_title[STR_MAX];
	int m_isbn[BOOK_ISBN_LEN];
	bool m_available;
	char m_renter[STR_MAX];

        static int s_idgen;
};

int Book::s_idgen = 0; //do not forget static member definition

Book::Book()
  : m_id(s_idgen++) //member is const, have to use initializer list to set it in all constructors
{
  SetTitle(BOOK_DEFAULT_TITLE); //code reuse - set the title to default
  SetIsbn(BOOK_DEFAULT_ISBN); //code reuse - set the isbn to default
  Free(); //code reuse - mark as free
}

Book::Book(const char *title, const int *isbn, const char *renter)
  : m_id(s_idgen++)
{
  SetTitle(title);
  SetIsbn(isbn);
  Free(); //code reuse - mark as free first but then check whether the user put in an actual renter name or left everything to the default parameter list value
  if ( strcmp(renter, BOOK_DEFAULT_RENTER) ){
    (*this) + renter; //note: cannot write this->+(renter) - alternative is: this->operator+(renter)
  }
}

Book::Book(const Book &other)
  : m_id(s_idgen++)
{
  SetTitle(other.m_title);
  SetIsbn(other.m_isbn);
  Free(); //custom copy constructor will make book copy but mark new object as free
}

Book::~Book(){
  //--s_idgen; //not decrementing static to avoid duplication
}

Book& Book::operator=(const Book &rhs)
{
  if (this != &rhs){
    //cannot do anything to const int m_id
    SetTitle(rhs.m_title);
    SetIsbn(rhs.m_isbn);
    if (rhs.m_available){
      Free();
    }
    else{
      (*this) + rhs.m_renter;
    }
  }
  return *this;
}

void Book::SetTitle(const char* title){
  strcpy(m_title,title);
}

const char* Book::GetTitle() const{
  return m_title;
}

void Book::SetIsbn(const int* isbn){
  intcpy(m_isbn, isbn, BOOK_ISBN_LEN);
}

const int* Book::GetIsbn() const{
  return m_isbn;
}

bool Book::GetAvailable() const{
  return m_available;
}

const char* Book::GetRenter() const{
  return m_renter;
}

bool Book::Valid() const{
  if (!strcmp(m_title, BOOK_DEFAULT_TITLE) || !intcmp(m_isbn, BOOK_DEFAULT_ISBN, BOOK_ISBN_LEN)){
    return false;
  }
  return true;
}

bool Book::operator+(const char* renter){
  if (!m_available || !strcmp(renter, BOOK_DEFAULT_RENTER)){ //basic sanity check: is the book available? are we giving a valid name for the renter?
    return false;
  }
  else{
    strcpy(m_renter, renter);
    m_available = false;
  }
  return true;
}

void Book::Free(){
  strcpy(m_renter, BOOK_DEFAULT_RENTER); 
  m_available = true;
}

int Book::GetIdgen(){
  return s_idgen;
}

std::ostream& operator<<(std::ostream& os, const Book& b){
  os << b.m_title <<" (" << b.m_id << ") ";
  intprint(os, b.m_isbn, BOOK_ISBN_LEN);
  if (b.m_available){
    os << " Free for rent";
  }
  else{
    os << " Rented to: " << b.m_renter;
  }
  return os;
}


/*  
 * Library Class 
 */
const int LIBRARY_N_BOOKS = 1000; 

class Library {

 friend std::ostream& operator<<(std::ostream& os, const Library& l); 

 public:
  Library(const char* name);

  void SetName(const char* name);
  const char* GetName() const;
  
  Book* FindOpenSpot();
  Book* operator[](const char* title);
  Book& operator[](int index);

  bool RentBook(int index, const char* name);

  bool operator+(const Book& book);

 private:

  char m_name[STR_MAX];
  Book m_inventory[LIBRARY_N_BOOKS];

};



Library::Library(const char* name)
{ 
  SetName(name);
}

void Library::SetName(const char* name){
  strcpy(m_name, name);
}

const char* Library::GetName() const{
  return m_name;
}

Book* Library::FindOpenSpot(){
  Book *m_inventory_pt = m_inventory;
  for (int i=0; i<LIBRARY_N_BOOKS; ++i){
    if ( !m_inventory_pt->Valid() ){ //code reuse: if the object at that index is not valid, it can be considered as "open-to-assign"
      return m_inventory_pt;    
    }
    ++m_inventory_pt;
  }
  return NULL;
}

Book* Library::operator[](const char* title){
  Book* m_inventory_pt = m_inventory;
  for (int i=0; i<LIBRARY_N_BOOKS; ++i){
    if ( !strcmp(m_inventory_pt->GetTitle(), title) ){ //code reuse: if check for specific title
      return m_inventory_pt;
    } 
    ++m_inventory_pt;
  }
  return NULL;
}

Book& Library::operator[](int index){
  return m_inventory[index];
}

bool Library::RentBook(int index, const char* name){
  return m_inventory[index] + name; //code reuse: class Book operator+ function returns bool on success/fail
}

bool Library::operator+(const Book& book){
  if ( book.Valid() ){ //code reuse: first check that passed object is valid
    Book* open_book_pt = FindOpenSpot(); //code reuse: then find an open spot
    if ( open_book_pt ){ //code reuse: check not NULL-pointer - if FindOpenSpot succeeded
      *open_book_pt = book; //dereference and assign-to
      return true;
    }
  }
  return false;
}

std::ostream& operator<<(std::ostream& os, const Library& l){
  const Book* m_inventory_pt = l.m_inventory;
  for (int i=0; i<LIBRARY_N_BOOKS; ++i){
    if ( m_inventory_pt->Valid() ){ //code reuse: check that the output object is valid
      os << "Index: " << i << ", Book: " << *m_inventory_pt << endl;  //call insertion operator on ostream os and pass Book object - have to dereference m_inventory_pt
    } 
    ++m_inventory_pt;
  }
  // Alternative implementation: code reuse of operator[] - compiler will optimize away the extra function call and treat l[i] as direct indexing
  // for (int i=0; i<N_BOOKS; ++i){
  //   if ( l[i]->Valid() ){
  //     os << "Index: " << i << ", Book: " << l[i] << endl; 
  //   }
  // }
  return os;
}

/*  
 * IO functions - (Non-member functions)
 */
void importBooks(Library& library){
  ifstream fin("LibraryIndex.txt");

  while (!fin.eof()){
    char title[STR_MAX];
    fin >> title; 
    char isbn_char[BOOK_ISBN_LEN];
    fin >> isbn_char;
    const char *isbn_char_pt = isbn_char;
    int isbn[BOOK_ISBN_LEN];
    int *isbn_pt = isbn;
    for (int i=0; i<BOOK_ISBN_LEN; ++i){
      *isbn_pt = *isbn_char_pt-'0';
      ++isbn_pt;
      ++isbn_char_pt;
    }
    char renter[STR_MAX];
    fin >> renter;

    if (fin.eof()){
      break;
    }

    Book book(title, isbn, renter);
    library + book;
  }

  fin.close();
}

void exportBooks(const Library& library){
  ofstream fout("LibraryIndexPost.txt");
  fout << library;
  fout.close();
}


/*  
 * Main 
 */
int main(){
  Library delamare("DeLaMare Science and Engineering Library");

  importBooks(delamare);
  cout << delamare;

  int bookIndex;
  cout << endl << "What library book index would you like to rent?" << endl;
  cin >> bookIndex;
  char renterName[STR_MAX];
  cout << "What is your name?" << endl;
  cin >> renterName;
  if ( !delamare.RentBook(bookIndex, renterName) ){
    cout << "Could not reserve this library book based on its index, are you sure it is available?" << endl;
  }

  exportBooks(delamare);

  return 0;

}
