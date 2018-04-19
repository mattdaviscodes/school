#include "NodeList.h"

NodeList::NodeList() {
    m_head = NULL;
}

NodeList::NodeList(size_t count, const DataType &value) {
    Node *next = NULL;
    Node *curr = NULL;

    while (count--) {
        if (!next) {
            next = new Node(value);
        } else {
            curr = new Node(value, next);
            next = curr;
        }
    }

    m_head = curr;

}
NodeList::NodeList(const NodeList &other) {
    Node *thatCurr = other.m_head;
    Node *thisCurr = NULL;
    Node *newNode;

    while (thatCurr) {
        newNode = new Node(*thatCurr);

        if (!thisCurr) {
            m_head = newNode;
            thisCurr = m_head;
        } else {
            thisCurr->m_next = newNode;
            thisCurr = newNode;
        }

        thatCurr = thatCurr->m_next;
    }


}

NodeList::~NodeList() {
    Node *curr = m_head;
    Node *next;

    // If m_head is null, we don't need
    // to do anything special
    if (m_head) {
        do {
            next = curr->m_next;
            delete curr;
        } while ((curr = next));
    }
}

NodeList &NodeList::operator=(const NodeList &rhs) {
    if (this != &rhs) {
        m_head = rhs.m_head;
    }
}

Node *NodeList::front() {
    return m_head;
}

Node *NodeList::back() {
    Node *curr = m_head;

    // Empty list
    if (!m_head) {
        return NULL;
    }

    while (curr->m_next) {
        curr = curr->m_next;
    }

    return curr;
}

Node *NodeList::find(const DataType &target, Node *&previous, const Node *start) {
    Node *foundNode = NULL;
    Node *curr = m_head;
    Node *prev = NULL;

    previous = NULL;

    while (curr) {

        if (curr->getData() == target) {
            foundNode = curr;
            previous = prev;
            break;
        }

        prev = curr;
        curr = curr->m_next;
    }

    return foundNode;
}

Node *NodeList::insertAfter(const DataType &target, const DataType &value) {
    Node *previous = NULL;
    Node *found = NULL;
    Node *newNode = NULL;

    found = find(target, previous);

    if (found != NULL) {

        if (found->m_next == NULL) {
            newNode = new Node(value);
            found->m_next = newNode;
        } else {
            // Found node is in the middle
            newNode = new Node(value, found->m_next);
            found->m_next = newNode;
        }
    }

    return newNode;
}

Node *NodeList::insertBefore(const DataType &target, const DataType &value) {
    Node *previous = NULL;
    Node *found = NULL;
    Node *newNode = NULL;

    found = find(target, previous);

    if (found != NULL) {

        if (previous == NULL) {
            newNode = new Node(value, found);
            m_head = newNode;
        } else {
            // Found node is in the middle
            newNode = new Node(value, found);
            previous->m_next = newNode;
        }
    }

    return newNode;
}

Node *NodeList::erase(const DataType &target) {
    Node *previous = NULL;
    Node *found = NULL;
    Node *next = NULL;
    Node *tmpNode = NULL;

    found = find(target, previous);

    if (found != NULL) {

        if (previous == NULL) {
            tmpNode = m_head;
            next = m_head->m_next;
            m_head = next;
        } else {
            tmpNode = found;
            next = found->m_next;
            previous->m_next = next;
        }

        delete tmpNode;
    }

    return next;
}

DataType &NodeList::operator[](size_t position) {
    Node *curr = m_head;
    while (position--) {
        curr = curr->m_next;
        if (!curr) {
            break;
        }
    }
    return curr->getData();
}

const DataType &NodeList::operator[](size_t position) const {
    Node *curr = m_head;
    while (position--) {
        curr = curr->m_next;
        if (!curr) {
            break;
        }
    }
    return curr->getData();
}

size_t NodeList::size() const {
    Node *curr = m_head;
    size_t size = 0;

    while (curr) {
        size++;
        curr = curr->m_next;
    }

    return size;
}

bool NodeList::empty() const {
    return !m_head;
}

void NodeList::clear() {
    Node *curr = m_head;
    Node *next = NULL;

    m_head = NULL;

    while (curr != NULL) {
        next = curr->m_next;
        delete curr;
        curr = next;
    }
}

std::ostream &operator<<(std::ostream &os, const NodeList &nodeList) {
    size_t size = nodeList.size();

    for (int i = 0; i < size; i++) {
        os << i << ": " << nodeList[i];

        // Do not include linebreak on last print
        if (i != size - 1) {
            os << std::endl;
        }
    }

    return os;
}