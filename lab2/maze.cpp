//
//  maze.cpp
//  MazeCreator
//
//

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "maze.h"
#include "stack.h"
using namespace std;

Maze::Maze(int size, unsigned int rand_seed)
{
	srand(rand_seed);
	maze_size = size;

	// the actual size of the array, including walls and border
	maze_array_size = maze_size * 2 + 1;
	for(int a = 0; a < MAX; a++)
	{
		for(int b = 0; b < MAX; b++)
		{
			if(a % 2 == 0 || b % 2 == 0) {
				maze[a][b] = 1;
			}
			else {
				maze[a][b] = PATH;
			}
		}
	}
}

// solve_maze should be passed a human-readable maze
// with a start and finish, and a start position of 1,1
// dead-end paths that have been tested should be marked
// with lowercase b
// The correct path should be marked with periods, .
bool Maze::solve_maze_recursive(int row, int col) {
	// be careful! 2d arrays seem backwards and upside down
	// compared to cartesian coordinates:
	// maze[0][0] == top left
	// maze[1][0] == one down, zero to the right
	// maze[0][1] == zero down, one to the right
	// maze[row][col] == row down and col to the right

	if ((row < 0) or (row >= maze_array_size) or (col < 0) or
		(col >= maze_array_size)) {
		return false;
	}
	if ((maze[row][col] == 'X') or (maze[row][col] == 'b') or
			(maze[row][col] == '.')) {
		return false;
	}
	if (maze[row][col] == 'F') {
		return true;
	}
	maze[row][col] = '.';

	//print_maze(); // uncomment to debug

	// Recursively call solve_maze_recursive(row,col) for north, east, south, and west
	// If one of the positions returns true, then return true (north is done for you)

	// north
	if (solve_maze_recursive(row-1, col) == true) { // north
		return true;
	}
	if (solve_maze_recursive(row, col + 1) == true) { // east
		return true;
	}
	if (solve_maze_recursive(row + 1,col) == true) { // south
		return true;
	}
	if (solve_maze_recursive(row, col - 1) == true) { // west
		return true;
	}
	else {
		maze[row][col] = 'b';
	}
	return false;
}

void Maze::solve_maze_stack(int row, int col){

	Stack stack;

	while (1){

		if (maze[row][col] == 'F') { // finish line
			break;
		}
		maze[row][col] = '.'; // current pos could be part of path
		// north
		if (row-1 >= 0 &&
				maze[row-1][col]!='X' &&
				maze[row-1][col]!='b' &&
				maze[row-1][col]!='.'){
			stack.push(Position(row,col));
			row-=1;
			continue;
		}
		// east
		if (col + 1 >= 0 &&
				maze[row][col + 1]!='X' &&
				maze[row][col + 1]!='b' &&
				maze[row][col + 1]!='.'){
			stack.push(Position(row,col));
			col += 1;
			continue;
		}
		// south
		if (row + 1 >= 0 &&
				maze[row + 1][col]!='X' &&
				maze[row + 1][col]!='b' &&
				maze[row + 1][col]!='.'){
			stack.push(Position(row,col));
			row += 1;
			continue;
		}
		// west
		if (col - 1 >= 0 &&
				maze[row][col - 1]!='X' &&
				maze[row][col - 1]!='b' &&
				maze[row][col - 1]!='.'){
			stack.push(Position(row,col));
			col -= 1;
			continue;
		}
		maze[row][col] = 'b';
		Position temp = stack.pop();
		row = temp.row;
		col = temp.col;
	}
}

// generates a maze
void Maze::generate_maze(){
	int index = 0;
	int backtrack_x[CELL];
	int backtrack_y[CELL];
	backtrack_x[index] = 1;
	backtrack_y[index] = 1;
	maze_generator(index, backtrack_x, backtrack_y,
			1, 1, maze_size, 1);
}

void Maze::maze_generator(int index, int backtrack_x[CELL],
		int backtrack_y[CELL], int x, int y, int n, int visited)
{
	if(visited < n * n)
	{
		int neighbour_valid = -1;
		int neighbour_x[4];
		int neighbour_y[4];
		int step[4];

		int x_next;
		int y_next;

		if(x - 2 > 0 && is_closed(x - 2, y))  // upside
		{
			neighbour_valid++;
			neighbour_x[neighbour_valid]=x - 2;;
			neighbour_y[neighbour_valid]=y;
			step[neighbour_valid]=1;
		}

		if(y - 2 > 0 && is_closed(x, y - 2))  // leftside
		{
			neighbour_valid++;
			neighbour_x[neighbour_valid]=x;
			neighbour_y[neighbour_valid]=y - 2;
			step[neighbour_valid]=2;
		}

		if(y + 2 < n * 2 + 1 && is_closed(x, y + 2))  // rightside
		{
			neighbour_valid++;
			neighbour_x[neighbour_valid]=x;
			neighbour_y[neighbour_valid]=y + 2;
			step[neighbour_valid]=3;

		}

		if(x + 2 < n * 2 + 1 && is_closed(x + 2, y))  // downside
		{
			neighbour_valid++;
			neighbour_x[neighbour_valid]=x+2;
			neighbour_y[neighbour_valid]=y;
			step[neighbour_valid]=4;
		}

		if(neighbour_valid == -1)
		{
			// backtrack
			x_next = backtrack_x[index];
			y_next = backtrack_y[index];
			index--;
		}

		if(neighbour_valid!=-1)
		{
			int randomization = neighbour_valid + 1;
			int random = rand()%randomization;
			x_next = neighbour_x[random];
			y_next = neighbour_y[random];
			index++;
			backtrack_x[index] = x_next;
			backtrack_y[index] = y_next;

			int rstep = step[random];

			if(rstep == 1)
				maze[x_next+1][y_next] = PATH;
			else if(rstep == 2)
				maze[x_next][y_next + 1] = PATH;
			else if(rstep == 3)
				maze[x_next][y_next - 1] = PATH;
			else if(rstep == 4)
				maze[x_next - 1][y_next] = PATH;
			visited++;
		}

		maze_generator(index, backtrack_x, backtrack_y,
				x_next, y_next, n, visited);
	}
}

// requires human_readable_maze
void Maze::print_maze()
{
	for(int a = 0; a < maze_size * 2 + 1; a++)
	{
		for(int b = 0; b < maze_size * 2 + 1; b++)
		{
			printf("%c",maze[a][b]);
		}
		printf("\n");
	}
	printf("\n");
}

void Maze::human_readable_maze()
{
	for(int a = 0; a < maze_array_size; a++)
	{
		for(int b = 0; b < maze_array_size; b++)
		{
			if (a==1 && b==1)
				maze[a][b]='S'; // the start location
			else if (a==maze_array_size - 2 &&
					b==maze_array_size-2) {
				// the finish location
				maze[a][b]='F';
			}
			else if(maze[a][b] == WALL) {
				maze[a][b]='X';
			}
			else {
				maze[a][b]=' ';
			}
		}
	}
}

int Maze::is_closed(int x, int y)
{
	if(maze[x - 1][y]  == WALL
			&& maze[x][y - 1] == WALL
			&& maze[x][y + 1] == WALL
			&& maze[x + 1][y] == WALL
	)
		return 1;

	return 0;
}

bool Maze::isSameSolutionAs(Maze anotherMaze){
	for (int row=0;row<maze_array_size;row++){
		for (int col=0;col<maze_array_size;col++){
			if (maze[row][col] !=
					anotherMaze.maze[row][col]) {
				return false;
			}
		}
	}
	return true;
}
