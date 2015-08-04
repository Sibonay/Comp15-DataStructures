//
//  main.cpp
//  MazeCreator
//
//  Created by Chris Gregg on 2/7/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//
//  Maze creation modified from: http://azerdark.wordpress.com/2009/03/29/588/
//  and http://www.mazeworks.com/mazegen/mazetut/index.htm

#define same_maze 1
#define random_maze 0

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "stack.h"
#include "maze.h"
using namespace std;

int main()
{
        unsigned int rand_seed;
#if same_maze
        rand_seed = 0; // the same seed for each maze
        
#elif random_maze
        rand_seed = (unsigned)time(NULL); // quasi-random seed
#endif
        
        int size;
        
        cout << "MAZE CREATOR and SOLVER\n\n";
        cout << "input  (2 ~ 30): ";
        scanf("%d", &size);
        cout << "\n";
        
        // recursive solution
        Maze maze(size,rand_seed);
        
        maze.generate_maze();
        maze.human_readable_maze();
        
        // print original maze
        maze.print_maze();
        
        maze.solve_maze_recursive();
        
        cout << "Recursive solution:\n\n";
        maze.print_maze();
        
        
        // stack solution
        Maze maze2 = Maze(size,rand_seed);
        maze2.generate_maze();
        maze2.human_readable_maze();
        
        maze2.solve_maze_stack();
        
        cout << "Stack-based solution:\n\n";
        maze2.print_maze();
        
        // check solutions to see if they are the same
        if (maze.isSameSolutionAs(maze2)) {
                cout << "The recursive solution is " <<
                		"the same as the stack solution.\n";
        }
        else {
                cout << "The recursive solution " <<
                		"and the stack solution differ.\n";
        }
        
        return 0;
}
