//
//  stack.h
//  stack
//
//  Created by Chris Gregg on 2/7/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//

#ifndef __stack__stack__
#define __stack__stack__

#include <iostream>

struct Position {
        Position(int rowPos=0,int colPos=0) {
        		row=rowPos;
        		col=colPos;
        }
        int row;
        int col;
};

class Stack {
public:
        static const int INIT_CAPACITY = 5;
        
	Stack(); // constructor
        void push(Position p);
        Position pop();
        Position top();
        int getCapacity(){
        		return stackCapacity;
        }
        
        ~Stack(); // destructor
private:
	Position *stack;
        int stackCount;
        int stackCapacity;
        
};

#endif /* defined(__stack__stack__) */
