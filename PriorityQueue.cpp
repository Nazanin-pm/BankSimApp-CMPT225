/**
 * PriorityQueue.cpp
 * 
 * Class Description: Implements a Priority Queue using a Binary Heap as the underlying data structure.
 * Author: Nazanin Pouria Mehr
 * Last Modification: April 5th 2024
 */
#ifndef PRIORITYQUEUE_CPP
#define PRIORITYQUEUE_CPP

#include "PriorityQueue.h"
#include "Event.h"
#include "BinaryHeap.h"
#include <iostream>
#include "EmptyDataCollectionException.h"
#include "Queue.h"
#include <functional>

template<class ElementType>
PriorityQueue<ElementType>::PriorityQueue() {}

template<class ElementType>
PriorityQueue<ElementType>::~PriorityQueue() {}

template<class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const {
    // Description: Checks if the priority queue is empty.
    // Postcondition: This Priority Queue is unchanged by this operation.
    // Time Efficiency: O(1)
    return binaryHeap.getElementCount() == 0;
}

template<class ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType & newElement) {
    // Description: Inserts newElement into the Priority Queue.
    // Postcondition: The Priority Queue contains newElement.
    // Time Efficiency: O(log2 n)
    return binaryHeap.insert(newElement);
}

template<class ElementType>
void PriorityQueue<ElementType>::dequeue() {
    // Description: Removes the element with the highest priority from the Priority Queue.
    // Precondition: This Priority Queue is not empty.
    // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
    // Time Efficiency: O(log2 n)
    if (isEmpty()) {
        throw EmptyDataCollectionException("PriorityQueue is empty. Cannot peek.");
    }
    binaryHeap.remove();
}

template<class ElementType>
ElementType & PriorityQueue<ElementType>::peek() const {
    // Description: Retrieves the element with the highest priority from the Priority Queue.
    // Precondition: This Priority Queue is not empty.
    // Postcondition: This Priority Queue is unchanged by this operation.
    // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
    // Time Efficiency: O(1)
    if (isEmpty()) {
        throw EmptyDataCollectionException("PriorityQueue is empty. Cannot peek.");
    }   
    return binaryHeap.retrieve();
}

template class PriorityQueue<char>;
template class PriorityQueue<double>;
template class PriorityQueue<int>;

//template class BinaryHeap<Event>;

#endif
