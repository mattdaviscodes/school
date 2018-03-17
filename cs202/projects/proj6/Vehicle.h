/**
 * @brief  CS-202 Project 6 - Vehicle class definition
 * @Author Matt Davis (mattdavis@nevada.unr.edu)
 * @date   3/17/18
 */

#ifndef SCHOOL_VEHICLE_H
#define SCHOOL_VEHICLE_H

#include <iostream>

const int LLA_LEN = 3;

class Vehicle {

    friend std::ostream &operator<<(std::ostream &os, Vehicle &v);

public:
    Vehicle();
    Vehicle(const float *lla);
    Vehicle(const Vehicle &v);

    virtual ~Vehicle();

    Vehicle &operator=(const Vehicle &other);

    const float *GetLLA() const;
    void SetLLA(const float *lla);

    virtual void Move(const float *lla) = 0;
    virtual void serialize(std::ostream& os);

private:
    float m_lla[LLA_LEN];
};

/* HELPERS */
void arrayCopy(float * dest, const float * src, const int len);
void arrayPrint(std::ostream &os, const float * arr, const int len);


#endif //SCHOOL_VEHICLE_H
