//
//  InsertionSort.h
//  Header File for InsertionSort class
//

#ifndef __Sorting__InsertionSort__
#define __Sorting__InsertionSort__

#include <iostream>

struct arrayWithLength{
        int length;
        int *arr;
};

class InsertionSort {
public:
        InsertionSort(); // constructor

        // read in a list of values from stdin
        void readList();

        // sort function
        void sort();

        // print the array
        void printArray();

private:
        arrayWithLength sortArray;
};

#endif /* defined(__Sorting__InsertionSort__) */

