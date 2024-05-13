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

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "BinaryHeap.h"
#include "EmptyDataCollectionException.h"

template <class ElementType>
class PriorityQueue
{
private:
    BinaryHeap<ElementType>* MinBinaryHeap  = nullptr;
public:
    //Default constructor
    PriorityQueue();

    //Destructor
    ~PriorityQueue();
/******* Start of Priority Queue Public Interface *******/

   // Description: Returns true if this Priority Queue is empty, otherwise false.
   // Postcondition: This Priority Queue is unchanged by this operation.
   // Time Efficiency: O(1)
   bool isEmpty() const;

   // Description: Inserts newElement in this Priority Queue and 
   //              returns true if successful, otherwise false.
   // Time Efficiency: O(log2 n)
   bool enqueue(ElementType & newElement);

   // Description: Removes (but does not return) the element with the next
   //              "highest" priority value from the Priority Queue.
   // Precondition: This Priority Queue is not empty.
   // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
   // Time Efficiency: O(log2 n)
   void dequeue();
   
   // Description: Returns (but does not remove) the element with the next 
   //              "highest" priority from the Priority Queue.
   // Precondition: This Priority Queue is not empty.
   // Postcondition: This Priority Queue is unchanged by this operation.
   // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
   // Time Efficiency: O(1)
   ElementType & peek() const;
   
/*******  End of Priority Queue Public Interface *******/
};
#include "PriorityQueue.cpp"
#endif
