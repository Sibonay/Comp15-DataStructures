#
# Makefile for Boggle, hw6
#
CXX = clang++
FLAGS = -O0 -Wall -Wextra -g

all: scorerMain.cpp solverMain.cpp checkerMain.cpp \
	BogScorer.cpp BogScorer.h \
	BogSolver.cpp BogSolver.h \
	BogValidator.cpp BogValidator.h \
	Dictionary.h Dictionary.cpp Node.h Node.cpp \

	${CXX} ${FLAGS} -o bbscorer BogScorer.cpp scorerMain.cpp
	${CXX} ${FLAGS} -o bbsolver BogSolver.cpp solverMain.cpp \
				Dictionary.cpp Node.cpp 
	${CXX} ${FLAGS} -o bbchecker BogValidator.cpp checkerMain.cpp \
				Dictionary.cpp Node.cpp

bbscorer: scorerMain.cpp BogScorer.cpp BogScorer.h 
	${CXX} ${FLAGS} -o bbscorer BogScorer.cpp scorerMain.cpp
	
bbsolver: solverMain.cpp BogSolver.cpp BogSolver.h
	${CXX} ${FLAGS} -o bbsolver BogSolver.cpp solverMain.cpp \
				Dictionary.cpp Node.cpp
	
bbchecker: checkerMain.cpp BogValidator.cpp BogValidator.h
	${CXX} ${FLAGS} -o bbchecker BogValidator.cpp checkerMain.cpp \
			Dictionary.cpp Node.cpp
		
clean:
	rm -f bbscorer bbsolver bbchecker 

make provide:
	provide comp15 hw6 scorerMain.cpp solverMain.cpp checkerMain.cpp \
		BogScorer.cpp BogScorer.h \
		BogSolver.cpp BogSolver.h \
		BogValidator.cpp BogValidator.h \
		Dictionary.h Dictionary.cpp Node.h Node.cpp \
		BogWordList.h \
	        ReadMe.md Makefile

