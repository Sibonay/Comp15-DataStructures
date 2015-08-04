#include "List_linked_list.h"

#include <iostream>
#include <cassert>

using namespace std;

List_linked_list::List_linked_list()
{
	head = NULL;
}

List_linked_list::~List_linked_list()
{
	// delete list by looping through and deleting each node
	Card_Node *current = head;

	while (current != NULL) {
		head = current -> next;
		delete current;
		current = head;
	}

	head = NULL;
}

// copy constructor
List_linked_list::List_linked_list(const List_linked_list& source) {
	// explicit copy constructor necessary because of cards array
	if (source.head == NULL) return; // nothing to do

	head = new Card_Node;
	Card_Node *this_current = head;
	Card_Node *source_current = source.head;

	while (source_current != NULL) {
		// deep copy each Card_Node
		if (source_current->next != NULL) {
			Card_Node *new_node = new Card_Node();
			this_current->next = new_node;
			new_node->card = source_current->next->card;
		}
		else {
			this_current->next = NULL; // at tail
		}
		source_current = source_current->next;
		this_current = this_current->next;
	}
}

// operator= overload
List_linked_list List_linked_list::operator =(const List_linked_list&
		source) {
	// explicit operator= overload necessary because of cards array

	// check for self-assignment -- return without doing anything
	if (this == &source) {
		return *this;
	}
	// delete all current cards
	while (head != NULL) {
		Card_Node *next = head->next;
		delete head;
		head = next;
	}
	// copy over all cards from source list
	if (source.head == NULL) return *this; // nothing to do

	head = new Card_Node;
	Card_Node *this_current = head;
	Card_Node *source_current = source.head;

	while (source_current != NULL) {
		// deep copy each Card_Node
		this_current->card = source_current->card;
		if (source_current->next != NULL) {
			Card_Node *new_node = new Card_Node();
			this_current->next = new_node;
		}
		else {
			this_current->next = NULL; // at tail
		}
		source_current = source_current->next;
		this_current = this_current->next;
	}
	return *this;
}

void List_linked_list::print_list()
{
	Card_Node *current = head;
	while (current != NULL) {
		current->card.print_card();
		if (current->next != NULL) {
			cout << ",";
		}
		else {
			cout << "\n";
		}
		current = current->next;
	}
}

void List_linked_list::print_list_int()
{
	Card_Node *current = head;
	while (current != NULL) {
		current->card.print_card_int();
		if (current->next != NULL) {
			cout << ",";
		}
		else {
			cout << "\n";
		}
		current = current->next;
	}
}

// returns the number of cards in the hand
int List_linked_list::cards_in_hand()
{
	int num_cards = 0;
	Card_Node *current = head;
	while (current != NULL) { // walks list until reaches end of list
		num_cards++;
		current = current -> next;
	}
	return num_cards;
}

// empties the list by looping through and deleting each node
void List_linked_list::make_empty()
{
	Card_Node *current = head;

	while (current != NULL) {
		head = current -> next;
		delete current;
		current = head;
	}

	head = NULL;
}

// inserts a card at the head
// Should allow insert into an empty list
void List_linked_list::insert_at_head(Card c)
{
	Card_Node *new_card = new Card_Node;
	new_card -> card = c;
	new_card -> next = NULL;

	if (head == NULL) { // list is empty before insertion
		head = new_card;
	}
	else {
		new_card -> next = head;
		head = new_card;
	}
}

// inserts a card at the tail (final node)
// should allow insert into an empty list
void List_linked_list::insert_at_tail(Card c)
{
	Card_Node* new_card = new Card_Node;
	new_card -> card = c;
	new_card -> next = NULL;

	if (head == NULL) {
		head = new_card;
	}
	else {
		Card_Node *current = head;
		Card_Node *previous = NULL;
		while (current != NULL) { // walks list until reaches null ptr
			previous = current; // previous will point to the tail
			current = current -> next;
		}
		previous -> next = new_card;
	}
}

