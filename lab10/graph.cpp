#include "graph.h"

Graph::Graph()
{
	//Create two dynamic arrays, the adjacency
	//matrix to store the graph and the marked
	//set --- initialized to false for all to start
	//The adjacent matrix is all false, it is an
	//empty graph.

	adjacencyMatrix = new bool*[NODE_COUNT];
	markedVertices = new bool[NODE_COUNT];


	// an outer loop to create all rows (vertices) and an inner
	//loop to create the adjacent vertices (columns)
	//initialized to empty graph
	for(int i=0; i < NODE_COUNT; i++)
	{
		adjacencyMatrix[i] = new bool[NODE_COUNT];
		for (int j=0; j < NODE_COUNT; j++)
		{
			adjacencyMatrix[i][j] = false;
		}
		markedVertices[i]=false;

	}
}


Graph::Graph(bool adjM[][NODE_COUNT])
{
	//Create two dynamic arrays, the adjacency
	//matrix to store the graph and the marked
	//set --- initialized to false for all to start


	adjacencyMatrix = new bool*[NODE_COUNT];
	markedVertices = new bool[NODE_COUNT];


	// a loop to create all rows (vertices) an inner
	//loop to create the adjacent vertices (columns)
	//initialized to empty graph
	for(int i=0; i < NODE_COUNT; i++)
	{
		adjacencyMatrix[i] = new bool[NODE_COUNT];
		for (int j=0; j < NODE_COUNT; j++)
		{
			adjacencyMatrix[i][j] = adjM[i][j];
		}
		markedVertices[i]=false;

	}
}

Graph::~Graph() {
	for(int i=0; i < NODE_COUNT; i++)
	{
		delete [] adjacencyMatrix[i];


	}

	delete[] adjacencyMatrix;
	delete[] markedVertices;
}

bool Graph::createEdge(int u, int v)
{
	//if u and v are in bounds then add the edge and return true
	//if edge has been previously added, nothing happens, if
	//out of bounds returns false
	if(u >=0 && u <= NODE_COUNT && v >= 0 && v <= NODE_COUNT)
	{
		adjacencyMatrix[u][v] = true;
		adjacencyMatrix[v][u] = true;
		return true;
	}
	return false;
}



//returns true if there is an edge between
//u and v
bool Graph::isAdjacent(int u, int v)
{
	return adjacencyMatrix[u][v];
}

//marks a vertex true --- public
//could be private
bool Graph::markVertex(int u)
{
	if (u >= 0 && u <= NODE_COUNT)
	{
		markedVertices[u]=true;
		return true;
	}
	return false;
}



bool Graph::isMarked(int u)
{
	return markedVertices[u];
}




//unmark all vertices, also could be
//private
void Graph::unmarkAll()
{
	for (int i = 0; i < NODE_COUNT; i++) {
		markedVertices[i] = false;
	}
}




//BREADTH FIRST SEARCH

//unmark all,
//choose x
//mark and process (print)
//x add x to the Q
//while Q not empty
//remove vertex u from Q
//for all unmarked neighbors w of u
//mark and process (print)
//w
//insert w into Q
void Graph::BFS()
{
	int x = 0;
	int u;
	queue<int> graphQueue;

	unmarkAll();

	markVertex(x);
	cout << x << " ";
	graphQueue.push(x);

	while (! graphQueue.empty()) {
		u = graphQueue.front();
		graphQueue.pop();

		for (int w = 0; w < NODE_COUNT; w++) {
			if (isAdjacent(u, w) and !isMarked(w)) {
				markVertex(w);
				cout << w << " ";
				graphQueue.push(w);
			}
		}
	}

}


//DEPTH FIRST SEARCH

//unmark all vertices
//choose x
//mark and process (print) x
//for each unmarked neighbor of x, w
//recurse on w

void Graph::DFS()
{
	unmarkAll();
	DFS(0);
}

void Graph::DFS(int vertex)
{
	markVertex(vertex);
	cout << vertex << " ";

	for (int w = NODE_COUNT - 1; w >= 0; w--) {
		if (isAdjacent(vertex, w) and !isMarked(w)) {
				DFS(w);
		}
	}
}
