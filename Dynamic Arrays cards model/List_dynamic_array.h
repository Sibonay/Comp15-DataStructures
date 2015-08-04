// List_dynamic_array.h
// The List_dynamic_array header

// Purpose: create a list using a dynamic array that grows as needed.
//          The list is comprised of an array of Cards, which can be
//          inserted, removed, and replaced in a number of different
//          ways.
//          The "head" of the list is the beginning of the array
//          The "tail" of the list is the end of the array


#ifndef List_dynamic_array_h
#define List_dynamic_array_h

#include "card.h" // the definition of a Card

#define INITIAL_CAPACITY 10 // the initial size of our list.

class List_dynamic_array
{
public:
	List_dynamic_array(); // constructor
	// copy constructor
	List_dynamic_array(const List_dynamic_array& source);

	// operator= overload
	List_dynamic_array operator =(const List_dynamic_array& source);

	~List_dynamic_array(); // destructor
	
	void print_list(); // prints the list in human-readable form
	void print_list_int(); // prints the list as integers based
				// on rank and suit
	bool is_empty() { return cards_held==0; }
	void make_empty() { cards_held = 0; } // makes the list empty
	 
	void insert_at_head(Card c); // inserts at the beginning of the list
	void insert_at_tail(Card c); // inserts at the end of the list
	void insert_at_index(Card c, int index); // inserts at an index
	void replace_at_index(Card c, int index); // replaces the card
						// at an index
	Card card_at(int index); // returns the card at the index
	
	bool has_card(Card c); // returns true if the card is in the list
	
	bool remove(Card c); // removes the card
	Card remove_from_head(); // removes the beginning card
	Card remove_from_tail(); // removes the last card
	Card remove_from_index(int index); // removes the card at index
	
	int cards_in_hand() { return cards_held; }
	
private:
	void expand(); // expand the list when necessary
	Card *cards; // the array of cards
	int cards_held; // how many cards are currently in the hand
	int hand_capacity; // the capacity of the array that holds the cards
};

#endif // List_dynamic_array_h
