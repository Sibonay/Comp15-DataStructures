
#include <iostream>
#include <sstream>
using namespace std;

const int INIT_SIZE = 100;


class Heap{

public:

	//Build empty heap
	Heap();

	// destructor
	~Heap(); 

	//Builds a heap from list
	Heap(string list[], int listSize);

	//not used for this lab
	void insert(string x);

	//removes the smallest element in the heap
	string removeMin();

	//returns the size of the heap;
	int size();

private:

	//heap is implemented as a dynamic array
	string *heap;

	//number of elements currently in the heap
	int heapSize;

	//current max capacity of the dymnamic array
	int maxCapacity;

	//down heap function recursive and
	//works with the location of the element
	//in the tree. heap[location] stores
	//the value being inserted

	void downHeap(int location);

	//up heap function for insert
	//since it is an array it must
	//add to the tree at the last empty slot
	//and the added element percolates up to the
	//proper spot
	void upHeap(int location); 

	//build heap function used by constructor that takes in array
	//and turns the array into a heap
	void buildHeap();


	//getter methods to determine which/where child/parent
	//relationships
	int leftChild(int index);
	int rightChild(int index);
	int parent(int index);

	void expand();

};

