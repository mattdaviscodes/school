/**
 * @brief  CS-202 Project 3
 * @Author Matt Davis (mattdavis@nevada.unr.edu)
 * @date   2/8/18
 *
 * Expand on Project 2 car rental code by exploring classes, structs, and arrays of ATDs
 */

#include <iostream>
#include <fstream>

#include "RentalCar.h"
#include "RentalAgency.h"

using namespace std;

int menu();
int getIntBetween(int min, int max);
void fiveDigitIntToArray(int fiveDigitInt, int *arr);
void fiveDigitArrayFromFile(int *arr, ifstream &inf);
RentalAgency readRentalAgencyAndInventoryFromFile(ifstream &inf);
void readAllDataFromFile(RentalAgency * agencies);
void printRentalAgency(RentalAgency agency);
void printRentalAgencies(RentalAgency * agencies);
RentalCar readRentalCarFromFile(ifstream &inf);
RentalAgency selectAgency(RentalAgency * agencies);
RentalCar selectCar(RentalCar * cars);
void estimateRentalCost(RentalAgency * agencies);
void findMostExpensiveCar(RentalAgency * agencies);
void writeAvailableCarsToFile(RentalAgency * agencies);

// Custom string functions required by project spec
size_t myStringLength(const char * str);
int myStringCompare(const char * str1, const char * str2);
char *myStringCopy(char * destination, const char * source);
char * myStringCat(char * destination, const char * source);


int main() {
    RentalAgency agencies[AGENCIES_IN_FILE];
    ifstream inf;
    bool exit = false;
    int selection;

    do {
        selection = menu();
        switch (selection) {
            case 1: readAllDataFromFile(agencies); break;
            case 2: printRentalAgencies(agencies); break;
            case 3: estimateRentalCost(agencies); break;
            case 4: findMostExpensiveCar(agencies); break;
            case 5: writeAvailableCarsToFile(agencies); break;
            case 6: exit = true; break;
        }
    } while (!exit);

    return 0;
}

/*
* Display a menu to the user and prompt user for selection
*/
int menu() {
    cout << "What would you like to do?" << endl;
    cout << "1) Read rental agency data from file" << endl;
    cout << "2) Show rental agencies and cars" << endl;
    cout << "3) Estimate car rental cost" << endl;
    cout << "4) Find most expensive car" << endl;
    cout << "5) Write available cars to file" << endl;
    cout << "6) Exit" << endl;

    return getIntBetween(1, 6);
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
 * Convert a five digit integer to an int array.
 * This function uses modulous to extract the trailing digit from a base-10 integer, then stores those digits
 * in a target int array working from end to beginning.
 */
void fiveDigitIntToArray(int fiveDigitInt, int *arr) {
    int digit;
    int *arrEnd = arr + ZIPCODE_SIZE - 1;

    while (fiveDigitInt >= 10) {
        digit = fiveDigitInt % 10;  // Get last digit of base-10 int
        *arrEnd-- = digit;          // Fill array in reverse, because we're pulling digits from the end of fiveDigitInt
        fiveDigitInt /= 10;         // Chop last digit off base-10 int
    }
    *arrEnd = fiveDigitInt;         // At loop end, fiveDigitInt only contains final (first) digit
}

/*
 * Read a five digit integer from an ifstream and pass to fiveDigitIntToArray(). Mainly a helper function.
 */
void fiveDigitArrayFromFile(int *arr, ifstream &inf) {
    int fiveDigitInt;
    inf >> fiveDigitInt;
    fiveDigitIntToArray(fiveDigitInt, arr);
}

/*
 * Read in a single rental agency and all of it's associated inventory data from an ifstream.
 */
RentalAgency readRentalAgencyAndInventoryFromFile(ifstream &inf) {
    RentalAgency agency;
    RentalCar car;
    RentalCar *inventory = agency.inventory;

    inf >> agency.name;
    fiveDigitArrayFromFile(agency.zipcode, inf);
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        car = readRentalCarFromFile(inf);
        *inventory++ = car;
    }

    return agency;
}

/*
 * Prompt user for input filename, then read in all rental agency and rental car data until file is exhausted.
 */
void readAllDataFromFile(RentalAgency * agencies) {
    ifstream inf;
    char filename[MAX_CSTRING_SIZE];

    cout << "Infile name: ";
    cin >> filename;

    inf.open(filename);
    if (inf) {

        for (int i = 0; i < AGENCIES_IN_FILE; i++) {
            RentalAgency & agency = *agencies++;
            agency = readRentalAgencyAndInventoryFromFile(inf);
        }

    } else {
        cerr << "Unable to open file " << filename << endl;
    }

    inf.close();
}

