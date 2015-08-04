//
//  runner.cpp
//  OrderedRunners
//
//  Created by Chris Gregg on 1/31/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//

#include <iostream>
#include "runner.h"

using namespace std;

Runner::Runner(){ // constructor
        name = "";
        time = 0;
}
Runner::Runner(string runnerName, int timeInSeconds){
        name = runnerName;
        time = timeInSeconds;
}
        
string Runner::getName() { return name; }
int Runner::getTime() {return time; }
void Runner::setName(string runnerName) { name = runnerName; }
void Runner::setTime(int timeInSeconds) { time = timeInSeconds; }

bool Runner::isFasterThan(Runner anotherRunner) {
        // TODO: Students enter code here
}
