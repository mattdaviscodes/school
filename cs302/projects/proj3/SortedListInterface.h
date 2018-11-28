#ifndef SORTED_LIST_INTERFACE_
#define SORTED_LIST_INTERFACE_
template<class ItemType>
class SortedListInterface
{
public:
    virtual bool insertSorted(const ItemType& newEntry) = 0;
    virtual bool removeSorted(const ItemType& anEntry) = 0;
    virtual int getPosition(const ItemType& anEntry) const = 0;
    virtual bool isEmpty() const = 0;
    virtual int getLength() const = 0;
    virtual bool remove(int position) = 0;
    virtual void clear() = 0;
    virtual ItemType getEntry(int position) const = 0;
    virtual ~SortedListInterface() { }
};
#endif