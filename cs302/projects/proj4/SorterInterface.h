#ifndef SCHOOL_SORTERINTERFACE_H
#define SCHOOL_SORTERINTERFACE_H

//#include <string>

template<class ItemType>
class SorterInterface
{
public:
    // Read list of ints from file, return number of ints read in
    virtual int readFromFile(const std::string &filename) = 0;

    // Write list to file, one entry per line
    virtual bool writeToFile(const std::string &filename) const = 0;
};

#endif //SCHOOL_SORTERINTERFACE_H