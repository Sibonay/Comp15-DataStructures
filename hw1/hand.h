#ifndef __hand_h__
#define __hand_h__

#include "card.h"
#include "List_dynamic_array.h"

class Hand {
public:
	Hand(); // constructor
	~Hand(); // desctructor
	void order_hand();
	void print_hand(){ hand.print_list(); }
	void print_hand_int() { hand.print_list_int(); }
	void add_card(Card c); // adds card to the end of the hand
	
	bool remove_card(Card c); // returns true if the card was successfully
				  // removed, false otherwise
	void shuffle(); // randomly shuffles the hand
	Card deal_card_from_top(Hand &h); // deals a card from the top of the 
					  // hand (the last card)
	Card deal_card_from_bottom(Hand &h); // deals a card from the bottom of 
					     // the hand (the first card)

	bool has_card(Card c); // returns true if the hand contains the card
	void create_deck(); // creates a standard 52-card deck
	void read_deck(); // reads a deck from standard input
	int cards_in_hand() { return hand.cards_in_hand(); }
	
private:
	List_dynamic_array hand;
};

#endif // __hand_h__
