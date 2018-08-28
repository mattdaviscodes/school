//
// Created by Matthew Davis on 5/7/18.
//

#include "Cover.h"

std::ostream &operator<<(std::ostream &os, const Cover &cover) {
    os << std::boolalpha << cover.m_hard;
    return os;
}

std::istream &operator>>(std::istream &is, Cover &cover) {
    is >> cover.m_hard;
    return is;
}

Cover::Cover() {
    m_hard = false;
}

Cover::Cover(bool hard) {
    m_hard = hard;
}

bool Cover::GetValue() const {
    return m_hard;
}