/*
 * Print rental agency data, including inventory details
 */
void printRentalAgency(RentalAgency agency) {
    int *arrPtr = agency.zipcode;
    RentalCar *inventory = agency.inventory;

    // Print name and zipcode
    cout << agency.name << " - ";
    for (int i = 0; i < ZIPCODE_SIZE; i++) {
        cout << *arrPtr++;
    }
    cout << endl;

    // Print inventory
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        inventory->print();
        inventory++;
    }
    cout << endl;
}

/*
 * Helper function to print all rental agencies data. Mainly calls printRentalAgency()
 */
void printRentalAgencies(RentalAgency * agencies) {
    for (int i = 0; i < AGENCIES_IN_FILE; i++) {
        printRentalAgency(*agencies++);
    }
}

/*
 * Read in one rental car's data from an ifstream
 */
RentalCar readRentalCarFromFile(ifstream &inf) {
    int year;
    char make[MAX_CSTRING_SIZE], model[MAX_CSTRING_SIZE];
    float price;
    bool available;

    inf >> year >> make >> model >> price >> available;
    RentalCar car(year, make, model, price, available);

    return car;
}

/*
 * Prompt user to select a rental agency by entering an integer 1-3
 */
RentalAgency selectAgency(RentalAgency * agencies) {
    int selection;
    RentalAgency agency;
    RentalAgency * agenciesStart = agencies;

    cout << "Please select an agency." << endl;
    for (int i = 0; i < AGENCIES_IN_FILE; i++) {
        cout << i + 1 << ") " << agencies->name << endl;
        agencies++;
    }
    agencies = agenciesStart;   // Reset pointer after iterating
    selection = getIntBetween(1, AGENCIES_IN_FILE) - 1;
    agency = *(agencies + selection);

    return agency;
}

/*
 * Prompt user to select a rental car by entering an integer 1-5
 */
RentalCar selectCar(RentalCar * cars) {
    int selection;
    RentalCar * carsIterator = cars;

    cout << "Please select a car." << endl;
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        cout << i + 1 << ") ";
        carsIterator->print();
        carsIterator++;
    }
    selection = getIntBetween(1, INVENTORY_SIZE) - 1;

    return *(cars + selection);
}

/*
 * Calculate the estimated cost to rent a car for a user-input number of days, then print to screen
 */
void estimateRentalCost(RentalAgency * agencies) {
    RentalAgency agency;
    RentalCar car;
    int days;

    agency = selectAgency(agencies);
    car = selectCar(agency.inventory);

    cout << "For how many days would you like to rent the " << car.getMake() << " " << car.getModel() << "?" << endl;
    days = getIntBetween(1, 100);
    car.estimateCost(days);
}

/*
 * Locate the rental car with the greatest m_price member and print to screen
 */
void findMostExpensiveCar(RentalAgency * agencies) {
    RentalCar car, mostExpensiveCar = *(agencies->inventory);
    RentalCar * inventory;

    for (int i = 0; i < AGENCIES_IN_FILE; i++) {
        inventory = agencies->inventory;
        for (int j = 0; j < INVENTORY_SIZE; j++) {
            car = *inventory;
            if (car.getPrice() > mostExpensiveCar.getPrice()) {
                mostExpensiveCar = car;
            }
            inventory++;
        }
        agencies++;
    }

    cout << "Most expensive car: ";
    mostExpensiveCar.print();
}

/*
 * Prompt user to enter output file and write all available rental cars to that file
 */
void writeAvailableCarsToFile(RentalAgency * agencies) {
    char filename[MAX_CSTRING_SIZE];
    ofstream of;
    RentalCar car;
    RentalCar * inventory;
    int * zipcode;

    cout << "Name of file to write cars to: ";
    cin >> filename;

    of.open(filename);
    if (of) {

        for (int i = 0; i < AGENCIES_IN_FILE; i++) {
            inventory = agencies->inventory;
            zipcode = agencies->zipcode;

            of << agencies->name << " ";
            for (int k = 0; k < ZIPCODE_SIZE; k++) {
                of << *zipcode++;
            }
            of << endl;

            for (int j = 0; j < INVENTORY_SIZE; j++) {
                car = *inventory;
                if (car.getAvailable()) {
                    of << car.getYear() << " " << car.getMake() << " " << car.getModel() << " " << car.getPrice() << " "
                       << car.getAvailable() << endl;
                }
                inventory++;
            }
            of << endl;
            agencies++;
        }

    } else {
        cerr << "Unable to open file " << filename << endl;
    }

    of.close();
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