#
# Makefile for hookbook
#
CXX = clang++
FLAGS = -O0 -g3 -Wall

hookbookBattles: main.cpp hookbookBattles.cpp hookbookBattles.h \
		Abilities.cpp Abilities.h
	${CXX} ${FLAGS} -o hookbookBattles main.cpp hookbookBattles.cpp Abilities.cpp

valgrind:
	${CXX} ${FLAGS} -o hookbookBattles main.cpp hookbookBattles.cpp Abilities.cpp
	valgrind ./hookbookBattles

clean:
	rm -f hookbookBattles
	
provide:
	provide comp15 lab5 main.cpp hookbookBattles.cpp hookbookBattles.h \
		Abilities.h Abilities.cpp Makefile
