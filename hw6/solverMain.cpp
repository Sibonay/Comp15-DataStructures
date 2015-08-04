#include "BogWordList.h"
#include "Dictionary.h"
#include "BogSolver.h"

#include <iostream>

using namespace std;

int main()
{
	BogSolver solver;

	solver.readDict();
	solver.readBoard();
	solver.solve();
	solver.printWords();

	return 0;
}

