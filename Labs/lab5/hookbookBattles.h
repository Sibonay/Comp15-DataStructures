// HookBookBattles Abilities Social Network
// Lab 6 -- Data Strucures (COMP 15)
// Fall 2014

#ifndef HOOKBOOKBATTLES_H
#define HOOKBOOKBATTLES_H

#include<iostream>

using namespace std;

#include "Abilities.h"

const int INIT_CAPACITY = 5;

struct Pirate
{
	int memberID;
	string name;
	Abilities abilities;
};

struct BattleResult {
	std::string winnerName;
	int winnerId;
	std::string winnerWeapon;
	int winnerWeaponInitStrength;
	int winnerWeaponFinalStrength;

	std::string loserName;
	int loserId;
	std::string loserWeapon;
	int loserWeaponInitStrength;
	int loserWeaponFinalStrength;
};

class HookBookBattles{

public:
	/* constructor */
	HookBookBattles();

	/* destructor */
	~HookBookBattles();

	/* Adds a new pirate to HookBookBattles, probably the member should
       be created by the hookbook system, for now it is sent in
       from main, the pirate starts with no friends*/

	bool addPirate(int member, string memberName, Abilities initAbilities);

	// battle two pirates by index
	// return 1 if the first pirate wins, and 2 if the second pirate wins
	// return -1 if one or both pirates do not exist
	BattleResult battle(int pirate1MemId, int pirate2MemId);

	// print the hookbook pirate standings
	void printStandings();

private:

	Pirate* hbookBattles;
	int pirateCount;
	int currentCapacity;
	bool expandPirates();
	Ability &getRandomAbilityByPirateIndex(int index);
	int fight(int p1Strength, int p2Strength);
	void insertIntoStandings(Pirate *p,Pirate **standings, int num);
	void updateBattleResult(BattleResult &br,
			Ability &winnerAb,int winnerMemId, int winnerIndex,
			Ability &loserAb,int loserMemId, int loserIndex);
};

#endif
