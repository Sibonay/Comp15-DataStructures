//
//  sort2.h
//  Header File for MergeSort class
//

#ifndef __Sorting__sort2__
#define __Sorting__sort2__

#include <iostream>

struct arrayWithLength{
        int length;
        int *arr;
};

class MergeSort {
public:
        MergeSort(); // constructor
        
        ~MergeSort(); //destructor

        // read in a list of values from stdin
	arrayWithLength readList();
        
        // sort function
        arrayWithLength sort(arrayWithLength arr);
        
        // print the array
        void printArray();
        
private:
        arrayWithLength sortArray;
};

#endif /* defined(__Sorting__sort2__) */

