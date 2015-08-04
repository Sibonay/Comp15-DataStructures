#
# Makefile for maze solver
#
CXX = clang++
FLAGS = -g -Wall 

mazeSolver: main.cpp maze.cpp maze.h stack.cpp stack.h
	${CXX} ${FLAGS} -o mazeSolver main.cpp maze.cpp stack.cpp

clean:
	rm -f mazeSolver
	
provide:
	provide comp15 lab2 main.cpp maze.cpp maze.h stack.cpp stack.h Makefile
