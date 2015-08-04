#
# Makefile for hookbook
#
CXX = clang++
FLAGS = -O0 -g3 -Wall

peanuts5k: main.cpp runList.cpp runList.h runner.cpp runner.h
	${CXX} ${FLAGS} -o peanuts5k main.cpp runner.cpp runList.cpp

clean:
	rm -f peanuts5k
	
provide:
	provide comp15 lab1 main.cpp runner.cpp runner.h runList.cpp runList.h Makefile

