/**
 * @brief  CS-202 Project 2
 * @Author Matt Davis (mattdavis@nevada.unr.edu)
 * @date   2/1/18
 *
 * A program to assist users to rent a car
 */

#include <iostream>
#include <fstream>
#include "proj2.h"    // Just holds Car struct
using namespace std;

const int CARS_IN_FILE = 5;

int menu();
void showCars(const Car cars[]);
void showAvailableCars(const Car cars[]);
void showAvailableCars(const Car cars[], int days);
void readCarsFromFile(Car cars[]);
void readCarsFromFile(Car cars[], const char * filename);
void writeCarsToFile(Car cars[]);
void bubbleSortCars(Car cars[]);
int getIntBetween(int min, int max);
void promptRentalDays(Car cars[]);
void rentCar(Car cars[]);


int main()
{
    int selection;
    bool exit = false;
    Car cars[5];

    do {
        selection = menu();
        switch (selection) {
            case 1: readCarsFromFile(cars); break;
            case 2: showCars(cars); break;
            case 3: writeCarsToFile(cars); break;
            case 4: bubbleSortCars(cars); break;
            case 5: promptRentalDays(cars); break;
            case 6: rentCar(cars); break;
            case 7: exit = true; break;
            default: cout << "Uh oh" << endl;
        }


    } while (!exit);

    return 0;
}
/*
 * Display a menu to the user and prompt user for selection
 */
int menu()
{
    cout << "What would you like to do?" << endl;
    cout << "1) Read cars in from file" << endl;
    cout << "2) Show cars" << endl;
    cout << "3) Output cars to file" << endl;
    cout << "4) Sort cars by price" << endl;
    cout << "5) Show cars available for N days" << endl;
    cout << "6) Rent a car" << endl;
    cout << "7) Exit" << endl;

    return getIntBetween(1, 7);
}

/*
 * Prompt user for data filename. Read in file and store in array of Car structs.
 */
void readCarsFromFile(Car cars[])
{
    char filename[100];
    ifstream infile;

    // Prompt user for input filename
    cout << "Input filename: ";
    cin >> filename;

    infile.open(filename);
    if (infile) {

        // Read in file if successfully opened
        int i = 0;
        while (!infile.eof()) {
            infile >> cars[i].year >> cars[i].make >> cars[i].model >> cars[i].price >> cars[i].available;
            i++;
        }

    } else {
        cerr << "Unable to open file " << filename << endl;
    }

    infile.close();
}

/*
 * Read in data from file and store in array of Car structs.
 */
void readCarsFromFile(Car cars[], const char * filename)
{
    ifstream infile;
    infile.open(filename);
    if (infile) {

        // Read in file if successfully opened
        int i = 0;
        while (!infile.eof()) {
            infile >> cars[i].year >> cars[i].make >> cars[i].model >> cars[i].price >> cars[i].available;
            i++;
        }

    } else {
        cerr << "Unable to open file " << filename << endl;
    }

    infile.close();
}

/*
 * Prompt user for filename and write Car data out to file.
 */
void writeCarsToFile(Car cars[])
{
    char filename[100];
    ofstream outfile;

    cout << "Output filename: ";
    cin >> filename;

    outfile.open(filename);
    if (outfile) {

        // Write rows to file if successfully opened
        for (int i = 0; i < CARS_IN_FILE; i++) {
            outfile << cars[i].year << " " << cars[i].make << " " <<  cars[i].model << " " <<  cars[i].price << " " <<  cars[i].available << endl;
        }

    } else {
        cerr << "Unable to open file " << outfile << endl;
    }

    outfile.close();
}

/*
 * Print all cars to screen
 */
void showCars(const Car cars[])
{
    cout << endl;
    for (int i = 0; i < CARS_IN_FILE; i++) {
        cout << cars[i].year << " " << cars[i].make << " " << cars[i].model << ", $" << cars[i].price
             << " per day, Available: " << boolalpha << cars[i].available << endl;
    }
    cout << endl;
}

/*
 * Print available cars to screen
 */
void showAvailableCars(const Car cars[])
{
    cout << "\n" << endl;
    for (int i = 0; i < CARS_IN_FILE; i++) {
        if (cars[i].available) {
            cout << cars[i].year << " " << cars[i].make << " " << cars[i].model << ", $" << cars[i].price
                 << " per day" << endl;
        }
    }
    cout << "\n" << endl;
}

/*
 * Print all cars to screen with price multiplied by rental days
 */
void showAvailableCars(const Car cars[], int days)
{
    cout << endl;
    for (int i = 0; i < CARS_IN_FILE; i++) {
        if (cars[i].available) {
            cout << cars[i].year << " " << cars[i].make << " " << cars[i].model << ", Total Cost: $"
                 << cars[i].price * days << endl;
        }
    }
    cout << endl;
}

/*
 * Bubble sort array of Car structs ascending according to price
 */
void bubbleSortCars(Car cars[])
{
    Car tempCar;
    bool swapped;

    do {
        swapped = false;
        for (int i = 0; i < CARS_IN_FILE - 1; i++) {
            if (cars[i].price > cars[i+1].price) {
                tempCar = cars[i];
                cars[i] = cars[i+1];
                cars[i+1] = tempCar;
                swapped = true;
            }
        }
    } while (swapped);

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
 * Prompt user for number of days to rent car, and display available cars with estimated total cost
 */
void promptRentalDays(Car cars[])
{
    int days;

    cout << "How many days would you like to rent a car for?" << endl;
    days = getIntBetween(1, 100);  // TODO: Shouldn't use a between here

    bubbleSortCars(cars);
    showAvailableCars(cars, days);
}

/*
 * Prompt user to select a car for rental. If car is available, rent, otherwise fail.
 */
void rentCar(Car cars[])
{
    int carIndex, days;

    cout << "Which car would you like to rent? Please enter the car's index number." << endl;
    carIndex = getIntBetween(1, CARS_IN_FILE);
    Car & car = cars[carIndex-1]; // Account for zero- vs one-indexing

    cout << "How many days would you like to rent the " << car.make << " " << car.model << " for?" << endl;
    days = getIntBetween(1, 100);  // TODO: Shouldn't use a between here


    if (car.available) {
        car.available = false;
        cout << "SUCCESS: You've rented the " << car.make << " " << car.model << " for " << days << " days!\n"
             << "Estimated cost: $" << car.price * days << endl;
    } else {
        cout << "Sorry, the " << car.make << " " << car.model << " isn't available." << endl;
    }
}