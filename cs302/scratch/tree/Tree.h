//
// Created by Matthew Davis on 10/8/18.
//

#ifndef SCHOOL_TREE_H
#define SCHOOL_TREE_H

template<lass ItemType>
class Tree {
public:
    virtual int getHeight() const = 0;
    virtual bool add(const ItemType& newEntry) = 0;
};

#endif //SCHOOL_TREE_H
