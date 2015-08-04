#include <iostream>
#include <stdio.h>
#include "hector.h"

using namespace std;
//
// hector-main.cpp -- tests the three versions with sample data
//
int main() 
{
	void answers1(), answers2(), answers3();
	
	void test_with(string, int[]);

	int randomInserts[] = {	16807, 284249, 1603, 98438,
				1144130, 471272, 127544, 1450878,
				148723, 207709, SENTINEL };
	
	int notRandom1[] = { 3, 20, 37, 21, 4, 5, 7, 23, 2, 0, SENTINEL};
	
	int notRandom2[] = { 3, 9, 15, 20, 26, 32, 37, 43, 49, 0, SENTINEL};

	test_with("Test One",   randomInserts);
	answers1();
	test_with("Test Two",   notRandom1);
	answers2();
	test_with("Test Three", notRandom2);
	answers3();
	
	return 0;
}
//
// test the class with an array of ints
//  Does: insert the data, keep stats
//  then: report results, print the hash tables
//
void test_with(string title, int data[])
{
	Hector	h;
	
	int maxL = 0;
	int maxD = 0;
	int maxC = 0;
	int sumL = 0;
	int sumD = 0;
	int colls;
	int i;
	
	cout << title << endl;
	cout << "inserting keys:";
	for(i=0; data[i] != SENTINEL ; i++)
	{
		cout << " " << data[i];
		colls = h.linny(data[i]);
		sumL += colls;
		if ( colls > maxL ) maxL = colls;

		colls = h.doubles(data[i]);
		sumD += colls;
		if ( colls > maxD ) maxD = colls;

		colls = h.cheney(data[i]);
		if ( colls > maxC ) maxC = colls;
	}
	cout << endl << "Results of Your Code:" << endl;

	printf("     linny: reprobes = %d  max lookup = %d\n", sumL, maxL);
	printf("   doubles: reprobes = %d  max lookup = %d\n", sumD, maxD);
	printf("    cheney: reprobes = 0  max bucket size= %d\n",    maxC+1);
	cout << endl;
	cout << "Your Tables:" << endl;

	h.print();
	cout << endl;
}

void answers1()
{
  cout << "Results We Think Are Correct:" << endl;
  cout << "     linny: reprobes = 1  max lookup = 1" << endl;
  cout << "   doubles: reprobes = 1  max lookup = 1" << endl;
  cout << "    cheney: reprobes = 0  max bucket size= 2" << endl;
  cout << "" << endl;
  cout << "Our tables:" << endl;
  cout << "  L: 284249 471272 -1 127544 -1 1603 16807 -1 -1 -1 -1 148723 " << endl;
  cout << "     1144130 1450878 98438 -1 207709 " << endl;
  cout << "  D: 284249 471272 -1 127544 -1 1603 16807 -1 1450878 -1 -1 148723 " << endl;
  cout << "     1144130 -1 98438 -1 207709 " << endl;
  cout << "  C: [ 284249 ] [ 471272 ] [ ] [ 127544 ] [ ] [ 1603 ] [ 16807 ] [ ] " << endl;
  cout << "     [ ] [ ] [ ] [ 148723 ] [ 1450878 1144130 ] [ ] [ 98438 ] [ ] [ 207709 ]" << endl;
  cout << "" << endl;
}

void answers2()
{
  cout << "Results We Think Are Correct:" << endl;
  cout << "     linny: reprobes = 4  max lookup = 2" << endl;
  cout << "   doubles: reprobes = 7  max lookup = 1" << endl;
  cout << "    cheney: reprobes = 0  max bucket size= 3" << endl;
  cout << "" << endl;
  cout << "Our tables:" << endl;
  cout << "  L: 20 37 21 4 -1 5 -1 0 23 -1 -1 7 -1 2 -1 -1 3 " << endl;
  cout << "  D: 7 37 21 0 -1 20 -1 2 23 -1 -1 4 -1 5 -1 -1 3 " << endl;
  cout << "  Q: [ ] [ ] [ 4 21 ] [ ] [ ] [ 5 ] [ ] [ 0 ] [ 23 ] " << endl;
  cout << "     [ ] [ ] [ 7 ] [ ] [ 2 ] [ ] [ ] [ 37 20 3 ]" << endl;
  cout << "" << endl;
}

void answers3()
{
  cout << "Results We Think Are Correct:" << endl;
  cout << "     linny: reprobes = 28  max lookup = 6" << endl;
  cout << "   doubles: reprobes = 7  max lookup = 2" << endl;
  cout << "    cheney: reprobes = 0  max bucket size= 3" << endl;
  cout << "" << endl;
  cout << "Our tables:" << endl;
  cout << "  L: 9 15 20 26 32 37 43 49 0 -1 -1 -1 -1 -1 -1 -1 3 " << endl;
  cout << "  D: 9 15 -1 37 49 20 -1 0 32 43 -1 -1 -1 26 -1 -1 3 " << endl;
  cout << "  Q: [ 43 26 9 ] [ 49 32 15 ] [ ] [ ] [ ] [ ] [ ] [ 0 ] " << endl;
  cout << "     [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ 37 20 3 ]" << endl;
  cout << "" << endl;
}
