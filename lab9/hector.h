#ifndef HECTOR_H
#define HECTOR_H
#include <iostream>
#include <stdio.h>

using namespace std;
//
// hector.cpp -- compare three different collision solutions
//
// your job: code the insert functions
//  our job: run the three insert functions and report results
//

const int TSIZE = 17;
const int VAL = 10;
const int SENTINEL = -1;

//
// used by the chained version of collision handling
//
struct Node {
	int key;
	Node* next;
};

//
// the class interface
//
class Hector
{
	public:
		int linny(int value);
		int doubles(int value);
		int cheney(int value);		

		Hector(); // constructor
		~Hector(); // destructor
		void print();

	private:
		Node* cheneyTable[TSIZE];	
		int linnyTable[TSIZE];
		int doublesTable[TSIZE];
		
};
#endif	/* HECTOR_H */
