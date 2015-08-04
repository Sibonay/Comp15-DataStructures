#include <iostream>
#include<stdlib.h>
#include "BogScorer.h"

using namespace std;


BogScorer::BogScorer() {
	score = 0;
	wordCount = 0;
}

void BogScorer::printScore() {
	string status, word;

	while (cin >> status >> word) {

	    if (status == "OK") {
		    if ((int)word.size() == 3 or (int)word.size() == 4) {
			score++;
			wordCount++;
			cout << "1 OK " << word << endl;
		    }

		    else if ((int)word.size() == 5) {
			score += 2;
			wordCount++;
			cout << "2 OK " << word << endl;
		    }
		    else if ((int)word.size() == 6) {
			score += 3;
			wordCount++;
			cout << "3 OK " << word << endl;
		    }
		    else if ((int)word.size() == 7) {
			score += 5;
			wordCount++;
			cout << "5 OK " << word << endl;
		    }
		    else if ((int)word.size() > 7) {
			score += 11;
			wordCount++;

			cout << "11 OK " << word << endl;
		    }
	    } else { // status == "NO"
		    cout << "0 NO " << word << endl;
	    }
	}

	// final score
	cout << wordCount << " words " << score << " points" << endl;
}
