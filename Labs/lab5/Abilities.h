/*
 * Abilities.h
 *
 *  Created on: Oct 17, 2014
 *      Author: Chris Gregg
 */

#ifndef ABILITIES_H_
#define ABILITIES_H_

#include<iostream>

// an Ability has a weapon and a strength
struct Ability {
	std::string weapon;
	int strength;
};

// linked-list based Abilities class
class Abilities {
public:
	struct AbilityNode {
		Ability ability;
		AbilityNode *next;
	};

	// constructor
	Abilities();

	// copy constructor
	Abilities(const Abilities &source);

	// assignment (=) overload
	Abilities &operator=(const Abilities &source);

	// desctructor
	~Abilities();

	// update the ability of a weapon
	void updateAbility(std::string name, int amount);

	// determine the strength of a weapon based on the name
	// returns -1 if the pirate does not have this ability
	int getStrength(std::string name);

	// print the abilities list for a pirate
	void printAbilities();

	// return total strength: the total strength is the sum
	// of all the strengths for the pirate's weapons
	int totalStrength();

	// returns the number of abilities the a pirate has
	int abilityCount();

	// returns the ability by the index
	Ability &abilityByIndex(int index);

private:
	// the head of the linked list
	AbilityNode *head;

	// helper function for the destructor and for operator= overload
	void deleteList();
};

#endif /* ABILITIES_H_ */
