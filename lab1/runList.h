//
//  runList.h
//  OrderedRunners
//
//  Created by Chris Gregg on 1/31/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//

#ifndef __OrderedRunners__runList__
#define __OrderedRunners__runList__

#include <iostream>
#include "runner.h"
using namespace std;

struct RunnerNode {
        Runner aRunner;
        RunnerNode *next;
        RunnerNode *prev;
};

class RunList {
public:
        RunList();
	~RunList();
        void insertInOrder(string runnerName,int runnerTime);
        void insertBefore(RunnerNode *aNode,RunnerNode *newNode);
        void insertAfter(RunnerNode *aNode,RunnerNode *newNode);
        RunnerNode *getHead();
        RunnerNode *getTail();
        
        void printList(bool reversed);
private:
        RunnerNode *head;
        RunnerNode *tail;
};

#endif /* defined(__OrderedRunners__runList__) */
