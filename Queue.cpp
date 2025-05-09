/*
 * Queue.cpp
 *
 * Class Description: Implements the methods declared in the Queue.h file.
 * Author: Nazanin Pouria Mehr
 * Date of the last modification: April 5th 2024
 */

// Queue.cpp
#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "Queue.h"
#include <iostream> 

// Constructor
template<class ElementType>
Queue<ElementType>::Queue() : frontPtr(nullptr), backPtr(nullptr) {}

// Destructor
template<class ElementType>
Queue<ElementType>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Description: Returns true if this Queue is empty, otherwise false.
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
template<class ElementType>
bool Queue<ElementType>::isEmpty() const {
    return frontPtr == nullptr;
}

// Description: Inserts newElement at the "back" of this Queue 
//              (not necessarily the "back" of this Queue's data structure) 
//              and returns true if successful, otherwise false.
// Time Efficiency: O(1)
template<class ElementType>
bool Queue<ElementType>::enqueue(ElementType& newElement) {
    Node* newNode = new Node(newElement, nullptr); // Ensure both arguments are passed
    if (isEmpty()) {
        frontPtr = newNode;
    } else {
        backPtr->next = newNode;
    }
    backPtr = newNode;
    return true;
}

// Description: Removes (but does not return) the element at the "front" of this Queue 
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.   
// Time Efficiency: O(1)
template<class ElementType>
void Queue<ElementType>::dequeue() {
    if (isEmpty()) {
        throw EmptyDataCollectionException("dequeue() called on empty queue");
    }
    Node* temp = frontPtr;
    if (frontPtr == backPtr) {
        frontPtr = nullptr;
        backPtr = nullptr;
    } else {
        frontPtr = frontPtr->next;
    }
    delete temp;
}

// Description: Returns (but does not remove) the element at the "front" of this Queue
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template<class ElementType>
ElementType& Queue<ElementType>::peek() const {
    if (isEmpty()) {
        throw EmptyDataCollectionException("peek() called on empty queue");
    }
    return frontPtr->data;
}

// For testing purposes
template<class ElementType>
void Queue<ElementType>::print() const {
    Node* current = frontPtr;
    while (current != nullptr) {
        std::cout << current->data << " "; 
        current = current->next;
    }
    std::cout << std::endl; 
}
#endif