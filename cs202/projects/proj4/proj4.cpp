//
// Created by Matthew Davis on 2/20/18.
//

#include <iostream>
#include <cstring> // TODO REMOVE

#include "proj4.h"
#include "Sensor.h"
#include "Car.h"

using namespace std;

int main() {
    Sensor sensors[MAX_SENSORS_PER_CAR];
    Sensor lidar("lidar"), radar("radar"), camera("camera"), gps("gps");
    Car c("Ford", "F-150", 2006, 99.99, true, sensors);

    cout << c << endl;
    c + lidar;
    cout << c << endl;
    c + radar;
    cout << c << endl;
    c + camera;
    cout << c << endl;
    c + gps;
    cout << c << endl;

    return 0;
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