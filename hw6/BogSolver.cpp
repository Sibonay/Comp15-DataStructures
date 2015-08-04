#include <iostream>
#include "BogSolver.h"
#include <ctype.h> // for toupper and isalpha
#include<vector>
#include<string>
#include<stdlib.h>

using namespace std;


BogSolver::BogSolver() {
	board_rows = 0;
	board_cols = 0;
}

BogSolver::~BogSolver() {
	// nothing needed!
}

bool BogSolver::readDict() {
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

bool BogSolver::readBoard() {
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

 // search board for words in dict
bool BogSolver::solve() {
	for (int r = 0; r < board_rows; r++) {
		for (int c = 0; c < board_cols; c++) {
			BogWord prefix;
			BogLett prefix_start = board[r][c];
			solve_recurs(prefix, prefix_start);
		}
	}
	if ((int)wordlist.size() > 0) // at least one word was found
		return true;
	else
		return false; // no words found in board
}

// Recursive function that takes a bogword (the word we have formed so far by
// recursively traversing the board from a certain position), and a boglett 
// (an adjacent letter on the board).
// If it finds a valid word, adds it to two BogWordLists: one which accepts 
// duplicates, and one which does not.
// Returns if we have already checked a location on the board.
void BogSolver::solve_recurs(BogWord word, BogLett current) {
	// if we have already been to this location in this word, return
	if (already_checked(word, current))
		return;
	word.push_back(current);

	// is word valid? i.e. word is in the dictionary, longer than 2 letters
	string string_word = word_to_string(word);
	if (dict.isWord(string_word) && (int)string_word.size() > 2) { 
		list_with_duplicates.push_back(word);
		// wordlist will contain only one copy of every valid word
		if (!already_found(word)) 
			wordlist.push_back(word);
	}
	// continue solving process if current word is prefix for a word in
	// the dictionary
	if (dict.isPrefix(string_word)) {
		BogWord adj_letts = find_adj(current);

		// repeat solving process on all valid adjacent locations
		int num_adj_letts = (int)adj_letts.size();
		for (int i = 0; i < num_adj_letts; i++) {
			solve_recurs(word, adj_letts[i]);
		}
	}
}

// checks if we have already been to this location in word
bool BogSolver::already_checked(BogWord word, BogLett letter) {
	int wordLength = (int)word.size();
	for (int i = 0; i < wordLength; i++) {
		if ((word[i].row == letter.row) && (word[i].col == letter.col))
			return true;
	}
	return false;
}

// converts BogWords to strings
// handles Q (turns it into QU)
string BogSolver::word_to_string(BogWord word) {
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
BogWord BogSolver::find_adj(BogLett current) {
	BogWord adj_words; // list of valid adjacent letters
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

// checks whether word has been found before
bool BogSolver::already_found(BogWord word) {
	string found_word = word_to_string(word);

	for (int j = 0; j < (int)wordlist.size(); j++) {
		string old_word = word_to_string(wordlist[j]);
		if (found_word.compare(old_word) == 0)
			return true; // word already in list
	}
	return false;
}

// returns number of (non-duplicate) valid words in board
int  BogSolver::numWords() {
	return (int)wordlist.size();
}

// returns number of (non-duplicate) valid words in board of a certain length 
int  BogSolver::numWords(int len) {
	int num_words = 0;
	for (int i = 0; i < (int)wordlist.size(); i++) {
		// QU counts as 2 chars, but the BogWordList will be one
		// char shorter than the word length we are searching before
		// because QU is stored as Q
		if ((int)wordlist[i].size() == len -1) {
			if (containsQ(wordlist[i]))
				num_words++; // all 'QU' words
		}
		// all words which do not contain 'QU'
		if ((int)wordlist[i].size() == len && !containsQ(wordlist[i]))
			num_words++;
	}
	return num_words;
}

BogWordList* BogSolver::getWords() {
	// Note: The caller is responsible for freeing this memory
	BogWordList *list = new BogWordList;
	for (int i = 0; i < (int)wordlist.size(); i++) {
		list->push_back(wordlist[i]);
	}
	return list;
}

BogWordList* BogSolver::getWords(int len) {
	// Note: The caller is responsible for freeing this memory
	BogWordList *list = new BogWordList;

	for (int i = 0; i < (int)wordlist.size(); i++) {
		// QU counts as 2 chars, but the BogWordList will be one
		// char shorter than the word length we are searching before
		// because QU is stored as Q
		if ((int)wordlist[i].size() == len -1) {
			if (containsQ(wordlist[i])) // handles 'QU' words
				list->push_back(wordlist[i]);
		}
		// all words which do not contain 'QU'
		if ((int)wordlist[i].size() == len && !containsQ(wordlist[i]))
			list->push_back(wordlist[i]);
	}
	return list;
}

// prints all words and their coords. Includes duplicates
void BogSolver::printWords() {
	for (int i = 0; i < (int)list_with_duplicates.size(); i++) {
		print_single_word(list_with_duplicates[i]);
	}
	cout << "< >\n";
}

// prints all words of a certain length and their coords. Includes duplicates
// Note: QU counts as 2 chars
void BogSolver::printWords(int len) {
	for (int i = 0; i < (int)list_with_duplicates.size(); i++) {
		// handles QU 
		if ((int)list_with_duplicates[i].size() == len -1) {
			if (containsQ(list_with_duplicates[i]))
				print_single_word(list_with_duplicates[i]);

		}
		// handles all words which do not contain 'QU'
		if ((int)list_with_duplicates[i].size() == len
				 && !containsQ(wordlist[i])) {
			print_single_word(list_with_duplicates[i]);
		}
	}
	cout << "< >\n";
}

// prints all words (but no coords and no duplicates)
void BogSolver::listWords() {
	for (int i = 0; i < (int)wordlist.size(); i++) {
		string word = word_to_string(wordlist[i]);
		cout << word << endl;
	}
}

// prints all words of a certain length (but no words and no duplicates)
void BogSolver::listWords(int len) {
	string word;
	for (int i = 0; i < (int)wordlist.size(); i++) {
		if ((int)wordlist[i].size() == len -1) {
			if (containsQ(wordlist[i]))
				word = word_to_string(wordlist[i]);
				cout << word << endl;
		}

		if ((int)wordlist[i].size() == len && !containsQ(wordlist[i])) {
			word = word_to_string(wordlist[i]);
			cout << word << endl;
		}
	}
	//cout << "< >";
}

// prints single word and its coords
void BogSolver::print_single_word(BogWord word) {
	cout << "< ";
	for (int i = 0; i < (int)word.size(); i++) {
		if (word[i].c == 'Q') {
			cout << "QU" << " ";
		} else {
			cout << word[i].c << " ";
		}
		cout <<	word[i].row << " " <<
			word[i].col << " ";
	}
	cout << ">" << endl;
}

// checks whether BogWord contains the letter 'Q'
bool  BogSolver::containsQ(BogWord word) {
	for (int i = 0; i < (int)word.size(); i++) {
		if (word[i].c == 'Q')
			return true;
	}
	return false; // Q not in word
}


