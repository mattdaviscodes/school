#include "ArrayList.h"

/* Your implementation here */

ArrayList::ArrayList() {
    m_array = NULL;
    m_size = 0;
    m_maxsize = 0;
}

ArrayList::ArrayList(size_t count, const DataType &value) {
    m_array = new DataType[count];
    for (int i = 0; i < count; i++) {
        m_array[i] = value;
    }
    m_size = count;
    m_maxsize = count;
}

ArrayList::ArrayList(const ArrayList &other) {
    m_array = new DataType[other.m_size];
    for (int i = 0; i < other.m_size; i++) {
        m_array[i] = other.m_array[i];
    }
    m_size = other.m_size;
    m_maxsize = other.m_maxsize;
}

ArrayList::~ArrayList() {
    delete [] m_array;
}

ArrayList &ArrayList::operator=(const ArrayList &rhs) {
    if (this != &rhs) {
        delete [] m_array;
        m_array = rhs.m_array;
        m_size = rhs.m_size;
        m_maxsize = rhs.m_maxsize;
    }

    return *this;
}

DataType *ArrayList::front() {
    for (int i = 0; i < m_size; i++) {
        if (m_array[i].getIntVal() && m_array[i].getDoubleVal()) {
            return &m_array[i];
        }
    }

    return NULL;
}

DataType *ArrayList::back() {
    for (int i = m_size; i > 0; i--) {
        if (m_array[i].getIntVal() && m_array[i].getDoubleVal()) {
            return &m_array[i];
        }
    }

    return NULL;
}

DataType *ArrayList::find(const DataType &target, DataType *&previous, const DataType *start) {
    previous = NULL;

    for (int i = 0; i < m_size; i++) {
        if (m_array[i].getIntVal() && m_array[i].getDoubleVal() && m_array[i] == target) {

            // Head has no previous
            if (i != 0) {
                previous = &m_array[i-1];
            }

            return &m_array[i];
        }
    }

    return NULL;
}

DataType *ArrayList::insertAfter(const DataType &target, const DataType &value) {
    DataType *prev = NULL;
    DataType *found = find(target, prev);
    DataType *newElem = NULL;
    int listOffset = 0;


    if (found != NULL) {

        // If list is full
        if (m_size + 1 > m_maxsize) {
            DataType *newList = new DataType[m_size + 1];

            for (int i = 0; i < m_size + 1; i++) {

                if (&m_array[i] == found) {
                    listOffset = 1;
                    newList[i] = value;
                } else {
                    newList[i] = m_array[i + listOffset];
                }

            }
        }
    }

    return newElem;
}

//DataType *ArrayList::insertBefore(const DataType &target, const DataType &value) {
//    return nullptr;
//}
//
//DataType *ArrayList::erase(const DataType &target) {
//    return nullptr;
//}

DataType &ArrayList::operator[](size_t position) {
    return m_array[position];
}

size_t ArrayList::size() const {
    return m_size;
}

//bool ArrayList::empty() const {
//    return false;
//}
//
//void ArrayList::clear() {
//
//}
//
//void ArrayList::resize(size_t count) {
//
//}

std::ostream &operator<<(std::ostream &os, const ArrayList &arrayList) {
    size_t size = arrayList.size();
    for (int i = 0; i < size; i++) {
        os << i << ": " << arrayList.m_array[i];

        if (i != arrayList.size() - 1) {
            os << std::endl;
        }
    }

    return os;
}
