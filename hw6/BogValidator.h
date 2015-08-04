#ifndef BOGVALIDATOR_H
#define BOGVALIDATOR_H

#include "Dictionary.h"
#include "BogWordList.h"


class BogValidator
{
public:
	BogValidator(); // constructor
	~BogValidator(); // destructor
	bool readDict(); // read in a dictionary
	bool readBoard(); // read in a board
	bool isValid(std::string s); // validates one word
	void checkWords(); // validates cin. The end of input will
			   // simply return NULL to cin.
private:
	Dictionary dict; // must use a Dictionary
	Dictionary validWords; // words which have already been marked as valid
	std::vector<std::vector<BogLett> >board; // board stored as a 2d vector
						 // of BogLetts
	int board_rows, board_cols; // number of rows and cols in board

	// checks whether user's inputted word is in board and is valid size
	bool solve_recurs(BogWord word, BogLett current, string query); 
	// finds all adjacent letters on the board
	BogWord find_adj(BogLett current); 
	// sees whether location on board has already been checked
	bool already_checked(BogWord word, BogLett letter); 
	// converts BogWord to string
	string word_to_string(BogWord word); 
	// checks whether query is a prefix of string_word
	bool isPrefix(string string_word, string query); 
};

#endif

