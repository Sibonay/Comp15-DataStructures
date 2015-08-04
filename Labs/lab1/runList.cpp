//
//  runList.cpp
//  OrderedRunners
//
//  Created by Chris Gregg on 1/31/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//

#include "runList.h"
#include "runner.h"
#include <iostream>
using namespace std;

RunList::RunList() {
        head = NULL;
        tail = NULL;
}

RunList::~RunList() {
	RunnerNode *current = head;
	while (current != NULL) {
		head = current -> next;
		current -> prev = NULL;
		delete current;
		current = head;
	}
}

RunnerNode *RunList::getHead(){
        return head;
}

RunnerNode *RunList::getTail(){
        return tail;
}

// head will be the slowest runner, tail the fastest
void RunList::insertInOrder(string runnerName,int runnerTime) {
        RunnerNode *newNode = new RunnerNode();
        newNode->aRunner = Runner(runnerName,runnerTime);
        
        RunnerNode *tempNode = head;
        if(tempNode == NULL) { // there aren't any nodes yet
                insertBefore(head,newNode);
        }
        else {
        	// traverses list until reaches a runner that is faster than
        	// given runner and then inserts before this faster runner
        	if ((tempNode->aRunner).isFasterThan(newNode->aRunner)) {
        		insertBefore(tempNode,newNode);
        	} else {
        		tempNode = tempNode->next;
        	}
        }
}

void RunList::insertBefore(RunnerNode *aNode,RunnerNode *newNode) {
	if (aNode == NULL) { // empty list
		head = newNode;
		tail = newNode;
	}
	else {
		newNode -> next = aNode;
		newNode -> prev = aNode -> prev;

		if (aNode -> prev == NULL) // aNode is the head
		{
			head = newNode;
			aNode -> prev = newNode;
		} else {
			aNode -> prev = newNode;
			newNode -> prev -> next = newNode;
		}
	}

}

void RunList::insertAfter(RunnerNode *aNode, RunnerNode *newNode) {
        if (aNode == NULL) { // empty list
                head = newNode;
                tail = newNode;
        }
        else {
                newNode->prev = aNode;
                newNode->next = aNode->next;
                if (newNode->next==NULL) { // at the tail
                        tail = newNode;
                }
                else {
                        newNode->next->prev = newNode;
                }
                
                aNode->next = newNode;
        }

}

void RunList::printList(bool reversed){
        RunnerNode *iterator;
        
        if (reversed) {
                iterator = tail;
        }
        else {
                iterator = head;
        }
        
        while (iterator != NULL) {
                cout << iterator->aRunner.getName() << ": ";
                cout << iterator->aRunner.getTime() << "\n";
                if (reversed) {
                        iterator = iterator->prev;
                }
                else {
                        iterator = iterator->next;
                }
        }
}
