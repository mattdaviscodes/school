/**
 * @brief  CS-202 Project 3 - RentalCar class definition
 * @Author Matt Davis (mattdavis@nevada.unr.edu)
 * @date   2/8/18
 *
 */

#ifndef SCHOOL_RENTALCAR_H
#define SCHOOL_RENTALCAR_H

#define MAX_CSTRING_SIZE 255

class RentalCar {
    public:
    // Constructors
    RentalCar();
    RentalCar(int year, const char* make, const char* model, float price, bool available);

    // Getters
    int getYear() const;
    char* getMake();
    char* getModel();
    float getPrice() const;
    bool getAvailable() const;

    // Setters
    void setYear(int year);
    void setMake(char* make);
    void setModel(char* model);
    void setPrice(float price);
    void setAvailable(bool available);

    // Other methods
    void print() const;
    void estimateCost(int days) const;

    private:
    int m_year;
    char m_make[MAX_CSTRING_SIZE];
    char m_model[MAX_CSTRING_SIZE];
    float m_price;
    bool m_available;

};


#endif //SCHOOL_RENTALCAR_H
