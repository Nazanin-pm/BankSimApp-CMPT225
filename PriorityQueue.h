/**
 * PriorityQueue.h
 * 
 * Class Description: Implements a Priority Queue using a Binary Heap as the underlying data structure.
 * Author: Nazanin Pouria Mehr
 * Last Modification: April 5th 2024
 */
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "BinaryHeap.h"
#include "EmptyDataCollectionException.h"
#include "Queue.h"
#include "Event.h"



template<class ElementType>
class PriorityQueue {
public:
    // Default constructor
    PriorityQueue();
    // Destructor
    ~PriorityQueue();
    

    // Returns true if this Priority Queue is empty, otherwise false.
    // Postcondition: This Priority Queue is unchanged by this operation.
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Inserts newElement in this Priority Queue and returns true if successful, otherwise false.
    // Time Efficiency: O(log2 n)
    bool enqueue(ElementType & newElement);

    // Removes (but does not return) the element with the next "highest" priority value from the Priority Queue.
    // Precondition: This Priority Queue is not empty.
    // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
    // Time Efficiency: O(log2 n)
    void dequeue();

    // Returns (but does not remove) the element with the next "highest" priority value from the Priority Queue.
    // Precondition: This Priority Queue is not empty.
    // Postcondition: This Priority Queue is unchanged by this operation.
    // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
    // Time Efficiency: O(1)
    ElementType & peek() const;

private:
    BinaryHeap<ElementType> binaryHeap; // Using BinaryHeap as underlying data structure
};
#include "PriorityQueue.cpp"
#endif
