//
// Created by Matthew Davis on 9/11/18.
//

#ifndef SCHOOL_BAGINTERFACE_H
#define SCHOOL_BAGINTERFACE_H

template<class ItemType>
class BagInterface
{
public:
    virtual int getCurrentSize() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool add(const ItemType& newEntry) = 0;
    virtual bool remove(const ItemType& target) = 0;
    virtual void clear() = 0;
    virtual int getFrequencyOf(const ItemType& target) const = 0;
    virtual int getIndexOf(const ItemType& target) const = 0;
    virtual bool contains(const ItemType& anEntry) const = 0;
    virtual std::vector<ItemType> toVector() const = 0;
    virtual ~BagInterface() {}
};

#endif //SCHOOL_BAGINTERFACE_H
