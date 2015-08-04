#
# Makefile for List_dynamic_array
#
CXX = clang++
FLAGS =  -g -Wall 

cards_dynamic_array: List_dynamic_array.cpp List_dynamic_array.h \
     card.h card.cpp hand.h hand.cpp main.cpp
	${CXX} ${FLAGS} -o hw1 List_dynamic_array.cpp main.cpp \
	        hand.cpp card.cpp
clean:
	rm -f hw1

provide:
	provide comp15 hw1 main.cpp List_dynamic_array.cpp List_dynamic_array.h \
	        hand.cpp hand.h card.cpp card.h \
	        ReadMe.md Makefile

