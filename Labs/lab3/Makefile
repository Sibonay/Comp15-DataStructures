#
# Makefile for queues
#
CXX = clang++
FLAGS = -Wall -g

sandwichList: main.cpp sandwichList.cpp sandwichList.h
	${CXX} ${FLAGS} -o sandwichList main.cpp sandwichList.cpp

clean:
	rm -f sandwichList
	
provide:
	provide comp15 lab3 main.cpp sandwichList.cpp sandwichList.h Makefile
