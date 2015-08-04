#
# Makefile for Graph Traversal Lab
#
CXX = clang++
FLAGS = -O0 -g3 -Wall

graphTraversal: main.cpp graph.cpp graph.h
	${CXX} ${FLAGS} -o graphTraversal graph.cpp main.cpp

clean:
	rm -f graphTraversal
	
provide:
	provide comp15 lab10 main.cpp graph.cpp graph.h Makefile
