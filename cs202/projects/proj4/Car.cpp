//
// Created by Matthew Davis on 2/20/18.
//

#include <iostream>

#include "Car.h"
#include "Sensor.h"
#include "proj4.h"

using namespace std;


// Constructors
Car::Car() {
    setMake("\0");
    setModel("\0");
    setYear(0);
    setBasePrice(0);
    setAvailable(false);
    setOwner("\0");

    updatePrice();

    m_sensorCount = 0;

};
Car::Car(const char *make, const char *model, const int year, const float baseprice, const bool available,
         Sensor *sensors) {
    Sensor * sensor_arr = m_sensors;
    setMake(make);
    setModel(model);
    setYear(year);
    setBasePrice(baseprice);
    setAvailable(available);
    setOwner("\0");

    // TODO: Make sure this doesn't break my shit
    for (int i = 0; i < MAX_SENSORS_PER_CAR; i++) {
        *sensor_arr++ = Sensor(*sensors++);
        m_sensorCount++;
    }

    updatePrice();

};
Car::Car(Car & car) {
    Sensor * sensors_in = car.getSensors();
    Sensor * sensors_out = m_sensors;

    setMake(car.getMake());
    setModel(car.getModel());
    setYear(car.getYear());
    setBasePrice(car.getBasePrice());
    setAvailable(car.getAvailable());
    setOwner(car.getOwner());

    for (int i = 0; i < MAX_SENSORS_PER_CAR; i++) {
        *sensors_out++ = Sensor(*sensors_in++);
    }

    updatePrice();

    m_sensorCount = car.m_sensorCount;

};

// Getters
char * Car::getMake() { return m_make; };
char * Car::getModel() { return m_model; };
int Car::getYear() { return m_year; };
Sensor * Car::getSensors() {return m_sensors; };
float Car::getBasePrice() {return m_baseprice; };
float Car::getFinalPrice() { return m_finalprice; };
bool Car::getAvailable() { return m_available; };
char * Car::getOwner() { return m_owner; };
int Car::getSensorCount() { return m_sensorCount; };

// Setters
void Car::setMake(const char * make) { myStringCopy(m_make, make); };
void Car::setModel(const char * model) {myStringCopy(m_model, model); };
void Car::setYear(const int year) { m_year = year; };
void Car::setBasePrice(const float baseprice) {m_baseprice = baseprice; };
void Car::setAvailable(const bool available) {m_available = available; };
void Car::setOwner(const char * owner) { myStringCopy(m_owner, owner); };

// Operator overload
Car& Car::operator+(Sensor & sensor) {
    Sensor * sensors_ptr = m_sensors;

    // Iterate over car's sensors looking for an open spot (sensor type="none")
    for (int i = 0; i < MAX_SENSORS_PER_CAR; i++, sensors_ptr++) {
        if (!myStringCompare(sensors_ptr->getType(), "none")) {
            sensors_ptr->setType(sensor.getType());
            m_sensorCount++;
            updatePrice();
            break;
        };
    }
    return *this;
};
Car& Car::operator+(const char * owner) {
    setOwner(owner);
    setAvailable(false);
    return *this;
};
ostream & operator<<(ostream & os, const Car & car) {
    os << "Car(m_make=" << car.m_make << ", m_model=" << car.m_model << ", m_year=" << car.m_year << ", m_baseprice="
       << car.m_baseprice << ", m_finalprice=" << car.m_finalprice << ", m_available=" << boolalpha << car.m_available
       << ", m_owner=" << car.m_owner << ")";

    return os;
};

// Other
float Car::updatePrice() {
    float price = m_baseprice;
    Sensor * sensors_ptr = m_sensors;

    for (int i = 0; i < MAX_SENSORS_PER_CAR; i++, sensors_ptr++) {
        price += sensors_ptr->getExtraCost();
    }

    return m_finalprice = price;
};
void Car::print() {
    cout << *this << endl;
};
float Car::estimateCost(const int days) {
    return getFinalPrice() * days;
};

void Car::promptRent() {
    int selection;

    cout << "Would you like to rent this car?" << endl;
    cout << "1) Yes" << endl;
    cout << "2) No" << endl;

    selection = getIntBetween(1, 2);

    if (selection == 1) {
        rent();
    }
}

void Car::rent() {
    char name[MAX_CSTRING_SIZE];

    cout << "Please enter your first name: ";
    cin >> name;

    *this + name;
}

std::istream& operator>>(std::istream& is, Car& car) {
    char c;
    char sensor_str[MAX_CSTRING_SIZE];
    char * ss_start = sensor_str, * ss_ptr = ss_start;
    Sensor sensor;

    is >> car.m_year >> car.m_make >> car.m_model >> car.m_baseprice;

    is.get();   // discard space before curly brace
    is.get();   // discard opening curly brace

    while (is >> noskipws >> c) {

        if (c != ' ' && c != '}') {
            *ss_ptr++ = c;
        } else {
            // Ensure null terminator set
            *ss_ptr++ = '\0';

            // Set sensor type and add to car if sensor read in
            if (myStringLength(sensor_str)) {
                sensor.setType(sensor_str);
                car + sensor;
            }

            // Reset sensor string and pointer
            *ss_start = '\0';
            ss_ptr = ss_start;

            // Stop reading at closing curly
            if (c == '}') {
                break;
            }
        }
    }

    is >> skipws >> car.m_available;

    // Owner is only included if car is unavailable
    if (!car.m_available) {
        is >> car.m_owner;
    }

    // Update to final price in case no sensors were read in
    car.updatePrice();

    return is;
};