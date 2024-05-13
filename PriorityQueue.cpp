/*
 * PriorityQueue.h
 *
 * Description: Pritority Queue implemented using  a min Binary Heap ADT class. 
 *
 * Class Invariant: Always a Minimum Binary Heap.
 *
 * Authors: KW
 * Last Modified: April, 2024
 */

#include "PriorityQueue.h"
#include "EmptyDataCollectionException.h"

//Default constructor
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue(){
    MinBinaryHeap = new BinaryHeap<ElementType>();
}

//Destructor
template <class ElementType>
PriorityQueue<ElementType>::~PriorityQueue(){
    delete MinBinaryHeap; 
}

// Description: Returns true if this Priority Queue is empty, otherwise false.
// Postcondition: This Priority Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const{
    // returns true if element count is 0
    if (MinBinaryHeap->getElementCount() == 0)
    {
        return true;
    }
    else return false;
}

// Description: Inserts newElement in this Priority Queue and 
//              returns true if successful, otherwise false.
// Time Efficiency: O(log2 n)
template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType & newElement){
    return (MinBinaryHeap->insert(newElement));
}

// Description: Removes (but does not return) the element with the next
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void PriorityQueue<ElementType>::dequeue(){
    if(MinBinaryHeap->getElementCount() == 0)
    {
        throw EmptyDataCollectionException("dequeue() with empty queue");
    }

    MinBinaryHeap->remove();
    return;
}

// Description: Returns (but does not remove) the element with the next 
//              "highest" priority from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType & PriorityQueue<ElementType>::peek() const{
    if(MinBinaryHeap->getElementCount() == 0)
    {
        throw EmptyDataCollectionException("peek() with empty queue");
    }
    
    return MinBinaryHeap->retrieve();
}