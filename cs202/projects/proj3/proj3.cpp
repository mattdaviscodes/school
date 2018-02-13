// TODO: Header

#include <iostream>
#include <fstream>

#include "RentalCar.h"
#include "RentalAgency.h"

using namespace std;

int menu();
int getIntBetween(int min, int max);
void fiveDigitIntToArray(int fiveDigitInt, int *arr);
void fiveDigitArrayFromFile(int *arr, ifstream &inf);
RentalAgency readRentalAgencyFromFile(ifstream &inf);
RentalAgency readRentalAgencyAndInventoryFromFile(ifstream &inf);
void readAllDataFromFile(RentalAgency * agencies);
void readAllDataFromFile(RentalAgency * agencies, char * filename);
void printRentalAgency(RentalAgency agency);
void printRentalAgencies(RentalAgency * agencies);
RentalCar readRentalCarFromFile(ifstream &inf);
RentalAgency selectAgency(RentalAgency * agencies);
RentalCar selectCar(RentalCar * cars);
void estimateRentalCost(RentalAgency * agencies);
void findMostExpensiveCar(RentalAgency * agencies);
void writeAvailableCarsToFile(RentalAgency * agencies);

// custom string functions
size_t myStringLength(const char * str);
int myStringCompare(const char * str1, const char * str2);
char *myStringCopy(char * destination, const char * source);
char * myStringCat(char * destination, const char * source);


int main() {
    RentalAgency agency;
    RentalAgency agencies[AGENCIES_IN_FILE];
    RentalCar car;
    ifstream inf;
    bool exit = false;
    int selection;

    // TODO: Remove
    readAllDataFromFile(agencies, "Agencies.txt");

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

void fiveDigitArrayFromFile(int *arr, ifstream &inf) {
    int fiveDigitInt;
    inf >> fiveDigitInt;
    fiveDigitIntToArray(fiveDigitInt, arr);
}

RentalAgency readRentalAgencyFromFile(ifstream &inf) {
    RentalAgency agency;

    inf >> agency.name;
    fiveDigitArrayFromFile(agency.zipcode, inf);

    return agency;
}

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

void readAllDataFromFile(RentalAgency * agencies, char * filename) {
    ifstream inf;

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

void printRentalAgencies(RentalAgency * agencies) {
    for (int i = 0; i < AGENCIES_IN_FILE; i++) {
        printRentalAgency(*agencies++);
    }
}

RentalCar readRentalCarFromFile(ifstream &inf) {
    int year;
    char make[MAX_CSTRING_SIZE], model[MAX_CSTRING_SIZE];
    float price;
    bool available;

    inf >> year >> make >> model >> price >> available;
    RentalCar car(year, make, model, price, available);

    return car;
}

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

// custom string functions
size_t myStringLength(const char * str);
int myStringCompare(const char * str1, const char * str2);
char *myStringCopy(char * destination, const char * source);
char *myStringCat(char * destination, const char * source);