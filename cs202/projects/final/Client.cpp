//
// Created by Matthew Davis on 5/7/18.
//

#include "Client.h"

std::ostream &operator<<(std::ostream &os, const Client &client) {
    std::cout << "test" << std::endl;
    os << client.m_name;
    return os;
}

std::istream &operator<<(std::istream &is, Client &client) {
    is >> client.m_name;
    return is;
}

Client::Client() {

}

Client::Client(const char *name) {
    strcpy(m_name, "test");
}

Client::Client(const Client &other) {
    strcpy(m_name, other.m_name);
}

Client::~Client() {

}

Client &Client::operator=(const Client &rhs) {
    if (this != &rhs) {
        strcpy(m_name, rhs.m_name);
    }
    return *this;
}

char *Client::GetName() const {
    return m_name;
}
