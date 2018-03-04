//
// Created by Matthew Davis on 3/4/18.
//

#ifndef SCHOOL_VEHICLE_H
#define SCHOOL_VEHICLE_H

#include <iostream>

// [Latitude, Longitude, Altitude]
const int LLA_LEN = 3;


class Vehicle {

    friend std::ostream & operator<<(std::ostream & os, const Vehicle & vehicle);

public:
    Vehicle();
    Vehicle(const int vin, const float *lla);
    Vehicle(const Vehicle &vehicle);

    ~Vehicle();

    Vehicle &operator=(const Vehicle &rhs);

    float *getLLA() const;
    int getVIN() const;

    static int getIdgen();

    void setLLA(const float *lla);
    void setLLA(const int lat, const int lng, const int alt);
    void setVIN(const int vin);

    void move(const float *lla);


protected:
    float m_lla[LLA_LEN];
    const int m_vin;

private:
    static int s_idgen;
};


#endif //SCHOOL_VEHICLE_H
