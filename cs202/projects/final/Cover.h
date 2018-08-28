//
// Created by Matthew Davis on 5/7/18.
//

#ifndef SCHOOL_COVER_H
#define SCHOOL_COVER_H

#include <iostream>

class Cover {
    friend std::ostream &operator<<(std::ostream &os, const Cover &cover);
    friend std::istream &operator>>(std::istream &is, Cover &cover);

public:
    Cover();
    Cover(bool hard);

    bool GetValue() const;

private:
    bool m_hard;
};


#endif //SCHOOL_COVER_H
