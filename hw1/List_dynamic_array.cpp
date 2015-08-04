#include "List_dynamic_array.h"

#include <iostream>
#include <cassert>

using namespace std;

List_dynamic_array::List_dynamic_array()
{
	const int CAPACITY = 10;
        cards = new Card[CAPACITY];
	hand_capacity = CAPACITY;
        cards_held = 0;
}

List_dynamic_array::~List_dynamic_array()
{
        delete[] cards;
}

// copy constructor
List_dynamic_array::List_dynamic_array(const List_dynamic_array& source) {
	// explicit copy constructor necessary because of cards array
	cards_held = source.cards_held;
	hand_capacity = source.hand_capacity;

	cards = new Card[hand_capacity];
	for (int i=0;i<cards_held;i++) {
		cards[i] = source.cards[i];
	}
}

// operator= overload
List_dynamic_array List_dynamic_array::operator =(const List_dynamic_array&
		source) {
	// explicit operator= overload necessary because of cards array
	Card *new_cards;

	// check for self-assignment -- return without doing anything
	if (this == &source) {
		return *this;
	}

	hand_capacity = source.hand_capacity;
	cards_held = source.cards_held;
	new_cards = new Card[hand_capacity];
	for (int i=0;i<hand_capacity;i++) {
		new_cards[i]=source.cards[i];
	}
	delete [ ] cards;
	cards = new_cards;
	return *this;
}

void List_dynamic_array::print_list()
{
	for(int i=0; i<cards_held; i++) {
		cards[i].print_card();
		if (i != cards_held-1) {
			cout << ",";
		} else {
			cout << "\n";
		}
	}
}

void List_dynamic_array::print_list_int()
{
	for(int i=0; i<cards_held; i++) {
		cards[i].print_card_int();
		if (i != cards_held-1) {
			cout << ", ";
		} else {
			cout << "\n";
		}
	}
}

void List_dynamic_array::insert_at_head(Card c)
{
	// check if we need to expand, and expand if necessary
	if (cards_held == hand_capacity) 
		expand();
	// no need to move items over if list is currently empty
	if (cards_held == 0) {
		cards[0] = c; 
	// move all items over one, starting from the last one
	} else {
		for (int i = cards_held - 1; i >= 0; i--) {  
			cards[i + 1] = cards[i];
		}
		// insert the new card
		cards[0] = c;
	}
	cards_held = cards_held + 1; 
}

void List_dynamic_array::insert_at_tail(Card c)
{
	// check if we need to expand, and expand if necessary
	if (cards_held == hand_capacity) 
		expand();
	// insert the new card at the end
	cards[cards_held] = c;
	cards_held = cards_held + 1;
}

void List_dynamic_array::insert_at_index(Card c,int index)
{
	// if index is greater than cards_held, then fail
	assert(index <= cards_held);

	// check if we need to expand, and expand if necessary
	if (cards_held == hand_capacity) 
		expand();	
	// move all elements past the insertion point up one
	for (int i = cards_held - 1; i >= index; i--) {  
		cards[i + 1] = cards[i];
	}
	// insert the card
	cards[index] = c;
	cards_held = cards_held + 1;
}

void List_dynamic_array::replace_at_index(Card c, int index) {
	// if index is greater than cards_held-1, then fail
	assert(index < cards_held);
	
	// replace the card at index with c
	cards[index] = c;
}

Card List_dynamic_array::card_at(int index)
{
	// if index is out of bounds, fail
	assert (index >= 0 && index < cards_held);
	
	// return the card at index
	return cards[index];
}

bool List_dynamic_array::has_card(Card c) {
        // loop through the cards and use the same_card()
	for (int i = 0; i < cards_held; i++) {
		if (cards[i].get_rank() == c.get_rank() && 
		cards[i].get_suit() == c.get_suit())
			    return true;
	}
	return false;
}

bool List_dynamic_array::remove(Card c)
{
	// find the card and remove from the hand
	for (int i = 0; i < cards_held; i++) {
	// Returns true if the card was found and removed,
		if (has_card(c) == true) {
			// removes card and moves items over 
			for (int j = i; j < cards_held - 1; j++) {
				cards[j] = cards[j + 1];
			}
			cards_held = cards_held - 1;
			return true;
		} 
	}
	return false;
}

Card List_dynamic_array::remove_from_head()
{
	// if the list is empty, fail
	assert(cards_held > 0);

	Card removed_card = cards[0];
	for (int i = 0; i < cards_held - 1; i++) {
		cards[i] = cards[i + 1];
	}
	cards_held = cards_held - 1;
	return removed_card;

}

Card List_dynamic_array::remove_from_tail()
{
	// if the list is empty, fail
	assert(cards_held > 0);

	// removes the card that is at the tail, and returns it
	Card removed_card = cards[cards_held - 1];
	cards_held = cards_held - 1;
	return removed_card;
}

Card List_dynamic_array::remove_from_index(int index)
{
	// if the list is empty, fail
	assert(cards_held > 0);
	
	// if loc is outside of bounds, fail
	assert(index >= 0 && index < cards_held);

	Card removed_card = cards[index];
	for (int i = index; i < cards_held - 1; i++) {
		cards[i] = cards[i + 1];
	}
	cards_held = cards_held - 1;
	return removed_card;	
}

void List_dynamic_array::expand()
{
	Card *temp = new Card[hand_capacity * 2];
	for (int i = 0; i < hand_capacity; i++) {
		temp[i] = cards[i];
	}
	delete[] cards;
	cards = temp;
	hand_capacity = hand_capacity * 2;
}
