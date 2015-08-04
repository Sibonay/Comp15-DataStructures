#ifndef BOGWORDLIST_H
#define BOGWORDLIST_H

//
// A solution to boggle is a list of words.
// Each word is a sequence of letters at specific locations
// 	The locations are given as row and column,
// 	where the upper left is (0,0)
//
// a BogWordList is a struct holding a count of words
//   and a pointer to an array of words.  
//
// Each word is a struct holding a count of letters 
//   and a pointer to an array of letters
//
// Each letter is struct holding a char, the row, the col
//

#include<vector>

struct BogLett {
	char	c;
	int	row, col;
};
typedef std::vector<BogLett> BogWord;
typedef std::vector<BogWord> BogWordList;

#endif
