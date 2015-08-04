#
# Makefile for ImageEngine
#
CXX = clang++
FLAGS = -Wall -Wextra -Wreturn-type -g

imageengine: main.cpp ImageEngine.h ImageEngine.cpp
	${CXX} ${FLAGS} -o ImageEngine main.cpp ImageEngine.cpp

clean:
	rm -f ImageEngine
	
provide:
	provide comp15 lab8 main.cpp ImageEngine.cpp ImageEngine.h Makefile
