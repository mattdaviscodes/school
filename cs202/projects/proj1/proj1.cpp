/**
 * @brief  CS-202 Project 1
 * @Author Matt Davis (mattdavis@nevada.unr.edu)
 * @date   1/28/18
 *
 * This is the completed project 1 for CS 202, Spring 2018, with Chris Papachristos.
 */

#include <iostream>
#include <fstream>

using namespace std;

const int NAME_SIZE = 8;
const int NAMES_IN_FILE = 10;

// Prototypes
void bubble_sort_alpha(char input[NAMES_IN_FILE][NAME_SIZE + 1]);
void swap(char input[NAMES_IN_FILE][NAME_SIZE + 1], int str1_index, int str2_index);
int find_original_index(const char input[NAMES_IN_FILE][NAME_SIZE + 1], const char name[NAME_SIZE + 1]);
void myStringCopy(char destination [], const char source []);
int myStringLength(const char str []);
int myStringCompare(const char str1 [], const char str2 []);

int main()
{
    char input_filename[100], output_filename[100];
    char names[NAMES_IN_FILE][NAME_SIZE + 1], names_copy[NAMES_IN_FILE][NAME_SIZE + 1];;
    ifstream infile;
    ofstream outfile;


    // Prompt user for input and output filenames
    cout << "Input filename: ";
    cin >> input_filename;
    cout << "Output filename: ";
    cin >> output_filename;

    // Attempt file open. Exit on error
    infile.open(input_filename);
    if (!infile) {
        cerr << "Unable to open file " << input_filename << ". Exiting." << endl;
        return 1;
    }
    outfile.open(output_filename);
    if (!outfile) {
        cerr << "Unable to open file " << output_filename << ". Exiting." << endl;
        return 2;
    }

    // Read infile lines into names
    int i = 0;
    while (infile.getline(names[i++], NAME_SIZE + 1)) {
    }

    // Copy names into names_copy
    for (int i = 0; i < NAMES_IN_FILE; i++) {
        myStringCopy(names_copy[i], names[i]);
    }

    // Print original order
    cout << "Unsorted Data (Original Input Order and Name)\n"
            "=============================================" << endl;
    for (int i = 0; i < NAMES_IN_FILE; i++) {
        cout << i << " " << names[i] << endl;
    }
    cout << endl;

    // Sort copy, leave original alone for later reference
    bubble_sort_alpha(names_copy);

    // Print sorted list with unsorted index next to it
    // Write sorted list to output file with unsorted index
    cout << "Sorted Data (Original Input Order and Name)\n"
            "===========================================" << endl;
    for (int i = 0; i < NAMES_IN_FILE; i++) {
        int orig_index = find_original_index(names, names_copy[i]);
        cout << orig_index << " " << names_copy[i] << endl;
        outfile << orig_index << " " << names_copy[i] << endl;
    }

    outfile.close();
    infile.close();

    return 0;
}

/*
 * Sort 2d char array alphabetically using bubble sort
 */
void bubble_sort_alpha(char input[NAMES_IN_FILE][NAME_SIZE + 1])
{
    char temp[NAME_SIZE + 1];
    bool swapped;

    do {
        swapped = false;
        for (int i = 0; i < NAMES_IN_FILE - 1; i++) {
            if (myStringCompare(input[i], input[i+1]) > 0) {
                swap(input, i, i+1);
                swapped = true;
            }
        }
    } while (swapped);

}

/*
 * Swap the data at input[str1_index] with input[str2_index]
 */
void swap(char input[NAMES_IN_FILE][NAME_SIZE + 1], int str1_index, int str2_index)
{
    char temp[NAME_SIZE + 1];

    myStringCopy(temp, input[str1_index]);
    myStringCopy(input[str1_index], input[str2_index]);
    myStringCopy(input[str2_index], temp);
}

/*
 * Return the index of name in input
 */
int find_original_index(const char input[NAMES_IN_FILE][NAME_SIZE + 1], const char name[NAME_SIZE + 1])
{
    for (int i = 0; i < NAMES_IN_FILE; i++) {
        if (myStringCompare(input[i], name) == 0) {
            return i;
        }
    }

    return -1;
}

/*
 * Copy the contents of source into destination
 */
void myStringCopy(char destination [], const char source [])
{
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

/*
 * Find length of a char array, not including null terminator.
 *
 * myStringLength("test") == 4
 */
int myStringLength(const char str [])
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }

    return i;
}

/*
 * Returns the difference between the first non-matching character from both strings
 */
int myStringCompare(const char str1 [], const char str2 [])
{
    int i = 0;

    while (str1[i] && str2[i] && str1[i] == str2[i]) {
        i++;
    }

    return str1[i] - str2[i];
}