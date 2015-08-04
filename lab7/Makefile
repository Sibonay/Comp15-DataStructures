#
# Makefile for Heap
#
CXX = clang++
FLAGS = -Wall -Wextra -Wreturn-type -g

heapSort: main.cpp heap.cpp heap.h
	${CXX} ${FLAGS} -o heapSort main.cpp heap.cpp

clean:
	rm -f heapSort
	
provide:
	provide comp15 lab7 main.cpp heap.cpp heap.h Makefile
