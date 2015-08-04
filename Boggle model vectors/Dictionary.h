#ifndef	DICT_H
#define	DICT_H

/*
 * Dictionary interface
 *     purpose: store words
 *   functions: see public functions
 *        uses: Node class to build the trie
 */

#include	<iostream>
#include	<string>
#include	"Node.h"

class Dictionary
{
	public:
		Dictionary();			// create/init one
		~Dictionary();			// create/init one
		bool insert(std::string);	// rets: false if fails
		bool isPrefix(std::string);	 
		bool isWord(string);

	private:
		void postOrderRemove(Node *node);
		Node *root;
};

#endif
