#include <stdlib.h>     /* srand, rand */
#include <time.h>	/* time */
#include "hookbookBattles.h"

//#define USE_RANDOM

const unsigned int SIZE = 12;

void printBattleResult(BattleResult br) {
	cout << "*****\n";
	cout << "Battle between " << br.winnerName << "(winner) and " <<
			br.loserName << "(loser)\n";
	cout << "Winner Weapon: " << br.winnerWeapon << "\n";
	cout << "Winner Initial Weapon Strength: " <<
			br.winnerWeaponInitStrength << "\n";
	cout << "Winner Final Weapon Strength: " <<
			br.winnerWeaponFinalStrength << "\n";

	cout << "Loser Weapon: " << br.loserWeapon << "\n";
	cout << "Loser Initial Weapon Strength: " <<
			br.loserWeaponInitStrength << "\n";
	cout << "Loser Final Weapon Strength: " <<
			br.loserWeaponFinalStrength << "\n\n";
}

int main()
{
#ifdef USE_RANDOM
	// initialize with a random seed
	srand (time(NULL));
#else
	// initialize with a set seed (for testing)
	srand(1);
#endif


	string color[] = {"red", "blue", "grey", "white", "orange", "burnt sienna", "puce", "black", "cerulean", "dandelion", "cyan", "mauve"};

	HookBookBattles hb;

	// set up default ability list
	Abilities defaultAbilities;
	defaultAbilities.updateAbility("cannon",15);
	defaultAbilities.updateAbility("pistol",10);
	defaultAbilities.updateAbility("sword",5);
	defaultAbilities.updateAbility("rubberband gun",2);

	for (int i = 0; i < SIZE; i++) {
		hb.addPirate(i, color[i]+" beard",defaultAbilities);
	}

	// fight all battles
	for (int i=0;i<SIZE;i++) {
		for (int j=0;j<SIZE;j++) {
			if (i==j) continue; // can't fight yourself!
			BattleResult br = hb.battle(i,j);
			printBattleResult(br);
		}
	}
	hb.printStandings();

	return 0;
}
