#include <iostream>
#include <cstdlib>
#include <time.h>


#include "hand.h"

#define SEED_RANDOM false

int main(int argc, char **argv)
{
	if (SEED_RANDOM) srand(time(NULL));
	Hand deck, hand1, hand2;
	
	deck.create_deck();
	deck.print_hand();

	Card c;
	c.set_suit(HEART);
	c.set_rank(THREE);

	//deck.remove_card(c);

	deck.shuffle();
	deck.print_hand_int();

	for (int i=0;i<5;i++) {
		deck.deal_card_from_top(hand1);
		deck.deal_card_from_top(hand2);
	}
	hand1.order_hand();
	hand2.order_hand();
	deck.print_hand();
	hand1.print_hand();
	hand2.print_hand();
	
	return 0;
}
