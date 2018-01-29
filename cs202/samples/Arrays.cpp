/**
 * @brief  CS-202 Arrays Sample
 * @Author Christos Papachristos (cpapachristos@unr.edu)
 * @date   January, 2018
 *
 * This file shows a sample implementation of array and 2D-array: Declaration, Initialization (Complete, Partial, Zero) with brace-enclosed initializers,
 * as well as the syntax and logic involved in their use as parameters to functions, for the purposes of CS-202
 */
 
#include <iostream>

using namespace std;

const int FLT_ARR_SZ = 5;
const int FLT_2DARR_ROWS = 3;

/* Function declaration (prototypes) section */

/*
   Takes in a float array, its size and a "target" position index, and outputs that content to the terminal.
   Note 1: Performs necessary checks (position has to be non-negative and within the array bounds)
   Note 2: Only reads (does not modify) the content of array, therefore we pass it as a const-marked parameter ( const float array [] )
*/
void output_float_array_element(const float  array [], int array_size, int position);

/*
   Takes in a float array, its size and a "target" position index, and asks for user input to modify its content.
   Note 1: Performs necessary checks (position has to be non-negative and within the array bounds)
   Note 2: Modifies content of array, therefore it is required that it is passed as a non-const parameter ( float array [] )
*/
void input_float_array_element(float  array [], int array_size, int position);

/*
   Takes in a float array and its size and outputs its complete content to the terminal.
   Note 1: Makes code re-use, internally calls output_float_array_element by forwarding to it the same array and size parameters
   Note 2: Only reads (does not modify) the content of array (actually the internally called output_float_array_element does), therefore
           we pass it as a const-marked parameter ( const float array [] )
*/
void output_float_array_complete(const float  array [], int array_size);

/*
   Takes in a float array and its size and asks for user input to modify its entire content.
   Note 1: Makes code re-use, internally calls input_float_array_element by forwarding to it the same array and size parameters
   Note 2: Modifies content of array (actually the internally called input_float_array_element does), therefore it is required
           that it is passed as a non-const parameter ( float array [] )
*/
void input_float_array_complete(float  array [], int array_size);

/*
   Takes in a 2-Dimenstional float array and its number of size (number of rows, since a 2D array in an array of arrays), and outputs its complete content to the terminal.
   Note 1: Makes code re-use, internally calls output_float_array_complete by forwarding to it a sub-array of the input 2D array_2D, and size parameters
   Note 2: Only reads (does not modify) the content of array_2D (actually the internally called output_float_array_complete does not modify each passed sub-array), therefore
           we pass it as a parameter that specifies that its content sub-arrays are const-marked ( const float array_2D [][FLT_ARR_SZ] )
*/
void output_float_2D_array_complete(const float  array_2D [][FLT_ARR_SZ], int array_rows);

/*
   Takes in a 2-Dimenstional float array and its number of size (number of rows, since a 2D array in an array of arrays), and asks for user input to mofigy its entire content.
   Note 1: Makes code re-use, internally calls input_float_array_complete by forwarding to it a sub-array of the input 2D array_2D, and size parameters
   Note 2: Modifies content of array_2D (actually the internally called input_float_array_complete modifies each passed sub-array), therefore
           we pass it as a parameter that specifies that its content sub-arrays are non-const ( float array_2D [][FLT_ARR_SZ] )
*/
void input_float_2D_array_complete(float  array_2D [][FLT_ARR_SZ], int array_rows);


/* Program main function (entry point) */

