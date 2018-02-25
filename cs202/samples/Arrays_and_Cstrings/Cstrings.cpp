/**
 * @brief  CS-202 Cstrings Sample
 * @Author Christos Papachristos (cpapachristos@unr.edu)
 * @date   January, 2018
 *
 * This file shows a sample implementation of Cstrings: Declaration, Initialization (Complete, Partial, Zero) with brace-enclosed initializers and Cstring literals,
 * as well as the syntax and logic involved in their use as parameters to functions, for the purposes of CS-202
 */
 
#include <iostream>

#include <cstring>  // Only for demonstration purposes, you are not allowed to use cstring and its built-in functions

using namespace std;

const int STR_SZ = 25;
const int STR_2DARR_ROWS = 3;

/* Function declaration (prototypes) section */

/*
   Takes in a char array (assumes it represents a Cstring) and a "target" position index, and outputs that character to the terminal.
   Note 1: Performs necessary checks (position has to be non-negative and less than the Cstring length)
   Note 2: Only reads (does not modify) the content of array, therefore we pass it as a const-marked parameter ( const char str [] )
*/
void output_cstring_element(const char  str [], int position);

/*
   Takes in a char array (assumes it represents a Cstring) and a "target" position index, and asks for user input to modify its content.
   Note 1: Performs necessary checks (position has to be non-negative and less than the Cstring length)
   Note 2: Modifies content of Cstring, therefore it is required that it is passed as a non-const parameter ( char str [] )
*/
void input_cstring_element(char  str [], int position);

/*
   Takes in a char array and outputs its Cstring content to the terminal.
   Note 1: Internally uses insertion operator overloading for ostream objects with char arrays ( cout << ... ; ) 
   Note 2: Only reads (does not modify) the content of str (actually the internally called operator<< str does), therefore
           we pass it as a const-marked parameter ( const char str [] )
*/
void output_cstring(const char  str []);

/*
   Takes in a char array and inputs a Cstring sequence of characters into it.
   Note 1: Internally uses extraction operator overloading for ostream objects with char arrays ( cin >> ... ; ) 
   Note 2: Modifies content of str (actually the internally called operator>> does), therefore it is required
           that it is passed as a non-const parameter ( char array [] )
*/
void input_cstring(char  str []);

/*
   Takes in a 2-Dimensional char array (assumes it represents an array of Cstring) and its size (number of rows), and outputs its complete content to the terminal.
   Note 1: Makes code re-use, internally calls output_cstring by forwarding to it a sub-Cstring of the input 2D str_2D, and size parameters
   Note 2: Only reads (does not modify) the content of str_2D (actually the internally called input_cstring does not modify each passed sub-Cstring), therefore
           we pass it as a parameter that specifies that its content sub-Cstrings are const-marked ( const char str_2D [][STR_SZ] )
*/
void output_cstring_2D_array_complete(const char  str_2D [][STR_SZ], int array_rows);

/*
   Takes in a 2-Dimensional char array (assumes it represents an array of Cstring) and its size (number of rows), and asks for user input to mofigy its entire content.
   Note 1: Makes code re-use, internally calls input_cstring by forwarding to it a sub-Cstring of the input 2D str_2D, and size parameters
   Note 2: Modifies content of str_2D (actually the internally called input_cstring modifies each passed sub-Cstring), therefore
           we pass it as a parameter that specifies that its content sub-Cstrings are non-const ( char str_2D [][STR_SZ] )
*/
void input_cstring_2D_array_complete(char  str_2D [][STR_SZ], int array_rows);


/* Program main function (entry point) */

