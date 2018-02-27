//
// Created by Matthew Davis on 2/24/18.
//

#ifndef SCHOOL_AGENCY_H
#define SCHOOL_AGENCY_H

#include "Car.h"

// Constants
const int INVENTORY_SIZE = 5;

const int DEFAULT_ZIPCODE = 00000;


class Agency {

    friend std::istream& operator>>(std::istream& is, Agency& agency);

    public:
        Agency();

        // Getters
        const char* getName() const;
        const int getZipcode() const;

        // Setters
        void setName(const char* name);
        // No setZipcode function because zip is const,
        // and cannot be set after instantiation

        // Operator overload
        Car & operator[](int i);

        // Other
        void readAllData();


    private:
        char m_name[MAX_CSTRING_SIZE];
        int m_zipcode;
        Car m_inventory[INVENTORY_SIZE];

};


#endif //SCHOOL_AGENCY_H
