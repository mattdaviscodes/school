/**
 * @brief  CS-202 Project 9 - NodeQueue class implementation
 * @Author Matt Davis (mattdavis@nevada.unr.edu)
 * @date   4/25/18
 */

#include "NodeQueue.h"

/**
 * Default constructor for NodeQueue
 */
NodeQueue::NodeQueue() {
    m_front = NULL;
    m_back = NULL;
}

/**
 * Parameterized constructor for NodeQueue
 */
NodeQueue::NodeQueue(size_t size, const DataType &value) {
    m_front = NULL;
    m_back = NULL;

    for (int i = 0; i < size; i++) {
        push(value);
    }
}

/**
 * Copy constructor for NodeQueue
 */
NodeQueue::NodeQueue(const NodeQueue &other) {
    Node * curr = other.m_front;

    m_front = NULL;
    m_back = NULL;

    while (curr) {
        push(curr->getData());
        curr = curr->m_next;
    }
}

/**
 * Destructor for NodeQueue
 *
 * Handles freeing of dynamically allocated memory
 */
NodeQueue::~NodeQueue() {
    Node *curr = m_front;
    Node *next = NULL;

    while (curr) {
        next = curr->m_next;
        delete curr;
        curr = next;
    }
}

/**
 * Assignment operator overload for NodeQueue
 */
NodeQueue &NodeQueue::operator=(const NodeQueue &rhs) {
    if (this != &rhs) {

        // Make sure to clean up whatever lhs is
        // currently holding
        clear();

        Node * curr = rhs.m_front;

        m_front = NULL;
        m_back = NULL;

        while (curr) {
            push(curr->getData());
            curr = curr->m_next;
        }
    }

    return *this;
}

/**
 * Get DataType obj pointed by m_front
 */
DataType &NodeQueue::front() {
    return m_front->getData();
}

/**
 * Get DataType obj pointed by m_front
 */
const DataType &NodeQueue::front() const {
    return m_front->getData();
}

/**
 * Get DataType obj pointed by m_back
 */
DataType &NodeQueue::back() {
    return m_back->getData();
}

/**
 * Get DataType obj pointed by m_back
 */
const DataType &NodeQueue::back() const {
    return m_back->getData();
}

/**
 * Add a new node to the back of the queue
 */
void NodeQueue::push(const DataType &value) {
    Node * newNode = new Node(value);

    if (empty()) {
        m_front = newNode;
        m_back = newNode;
        return;
    }

    m_back->m_next = newNode;
    m_back = newNode;
}

/**
 * Remove a node from the front of the queue
 */
void NodeQueue::pop() {
    if (size() == 1) {
        // Popping from a 1-element queue
        // leaves queue empty
        clear();
    } else if (!empty()) {
        Node * tempFront = m_front;
        m_front = m_front->m_next;
        delete tempFront;
    }
}

/**
 * Get the total number of elements in the queue
 */
size_t NodeQueue::size() const {
    Node * curr = m_front;

    size_t i = 0;
    while (curr) {
        i++;
        curr = curr->m_next;
    }

    return i;
}

/**
 * Is queue empty?
 */
bool NodeQueue::empty() const {
    return m_front == NULL;
}

/**
 * Is queue full?
 *
 * NOTE: This method is only here to keep consistency with the
 * array-based implementation. A node-based queue has no member
 * limit, so this always returns false.
 */
bool NodeQueue::full() const {
    return false;
}

/**
 * Free all dynamically allocated memory and reset queue to empty state
 */
void NodeQueue::clear() {
    Node * curr = m_front;
    Node * tempNode = NULL;

    while (curr) {
        tempNode = curr;
        curr = curr->m_next;
        delete tempNode;
    }

    m_front = NULL;
    m_back = NULL;
}

/**
 * Print contents of queue to ostream
 */
void NodeQueue::serialize(std::ostream &os) const {
    Node *curr = m_front;
    int i = 0;
    while (curr) {
        os << i << ": " << curr->getData();

        if (curr->m_next) {
            os << std::endl;
        }

        curr = curr->m_next;
        i++;
    }
}

/**
 * Print contents of queue to ostream
 */
std::ostream &operator<<(std::ostream &os, const NodeQueue &nodeQueue) {
    nodeQueue.serialize(os);
    return os;
}