// inserts a card at an index such that
// all cards following the index will be moved farther
// down the list by one.
// The index can be one after the tail of the list
// I.e., you can insert at index 0 into an empty list,
// and you can insert at index 4 in a list with 4 nodes.
// In the first case, the node inserted would become the head
// In the second case, the node inserted would be inserted
// after the current tail.
void List_linked_list::insert_at_index(Card c, int index)
{
	if (index == 0)
		insert_at_head(c);
	else {
		Card_Node *new_card = new Card_Node;
		new_card -> card = c;
		new_card -> next = NULL;

		Card_Node *current = head;
		Card_Node *previous = NULL;
		int current_index = 0;
		// walks list until current points to node at desired index
		while (current != NULL and current_index != index) {
			previous = current;
			current = current -> next;
			current_index++;
		}
		// card is inserted in between previous and current
		previous -> next = new_card;
		new_card -> next = current;
	}
}

// replaces the card at index
// A card at index must already exist
void List_linked_list::replace_at_index(Card c, int index)
{
	Card_Node *current = head;
	int current_index = 0;
	// walks list until current points to node at desired index
	while (current != NULL and current_index != index) {
		current = current -> next;
		current_index++;
	}
	current -> card = c;
}

// returns the card at index
// allowed to crash if index is not in the list
Card List_linked_list::card_at(int index)
{
	Card_Node *current = head;
	int current_index = 0;
	// walks list until current points to node at desired index
	while (current != NULL and current_index != index) {
		current = current -> next;
		current_index++;
	}
	Card card_at_index;
	card_at_index = current -> card;
	return card_at_index;
}

// returns true if the card is in the list
// returns false if the card is not in the list
bool List_linked_list::has_card(Card c)
{
	Card_Node *current = head;
	while (current != NULL) { // walks list until reaches end of list
		if ((current -> card).same_card(c)) // or until reaches card c
			return true;
		else
			current = current -> next;
	}
	return false; // card c is not in list
}

// removes the card from the list
// Returns true if the card was removed
// Returns false if the card was not in the list
bool List_linked_list::remove(Card c)
{
	Card_Node *current = head;
	Card_Node *previous = NULL;
	while (current != NULL) {  // walks list until reaches card c
		if ((current -> card).same_card(c)){
			break;
		} else {
		previous = current;
		current = current -> next;
		}
	}

	if (current != NULL) {
		if (previous == NULL) { // card c is the first card in list
			head = current -> next;
		} else { // card c is anywhere else in list
			previous -> next = current -> next;
		}
		delete current;
		return true;
	}
	else {
		return false; // card c is not in list
	}
}


// Removes the card from the head, and assigns the head
// to head->next
// Returns the card that was removed
// Allowed to fail if list is empty
Card List_linked_list::remove_from_head()
{
	Card_Node *current = head;
	Card head_card = current -> card;

	head = current -> next;
	delete current;
	return head_card;
}

// Removes the card from the tail
// Returns the card that was removed
// Allowed to fail if the list is empty
Card List_linked_list::remove_from_tail()
{
	Card_Node *current = head;
	Card_Node *previous = NULL;

	if ((current != NULL) and ((current -> next) == NULL)) { // only one
		Card tail_card = current -> card;	         // node in list
		delete current;
		head = NULL;
		return tail_card;
	} else {
		while (current != NULL) { // walks list until reaches last node
			if ((current -> next) == NULL) {
				break;
			} else {
				previous = current;
				current = current -> next;
			}
		}
		Card tail_card = current -> card;
		delete current;
		previous -> next = NULL;
		return tail_card;
	}
}

// Removes the card from index
// Returns the card that was removed
// Allowed to fail if index is beyond the end of the list
Card List_linked_list::remove_from_index(int index) {
	if (index == 0) {
		Card card_at_index = remove_from_head();
		return card_at_index;
	}
	else {
		Card_Node *current = head;
		Card_Node *previous = NULL;

		// only one node in list
		if ((current != NULL) and ((current -> next) == NULL)) {
			Card card_at_index = current -> card;
			delete current;
			head = NULL;
			return card_at_index;
		} else {
			int current_index = 0;

			// walks list until current points to node at desired index
			while (current != NULL and current_index != index) {
				previous = current;
				current = current -> next;
				current_index++;
			}
			Card card_at_index = current -> card;
			previous -> next = current -> next;
			delete current;
			return card_at_index;
		}
	}
	Card dummy_card;   // this is to remove compiler warnings and is not
	return dummy_card; // a valid card. Will never get called due to
			   // logic above
}



