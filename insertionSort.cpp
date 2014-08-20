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
void InsertElement ( TypeIns val , TypeIns sortArray[] , int numHolding );

template<typename Type>
void InsertionSort(Type unsorted[], int numElements);

template <typename arrayType>
string ArrayOutput(arrayType items[], int numElements);

template <typename TestType>
void TestSort(TestType items[], int numElements);

class Creature{
private:
   string name;
   int strength;

public:
   Creature(string theName, int theStrenght):
      strength(theStrenght), name(theName){}

   friend bool operator < (const Creature& left, const Creature& right);
   friend ostream& operator << (ostream& out, const Creature& creature);

};




int main(){

   const int NUM_ELEMENTS = 10;

   ///defining test cases
   int numbers[NUM_ELEMENTS] = { 34, 55, 1, 6, 2, 66, 77, 43, 34};
   float floats[NUM_ELEMENTS] = { 3.4, 55.44, 10, .6, -2, 6.6, 7.788, 43, 34};
   string strs[NUM_ELEMENTS] = { "hello", "goodbye", "a", "A", "Bat", "cat",
         "hat", "dog", "Brandon", "Swanson"};
   Creature creats[NUM_ELEMENTS] = { Creature("Tobias",12),
                                     Creature("Dave", 18),
                                     Creature("Tim", 8),
                                     Creature("Bob", 40),
                                     Creature("Sue", 13),
                                     Creature("Tian", 12),
                                     Creature("Jimmy", 9),
                                     Creature("Tom", 32),
                                     Creature("Dan", 4),
                                     Creature("Joe", 56),
   };


   //displaying unsorted then sorted arrays
   TestSort(numbers,NUM_ELEMENTS);
   TestSort(floats,NUM_ELEMENTS);
   TestSort(strs,NUM_ELEMENTS);
   TestSort(creats,NUM_ELEMENTS);


}

////sorts items in array one item at a time
template<typename Type>
void InsertionSort(Type unsorted[], int numElements){
   for(int i=0;i<numElements;i++){
      InsertElement(unsorted[i],unsorted,i);
   }
}


///insertion algorithm
///sortArray[numholding] is holding the value passed in as val
///sortArray[0-numholding] should be already sorted
///items from [numholding+1 - n] not modified
template<typename TypeIns>
void InsertElement ( TypeIns val , TypeIns sortArray[] ,
      int numHolding ) {
   int i = 0;
   for ( ; i < numHolding ; i++ ) {
      // position for new element is found
      if ( val < sortArray[i] ) {
         //all sorted items greater than element are moved, one space
         //to make room new element
         for ( int j = numHolding ; j > i ; j-- ) {
            sortArray[j] = sortArray[j - 1];
         }
         break;
      }
   }
   //val is placed in "empty spot"
   sortArray[i] = val;
}

////////////////////////////////////////////////////////////////////
/////////CREATURE OPERATORS/////////////////////////////////////////
////////////////////////////////////////////////////////////////////

bool operator < (const Creature& left, const Creature& right){
   return (left.strength < right.strength);
}

ostream& operator << (ostream& out, const Creature& creature){
   out << creature.name << " (str:" << creature.strength << ")";
   return out;
}

////////////////////////////////////////////////////////////////////
//////////////TESTING OUTPUT///////////////////////////////////////
//////////////////////////////////////////////////////////////////

template <typename TestType>
void TestSort(TestType items[], int numElements){
   cout<< "\nBefore Sorting " << ArrayOutput(items, numElements) << endl;

   InsertionSort(items, numElements);

   cout << "After Sorting " << ArrayOutput(items, numElements) << endl;
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

