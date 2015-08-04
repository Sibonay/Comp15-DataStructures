//
//  SelectionSort.cpp
//  Sorts integers using the SelectionSort algorithm


#include "SelectionSort.h"

using namespace std;

SelectionSort::SelectionSort(){ // constructor
        sortArray.length = 0;
        sortArray.arr = NULL;
}

// reads in a list of integers from stdin and returns an arrayWithLength
void SelectionSort::readList(){
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


// selection sort on sortArray
void SelectionSort::sort(){
	int i, j, minIndex, temp; 
	
	for (i = 0; i < sortArray.length; i++) { 
		minIndex = i; // assume first element is the minimum 
		for (j = i + 1; j < sortArray.length; j++) { 
			if (sortArray.arr[j] < sortArray.arr[minIndex]) {
				// index of minimum element in unsorted part
				minIndex = j; 
			}
		} 
		if (minIndex != i) {
			// swap first element of unsorted part with min
			temp = sortArray.arr[i];
			sortArray.arr[i] = sortArray.arr[minIndex]; 
			sortArray.arr[minIndex] = temp;
		}
	}
}

// prints out the integers in sorted order
void SelectionSort::printArray(){
	for (int i = 0; i < sortArray.length; i++) {
	    cout << sortArray.arr[i] << endl; 
	}
}


