//
//  sort2.cpp
//  Sorts integers using the MergeSort algorithm


#include "sort2.h"

using namespace std;

MergeSort::MergeSort(){ // constructor
        sortArray.length = 0;
        sortArray.arr = NULL;
}

MergeSort::~MergeSort() { // destructor
	delete [] sortArray.arr;
}

// reads in a list of integers from stdin and returns an arrayWithLength
arrayWithLength MergeSort::readList(){
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
        return sortArray;
}


// merge sort on sortArray
arrayWithLength MergeSort::sort(arrayWithLength array){
	if (array.length <= 1)
		return array; // list is sorted by definition
	else {
		int middle = (array.length / 2);
		arrayWithLength leftHalf,rightHalf;
		
		// if original array has odd number of elements, leftHalf will
		// be smaller half e.g. if array has 9 elems, left will have 4
		leftHalf.length = middle;
		leftHalf.arr = new int[leftHalf.length]; // create array

		for (int x = 0; x < middle; x++) { // copy left half of
		    leftHalf.arr[x] = array.arr[x];    // original array
		}

		rightHalf.length = array.length - middle; 
		rightHalf.arr = new int[rightHalf.length]; // create array

		for (int y = middle; y < array.length; y++) { // copy right half
		    rightHalf.arr[y - middle] = array.arr[y];
		}
		
		leftHalf = sort(leftHalf);
		rightHalf = sort(rightHalf);
		
		// merge the two smaller sorted lists into a larger sorted list
		int i = 0, j = 0, k = 0;
		while ((i < leftHalf.length) and (j < rightHalf.length)) {
			if (leftHalf.arr[i] < rightHalf.arr[j]) {
				array.arr[k] = leftHalf.arr[i];
				i++;
			} else { // element in rightHalf is larger
				array.arr[k] = rightHalf.arr[j];
				j++;
			}
			k++;
		}
		
		// one smaller list is now fully emptied into the larger list
		// so the remainder of the other smaller list must be added to
		// the end of the larger list
		while (i < leftHalf.length) {
			array.arr[k] = leftHalf.arr[i];
			i++;
			k++;
		}
		while (j < rightHalf.length) {
			array.arr[k] = rightHalf.arr[j];
			j++;
			k++;
		}
		// cleaning up memory
		delete [] leftHalf.arr;
		delete [] rightHalf.arr;
	}

	return array; // should never reach here due to above logic
}

// prints out the integers in sorted order
void MergeSort::printArray(){
	for (int i = 0; i < sortArray.length; i++) {
	    cout << sortArray.arr[i] << endl; 
	}
}


