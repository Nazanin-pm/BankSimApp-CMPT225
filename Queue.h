/*
 * Queue.h
 *
 * Class Description: Defines a template class for a queue data structure.
 *                    This class includes methods to manipulate the queue such as enqueue, dequeue, and peek.
 *
 * Author: Nazanin Pouria Mehr
 * Date of the last modification: April 5th 2024
 */

// Queue.h

#ifndef QUEUE_H
#define QUEUE_H

#include "EmptyDataCollectionException.h"

template<class ElementType>
class Queue {
private:
struct Node {
    ElementType data;
    Node* next;
    Node(ElementType newData, Node* newNext) : data(newData), next(newNext) {}
};

    Node* frontPtr; // Pointer to the front of the queue
    Node* backPtr;  // Pointer to the back of the queue

public:
    // Constructor
    Queue();

    // Destructor
    ~Queue();

    // Description: Checks if the queue is empty.
    // Precondition: None.
    // Postcondition: Returns true if the queue is empty, false otherwise.
    bool isEmpty() const;

    // Description: Adds an element to the back of the queue.
    // Precondition: None.
    // Postcondition: If the enqueue operation is successful, the element is added to the back of the queue.
    //                Returns true if successful, otherwise false.
    bool enqueue(ElementType& newElement);

    // Description: Removes the element at the front of the queue.
    // Precondition: The queue is not empty.
    // Postcondition: The element at the front of the queue is removed.
    //                Throws EmptyDataCollectionException if the queue is empty.
    void dequeue();

    // Description: Retrieves the element at the front of the queue.
    // Precondition: The queue is not empty.
    // Postcondition: Returns a reference to the element at the front of the queue.
    //                Throws EmptyDataCollectionException if the queue is empty.
    ElementType& peek() const;

    // For testing purposes
    // Description: Prints the contents of the queue.
    // Precondition: None.
    // Postcondition: None (no changes to the queue).
    void print() const;
};

#include "Queue.cpp"
#endif
