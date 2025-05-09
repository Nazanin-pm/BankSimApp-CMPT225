/*
 * BinaryHeap.cpp
 *
 * Description: Binary Heap ADT class.
 *
 * Class Invariant: Always a min Binary Heap.
 * 
 * Author: Nazanin Pouria Mehr
 * Last Modification: April 5th 2024
 */
#ifndef BINARYHEAP_CPP
#define BINARYHEAP_CPP

#include "BinaryHeap.h"

// Default constructor
template<class ElementType>
BinaryHeap<ElementType>::BinaryHeap() {}

// Destructor
template<class ElementType>
BinaryHeap<ElementType>::~BinaryHeap() {
    if (elements != nullptr) {
        delete[] elements;
        elements = nullptr;
    }
}

// Description: Removes (but does not return) the necessary element.
// Precondition: This Binary Heap is not empty.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template<class ElementType>
void BinaryHeap<ElementType>::remove() {  
   if(elementCount == 0) 
      throw EmptyDataCollectionException("remove() called with an empty BinaryHeap.");

   elements[0] = elements[elementCount - 1];
   elementCount--;
   
   // No need to call reheapDown() is we have just removed the only element
   if ( elementCount > 0 ) 
      reHeapDown(0);
}

// Description: Returns the number of elements in the Binary Heap.
// Postcondition: The Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template<class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const {
    return elementCount;
}

// Description: Inserts newElement into the Binary Heap. 
//              It returns true if successful, otherwise false.      
// Time Efficiency: O(log2 n)
template<class ElementType>
bool BinaryHeap<ElementType>::insert(ElementType& newElement) {


    if (elementCount == capacity) {
        // Binary heap is full, allocate more memory
        unsigned int newCapacity = capacity * 2; // Double the capacity
        ElementType* newElements = new ElementType[newCapacity];

        // Copy existing elements to the new array
        for (unsigned int i = 0; i < elementCount; ++i) {
            newElements[i] = elements[i];
        }

        // Free memory occupied by the old array
        delete[] elements;

        // Update pointer and capacity
        elements = newElements;
        capacity = newCapacity;
    }

    // Insert at the end
    elements[elementCount] = newElement;
    elementCount++;

    // Bubble up
    unsigned int currentIndex = elementCount - 1;
    unsigned int parentIndex = (currentIndex - 1) / 2;

    while (currentIndex > 0 && elements[currentIndex] < elements[parentIndex]) {
        // Swap with parent
        ElementType temp = elements[currentIndex];
        elements[currentIndex] = elements[parentIndex];
        elements[parentIndex] = temp;

        // Update indices
        currentIndex = parentIndex;
        parentIndex = (currentIndex - 1) / 2;
    }

    return true; // Successfully inserted
}

// Description: Retrieves (but does not remove) the necessary element.
// Precondition: This Binary Heap is not empty.
// Postcondition: This Binary Heap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(1) 
template<class ElementType>
ElementType& BinaryHeap<ElementType>::retrieve() const {
    if (elementCount == 0)
        throw EmptyDataCollectionException("retrieve() called with an empty BinaryHeap.");
    return elements[0];
}

// Utility method
// Description: Recursively put the array back into a min Binary Heap.
template<class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) {
   unsigned int indexOfMinChild = indexOfRoot;
   
   // Find indices of children.
   unsigned int indexOfLeftChild = 2 * indexOfRoot + 1;
   unsigned int indexOfRightChild = 2 * indexOfRoot + 2;

   // Base case: elements[indexOfRoot] is a leaf as it has no children
   if (indexOfLeftChild > elementCount - 1) return;

   // If we need to swap, select the smallest child
   if ( ! (elements[indexOfRoot] <= elements[indexOfLeftChild]) )
      indexOfMinChild = indexOfLeftChild;

   // Check if there is a right child, is it the smallest?
   if (indexOfRightChild < elementCount) {
      if ( ! (elements[indexOfMinChild] <= elements[indexOfRightChild]) )
         indexOfMinChild = indexOfRightChild;
   }

   // Swap parent with smallest of children.
   if (indexOfMinChild != indexOfRoot) {
      ElementType temp = elements[indexOfRoot];
      elements[indexOfRoot] = elements[indexOfMinChild];
      elements[indexOfMinChild] = temp;
      
      // Recursively put the array back into a heap
      reHeapDown(indexOfMinChild);
   }
   return;
}

// Explicit Instantiation of BinaryHeap for supported types
template class BinaryHeap<int>;

#endif
