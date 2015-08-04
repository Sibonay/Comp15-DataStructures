#include "graph.h"

int main()
{
	Graph hookbook;

	//Add some edges
	hookbook.createEdge(0,1);
	hookbook.createEdge(0,4);
	hookbook.createEdge(0,6);
	hookbook.createEdge(1,2);
	hookbook.createEdge(1,3);
	hookbook.createEdge(2,3);
	hookbook.createEdge(2,5);
	hookbook.createEdge(3,4);
	hookbook.createEdge(4,6);
	hookbook.createEdge(4,8);
	hookbook.createEdge(5,6);
	hookbook.createEdge(5,7);
	hookbook.createEdge(7,8);
	hookbook.createEdge(8,9);


	//now do a BFS

	hookbook.BFS();

	cout << endl;
	cout << "One possible solution for a BFS is :" << endl;
	cout << "0 6 5 7 8 9 4 3 2 1" << endl;

	cout << endl;

	//now do a DFS
	hookbook.DFS();

	cout << endl;
	cout << "One possible solution for a DFS is :" << endl;
	cout << "0 6 5 7 8 9 2 3 4 1" << endl;

	cout << endl;


	return 0;
}
