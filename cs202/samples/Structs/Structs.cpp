/**
 * @brief  CS-202 Structs Sample
 * @Author Christos Papachristos (cpapachristos@unr.edu)
 * @date   February, 2018
 *
 * This file shows a sample implementation of code that employs C++ structs for the purposes of CS-202
 */
 
#include <iostream>

#include <cstring>  // Only for demonstration purposes, you are not allowed to use cstring and its built-in functions

using namespace std;

const size_t STR_SZ = 256;  //size_t is an unsigned integral type which can represent the maximum possible number of a storage size that can appear on a target architecture 
const int STUDENTS_NUM = 3;

/* Structs declaration section */
struct Student {
   char name[STR_SZ];
   size_t id;
   char dept[STR_SZ];
   char gender;
};


/* Function declaration (prototypes) section */

/*
   Takes in a Student object by-Reference and outputs its data members to terminal
   Note: Does not modify the content of the object, therefore we pass it by-const-Reference ( const Student & )
*/
void output_student_data(const Student & st);

/*
   Takes in a Student object by-Reference and populates its data members by requesting user input
   Note: Modifies the content of the object, therefore we pass it by a non-const Reference ( Student & )
*/
void input_student_data(Student & st);

/*
   Takes in an array of Student objects and outputs each individual object's data members by calling output_student_data and forwarding it the appropriate student object
   Note 1: Parameter is an array, and array indexing is used to fetch the appropriate Student object from it ( st_arr[i] ) and forward it to output_student_data
   Note 2: Does not modify the content of the array (actually the internally called output_student_data does), therefore we pass it by const-Pointer ( const Student * st_arr_pt )
*/
void output_student_array_vArrayIndexing(const Student st_arr [], size_t sz);

/*
   Takes in an array of Student objects and populates each individual object's data members by calling input_student_data and forwarding it the appropriate student object
   Note 1: Parameter is an array, and array indexing is used to fetch the appropriate Student object from it ( st_arr[i] ) and forward it to input_student_data
   Note 2: Modifies the content of the array (actually the internally called input_student_data does), therefore we pass it as a non-const parameter ( Student st_arr [] )
*/
void input_student_array_vArrayIndexing(Student st_arr [], size_t sz);

/*
   Takes in an array of Student objects via Pointer and outputs each individual object's data members by calling output_student_data and forwarding it the appropriate student object
   Note 1: Parameter is a Pointer, and Pointer manipulation (++/--/etc) is used to reach the appropriate Student object, and Pointer dereference ( *st_pt ) to access it
   Note 2: Does not modify the content of the array (actually the internally called output_student_data does), therefore we pass it by const-Pointer ( const Student * st_arr_pt )
*/
void output_student_array_vPointerIncrement(const Student * st_arr_pt, size_t sz);

/*
   Takes in an array of Student objects via Pointer and outputs each individual object's data members by calling output_student_data and forwarding it the appropriate student object
   Note 1: Parameter is a Pointer, and Pointer manipulation (++/--/etc) is used to reach the appropriate Student object, and Pointer dereference ( *st_pt ) to access it
   Note 2: Modifies the content of the array (actually the internally called input_student_data does), therefore we pass it by non-const Pointer ( Student * st_arr_pt )
*/
void input_student_array_vPointerIncrement(Student * st_arr_pt, size_t sz);


/* Program main function (entry point) */

