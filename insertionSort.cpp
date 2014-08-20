/*
 * insertionSort.cpp
 *
 *  Created on: Aug 19, 2014
 *      Author: brandon
 */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template<typename TypeIns>
void InsertElement ( TypeIns val , TypeIns sortArray[] ,
      int numHolding ) {
   int i = 0;
   for ( ; i < numHolding ; i++ ) {
      if ( val < sortArray[i] ) {
         for ( int j = numHolding ; j > i ; j-- ) {
            sortArray[j] = sortArray[j - 1];
         }
         break;
      }
   }
   sortArray[i] = val;
}

template<typename Type>
void InsertionSort(Type unsorted[], int numElements){
   for(int i=0;i<numElements;i++){
      InsertElement(unsorted[i],unsorted,i);
   }
}

template <typename arrayType>
string ArrayOutput(arrayType items[], int numElements){
   stringstream output;
   output << "Array is: ";
   for(int i=0; i<numElements; i++){
      output << items[i];
      if(i<numElements-1) output << ", ";
   }
   return output.str();
}


template <typename TestType>
void TestSort(TestType items[], int numElements){
   cout<< "\nBefore Sorting " << ArrayOutput(items, numElements) << endl;

   InsertionSort(items, numElements);

   cout << "After Sorting " << ArrayOutput(items, numElements) << endl;
}


int main(){

   const int NUM_ELEMENTS = 10;

   int numbers[NUM_ELEMENTS] = { 34, 55, 1, 6, 2, 66, 77, 43, 34};
   float floats[NUM_ELEMENTS] = { 3.4, 55.44, 10, .6, -2, 6.6, 7.788, 43, 34};
   string strs[NUM_ELEMENTS] = { "hello", "goodbye", "a", "A", "Bat", "cat",
         "hat", "dog", "Brandon"};


   TestSort(numbers,NUM_ELEMENTS);
   TestSort(floats,NUM_ELEMENTS);
   TestSort(strs,NUM_ELEMENTS);


}


