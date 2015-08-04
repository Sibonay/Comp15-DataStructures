#
# Makefile for Hashing Lab
#
CXX = clang++
FLAGS = -O0 -g3 -Wall

hectorHash: main.cpp hector.cpp hector.h
	${CXX} ${FLAGS} -o hectorHash main.cpp hector.cpp

clean:
	rm -f hectorHash
	
provide:
	provide comp15 lab9 main.cpp hector.cpp hector.h Makefile
