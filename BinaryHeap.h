/*
 * BinaryHeap.h
 *
 * Description: Minimum Binary Heap ADT class. 
 *
 * Class Invariant: Always a Minimum Binary Heap.
 *
 * Authors: KW
 * Last Modified: April 3rd, 2024
 */

#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include "EmptyDataCollectionException.h"

template <class ElementType>
class BinaryHeap {

private:

    unsigned int elementCount = 0;
    unsigned int capacity = 10;
    
    ElementType * elements = nullptr;

    // Utility method
    // Description: Recursively put the array back into a ____________ Binary Heap.
    void reHeapDown(unsigned int indexOfRoot);

    // Utility method
    // Description: Recursively put the array back into a ____________ Binary Heap.
    void reHeapUp(unsigned int indexOfBottom);

public:

/******* Start of Binary Heap  Public Interface *******/	

    // Constructor 
    BinaryHeap();

    // Destructor
    ~BinaryHeap();

    // Copy Constructor
    BinaryHeap(const BinaryHeap & obj);

    // Description: Returns the number of elements in the Binary Heap.
    // Postcondition: The Binary Heap is unchanged by this operation.
    // Time Efficiency: O(1)
    unsigned int getElementCount() const;

    // Description: Inserts newElement into the Binary Heap. 
    //              It returns true if successful, otherwise false.      
    // Time Efficiency: O(log2 n)
    bool insert(ElementType & newElement);
      
    // Description: Removes (but does not return) the necessary element.
    // Precondition: This Binary Heap is not empty.
    // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
    // Time Efficiency: O(log2 n)
    void remove();

    // Description: Retrieves (but does not remove) the necessary element.
    // Precondition: This Binary Heap is not empty.
    // Postcondition: This Binary Heap is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
    // Time Efficiency: O(1) 
    ElementType & retrieve() const;
 
/******* End of Binary Heap Public Interface *******/

};

#include "BinaryHeap.cpp"
#endif