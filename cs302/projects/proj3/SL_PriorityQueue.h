#ifndef PRIORITY_QUEUE_
#define PRIORITY_QUEUE_

//#include "PriorityQueueInterface.h"
#include "LinkedSortedList.h"
#include "PrecondViolatedExcept.h"
#include <memory>

template<class ItemType>
class SL_PriorityQueue {
private:
    // Ptr to sorted list of items
    std::unique_ptr <LinkedSortedList<ItemType>> slistPtr;

public:
    SL_PriorityQueue();
    SL_PriorityQueue(const SL_PriorityQueue &pq);
    ~SL_PriorityQueue();

    bool isEmpty() const;
    bool enqueue(const ItemType &newEntry);
    bool dequeue();

    // @throw PrecondViolatedExcept if priority queue is empty
    ItemType peekFront() const throw(PrecondViolatedExcept);
}; // end SL_PriorityQueue

template <class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue() : slistPtr(std::make_unique<LinkedSortedList<ItemType>>()) {
}

#endif