int main(){

  /* Part 1: Single struct object */
  
  Student me_student;                        // This creates a single Student object, it will be instantiated therefore without any specific initial values for their data members,
                                             // therefore they will contain "garbage" data

  cout << "\n---------------------------------------------------\n" << 
            "Inputting data of single Student object: me_student\n" <<
			"---------------------------------------------------" << endl;										 
  input_student_data( me_student );

  cout << "\n----------------------------------------------------\n" << 
            "Outputting data of single Student object: me_student\n" <<
			"----------------------------------------------------" << endl;										 
  output_student_data( me_student );
  
  
  /* Part 2: Array of struct objects */

  Student other_students[ STUDENTS_NUM ];    // This creates an array of STUDENTS_NUM Student objects, each of them will be instantiated the same way as a single Student object,
                                             // therefore without any specific initial values for their data members
 
  cout << "\n------------------------------------------------------------\n" << 
            "---   Demonstration of Array-Indexing based acccessing   ---\n" <<
			"------------------------------------------------------------" << endl;	  
 
  cout << "\n----------------------------------------------------------\n" << 
            "Inputting data of array of Student objects: other_students\n" <<
			"----------------------------------------------------------" << endl;	
  input_student_array_vArrayIndexing(other_students, STUDENTS_NUM);
  
  cout << "\n-----------------------------------------------------------\n" << 
            "Outputting data of array of Student objects: other_students\n" <<
			"-----------------------------------------------------------" << endl;	
  output_student_array_vArrayIndexing(other_students, STUDENTS_NUM);
  
  cout << "\n------------------------------------------------------------------\n" << 
            "---   Demonstration of Pointer-Manipulation based acccessing   ---\n" <<
			"------------------------------------------------------------------" << endl;	 

  cout << "\n------------------------------------------------------------------\n" << 
            "Inputting (again) data of array of Student objects: other_students\n" <<
			"------------------------------------------------------------------" << endl;	
  input_student_array_vPointerIncrement(other_students, STUDENTS_NUM);
  
  cout << "\n-----------------------------------------------------------\n" << 
            "Outputting (again) data of array of Student objects: other_students\n" <<
			"-----------------------------------------------------------" << endl;	
  output_student_array_vPointerIncrement(other_students, STUDENTS_NUM);
  
  
  return 0;
}


/* Function implementations section */

void output_student_data(const Student & st){
  cout << "Student data - name: " << st.name << ", id:" << st.id << ", dept:" << st.dept << ", gender: " << st.gender << endl;
}

void input_student_data(Student & st){
  cout << "Please give Student data" << endl;
  cout << "name: ";
  cin >> st.name;
  cout << "id: ";
  cin >> st.id;
  cout << "dept: ";
  cin >> st.dept;
  cout << "gender: ";
  cin >> st.gender;
}

void output_student_array_vArrayIndexing(const Student st_arr [], size_t sz){
  cout << "Ouputting complete content of Student array - Array Indexing version" << endl;
  for (size_t i=0; i<sz; ++i){  // Make as many iterations as the number of elements in the array
    cout << "Student nr. " << i << endl;
    output_student_data( st_arr[i] );  // Directly access object via array indexing in order to pass it to function
  }  
}

void input_student_array_vArrayIndexing(Student st_arr [], size_t sz){
  cout << "Inputting complete content of Student array - Array Indexing version" << endl;
  for (size_t i=0; i<sz; ++i){  // Make as many iterations as the number of elements in the array
    cout << "Student nr. " << i << endl;
    input_student_data( st_arr[i] );  // Directly access object via array indexing in order to pass it to function
  }  
}

void output_student_array_vPointerIncrement(const Student * st_arr_pt, size_t sz){
  cout << "Ouputting complete content of Student array - Pointer Access Version" << endl;
  const Student * access_pt = st_arr_pt;  // Initialize a pointer to point to the 1st element in the array - HAS TO BE const because st_arr_pt is const !
  for (size_t i=0; i<sz; ++i){  // Make as many iterations as the number of elements in the array
    cout << "Student nr. " << i << endl;
    output_student_data( *access_pt );  // Dereference object that pointer is currently pointing in order to pass it to function
	access_pt++;  // Increment pointer in order to point to the subsequent position in the array
  }  
}

void input_student_array_vPointerIncrement(Student * st_arr_pt, size_t sz){
  cout << "Inputting complete content of Student array - Pointer Access Version" << endl;
  Student * access_pt = st_arr_pt;  // Initialize a pointer to point to the 1st element in the array - CAN BE non-const because st_arr_pt is non-const !
  for (size_t i=0; i<sz; ++i){  // Make as many iterations as the number of elements in the array
    cout << "Student nr. " << i << endl;
    input_student_data( *access_pt );  // Dereference object that pointer is currently pointing in order to pass it to function
	access_pt++;  // Increment pointer in order to point to the subsequent position in the array  
  }  
}