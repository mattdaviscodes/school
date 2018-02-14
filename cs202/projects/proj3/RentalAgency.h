/**
 * @brief  CS-202 Project 3 - RentalAgency class definition
 * @Author Matt Davis (mattdavis@nevada.unr.edu)
 * @date   2/8/18
 *
 */

#ifndef SCHOOL_RENTALAGENCY_H
#define SCHOOL_RENTALAGENCY_H

#include "RentalCar.h"

#define MAX_CSTRING_SIZE 255
#define AGENCIES_IN_FILE 3
#define ZIPCODE_SIZE 5
#define INVENTORY_SIZE 5

struct RentalAgency {
    char name[MAX_CSTRING_SIZE];
    int zipcode[ZIPCODE_SIZE];
    RentalCar inventory[INVENTORY_SIZE];
};

#endif //SCHOOL_RENTALAGENCY_H
