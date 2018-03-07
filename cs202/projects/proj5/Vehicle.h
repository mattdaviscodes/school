/**
 * @brief  CS-202 Project 5 - Vehicle class definition
 * @Author Matt Davis (mattdavis@nevada.unr.edu)
 * @date   3/5/18
 */

#ifndef SCHOOL_VEHICLE_H
#define SCHOOL_VEHICLE_H

#include <iostream>

// [Latitude, Longitude, Altitude]
const int LLA_LEN = 3;


class Vehicle {

    friend std::ostream & operator<<(std::ostream & os, const Vehicle & vehicle);

public:
    // Constructors
    Vehicle();
    Vehicle(const int vin, const float *lla);
    Vehicle(const Vehicle &vehicle);

    // Destructor
    ~Vehicle();

    // Operator overload
    Vehicle &operator=(const Vehicle &rhs);

    // Getters
    const float *getLLA() const;
    int getVIN() const;
    static int getIdgen();

    // Setters
    void setLLA(const float *lla);
    void setLLA(const int lat, const int lng, const int alt);

    void move(const float *lla);

    // Check VIN validity against s_idgen
    static bool validateVIN(const int vin);


protected:
    float m_lla[LLA_LEN];
    const int m_vin;

private:
    static int s_idgen;
};


#endif //SCHOOL_VEHICLE_H
