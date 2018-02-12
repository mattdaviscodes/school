// TODO: Header

#include <iostream>
#include <fstream>

#include "RentalCar.h"
#include "RentalAgency.h"

using namespace std;

void fiveDigitIntToArray(int fiveDigitInt, int * arr);
void fiveDigitArrayFromFile(int * arr, ifstream& inf);
RentalAgency readRentalAgencyFromFile(ifstream& inf);
RentalAgency readRentalAgencyAndInventoryFromFile(ifstream& inf);
void printRentalAgency(RentalAgency agency);
RentalCar readRentalCarFromFile(ifstream& inf);

int main() {
    int fiveDigitInt = 12345;
    int arr[ZIPCODE_SIZE];
    RentalAgency agency;
    RentalCar car;
    ifstream inf;

    inf.open("test.txt");
    for (int i = 0; i < AGENCIES_IN_FILE; i++) {
        agency = readRentalAgencyAndInventoryFromFile(inf);
        printRentalAgency(agency);
    }
    inf.close();

    return 0;
}

void fiveDigitIntToArray(int fiveDigitInt, int * arr) {
    int digit;
    int * arrEnd = arr + ZIPCODE_SIZE - 1;

    while (fiveDigitInt >= 10) {
        digit = fiveDigitInt % 10;  // Get last digit of base-10 int
        *arrEnd-- = digit;          // Fill array in reverse, because we're pulling digits from the end of fiveDigitInt
        fiveDigitInt /= 10;         // Chop last digit off base-10 int
    }
    *arrEnd = fiveDigitInt;         // At loop end, fiveDigitInt only contains final (first) digit
}

void fiveDigitArrayFromFile(int * arr, ifstream& inf) {
    int fiveDigitInt;
    inf >> fiveDigitInt;
    fiveDigitIntToArray(fiveDigitInt, arr);
}

RentalAgency readRentalAgencyFromFile(ifstream& inf) {
    RentalAgency agency;
    int zipcodeInt;

    inf >> agency.name;
    fiveDigitArrayFromFile(agency.zipcode, inf);

    return agency;
}

RentalAgency readRentalAgencyAndInventoryFromFile(ifstream& inf) {
    RentalAgency agency;
    RentalCar car;
    RentalCar * inventory = agency.inventory;
    int zipcodeInt;

    inf >> agency.name;
    fiveDigitArrayFromFile(agency.zipcode, inf);
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        car = readRentalCarFromFile(inf);
        *inventory++ = car;
    }

    return agency;
}

void printRentalAgency(RentalAgency agency) {
    int * arrPtr = agency.zipcode;
    RentalCar * inventory = agency.inventory;

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

RentalCar readRentalCarFromFile(ifstream& inf) {
    int year;
    char make[MAX_CSTRING_SIZE], model[MAX_CSTRING_SIZE];
    float price;
    bool available;

    inf >> year >> make >> model >> price >> available;
    RentalCar car(year, make, model, price, available);

    return car;
}