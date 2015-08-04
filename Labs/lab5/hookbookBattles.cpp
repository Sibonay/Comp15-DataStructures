#include <stdlib.h>     /* srand, rand */
#include "hookbookBattles.h"

HookBookBattles::HookBookBattles()
{
	hbookBattles = new Pirate[INIT_CAPACITY];
	currentCapacity = INIT_CAPACITY;
	pirateCount = 0;
}

HookBookBattles::~HookBookBattles() {
	// now delete the pirates
	delete [] hbookBattles;
}

/* Adds a new pirate to HookBookBattles*/

bool HookBookBattles::addPirate(int member, string memberName,Abilities initAbilities)
{
	//check to see if we need to expand to add
	if(pirateCount >= currentCapacity)
	{
		// check to see if expand worked
		if(!expandPirates())
		{
			return false;
		}
	}
	//made it here so we can add a pirate
	hbookBattles[pirateCount].memberID = member;
	hbookBattles[pirateCount].name = memberName;
	hbookBattles[pirateCount].abilities = initAbilities;
	pirateCount++;
	return true;
}

BattleResult HookBookBattles::battle(int pirate1MemId, int pirate2MemId) {
	BattleResult battleResult;
	battleResult.winnerId = -1; // in case of failure

	// first ensure the pirates are in hbookBattles
	int p1Index = -1;
	int p2Index = -1;
	for (int i=0;i<pirateCount;i++) {
		if (hbookBattles[i].memberID == pirate1MemId) {
			p1Index = i;
		}
		if (hbookBattles[i].memberID == pirate2MemId) {
			p2Index = i;
		}
	}
	if (p1Index != -1 && p2Index != -1) {
		// fight the pirates based on a random weapon for both
		Ability &p1Ability =
				getRandomAbilityByPirateIndex(p1Index);
		Ability &p2Ability =
				getRandomAbilityByPirateIndex(p2Index);

		int winner = fight(p1Ability.strength,p2Ability.strength);

		if (winner == 1) {
			updateBattleResult(battleResult,
					p1Ability,pirate1MemId,p1Index,
					p2Ability,pirate2MemId,p2Index);
		}
		else {
			updateBattleResult(battleResult,
					p2Ability,pirate2MemId,p2Index,
					p1Ability,pirate1MemId,p1Index);
		}
	}

	return battleResult;
}

void HookBookBattles::updateBattleResult(BattleResult &battleResult,
		Ability &winnerAb,int winnerMemId, int winnerIndex,
		Ability &loserAb,int loserMemId, int loserIndex) {
	battleResult.winnerId = winnerMemId;
	battleResult.winnerName = hbookBattles[winnerIndex].name;
	battleResult.winnerWeapon = winnerAb.weapon;
	battleResult.winnerWeaponInitStrength =
			winnerAb.strength;
	battleResult.winnerWeaponFinalStrength =
			winnerAb.strength+= loserAb.strength;
	winnerAb.strength =
			battleResult.winnerWeaponFinalStrength;

	battleResult.loserId = loserMemId;
	battleResult.loserName = hbookBattles[loserIndex].name;
	battleResult.loserWeapon = loserAb.weapon;
	battleResult.loserWeaponInitStrength =
			loserAb.strength;
	battleResult.loserWeaponFinalStrength =
			loserAb.strength / 2;
	loserAb.strength =
			battleResult.loserWeaponFinalStrength;
}
void HookBookBattles::printStandings() {
	cout << "Hookbook Standings\n";
	Pirate **standings = new Pirate*[pirateCount];
	for (int i=0;i<pirateCount;i++) {
		insertIntoStandings(&hbookBattles[i],standings,i);
	}
	for (int i=0;i<pirateCount;i++) {
		cout << i+1 << ". ";
		if (i==0) {
			cout << "(leader) ";
		}
		cout << standings[i]->name << ":\n";
		standings[i]->abilities.printAbilities();
		cout << "Pirate overall strength: " <<
				standings[i]->abilities.totalStrength();
		cout << "\n\n";
	}
	delete [] standings;
}

void HookBookBattles::insertIntoStandings(Pirate *p,Pirate **standings,int num) {
	// num is the number we have already put into the standings
	// perform an insertion sort to keep the list in order
	int i;
	for (i=num;i>0;i--) {
		if (p->abilities.totalStrength() <
				standings[i-1]->abilities.totalStrength()) {
			break;
		}
		standings[i]=standings[i-1];
	}
	standings[i]=p;
}

Ability &HookBookBattles::getRandomAbilityByPirateIndex(int index) {
	int abilityCount = hbookBattles[index].abilities.abilityCount();

	// randomly select an ability
	int randAbilityNum = rand() % abilityCount;
	return hbookBattles[index].abilities.abilityByIndex(randAbilityNum);
}

// calculates a winner based on strength (and probability)
int HookBookBattles::fight(int p1Strength, int p2Strength){
	// returns 1 for p1 winning, 2 for p2 winning

	// if p1 has a strength of 0, that pirate loses
	if (p1Strength == 0) {
		return 2;
	}
	// calculate the percentage of time p1 will win
	float p1PercentWin =
			(float)p1Strength / (p1Strength+p2Strength) * 100;

	// calculate random percentage, 1 decimal place of precision
	float randPerc = (rand() % 1000)/ 10.0;

	// p1 wins if randPerc is equal or below p1PercentWin
	if (randPerc <= p1PercentWin) {
		return 1;
	}
	else {
		return 2;
	}
}

bool HookBookBattles::expandPirates()
{
	Pirate* temp = new Pirate[currentCapacity*2];
	if(temp == NULL){
		return false;
	}
	for (size_t i = 0; i < pirateCount; i++) {
		temp[i]=hbookBattles[i];
	}
	delete[] hbookBattles;
	hbookBattles = temp;
	currentCapacity = currentCapacity*2;
	return true;
}
