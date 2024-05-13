/* 
 * BinaryHeap.cpp
 *
 * Description: Minimum Binary Heap ADT class.
 *
 * Class Invariant: Always a Minimum Binary Heap.
 * 
 * Author: KW
 * Last Modification: April 3rd, 2024
 *
 */  

#include <iostream>
#include "BinaryHeap.h"  // Header file

using std::cout;
using std::endl;

// Utility method
// Description: Recursively put the array back into a Minimum Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) {

   unsigned int indexOfMinChild = indexOfRoot;
   
   // Find indices of children.
   unsigned int indexOfLeftChild = 2 * indexOfRoot + 1;
   unsigned int indexOfRightChild = 2 * indexOfRoot + 2;

   // Base case: elements[indexOfRoot] is a leaf as it has no children
   if (indexOfLeftChild > elementCount - 1) return;

   // If we need to swap, select the smallest child
   // If (elements[indexOfRoot] > elements[indexOfLeftChild])
   if ( ! (elements[indexOfRoot] <= elements[indexOfLeftChild]) )
      indexOfMinChild = indexOfLeftChild;

   // Check if there is a right child, is it the smallest?
   if (indexOfRightChild < elementCount) {
      // if (elements[indexOfMinChild] > elements[indexOfRightChild])
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

// Utility method
// Description: Recursively put the array back into a Minimum Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfBottom) {

   // if the rightmost (last) node exists...
   if(indexOfBottom > 0){

      // find the index of its parent
      unsigned int indexOfParent = (indexOfBottom -1) / 2;

      // if the rightmost node is smaller than the parent node...
      if(elements[indexOfBottom] <= elements[indexOfParent]){

         ElementType tempIndex = elements[indexOfParent]; // create a temporary node and assign the parent node's value to it 
         elements[indexOfParent] = elements[indexOfBottom]; // swap parent with the rightmost node 
         elements[indexOfBottom] = tempIndex;
         reHeapUp(indexOfParent); // recursively put the array back into the heap

      }

   }

}

// Constructor
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap() {

   elements = new ElementType[capacity];

} 

// Destructor 
template <class ElementType>
BinaryHeap<ElementType>::~BinaryHeap() {

   if(elements != nullptr){

      delete[] elements;

   }

}

// Copy Constructor 
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap(const BinaryHeap & obj) {

   elementCount = obj.elementCount;
   capacity = obj.capacity;

   elements = new ElementType[capacity];

   for(int i = 0; i < elementCount; i++){

      elements[i] = obj.elements[i];

   }

}

// getElementCount
// Description: Returns the number of elements in the Binary Heap.
// Postcondition: The Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const {

   return elementCount;

}

// insert
// Description: Inserts newElement into the Binary Heap. 
//              It returns true if successful, otherwise false.      
// Time Efficiency: O(log2 n)
template <class ElementType>
bool BinaryHeap<ElementType>::insert(ElementType & newElement) {

   // if memory allocation failed or heap is at capacicity already...
   if(elements == nullptr || elementCount == capacity){

      return false;

   }
   else{

      elements[elementCount] = newElement; // insert new element at rightmost node
      reHeapUp(elementCount); // reheap up at rightmost node
      elementCount = elementCount + 1; // increment elementCount
      return true;

   }

}

// remove
// Description: Removes (but does not return) the necessary element.
// Precondition: This Binary Heap is not empty.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove() {  

   if(elementCount == 0) 
      throw EmptyDataCollectionException("remove() called with an empty BinaryHeap.");

   elements[0] = elements[elementCount - 1];
   elementCount--;
   
   // No need to call reheapDown() is we have just removed the only element
   if ( elementCount > 0 ) 
      reHeapDown(0);
   
   return;   
}

// retrieve
// Description: Retrieves (but does not remove) the necessary element.
// Precondition: This Binary Heap is not empty.
// Postcondition: This Binary Heap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
template <class ElementType>
ElementType & BinaryHeap<ElementType>::retrieve() const {

   // if binary heap is empty...
   if(elementCount == 0){

      throw EmptyDataCollectionException("called retrieve() for an empty data collection"); // throw exception if heap is empty

   }
   
   return elements[0]; // return the topmost element 

}


 