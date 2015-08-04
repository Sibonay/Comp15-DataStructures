//
//  stack.cpp
//  stack
//
//  Created by Chris Gregg on 2/7/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//

#include <cassert>
#include "stack.h"

Stack::Stack(){ // constructor
        stack = NULL;
        stackCount = 0;
        stackCapacity = 0;
}

void Stack::push(Position p){
        if (stack == NULL) { // no stack yet, better create it
                stack = new Position[INIT_CAPACITY];
                stackCapacity = INIT_CAPACITY;
        }
        else if (stackCount == stackCapacity) { // full, better expand
                Position *tempStack = new Position[stackCapacity * 2];
                for (int i=0;i<stackCount;i++){
                        tempStack[i]=stack[i];
                }
                delete [] stack;
                stack = tempStack;
                stackCapacity = stackCapacity * 2;
        }
        stack[stackCount]=p;
        stackCount++;
}

Position Stack::pop() {
        assert(stackCount > 0); // stack underflow
        return stack[--stackCount];
}
Position Stack::top() {
        return stack[stackCount-1];
}

Stack::~Stack(){ // destructor
	delete stack;
}
