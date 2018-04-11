/**
 * @brief  CS-202 Project X - Implementation for SmartPtr class
 * @Author Matt Davis (mattdavis@nevada.unr.edu)
 * @date   4/10/18
 */

#include "DataType.h"
#include "SmartPtr.h"

/**
 * @summary Default ctor
 */
SmartPtr::SmartPtr() {
    try {
        m_ptr = new DataType;
        m_refcount = new size_t;
        *m_refcount = 1;
    } catch (std::bad_alloc &e) {
        e.what();
    }

    std::cout << "SmartPtr Default Constructor for new allocation, RefCount=" << *m_refcount << std::endl;
}

/**
 * @summary Param ctor
 *
 * Will always create a new m_refcount, even if the DataType pointed
 * by this object is already pointed to by another SmartPtr. This
 * is because the new object has no way of knowing that another
 * SmartPtr is pointing to the data. Can cause destruction errors.
 */
SmartPtr::SmartPtr(DataType *data) {
    try {
        m_refcount = new size_t;
    } catch (std::bad_alloc &e) {
        e.what();
    }
    m_ptr = data;

    // if pointer passed in is valid, count 1
    // smart pointer pointing to it
    if (data) {
        *m_refcount = 1;
    } else {
        *m_refcount = 0;
    }

    std::cout << "SmartPtr  Parametrized  Constructor  from data pointer, RefCount=" << *m_refcount << std::endl;
}

/**
 * @summary Copy ctor
 */
SmartPtr::SmartPtr(const SmartPtr &other) {
    if (other.m_ptr) {
        m_refcount = other.m_refcount;
        (*m_refcount)++;
    } else {
        try {
            m_refcount = new size_t;
            *m_refcount = 0;
        } catch (std::bad_alloc &e) {
            e.what();
        }
    }

    m_ptr = other.m_ptr;

    std::cout << "SmartPtr  Copy  Constructor,  RefCount=" << *m_refcount << std::endl;
}

/**
 * @summary Dtor
 *
 * Decrements m_refcount in order to keep an accurate count of the SmartPtrs
 * pointing to this DataType obj. If that number is reduced to 0, then
 * also delete the heap memory pointed by the obj.
 */
SmartPtr::~SmartPtr() {
    (*m_refcount)--;

    std::cout << "SmartPtr  Destrcutor,  RefCount=" << *m_refcount << std::endl;

    if (*m_refcount <= 0) {
        delete m_ptr;
        delete m_refcount;
    }
}

/**
 * @summary Assignment operator
 */
SmartPtr &SmartPtr::operator=(const SmartPtr &rhs) {
    if (this != &rhs) {

        // One less SmartPtr pointing to this object's
        // current target, because it's being reassigned
        if (--(*m_refcount) <= 0) {
            delete m_ptr;
            delete m_refcount;
        }

        if (rhs.m_ptr) {
            m_refcount = rhs.m_refcount;
            (*m_refcount)++;
        } else {
            try {
                m_refcount = new size_t;
                *m_refcount = 0;
            } catch (std::bad_alloc &e) {
                e.what();
            }
        }

        m_ptr = rhs.m_ptr;
    }

    std::cout << "SmartPtr  Copy  Assignment,  RefCount=" << *m_refcount << std::endl;

    return *this;
}

/**
 * @summary Star operator overload
 *
 * Purpose is to provide similar functionality to base C++ pointer
 */
DataType &SmartPtr::operator*() {
    return *m_ptr;
}

/**
 * @summary Arrow operator overload
 *
 * Purpose is to provide similar functionality to base C++ pointer
 */
DataType *SmartPtr::operator->() {
    return m_ptr;
}