int main(){

  /* Part 1: Cstrings */
  
  char myCstring[ STR_SZ ];                                                       // This means that the Cstring is left uninitialized (actual char sequence undefined,
                                                                                  // can contain anything)
  char myCstring_initialized[ STR_SZ ] = {'M','a','r','y',' ','S','u','e','\0'};  // This means that the Cstring's 9 first array elements become initialized to the specific values
                                                                                  // in the standard brace-enclosed initializer method
  char myCstring_initialized_2[ STR_SZ ] = "John Doe";                            // This means that the Cstring becomes initialized to the sequence of characters of the string
                                                                                  // literal on the right hand side (the NULL-terminator is implicitly inserted at the end too)
  char myCstring_zero_initialized[ STR_SZ ] = { };                                // The zero-initialization means all characters are 0 (0=='\0'), therefore the Cstring is empty
  char myCstring_zero_initialized_2[ STR_SZ ] = "";                               // This is an alternative to initialize to an empty string value (via an empty string literal)
															
  cout << "\n-----------------------------------------------------------------\n" << 
            "Outputting the content of myCstring\n" <<
            "(STR_SZ number of elements, none of them initialized,\n" <<
            " but this is a bad idea because output will stop only\n" <<
            " when a NULL-terminator '\\0' or equivalently a 0 value is found):\n" <<
			"-----------------------------------------------------------------" << endl;
  output_cstring( myCstring );
  
  cout << "\n---------------------------------------------------------\n" << 
            "Outputting the content of myCstring_initialized\n"
            "(STR_SZ is not the same as Cstring length):\n" <<
			"---------------------------------------------------------" << endl;
  output_cstring( myCstring_initialized );
  
  cout << "\n----------------------------------------------------------------------\n" << 
            "Outputting the content of myCstring_initialized_2\n"
            "(STR_SZ is not the same as Cstring length):\n" <<
			"----------------------------------------------------------------------" << endl;
  output_cstring( myCstring_initialized_2 );
  
  cout << "\n----------------------------------------------------------------\n" << 
            "Outputting the content of myCstring_zero_initialized\n"
            "(STR_SZ is not the same as empty Cstring length of 0):\n" <<
			"----------------------------------------------------------------" << endl;
  output_cstring( myCstring_zero_initialized );
 
  cout << "\n----------------------------------------------------------------\n" << 
            "Outputting the content of myCstring_zero_initialized_2\n"
            "(STR_SZ is not the same as empty Cstring length of 0):\n" <<
			"----------------------------------------------------------------" << endl;
  output_cstring( myCstring_zero_initialized_2 );

  cout << "\n-----------------------------------------------------------------------\n" << 
            "Inputting to myCstring\n" <<
            "(STR_SZ-1 number of characters max, to fit NULL-terminator at the end):\n" <<
			"-----------------------------------------------------------------------" << endl;
  input_cstring( myCstring );
  cout << "\n----------------------------------------------------------------------------\n" << 
            "Outputting the new content of myCstring\n" <<
            "(STR_SZ number of elements, but now with proper values and NULL-terminated):\n" <<
			"----------------------------------------------------------------------------" << endl;
  output_cstring( myCstring );
  
  return 0;
}


/* Function implementations section */

void output_cstring_element(const char  str [], int position) {
	if (position>=0 && position<strlen(str)) {
		cout << "Character number at index " << position << " of the Cstring is: " << str[ position ] << endl;
	}
	else {
		cout << "Error detected: Cstring element position " << position << " to output in has to be non-negative (>0) and\n" <<
		        "smaller than the Cstring length (<" << strlen(str) << "), aborting..." << endl;
	}
}

void input_cstring_element(char str [], int position) {
	if (position>=0 && position<strlen(str)) {
		cout << "Please input a char to fill in at index " << position << " of the Cstring." << endl;
        cin >> str[ position ];
	}
	else {
		cout << "Error detected: Cstring element position " << position << " to fill in has to be non-negative (>0) and\n" <<
		        "smaller than the Cstring length (<" << strlen(str) << "), aborting..." << endl;
	}
}

void output_cstring(const char  str []) {
	cout << "Starting output of Cstring ( " << strlen(str) << " characters long)..." << endl;
	cout << str << endl;
}

void input_cstring(char  str []) {
    cout << "Starting input of Cstring, make sure you only give up to " << STR_SZ << " characters long ..." << endl;
	cin >> str;
}

void output_cstring_2D_array_complete(const char  str_2D [][STR_SZ], int array_rows) {
	cout << "Starting output of " << array_rows << " rows of 2d Cstring array\n(each row is itself a separate Cstring)..." << endl;
	for (int j=0; j<array_rows; ++j) {
		cout << "Sub-Cstring at row j = " << j << endl;
		output_cstring( str_2D[j] );
	}
}

void input_cstring_2D_array_complete(char  str_2D [][STR_SZ], int array_rows) {
	cout << "Starting input of " << array_rows << " rows of 2d Cstring array\n(each row is itself a separate Cstring)..." << endl;
	for (int j=0; j<array_rows; ++j) {
	    cout << "Starting input of sub-Cstring at row j = " << j << endl;
		input_cstring( str_2D[j] );
	}
}