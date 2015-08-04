/*
 * BinarySearchTree.cpp
 */

#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

BinarySearchTree::BinarySearchTree() {
	root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
	// walk tree in post-order traversal and delete
	post_order_delete(root);
}

void BinarySearchTree::post_order_delete(Node *node) {
	if (node != NULL) {
		post_order_delete(node -> left);     
		post_order_delete(node -> right);
		// delete operator will only be called when we reach a leaf
		delete node; 
	}
}

// copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source) {
	// pre-order traversal to copy the tree
	root = pre_order_copy(source.root);
}

// assignment overload
BinarySearchTree& BinarySearchTree::operator=
		(const BinarySearchTree &source) {
	// check for self-assignment
	if (this == &source) {
		return *this;
	}
	else {
	// delete current tree if it exists
		post_order_delete(root); 
	// use pre-order traversal to copy the tree
		root = pre_order_copy(source.root);
	}

	// return the object we just copied into
	return *this; 
}
	
// pre-order traversal to copy source tree
// takes and returns individual node pointers that make up the tree 
Node * BinarySearchTree::pre_order_copy(Node *node) {
	if (node == NULL) return NULL; // nothing to do
	    
	Node *new_node = new Node();
	new_node->data = node->data;
	new_node->count = node->count;
	
	new_node->left = pre_order_copy(node->left);
	new_node->right = pre_order_copy(node->right);
	return new_node;
}

int BinarySearchTree::find_min() {
	if (root == NULL) return INT_MIN;
	return find_min(root)->data;
}

// assumes the node pointer passed into this function is the root
Node *BinarySearchTree::find_min(Node *node) {
	if (node->left == NULL) 
		return node;  
	
	return find_min(node->left); 
}

// assumes the node pointer passed into this function is the root
int BinarySearchTree::find_max() {
	if (root == NULL) return INT_MAX; 
	return find_max(root)->data;
}

Node *BinarySearchTree::find_max(Node *node) {
	if (node->right == NULL) // we have reached the min value
	    return node; 
	
	
	return find_max(node->right); 
}

bool BinarySearchTree::contains(int value) {
	return contains(root, value);
}

bool BinarySearchTree::contains(Node *node, int value) {
	if (node == NULL) return false; // either tree is empty, or has
					// reached leaf without finding value
	if (node->data == value) 
	    return true;
	
	if (node->data > value) // if value occurs, must be in left subtree
		return contains(node->left, value); 
	else //if value occurs, must be in right subtree
		return contains(node->right, value);
}

void BinarySearchTree::insert(int value) {
	insert(root,NULL,value);
}

void BinarySearchTree::insert(Node *node,Node *parent, int value) {
	if (node == NULL) {  // value is not already in tree 
		Node *newNode = new Node; 
		newNode->data = value;
		newNode->count = 1;
		newNode->right = NULL; // new node is a leaf or root, so right 
		newNode->left = NULL;  // and left pointers must be NULL
		
		if (parent == NULL) { // empty tree, so insert at root
			root = newNode;
		} else { // tree is not empty - new node will be a leaf
		        // if value is greater than parent's data, insert right
			if (value > parent->data)
				parent->right = newNode; 
			// value is smaller than parent's data, so insert left 
			else  
				parent->left = newNode; 
		}
		return;
	}
	
	if (node->data == value) // value already in tree, so count incremented
		node->count += 1;
	else if (value < node->data)  // value must be in left subtree
		insert(node->left, node, value); 
	else // value must be in right subtree
		insert(node->right, node, value);
}

bool BinarySearchTree::remove(int value) {
	return remove(root,NULL,value);
}

