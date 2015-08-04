#include <iostream>
#include "BogValidator.h"
#include <ctype.h> // for toupper and isalpha
#include<vector>
#include<string>
#include<stdlib.h>


using namespace std;

BogValidator::BogValidator() { // constructor
	board_rows = 0;
	board_cols = 0;
}

BogValidator::~BogValidator() { // destructor
	// nothing needed!
}

bool BogValidator::readDict(){ // read in a dictionary
	string word;
	while (cin >> word && word != ".") {
		for (int i=0;i<(int)word.size();i++) {
			// check if words are alphabetical chars
			if (!isalpha(word[i])) {
				return false;
			}
			// convert inputted word to uppercase
			word[i] = toupper(word[i]);
		}
		dict.insert(word);
	}

	return true;
}

bool BogValidator::readBoard(){ // read in a board
	cin >> board_rows;
	cin >> board_cols;

	for (int r = 0; r < board_rows; r++) {
		vector <BogLett> row;
		for (int c = 0; c < board_cols; c++) {
			BogLett letter;
			cin >> letter.c;
			// check if board has correct dimensions
			if (cin.eof()) exit(-1);			
			// check if letter is alphabetical character
			if (!isalpha(letter.c)) return false;
			// convert inputted letter to uppercase
			letter.c = toupper(letter.c);
			// note: rows and cols are zero-indexed
			letter.row = r;
			letter.col = c;
			row.push_back(letter);
		}
		board.push_back(row);
	}
	return true;
}

bool BogValidator::isValid(std::string s){ // validates one word
	// if word has already been found, will not be valid the second time
	if (validWords.isWord(s))
	    return false;
	
	if (dict.isWord(s)) {
		for (int r = 0; r < board_rows; r++) {
			for (int c = 0; c < board_cols; c++) {
				BogWord prefix;
				BogLett prefix_start = board[r][c];
				if (prefix_start.c == s[0]) {
					bool valid = solve_recurs( 
						       prefix, prefix_start, s);
					if (valid) {
					    validWords.insert(s);
					    return true;
					}
				}
			}
		}
		return false; // word not in board
	} else // word is not in dict so cannot be valid even if is in board
		return false;
}

// Recursive function that takes a bogword (the word we have formed so far by
// recursively traversing the board from a certain position), a boglett (an 
// adjacent letter on the board), and a query (the string we want to validate).
// Returns true if the query is valid (word is in board and is correct length).
// Returns false if query is not found or if we have already checked a certain
// location.
bool BogValidator::solve_recurs(BogWord word, BogLett current, string query) {
	// if we have already been to this location in this word, return false
	if (already_checked(word, current)) 
		return false;
	else word.push_back(current); 

	string string_word = word_to_string(word);
	if (string_word.compare(query) == 0) { // strings are identical
		if ((int)string_word.size() < 3) return false;// word too short
		else return true; // word user inputted is in boggle board
	}
	// continue solving process if current word is prefix for a word in
	// the dictionary
	if (isPrefix(string_word, query)) {
		BogWord adj_letts = find_adj(current);

		// repeat solving process on all valid adjacent locations
		int num_adj_letts = (int)adj_letts.size();
		for (int i = 0; i < num_adj_letts; i++) {
			 if (solve_recurs(word, adj_letts[i], query)) {
				 return true;
			 }
		}
	}
	return false;
}

// checks whether string_word is a prefix of query
bool BogValidator::isPrefix(string string_word, string query) {
	for (int i = 0; i < (int)string_word.size(); i++) {
		if (string_word[i] != query[i])
			return false;
	}
	return true; // have reached end of string_word and all characters are
		     // the same for the start of query
}


// checks if we have already been to this location in word
bool BogValidator::already_checked(BogWord word, BogLett letter) {
	int wordLength = (int)word.size();
	for (int i = 0; i < wordLength; i++) {
		if ((word[i].row == letter.row) && (word[i].col == letter.col))
			return true;
	}
	return false;
}

// converts BogWords to strings that it then returns
// handles Q (turns it into QU)
string BogValidator::word_to_string(BogWord word) {
	int wordLength = (int)word.size();
	string string_word;
	for (int i = 0; i < wordLength; i++) {
		if (word[i].c == 'Q') {
			string_word += "QU";
		} else {
			string_word += word[i].c;
		}
	}
	return string_word;
}

// returns a BogWord of all valid adjacent letters in board
BogWord BogValidator::find_adj(BogLett current) {
	BogWord adj_words;
	BogLett left, right, above, below, leftupdiag, leftdowndiag,
		rightupdiag, rightdowndiag; // all possible adjacent letters

	left.col = current.col - 1;
	left.row = current.row;
	// if location is valid (not outside of board's bounds)
	// only col is changing, so don't need to check row
	if ((left.col >= 0) and (left.col < board_cols)) {
		left.c = board[left.row][left.col].c;
		adj_words.push_back(left);
	}

	right.col = current.col + 1;
	right.row = current.row;
	if ((right.col >= 0) and (right.col < board_cols)) {
		right.c = board[right.row][right.col].c;
		adj_words.push_back(right);
	}

	above.col = current.col;
	above.row = current.row - 1;
	// only row is changing, so don't need to check col
	if ((above.row >= 0) and (above.row < board_rows)) {
		above.c = board[above.row][above.col].c;
		adj_words.push_back(above);
	}

	below.col = current.col;
	below.row = current.row + 1;
	if ((below.row >= 0) and (below.row < board_rows)) {
		below.c = board[below.row][below.col].c;
		adj_words.push_back(below);
	}

	leftupdiag.col = current.col - 1;
	leftupdiag.row = current.row - 1;
	if ((leftupdiag.col >= 0) and (leftupdiag.col < board_cols) and
	     (leftupdiag.row >= 0) and (leftupdiag.row < board_rows)) {
		leftupdiag.c = board[leftupdiag.row][leftupdiag.col].c;
		adj_words.push_back(leftupdiag);
	}

	leftdowndiag.col = current.col - 1;
	leftdowndiag.row = current.row + 1;
	if ((leftdowndiag.col >= 0) and (leftdowndiag.col < board_cols) and
	     (leftdowndiag.row >= 0) and (leftdowndiag.row < board_rows)) {
		leftdowndiag.c = board[leftdowndiag.row][left.col].c;
		adj_words.push_back(leftdowndiag);
	}

	rightupdiag.col = current.col + 1;
	rightupdiag.row = current.row - 1;
	if ((rightupdiag.col >= 0) and (rightupdiag.col < board_cols) and
	     (rightupdiag.row >= 0) and (rightupdiag.row < board_rows)) {
		rightupdiag.c = board[rightupdiag.row][rightupdiag.col].c;
		adj_words.push_back(rightupdiag);
	}

	rightdowndiag.col = current.col + 1;
	rightdowndiag.row = current.row + 1;
	if ((rightdowndiag.col >= 0) and (rightdowndiag.col < board_cols) and
	     (rightdowndiag.row >= 0) and (rightdowndiag.row < board_rows)) {
		rightdowndiag.c = board[rightdowndiag.row][rightdowndiag.col].c;
		adj_words.push_back(rightdowndiag);
	}

	return adj_words;
}

// prints whether word is valid or invalid 
void BogValidator::checkWords(){
	string word;
	while (cin >> word) {
		if (isValid(word))
			cout << "OK " << word << endl;
		else // word is invalid
			cout << "NO " << word << endl;
	}
}


