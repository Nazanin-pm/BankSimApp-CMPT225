#include "BinaryHeap.h"
#include <iostream>

int main() {
    // Create a BinaryHeap of integers
    BinaryHeap<int> heap;


    // Create variables for the values to be inserted
    int value1 = 5;
    int value2 = 3;
    int value3 = 8;
    int value4 = 1;
    int value5 = 10;
    int value6 = 3; // Duplicate element
    int value7 = 5; // Duplicate element

    // Insert elements into the heap using references to the variables
    heap.insert(value1);
    heap.insert(value2);
    heap.insert(value3);
    heap.insert(value4);
    heap.insert(value5);
    heap.insert(value6); // Duplicate element
    heap.insert(value7); // Duplicate element

    // Print the current state of the heap
    std::cout << "Heap after insertions:" << std::endl;
    std::cout << "Element count: " << heap.getElementCount() << std::endl;
    std::cout << "Minimum element: " << heap.retrieve() << std::endl;

    // Remove the minimum element
    heap.remove();

    // Print the state of the heap after removal
    std::cout << "\nHeap after removing minimum element:" << std::endl;
    std::cout << "Element count: " << heap.getElementCount() << std::endl;
    std::cout << "Minimum element: " << heap.retrieve() << std::endl;

    // Insert more elements to trigger resizing
    for (int i = 1; i <= 10; i++) {
        heap.insert(i);
    }

    // Print the state of the heap after resizing
    std::cout << "\nHeap after inserting more elements:" << std::endl;
    std::cout << "Element count: " << heap.getElementCount() << std::endl;
    std::cout << "Minimum element: " << heap.retrieve() << std::endl;

    // Remove all elements from the heap
    while (heap.getElementCount() > 0) {
        heap.remove();
    }

    // Print the state of the heap after removing all elements
    std::cout << "\nHeap after removing all elements:" << std::endl;
    std::cout << "Element count: " << heap.getElementCount() << std::endl;

    return 0;
}
