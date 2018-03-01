//
// Created by Matthew Davis on 2/20/18.
//

#include <iostream>
#include <fstream>

#include "proj4.h"
#include "Sensor.h"
#include "Car.h"
#include "Agency.h"

using namespace std;

// Prototypes
int menu();
int getIntBetween(int min, int max);

int main() {
    Agency agency;
    ifstream inf;
    bool exit = false;
    int selection;

    do {
        selection = menu();
        switch (selection) {
            case 1: agency.readAllData(); break;
            case 2: agency.printAllData(); break;
            case 3: agency.printSensorCounts(); break;
            case 4: agency.findMostExpensiveCar(); break;
            case 5: exit = true; break;
        }
    } while (!exit);

    return 0;
}

/*
* Display a menu to the user and prompt user for selection
*/
int menu() {
    cout << "What would you like to do?" << endl;
    cout << "1) Read all data from file" << endl;
    cout << "2) Show all data" << endl;
    cout << "3) Show total sensor counts" << endl;
    cout << "4) Find most expensive car" << endl;
    cout << "5) Exit" << endl;

    return getIntBetween(1, 5);
}

/*
 * Prompt user for an integer between min and max, inclusive.
 * NOTE: This function completely blows up user enters non-integer
 */
int getIntBetween(int min, int max)
{
    int selection;

    // Prompt until valid selection entered
    do {
        cout << "Enter selection (" << min << "-" << max << "): ";
        cin >> selection;   // TODO: Prevent non-integer input infinite loop

    } while (selection < min || selection > max);

    return selection;
}

/*
 * Find the length of a string, not including the null-terminator
 */
size_t myStringLength(const char * str) {
    size_t i = 0;

    while (*str++) {
        i++;
    };

    return i;
}

/*
 * Compare two strings. Return -1 of str1 is less than str2, 1 if the opposite, 0 if they're identical
 */
int myStringCompare(const char * str1, const char * str2) {
    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }

    return *str1 - *str2;
}

/*
 * Copy a source string to a destination string
 */
char *myStringCopy(char * destination, const char * source) {
    while ((*destination++ = *source++))
        ;

    return destination;
}

/*
 * Concatenate a source string onto the end of a destination string
 */
char *myStringCat(char * destination, const char * source) {
    // Find end of destination
    while (*destination) {
        destination++;  // Leaves destination pointing to null character
    }

    // Copy source onto end of destination
    while ((*destination++ = *source++))
        ;

    return destination;
}