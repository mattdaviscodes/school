//
// Created by Matthew Davis on 5/7/18.
//

#ifndef SCHOOL_CLIENT_H
#define SCHOOL_CLIENT_H

#include <iostream>
//#include <string>

class Client {
    friend std::ostream & operator<<(std::ostream & os, const Client & client);
    friend std::istream & operator<<(std::istream & is, Client & client);

public:
    Client();
    Client(const char * name);
    Client(const Client & other);

    ~Client();

    Client & operator=(const Client & rhs);

    char * GetName() const;

private:
    char * m_name;
};


#endif //SCHOOL_CLIENT_H