int main(){

  /* Part 1: Arrays */
  
  float myFloatArray[ FLT_ARR_SZ ];  // This means that the array elements are left uninitialized (actual values undefined, can contain anything)
  float myFloatArray_initialized[ FLT_ARR_SZ ] = {1.0, -1.0, 2.0, -2.0, 3.14159};  // This means that all the array elements become initialized to the specific values
                                                                                   //in the brace-enclosed initializer
  float myFloatArray_partially_initialized[ FLT_ARR_SZ ] = {1.0, -1.0};  // This means that only the 2 first array elements become initialized to the specified values
                                                                         // in the brace-enclosed initializer, while the rest become "zero-initialized" (zero-initalization
                                                                         // for float numbers means they become 0.0);
  float myFloatArray_zero_initialized[ FLT_ARR_SZ ] = { };  // The empty brace-enclosed initializer means that all the array elements become "zero-initialized", 
                                                            // hence they all become 0.0
															
  cout << "\n----------------------------------------------------------\n" << 
            "Outputting the content of myFloatArray\n" <<
            "(FLT_ARR_SZ number of elements, none of them initialized):\n" <<
			"----------------------------------------------------------" << endl;
  output_float_array_complete( myFloatArray, FLT_ARR_SZ );
  
  cout << "\n---------------------------------------------------------\n" << 
            "Outputting the content of myFloatArray_initialized\n"
            "(FLT_ARR_SZ number of elements, all of them initialized):\n" <<
			"---------------------------------------------------------" << endl;
  output_float_array_complete( myFloatArray_initialized, FLT_ARR_SZ );
  
  cout << "\n----------------------------------------------------------------------\n" << 
            "Outputting the content of myFloatArray_partially_initialized\n"
            "(FLT_ARR_SZ number of elements, only the first 2 of them initialized):\n" <<
			"----------------------------------------------------------------------" << endl;
  output_float_array_complete( myFloatArray_partially_initialized, FLT_ARR_SZ );
  
  cout << "\n----------------------------------------------------------------\n" << 
            "Outputting the content of myFloatArray_zero_initialized\n"
            "(FLT_ARR_SZ number of elements, all of them \"zero-initialized\"):\n" <<
			"----------------------------------------------------------------" << endl;
  output_float_array_complete( myFloatArray_zero_initialized, FLT_ARR_SZ );
 

  cout << "\n----------------------------------------------------------\n" << 
            "Inputting values to myFloatArray\n" <<
            "(FLT_ARR_SZ number of elements, none of them initialized):\n" <<
			"----------------------------------------------------------" << endl;
  input_float_array_complete( myFloatArray, FLT_ARR_SZ );
  cout << "\n--------------------------------------------------------------------\n" << 
            "Outputting the new content of myFloatArray\n" <<
            "(FLT_ARR_SZ number of elements, all of them defined via user input):\n" <<
			"--------------------------------------------------------------------" << endl;
  output_float_array_complete( myFloatArray, FLT_ARR_SZ );
  
  
  /* Part 2: Multi-Dimensional Arrays */
  float myFloat2DArray[ FLT_2DARR_ROWS ][ FLT_ARR_SZ ];  // This means that the 2D array consists of a number of FLT_2DARR_ROWS float arrays, each with FLT_ARR_SZ elements
                                                         // Hence, each element of myFloat2DArray (e.g. myFloat2DArray[0], myFloat2DArray[1], myFloat2DArray[2]) is a float array
                                                         // (also, this 2D array is uninitialized therefore all the float arrays it contains have unspecified values)

  float myFloat2DArray_initialized[ FLT_2DARR_ROWS ][ FLT_ARR_SZ ] = { {1.0, -1.0, 2.0, -2.0, 3.14159},   // Again a 2D array consisting of FLT_2DARR_ROWS float arrays
                                                                       {3.0, -3.0, 4.0, -4.0, 0.01745},   // Here, initialized by a brace-enclosed initializer which contains
                                                                       {5.0, -5.0, 6.0, -6.0, 2.71828} }; // other brace-enclosed initializers for each sub-array
																	   
  float myFloat2DArray_partially_initialized[ FLT_2DARR_ROWS ][ FLT_ARR_SZ ] = { {1.0, -1.0},                     // Again a 2D array consisting of FLT_2DARR_ROWS float arrays
                                                                                 {3.0, -3.0, 4.0, -4.0, 0.01745}, // Here, partially initialized by a brace-enclosed initializer 
                                                                                 {} };                            // which contains other partially filled brace-enclosed initializers
																				 
  float myFloat2DArray_zero_initialized[ FLT_2DARR_ROWS ][ FLT_ARR_SZ ] = { {} };  // Again a 2D array consisting of FLT_2DARR_ROWS float arrays
                                                                                   // Here, fully zero-initialized by a brace-enclosed initializer which contains no specific
                                                                                   // brace-enclosed initializers (just an empty one)
		
  cout << "\n----------------------------------------------------------------------------\n" << 
            "Outputting the content of myFloat2DArray\n" <<
            "(FLT_2DARR_ROWS number of rows with float sub-arrays of FLT_ARR_SZ elements,\n"
            " none of them initialized):\n" <<
			"----------------------------------------------------------------------------" << endl;		
  output_float_2D_array_complete(myFloat2DArray, FLT_2DARR_ROWS);	

  cout << "\n----------------------------------------------------------------------------\n" << 
            "Outputting the content of myFloat2DArray_initialized\n" <<
            "(FLT_2DARR_ROWS number of rows with float sub-arrays of FLT_ARR_SZ elements,\n"
            " all of them initialized):\n" <<
			"----------------------------------------------------------------------------" << endl;		
  output_float_2D_array_complete(myFloat2DArray_initialized, FLT_2DARR_ROWS);	
  
  cout << "\n-----------------------------------------------------------------------------\n" << 
            "Outputting the content of myFloat2DArray_partially_initialized\n" <<
            "(FLT_2DARR_ROWS number of rows with float sub-arrays of FLT_ARR_SZ elements,\n"
            " 1 partially initialized, 1 fully initialized, and the last zero-intialized):\n" <<
			"-----------------------------------------------------------------------------" << endl;		
  output_float_2D_array_complete(myFloat2DArray_partially_initialized, FLT_2DARR_ROWS);	
  
  cout << "\n-----------------------------------------------------------------------------\n" << 
            "Outputting the content of myFloat2DArray_zero_initialized\n" <<
            "(FLT_2DARR_ROWS number of rows with float sub-arrays of FLT_ARR_SZ elements,\n"
            " zero-initialized completely):\n" <<
			"-----------------------------------------------------------------------------" << endl;		
  output_float_2D_array_complete(myFloat2DArray_zero_initialized, FLT_2DARR_ROWS);	
  
  
  cout << "\n----------------------------------------------------------------------------\n" << 
            "Inputting values to myFloat2DArray\n" <<
            "(FLT_2DARR_ROWS number of rows with float sub-arrays of FLT_ARR_SZ elements,\n"
            " none of them initialized):\n" <<
			"----------------------------------------------------------------------------" << endl;
  input_float_2D_array_complete( myFloat2DArray, FLT_2DARR_ROWS );
  cout << "\n--------------------------------------------------------------------\n" << 
            "Outputting the new content of myFloat2DArray\n" <<
            "(FLT_2DARR_ROWS number of rows with float sub-arrays of FLT_ARR_SZ elements,\n"
            " all of them defined via user input):\n" <<
			"--------------------------------------------------------------------" << endl;
  output_float_2D_array_complete( myFloat2DArray, FLT_2DARR_ROWS );
  
  
  return 0;
}


