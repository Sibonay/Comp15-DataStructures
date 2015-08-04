//
//  InsertionSort.cpp
//  Sorts integers using the InsertionSort algorithm


#include "sort3.h"

using namespace std;

InsertionSort::InsertionSort(){ // constructor
        sortArray.length = 0;
        sortArray.arr = NULL;
}

// reads in a list of integers from stdin and returns an arrayWithLength
void InsertionSort::readList(){
        int currentCapacity = 10;
        sortArray.arr = new int[currentCapacity];

        while (cin >> sortArray.arr[sortArray.length]) {
                ++sortArray.length;
                if (sortArray.length==currentCapacity) {
                        int *temp = new int[currentCapacity*2];
                        for (int i=0;i<currentCapacity;i++) {
                                temp[i] = sortArray.arr[i];
                        }
                        delete [] sortArray.arr;
                        sortArray.arr = temp;
                        currentCapacity *= 2;
                }
        }
}


// Insertion sort on sortArray
void InsertionSort::sort(){

	int currentVal;
	int previous; 
	int temp;
	for (int i = 1; i < sortArray.length; i++) { // assume index 0 is a 
						     // sorted list of 1 item
		currentVal = sortArray.arr[i];
		previous = i - 1;

		// "sift down" first elem in unsorted part by swapping with 
		// elems in sorted part until it occupies correct position
		while ((previous >= 0) and (sortArray.arr[previous] > 
		    currentVal)) {
			temp = sortArray.arr[previous + 1];  
			sortArray.arr[previous + 1] = sortArray.arr[previous];
			sortArray.arr[previous] = temp;
			previous--;
		}
		// element inserted in correct place 
		sortArray.arr[previous + 1] = currentVal; 
	}
}


// prints out the integers in sorted order
void InsertionSort::printArray(){
	for (int i = 0; i < sortArray.length; i++) {
	    cout << sortArray.arr[i] << endl; 
	}
}


