#ifndef BOGSOLVER_H
#define BOGSOLVER_H

#include "BogWordList.h"
#include "Dictionary.h"

//
// A class to solve boggle puzzles
//  The class reads in a dictionary and a board
//  Then solves it.
//  Once it has solved it, the solver can be
//  asked for the words it found, can be asked to print the words
//  with their locations, and to print the words just as strings
//

class BogSolver
{
    public:
	BogSolver();
	~BogSolver();
	bool readDict();
	bool readBoard();
	bool solve();			// search board for words in dict
	int  numWords();		// returns number of words found
	int  numWords(int len);		// number of words of length len
	BogWordList* getWords();	// returns all words found
	BogWordList* getWords(int len);	// returns words of len len
	void printWords();		// print all words in HBF
	void printWords(int len);	// print len-length words in HBF
	void listWords();		// print just the text, no coords
	void listWords(int len);	// just the text, no coords


   private:
	Dictionary dict;		// list of valid words in dictionary
	std::vector<std::vector<BogLett> >board; // board stored as a 2d vector
						 // of BogLetts
	BogWordList wordlist; // list with a single copy of every valid word
	BogWordList list_with_duplicates; // contains duplicates of valid words
	int board_rows, board_cols; // number of rows and cols in board

	// goes through board and finds all valid words, which are inserted 
	// into the two BogWordLists 
	void solve_recurs(BogWord word, BogLett current);
	// finds all adjacent letters on the board
	BogWord find_adj(BogLett current);
	// sees whether location on board has already been checked
	bool already_checked(BogWord word, BogLett letter);
	// converts BogWord to string
	string word_to_string(BogWord word);
	// checks whether word has been found before
	bool already_found(BogWord word);
	// prints text and coords of a single word
	void print_single_word(BogWord word);
	// checks whether a word contains the letter 'Q'
	bool containsQ(BogWord word);

};
#endif
