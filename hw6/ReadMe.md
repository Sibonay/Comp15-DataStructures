# ReadMe for COMP 15 HW6
## Boggle Assignment
## Sibonay Koo

1.  Purpose of program:
    - to simulate the game "Boggle"
    - this program solves the board, checks user answers, and then scores those answers

2.  List of files:
    - BogSolver.h  ~  header file for BogSolver class
    - BogSolver.cpp  ~  function definitions for BogSolver class
    - solverMain.cpp  ~  main file for BogSolver class 
    - BogChecker.h  ~  header file for BogChecker class
    - BogChecker.cpp  ~  function definitions for BogChecker class
    - checkerMain.cpp  ~  main file for BogChecker class 
    - BogScorer.h  ~  header file for BogScorer class
    - BogScorer.cpp  ~  function definitions for BogScorer class
    - scorerMain.cpp  ~  main file for BogSolver class 
    - Dictionary.h  ~  header file for Dictionary class
    - Dictionary.cpp  ~  function definitions for Dictionary class
    - Node.h  ~  header file for Node class
    - Node.cpp  ~  function definitions for Node class
    - Makefile  ~  compiling instructions

3.  How to compile program:
    - use included Makefile

4.  Outline of data structures:
    - the words are stored in BogWordLists, which are vectors of BogLetts
	- a BogLett is a struct that contains a character and two ints (the location of the char
	  on the board)
    - the board is a 2D vector of BogLetts 
    - the dictionary is implemented using Tries 

5.  Outline of BogSolver algorithm for the solve function:
    - For every letter in the board, we call a recursive function which:
	- recurses through that location, taking the BogLett at that location and the BogWord we have
	  formed so far
	- if we have not already been at this location, we add the BogLett there to our current BogWord
	- if our BogWord is defined in the dictionary, we add it to our BogWordLists
	- if the BogWord is also a prefix for another word in the dictionary, we recurse (so the function
	  is called on this prefix BogWord and each of its neighbouring BogLetts)

6. Outline of the BogChecker algorithm for the isValid function:
    - For every letter in the board that is the first letter of the word we are checking for, we call a 
      recursive function which:
	- recurses through that location, taking the BogLett at that location and the BogWord we have
	  formed so far
	- if we have not already been at this location, we add the BogLett there to our current BogWord
	- if our BogWord is the word we are looking for and the word is a valid size, we return true 
	- if the BogWord is also a prefix for the word we are searching for, we recurse (so the function
	  is called on this prefix BogWord and each of its neighbouring BogLetts)

7. OutLine of the BogScorer algorithm:
    - For all words, program reads in the status (OK or NO) of a word and then the word itself
    - If the status is OK (i.e. word is valid), it scores the word:
	- 3 or 4 letters = 1 point
	- 5 letters = 2 points
	- 6 letters = 3 points
	- 7 letters = 5 points
	- 8 letters = 11 points
    - It then prints the status/points for each word as well as the total score and number of words found

8. I discussed ideas with Jeremy Colebrook-Soucie
