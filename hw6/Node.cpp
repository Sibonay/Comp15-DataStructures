//
//  Node.cpp
//  Provides the Node class for a trie
//
//

#include "Node.h"

Node::Node() {
	theCharacter = ' ';
	wordMarker = false;
	for (int i=0;i<ALPHABET_LENGTH;i++) children[i]=NULL;
}

Node* Node::findChild(char c){
	if (children[c-'A'] != NULL) {
		return children[c-'A'];
	}
	else {
		return NULL;
	}
}

void Node::appendChild(Node* child) {
	children[child->theCharacter - 'A'] = child;
}

void Node::printNode(int level){
        cout << level << "," << theCharacter << "," << wordMarker << endl;
        for (int i=0; i< ALPHABET_LENGTH; i++) {
                Node *tmp = children[i];
                if (tmp != NULL) {
                	tmp->printNode(level+1);
                }
        }
}

size_t Node::addPreNodes(vector <preNode> preNodes,int level,size_t index) {
	while (index != preNodes.size()) { // base case
		preNode pn = preNodes[index];
		//cout << level << "," << pn.level << "," << pn.c << "," << pn.wordMarker << "\n";
		if (pn.level <= level) return index; // next sibling
		// we have a child to add
		Node *tmp = new Node();
		tmp->setCharacter(pn.c);
		if (pn.wordMarker) tmp->setWordMarker();
		appendChild(tmp);
		index = tmp->addPreNodes(preNodes,pn.level,index+1);
	}
	return index;
}
