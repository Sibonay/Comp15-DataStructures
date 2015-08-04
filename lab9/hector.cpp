#include <iostream>
#include <stdio.h>
#include "hector.h"

using namespace std;
//
// hector.cpp -- compare three different collision solutions
//
// your job: code the insert functions
//  our job: run the three insert functions and report results
//

int doubleJump(int value, int attempt);

// constructor
Hector::Hector()
{
	for(int i = 0; i < TSIZE; i++)
	{
		cheneyTable[i] = NULL;
		linnyTable[i] = -1;
		doublesTable[i] = -1;
	}
}

// destructor
// NOTE: DOESN'T REALLY WORK
Hector::~Hector() {
	for (int i = 0; i < TSIZE; i++) {
		delete [] linnyTable;
		delete [] doublesTable;

		Node *current = cheneyTable[i];
		while (current != NULL) {
			cheneyTable[i] = current->next;
			delete current;
			current = cheneyTable[i];
		}
		cheneyTable[i] = NULL;
	}
}

// linear probing
//
//  returns number of collisions before finding a spot
//
int Hector::linny(int value)
{
	int attempt = 0;
	int index;
	bool found = false;
	while(!found)
	{
		index = (3*value + 7 + attempt)%17;
		if (linnyTable[index] == -1) {
			linnyTable[index] = value;
			found = true;
		} else {
			attempt++;
		}
	}
	return attempt;
}

// double hashing using a second function
//  
//  returns number of collisions before finding a spot
//
int Hector::doubles(int value)
{

	int attempt = 0;
	int index;
	bool found = false;
	int jump = 0;

	while(!found)
	{
		index = (3*value + 7 + jump)%17;
		if (doublesTable[index] == -1) {
			doublesTable[index] = value;
			found = true;
		} else {
			attempt++;
			jump = doubleJump(value, attempt);
		}
	}
	return attempt;
	
}

// chained hashing -- each spot in table is a linked list 
//
//  returns number of items in that spot before insertion
//
int Hector::cheney(int value)
{
	int chainLength = 0;
	int index;
	bool found = false;

	Node *insertedNode = new Node;
	insertedNode->key = value;
	insertedNode->next = NULL;

	while(!found)
		{
			index = (3*value + 7)%17;
			if (cheneyTable[index] == NULL) {
				cheneyTable[index] = insertedNode;
				found = true;
			} else {
				Node *current = cheneyTable[index];
				while (current != NULL) {
					chainLength++;
					if (current->next != NULL) {
						current = current->next;
					} else {
						current->next = insertedNode;
						return chainLength;

					}
				}
			}
		}
}

// print the hash tables
void Hector::print()
{
	for(int i=0; i < TSIZE; i++)
	{
		cout << linnyTable[i] << " ";
		
	}
	
	cout << endl;
	
	for(int i=0; i < TSIZE; i++)
	{
		cout << doublesTable[i] << " ";
		
	}
	cout << endl;
	
	Node* iter = NULL;
	for(int i=0; i < TSIZE; i++)
	{
		iter = cheneyTable[i];
		cout << "[ ";
		while(iter != NULL)
		{
			cout << iter->key << " ";
			iter = iter->next;
		}
		cout << "]";
	}
	cout << endl;
}

int doubleJump(int value, int attempt) {
	return attempt * (13 - (value % 13));
}
