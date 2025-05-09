/*
 * BinaryHeap.h
 *
 * Description: Binary Heap ADT class.
 *
 * Class Invariant: Always a min Binary Heap.
 * 
 * Author: Nazanin Pouria Mehr
 * Last Modification: April 5th 2024
 */
#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include "BinaryHeap.h"
#include "EmptyDataCollectionException.h"

template<class ElementType>
class BinaryHeap {
private:
    static const int DEFAULT_CAPACITY = 100;
    ElementType* elements; // Pointer to dynamic array of elements
    unsigned int elementCount; // Number of elements in the heap
    unsigned int capacity; // Capacity of the dynamic array

    // Recursively put the array back into a min Binary Heap.
    // Time Efficiency: O(log2 n)
    void reHeapDown(unsigned int indexOfRoot);

public:
    // Default constructor
    BinaryHeap();

    // Destructor
    ~BinaryHeap();

    // Removes (but does not return) the necessary element.
    // Precondition: This Binary Heap is not empty.
    // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
    // Time Efficiency: O(log2 n)
    void remove();  

    // Returns the number of elements in the Binary Heap.
    // Postcondition: The Binary Heap is unchanged by this operation.
    // Time Efficiency: O(1)
    unsigned int getElementCount() const;

    // Inserts newElement into the Binary Heap. 
    // It returns true if successful, otherwise false.      
    // Time Efficiency: O(log2 n)
    bool insert(ElementType& newElement);

    // Retrieves (but does not remove) the necessary element.
    // Precondition: This Binary Heap is not empty.
    // Postcondition: This Binary Heap is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
    // Time Efficiency: O(1) 
    ElementType& retrieve() const;
};
#include "BinaryHeap.cpp"
#endif
