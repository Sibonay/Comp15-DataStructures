//
//  main2.cpp
//  Sorting
//

#include <iostream>
#include "sort2.h"

using namespace std;

int main()
{
        MergeSort sorter;
        
        arrayWithLength array = sorter.readList();
        sorter.sort(array);
        cout << "Output:\n";
        sorter.printArray();
	return 0;
}