/* Function implementations section */

void output_float_array_element(const float  array [], int array_size, int position) {
	if (position>=0 && position<array_size) {
		cout << "Floating-point number at index " << position << " of the array is: " << array[ position ] << endl;
	}
	else {
		cout << "Error detected: array element position " << position << " to output in has to be non-negative (>0) and\n" <<
		        "within the bounds of the array size (<" << array_size << "), aborting..." << endl;
	}
}

void input_float_array_element(float  array [], int array_size, int position) {
	if (position>=0 && position<array_size) {
		cout << "Please input a float number to fill in at index " << position << " of the array." << endl;
        cin >> array[ position ];
	}
	else {
		cout << "Error detected: array element position " << position << " to fill in has to be non-negative (>0) and\n" <<
		        "within the bounds of the array size (<" << array_size << "), aborting..." << endl;
	}
}

void output_float_array_complete(const float  array [], int array_size) {
	cout << "Starting output of " << array_size << " elements to output complete float array..." << endl;
	for (int i=0; i<array_size; ++i) {
		output_float_array_element( array, array_size, i );
	}
}

void input_float_array_complete(float  array [], int array_size) {
    cout << "Starting input of " << array_size << " elements to fill in float array..." << endl;
	for (int i=0; i<array_size; ++i) {
		input_float_array_element( array, array_size, i );
	}
}

void output_float_2D_array_complete(const float  array_2D [][FLT_ARR_SZ], int array_rows) {
	cout << "Starting output of " << array_rows << " rows of 2d float array\n(each row is itself a separate float array)..." << endl;
	for (int j=0; j<array_rows; ++j) {
		cout << "Sub-array at row j = " << j << endl;
		output_float_array_complete( array_2D[j], FLT_ARR_SZ);
	}
}

void input_float_2D_array_complete(float  array_2D [][FLT_ARR_SZ], int array_rows) {
	cout << "Starting input of " << array_rows << " rows of 2d float array\n(each row is itself a separate float array)..." << endl;
	for (int j=0; j<array_rows; ++j) {
	    cout << "Starting input of sub-array at row j = " << j << endl;
		input_float_array_complete( array_2D[j], FLT_ARR_SZ);
	}
}