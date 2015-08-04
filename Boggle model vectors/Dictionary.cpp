//
//  Dictionary.cpp
//  Creates a Dictionary with a Dictionary
//
//

#include "Dictionary.h"
#include "Node.h"

Dictionary::Dictionary()
{
        root = new Node();
}

Dictionary::~Dictionary()
{
	postOrderRemove(root); 
}

void Dictionary::postOrderRemove(Node *node){
	// remove all children recursively
	for (int i=0;i<Node::ALPHABET_LENGTH;i++) {
		Node *child = node->findChild('A'+i);
		if (child != NULL) {
			postOrderRemove(child);
		}
	}
	// now remove this node
	delete node;
}

bool Dictionary::insert(string s)
{
        Node* tmp = root;

        for ( size_t i = 0; i < s.length(); i++ )
        {
                Node* child = tmp->findChild(s[i]);
                if ( child != NULL )
                {
                        tmp = child;
                }
                else
                {
                        Node* childNode = new Node();
                        childNode->setCharacter(s[i]);
                        tmp->appendChild(childNode);
                        tmp = childNode;
                }
                if ( i == s.length() - 1 )
                        tmp->setWordMarker();
        }
	return true;
}


bool Dictionary::isWord(string s)
{
        Node* tmp = root;

        while ( tmp != NULL )
        {
                for ( size_t i = 0; i < s.length(); i++ )
                {
                        Node* child = tmp->findChild(s[i]);
                        if ( child == NULL )
                                return false;
                        tmp = child;
                }

                if ( tmp->getWordMarker() )
                        return true;
                else
                        return false;
        }

        return false;
}

bool Dictionary::isPrefix(string s){
	// returns true if the string is a prefix in the trie
        Node* tmp = root;

        if ( tmp != NULL )
        {
                for ( size_t i = 0; i < s.length(); i++ )
                {
                        Node* child = tmp->findChild(s[i]);
                        if ( child == NULL )
                                return false;
                        tmp = child;
                }
		// made it through the string successfully
		return true;	
        }

        return false;	
}
