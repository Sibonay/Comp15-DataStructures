# ReadMe for COMP 15 HW5
## Sorting Assignment

1.  Purpose of program:
	- implement Selection Sort, Merge Sort, and Insertion Sort to sort numbers
	  that are input through the "standard input" in ascending order

2.  List of files with one/or two-line summary
	- main1.cpp  ~  tests Selection Sort
	- main2.cpp  ~  tests Merge Sort
	- main3.cpp  ~  tests Insertion Sort
	- SelectionSort.h  ~  header file for SelectionSort class
	- SelectionSort.cpp  ~  function definitions of SelectionSort class
	- sort2.h  ~  header file for MergeSort class
	- sort2.cpp  ~  function definitions of MergeSort class
	- sort3.h  ~  header file for InsertionSort class
	- sort.cpp  ~  function definitions of InsertionSort class
	- Makefile  ~  makefile for aforementioned files 

3.  How to compile:
	- use included Makefile 

4.  Outline of data structure:
	- the numbers that are read in are put into an array which is contained in
	  the struct arrayWithLength, which contains the length of the int array and 
	  a pointer to the array itself
	- this arrayWithLength is implemented using dynamic arrays (the function that 
	  reads in the input at first creates an array that can hold 10 elements, and 
	  then expands it as necessary)

5.  Selection Sort Algorithm:
	- is an in-place comparison sort
	- the array is divided into 2 parts (imaginarily): 
		the sorted part, which is built from left to right at the front of the list,
		and is empty at the start;
		the unsorted part, which contains the elements that remain to be sorted 
		that occupy the rest of the list, and contains the whole array at the start
	- the minimum element in the unsorted part is found and then added to the end of the 
	  sorted part 
	- when the unsorted part is empty (i.e. all elements have been moved to the 
	  sorted part), the algorithm ends
    
    Complexity:
	- worst case: O(n^2)
	    because to find the minimum element in the unsorted part, we have to scan all the
	    elements in the array i.e. all n elements. Then to find the next lowest element, we
	    have to scan n-1 elements, and then n-2, and so on. n + (n-1) + (n-2)... results in
	    O(n^2) number of comparisons
	- best case: 0(n^2)
	    exactly the same as the worst case because it is impossible to know if an element is
	    the minimum without scanning all n elements

6.  Merge Sort Algorithm:
	- my particular algorithm is not in place, but rather, allocates extra memory in the form of
	  a temporary array 
	- the list is divided into two halves 
		I create 2 new arrays (lefthalf, righthalf) and copy the elements from the 
		original array into these new arrays
	- the function is then called recursively until the unsorted list has been divided into n sublists,
	  with each sublist containing one element (that is, by definition, sorted)
	- then these sublists are merged to form a single, sorted, new list
	- this continues until there is only one sublist i.e. the whole sorted list 
    
    Complexity:
	- worst case: O(nlogn)
	    Dividing each list in half is a logarithmic operation i.e. logn
	    The merging process requires going through every single element i.e. n
	    So the entire algorithm has a complexity of O(nlogn)
	- best case: 0(nlogn)
	    exactly the same as the worst case because there is no case that makes the process 
	    of dividing each list in half or going through every single element any shorter - 
	    the process is the same no matter what the original order is

    Sources referenced: 
	- http://en.wikipedia.org/wiki/Merge_sort
	- http://www.vogella.com/tutorials/JavaAlgorithmsMergesort/article.html

6.  Insertion Sort Algorithm:
	- is an in-place comparison sort
	- like selection sort, the list has a sorted part and an unsorted part
	- each "new" item in the unsorted part, i.e. the first element in the unsorted part of
	  the array, is checked against those in the sorted part and then inserted in its proper
	  sorted position
	- this continues until the unsorted part is empty and the sorted part is the entire array
    
    Complexity:
	- worst case: O(n^2)
	    if the array is sorted in reverse order, then every iteration must traverse the entire list
	    before inserting the next element into the sorted part.This results in n(n-1)/2 comparisons 
	    being made, i.e. O(n^2) behaviour 
	- best case: 0(n)
	    if an array is already sorted, then during each iteration, the first remaining element of
	    the unsorted part is only compared with the end element of the sorted part, therefore we
	    only traverse through each element once
	    
    Sources referenced:
	- http://interactivepython.org/courselib/static/pythonds/SortSearch/TheInsertionSort.html
	- http://en.wikipedia.org/wiki/Insertion_sort

7.  No one helped me on this assignment 