bool BinarySearchTree::remove(Node *node, Node *parent, int value) {
	// tree is empty, nothing to do
	if (node == NULL)
		return false; // node was not removed
	if (contains(value) == false) // value does not exist in tree
		return false;

	if (node->data == value) { // this is node to be removed
		// node's count is greater than 1 therefore count is
		// decremented but node is not removed
		if (node->count > 1) {
			node->count -= 1;
			return true;
		}
		// node's count is 1 so node will be removed 
		// if node to be removed is the root, parent pointer not changed
		else {
			// node to be removed has no children (is a leaf)
			if ((node->left == NULL) and (node->right == NULL)) { 
				if (parent != NULL) { // node is not the root
					if (parent->right == node)
						parent->right = NULL;
					if (parent->left == node)
						parent->left = NULL;
				} else // node is the root
					root = NULL;
				delete node;
				return true;
			}
			
			// if node to be removed has one child
			// node is cut from tree and single child (with subtree 
			// ) is linked directly to parent of removed node
			
			// node has a right child
			if ((node->left == NULL) and (node->right != NULL)) {
				if (parent != NULL) { // node not the root
					if (parent->right == node)
						parent->right = node->right;
					if (parent->left == node)
						parent->left = node->right;
				}
				else  // node is the root
					root = node->right;
				delete node;
				return true;
			}
			// node has a left child
			if ((node->right == NULL) and (node->left != NULL)) { 
				//if (parent != NULL) { // node not the root
					if (parent->right == node)
						parent->right = node->left;
					if (parent->left == node)
						parent->left = node->left;
				//} else // node is the root
					//root = node->left;
				delete node;
				return true; 
			}
			
			// node to be removed has two children
			if ((node->left != NULL) and (node->right != NULL)) {
				// min in right subtree of node to be removed
				Node *right_min = find_min(node->right); 
				node->data = right_min->data;
				node->count = right_min->count;

				// want to remove node completely, not just
				// decrement its count. Therefore set count to 1
				right_min->count = 1;
				return remove(node->right, node,
						right_min->data);
			}
		}
	}
	if (value < node->data) { // go left
		return remove(node->left, node, value);
	}
	else if (value > node->data) { // go right
		return remove(node->right, node, value);
	}
	return false; // node isn't contained
}

int BinarySearchTree::tree_height() {
	return tree_height(root);
}

int BinarySearchTree::tree_height(Node *node) {
	if (node == NULL) // tree is empty so height is -1
	    return -1;
	else {
		int left_height = tree_height(node->left);
		int right_height = tree_height(node->right);
		
		// returns the largest depth i.e. either left_height or 
		// right_height, depending on which one is greater.
		// +1 necessary to increment the count of left_height and 
		// right_height each time function is recursively called
		return 1 + std::max(left_height, right_height);
	}
}

// returns the total number of nodes
int BinarySearchTree::node_count() {
	return node_count(root);
}

int BinarySearchTree::node_count(Node *node) {
	if (node == NULL) // tree is empty
		return 0;
	else {
		int num_nodes = 1;
		// adds number of nodes in left subtree
		num_nodes += node_count(node->left);
		// adds number of nodes in right subtree
		num_nodes += node_count(node->right);
		
		return num_nodes;
	}
}

// return the sum of all the node values (including duplicates)
int BinarySearchTree::count_total() {
	return count_total(root);
}

int BinarySearchTree::count_total(Node *node) {
	if (node == NULL) // tree is empty
		return 0;
	else {
		int total = ((node->data) * (node->count)); 
		total += count_total(node->left); // count for left subtree
		total += count_total(node->right); // count for right subtree
		
		return total;
	}
}

// use the printPretty helper to make the tree look nice
void BinarySearchTree::print_tree() {
	printPretty(root, 1, 0, std::cout);
}

Node *BinarySearchTree::find_parent(Node *node,Node *child) {
	if (node==NULL) return NULL;

	// if either the left or right is equal to the child,
	// we have found the parent
	if (node->left==child || node->right == child) {
		return node;
	}

	// Use the binary search tree invariant to walk the tree
	if (child->data > node->data) {
		return find_parent(node->right,child);
	}
	else {
		return find_parent(node->left,child);
	}
}
