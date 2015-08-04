// Test: tests the replace_at_index() method
/*
 * main4.cpp
 *
 *  Created on: Aug 27, 2014
 *      Author: chrisgregg
 */
/*#include <iostream>
#include <cstdlib>
#include <time.h>

#include "hand.h"

using namespace std;

int main() {
	List_dynamic_array da;

	Card c('A','D');

	da.insert_at_index(c,0);
	da.print_list(); // should print AD

	c.set_suit(HEART);
	c.set_rank(TEN);
	da.replace_at_index(c,0);
	da.print_list(); // should print TH

	c.set_suit(SPADE);
	c.set_rank(FIVE);
	da.insert_at_index(c,0);
	da.print_list(); // should print 5S, TH

	c.set_suit(CLUB);
	c.set_rank(TWO);
	da.insert_at_index(c,0); // should print 2C, 5S, TH
	da.print_list();

	c.set_rank(NINE);
	da.replace_at_index(c,2); // should print 2C, 5S, 9C
	da.print_list();

	c.set_suit(HEART);
	c.set_rank(FOUR);
	da.replace_at_index(c,1); // should print 2C, 4H, 9C
	da.print_list();

	return 0;
}*/

// Test: tests the card_at() method
/*
 * main5.cpp
 *
 *  Created on: Aug 27, 2014
 *      Author: chrisgregg
 */
/*#include <iostream>
#include <cstdlib>
#include <time.h>

#include "hand.h"

using namespace std;

int main() {
	List_dynamic_array da;

	Card c('A','D');

	da.insert_at_index(c,0);

	c.set_suit(HEART);
	c.set_rank(TEN);
	da.insert_at_index(c,0);

	c.set_suit(SPADE);
	c.set_rank(FIVE);
	da.insert_at_index(c,0);

	c.set_suit(CLUB);
	c.set_rank(TWO);
	da.insert_at_index(c,0);

	c.set_rank(NINE);
	da.insert_at_index(c,0);

	c.set_suit(HEART);
	c.set_rank(FOUR);
	da.insert_at_index(c,0);
	da.print_list(); // should print 4H,9C,2C,5S,TH,AD

	// following prints list a second time, but with spaces after commas
	da.card_at(0).print_card();
	cout << ", ";

	da.card_at(1).print_card();
	cout << ", ";

	da.card_at(2).print_card();
	cout << ", ";

	da.card_at(3).print_card();
	cout << ", ";

	da.card_at(4).print_card();
	cout << ", ";

	da.card_at(5).print_card();
	cout << "\n";

	return 0;
}*/

// Test: tests the insert_at_tail() method
/*#include <iostream>
#include <cstdlib>
#include <time.h>

#include "hand.h"

using namespace std;

int main() {
	 List_dynamic_array test_list;
	 Card card1('A','D'); // ace of diamonds
	 Card card2('5','S'); // five of spades
	 Card card3('8','C'); // eight of clubs

	 test_list.print_list(); // should be blank

	 test_list.insert_at_tail(card1); // insert a card
	 test_list.print_list(); // should print the Ace of Diamonds (AD)

	 test_list.insert_at_tail(card2); // insert another card
	 test_list.print_list(); // should print AD,5S

	 test_list.insert_at_tail(card3); // insert another card
	 test_list.print_list(); // should print AD,5S,8C
}*/

// Test: tests the insert_at_head() method
/*#include <iostream>
#include <cstdlib>
#include <time.h>

#include "hand.h"

using namespace std;

int main() {
	 List_dynamic_array test_list;
	 Card card1('A','D'); // ace of diamonds
	 Card card2('5','S'); // five of spades
	 Card card3('8','C'); // eight of clubs

	 test_list.print_list(); // should be blank

	 test_list.insert_at_head(card1); // insert a card
	 test_list.print_list(); // should print the Ace of Diamonds (AD)

	 test_list.insert_at_head(card2); // insert another card
	 test_list.print_list(); // should print 5S, AD

	 test_list.insert_at_head(card3); // insert another card
	 test_list.print_list(); // should print 8C, 5S, AD
}*/

// Test: tests the has_card() method
/*#include <iostream>
#include <cstdlib>
#include <time.h>

#include "hand.h"

using namespace std;

int main() {
	 List_dynamic_array test_list;
	 Card card1('A','D'); // ace of diamonds
	 Card card2('5','S'); // five of spades
	 Card card3('8','C'); // eight of clubs

	 test_list.insert_at_head(card1); // insert a card
	 test_list.insert_at_head(card2); // insert another card

	 if (test_list.has_card(card2))
		 cout << "card 2 is in hand \n";
	 else
		 cout << "card 2 not in hand \n";
	 if (test_list.has_card(card3))
		 cout << "card 3 in hand \n";
	 else
		 cout << "card 3 not in hand \n";
}*/

// Test: tests the remove() method
/*#include <iostream>
#include <cstdlib>
#include <time.h>

#include "hand.h"

using namespace std;

int main() {
	 List_dynamic_array test_list;
	 Card card1('A','D'); // ace of diamonds
	 Card card2('5','S'); // five of spades
	 Card card3('8','C'); // eight of clubs

	 test_list.insert_at_head(card1); // insert a card
	 test_list.insert_at_head(card2); // insert another card
	 test_list.insert_at_head(card3); // insert another card
	 test_list.print_list(); // should print 8C, 5S, AD

	 test_list.remove(card2);
	 test_list.print_list(); // should print 8C, AD
}*/

// Test: tests the remove_at_head() method
/*#include <iostream>
#include <cstdlib>
#include <time.h>

#include "hand.h"

using namespace std;

int main() {
	 List_dynamic_array test_list;
	 Card card1('A','D'); // ace of diamonds
	 Card card2('5','S'); // five of spades
	 Card card3('8','C'); // eight of clubs

	 test_list.insert_at_head(card1); // insert a card
	 test_list.insert_at_head(card2); // insert another card
	 test_list.insert_at_head(card3); // insert another card
	 test_list.print_list(); // should print 8C, 5S, AD

	 test_list.remove_from_head();
	 test_list.print_list(); // should print 5S, AD
}*/

// Test: tests the remove_from_tail() method
/*#include <iostream>
#include <cstdlib>
#include <time.h>

#include "hand.h"

using namespace std;

int main() {
	 List_dynamic_array test_list;
	 Card card1('A','D'); // ace of diamonds
	 Card card2('5','S'); // five of spades
	 Card card3('8','C'); // eight of clubs

	 test_list.insert_at_head(card1); // insert a card
	 test_list.insert_at_head(card2); // insert another card
	 test_list.insert_at_head(card3); // insert another card
	 test_list.print_list(); // should print 8C, 5S, AD

	 test_list.remove_from_tail();
	 test_list.print_list(); // should print 8C, 5S
}*/

// Test: tests the remove_from_index() method
/*
#include <iostream>
#include <cstdlib>
#include <time.h>

#include "hand.h"

using namespace std;

int main() {
	 List_dynamic_array test_list;
	 Card card1('A','D'); // ace of diamonds
	 Card card2('5','S'); // five of spades
	 Card card3('8','C'); // eight of clubs

	 test_list.insert_at_head(card1); // insert a card
	 test_list.insert_at_head(card2); // insert another card
	 test_list.insert_at_head(card3); // insert another card
	 test_list.print_list(); // should print 8C, 5S, AD

	 test_list.remove_from_index(1);
	 test_list.print_list(); // should print 8C, AD
	 test_list.remove_from_index(0);
	 test_list.print_list(); // should print AD
}*/



