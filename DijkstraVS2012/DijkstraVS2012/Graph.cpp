//Shabnam Basmani
//Class calculates the best distance from a given Vertex to another Vertex as well as calculates the path it takes using Dijkstra's algorithm
//Class allows for both display of one source or all sources
//User can both insert and remove an edge
//Preconditions: Input will be formatted properly per specs within text file; all methods will be passed valid data
//Postconditions: Will read in a file, calculate shortest path, and display either one or all sources to cout
//remove and inserting an edge is allowed. User cannot remove a source or add a source without building it into the file
#include <fstream>
#include "Graph.h"
#include "GraphData.h"
#include <iostream>
#include <string>
#include <queue>
#include <istream>
#include <sstream>
using namespace std;



//-------------------------------- buildGraph ---------------------------------
// Builds a graph by reading data from an ifstream
// Preconditions:  infile has been successfully opened and the file contains
//                 properly formated data (according to the program specs)
// Postconditions: One graph is read from infile and stored in the object

//BuildGraph takes in a txt file with vertices, paths, weights, and decriptions
//Preconditions: Number of Vertices should be the first input in the file followed by a new line, following lines should be a description per vertex (there should be the same number of following 
//desciptions as vertices specified). The following lines should be source vertex with a space, adjacent vertex, and weight. Every path should have it's own line with a space in between characteristics. 
//The ending line should be three 0's with a space between each 0 to specifiy the end of the file. There should be no spaces at the end of the file. Assumptions are made that user does not input 
//invalid or nonsensical data.
//Postconditions: File will processed and each vertex with associated paths will be stored 
void Graph::buildGraph(ifstream& infile) {

	infile >> size;                          // data member stores array size
	if (infile.eof())
		return;
	infile.ignore();  // throw away '\n' go to next line

	string data;
	string line;

	// get descriptions of vertices
	for (int v = 1; v <= size; v++) 
	{

		
		getline(infile, data);
		
		GraphData *Vertex = new GraphData;
		//insert description into GraphData obj
		Vertex->setData(data);
		//Create a non-dynamic Vertex Node to be stored in an array
		VertexNode VN;
		//Set the VertexNode object's data to point to the correct Vertex
		VN.data = Vertex;
		//Store the VertexNode in the array based on order provided
		vertices[v] = VN;
	}

	// fill cost edge array
	int src = 1, dest = 1, cost = 1;
	for (;;) {
		infile >> src >> dest >> cost;
		if (src == 0 || infile.eof())
			break;
		insertEdge(src, dest, cost);
	}
}

//insertEdge will insert a new Edge according to source Vertex
//Preconditions: User will input only postive integer values and will not duplicate any edges already provided
//Postconditions: Edge will be inserted into a VertexNode object an placed in the vertices array
//if Edge already exists it replaces the Edge with new weight
void Graph::insertEdge(const int &src,const int &dest,const int &cost)

{
	EdgeNode *Node = new EdgeNode;


	if (vertices[src].edgeHead == NULL)
	{
		Node->weight = cost;
		Node->adjVertex = dest;
		vertices[src].edgeHead = Node;
		Node->nextEdge = NULL;
		
	}
	else
	{
		//checking to ensure Edge has not been inserted into the table yet
		if (T[src][dest].dist == INT_MAX)
		{
			Node->weight = cost;
			Node->adjVertex = dest;
			Node->nextEdge = vertices[src].edgeHead;
			vertices[src].edgeHead = Node;
		}
		else
		{
			EdgeNode *cur = vertices[src].edgeHead;
			while (cur != NULL)
			{
				if (cur->adjVertex == dest)
				{
					cur->weight = cost;
					delete Node;
					Node = NULL;
					return;
				}

					cur = cur->nextEdge;
			}
		}

	}

}

//removeEdge will allow an edge to be removed
//Preconditions: user will only input a previously given edge to remove. FindShortestPath should be called after this method is ran to update Display methods outputs.
//Postconditions: Edge will be removed from VertexNode within array
void Graph::removeEdge(const int &svertex,const int &dvertex)
{
	EdgeNode *cur = vertices[svertex].edgeHead;
	EdgeNode *deleteNode = vertices[svertex].edgeHead;

	if (cur == NULL)
		return;

	if (cur->adjVertex == dvertex)
	{
		cur = cur->nextEdge;
		delete deleteNode;
		deleteNode = NULL;
		return;
	}

	while (cur->nextEdge != NULL)
	{
		if (cur->nextEdge->adjVertex == dvertex)
		{
			deleteNode = cur->nextEdge;
			cur->nextEdge = cur->nextEdge->nextEdge;
			delete deleteNode;
			deleteNode = NULL;
			return;

		}
		cur = cur->nextEdge;
	}
}


//findShortestPath calculates the best path from all source vertices to all other possible vertices
//Preconditions: buildGraph or insertEdge is assummed to have already been ran with usuable data
//Postcondtions: will calculate the best possible paths from all sources to all destinations. No output will be provided until a display method is called.
void Graph::findShortestPath()
{
	for (int i = 1; i <= size; i++)
	{
		buildTable(i);
	}
}

//buildTable is a helper method for findShortestPath that builds the T table by performing proper calucations 
//Preconditions: buildGraph or insert edge has been run. Only provide a positive valid source Vertex
//Postconditions: For the given source Vertex the T table will be populated (if the Node has already been visited, the best known distance, and the path where the best
//known distance came from)
void Graph :: buildTable(const int &src)
{
	//This loops resets the table back to previous condition
	for (int i = 1; i <= size; i++)
	{
		Table t;
		if (i == src)
		{
			t.dist = 0;
			t.path = -1;
			t.visited = false;
			T[src][i] = t;
		}
		else
		{
			t.dist = INT_MAX;
			t.path = NULL;
			t.visited = false;
			T[src][i] = t;
		}

	}
	int v = src;
	int smallestPath = INT_MAX;
	//int temp;
	for (int i = 1; i <= size - 1; i++)
	{
		//check if v has been visited 
		if (T[src][v].visited == false)
		{
			//marking v as visited
			T[src][v].visited = true;

			EdgeNode *cur = vertices[v].edgeHead;

			//check each source's linked list
			while (cur != NULL)
			{
				//if the current distance of the vertex is greater than the overall new distance 
				//update current distance with new value
				//record the path of where this new best distance was found
				if (T[src][cur->adjVertex].dist > cur->weight + T[src][v].dist)
				{
					T[src][cur->adjVertex].dist = cur->weight + T[src][v].dist;
					T[src][cur->adjVertex].path = v;

				}
				cur = cur->nextEdge;
				
			}
			int nextVertex = src;
			int smallestDist = INT_MAX;
			//find the Vertex with the smallest distance to visit
			for (int t = 1; t < size; t++)
			{
				if (smallestDist > T[src][t].dist && T[src][t].visited == false)
				{
					smallestDist = T[src][t].dist;
					nextVertex = t;
				}
			}
			v = nextVertex;
		}

	}


}

//displayAll displays the shortest distance and path of all vertices to all other vertices
//Preconditions: buildGraph or insertEdge should have been called. In addition, in order to display relevent information user should have called findShortestPath.
//Postconditions: Method will output details of each vertex to every other vertex's distance and shortest path to cout
void Graph::displayAll() const         // display shortest distance, path to cout
{
	cout << "Description\t\tFrom\tTo\tDistance\tPath" << endl;
	for (int i = 1; i <= size; i++)
	{
		cout << *vertices[i].data << endl;
		for (int j = 1; j <= size; j++)
		{
			if (i != j)
			{
				cout << "\t\t\t" << i << "\t" << j << "\t";
				if(T[i][j].dist != INT_MAX) 
					cout << T[i][j].dist << "\t\t";
				else cout << "--" << "\t\t";
				calculateShortPath(i, j);
				cout << endl;
			}

		}
	}

}

//display displays the shortest distance and path of a given source and distination vertex
//Preconditions: buildGraph or insertEdge should have been called. In addition, in order to display relevent information user should have called findShortestPath. User
//should provide a source and distance vertex that already exists.
//Postconditions: Method will output details of source vertex to the destination vertex's distance and shortest path to cout
void Graph::display(const int &svertex,const int &dvertex) const
{
	cout << svertex << "   ";
	cout << dvertex << "   ";
	//check if path is valid
	if (T[svertex][dvertex].dist != INT_MAX)
	{
		cout << T[svertex][dvertex].dist << "   ";
	}
	else cout << "--" << "   ";
	calculateShortPath(svertex, dvertex);
	printShortPathDesc(svertex, dvertex);
}



//calculateShortPath is a helper method used with display and displayAll to print out the shortest path from a source vertex to a distination vertex
//Preconditions:buildGraph or insertEdge has been ran. buildTable has been called for given src and pos variables. Only valid and postive integers are provided.
//Postconditions: will print to cout the shortest path from one vertex to another 
int Graph :: calculateShortPath(const int &src,const int &pos) const
{

	if (T[src][pos].path == -1)
	{
		cout << pos << " ";
		return pos;
	}
	
	
	if (pos >= 0)
	{
		//so long as the path is actually a valid path (check that it is no greater than the size of the array and greater than 0)
		if (T[src][pos].path <= size && T[src][pos].path > 0)
		{
			calculateShortPath(src, T[src][pos].path);
			cout << pos << " ";
		}
		return 0;
	}
	else return pos;

}

//printShortPathDesc is a helper method used with display to print out description's of the shortest path vertices from a source vertex to a destination vertex
//Preconditions: buildGraph or insertEdge has been ran. buildTable has been called for given src and pos variables. Only valid and postive integers are provided.
//Postconditions: will print to cout the descritions of the vertices from the shortert path in order
int Graph::printShortPathDesc(const int &src,const int &pos) const
{

	if (T[src][pos].path == -1)
	{
		cout << endl;
		cout << *vertices[pos].data << endl;
		return pos;
	}


	if (pos >= 0)
	{
		//check if path is valid
		if (T[src][pos].path <= size && T[src][pos].path > 0)
		{
			printShortPathDesc(src, T[src][pos].path);
			cout << *vertices[pos].data << endl;
			return 0;
		}
		else 
		{
			cout << "Not a valid path" << endl;
			return 0;
		}
	}
	else return pos;

}




//Overloaded copy constructor is used to create a deep copy of all objects stored in the vertices array
//no preconditions will be used when necessary automatically
//Postcondition: After copy is complete you should have two graph objects that are identical without reusing pointers
Graph::Graph(const Graph &obj)
{
	for (int i = 1; i <= obj.size; i++)
	{
		//create new graphData object
		GraphData *g = new GraphData;
		*g = *obj.vertices[i].data;
		vertices[i].data = g;
		
		EdgeNode *cur = obj.vertices[i].edgeHead;
		while (cur != NULL)
		{
			this->insertEdge(i, cur->adjVertex, cur->weight);
			cur = cur->nextEdge;

		}
		
		for (int k = 1; k <= obj.size; k++)
		{
			T[i][k].dist = obj.T[i][k].dist;
			T[i][k].path = obj.T[i][k].path;
			T[i][k].visited = obj.T[i][k].visited;
		}
	}
	size = obj.size;
}

//default constuctor will intialize size variable to 0
//No preconditions 
//Posconditions: Will intialize size varible when new graph object is created
Graph::Graph()
{
	size = 0;
}

//Constructor which takes in a file 
//Preconditions: File is formated with valid data as specified by specs
//Postconditions: Will automatically build Graph for user with file passed in
Graph :: Graph(ifstream& infile)
{
	size = 0;
	buildGraph(infile);
}


//destructor will clean up memory allocated within the program for EdgeNodes and GraphData
//No preconditions
//Postconditions: will run at the completion of program to clean up any dynamic memory
Graph::~Graph()
{
	for (int i = 1; i <= size; i++)
	{
		EdgeNode *cur = vertices[i].edgeHead;

		delete vertices[i].data;
		vertices[i].data = NULL;
		while (cur != NULL)
		{
			EdgeNode *toDelete = cur;
			cur = cur->nextEdge;
			delete toDelete;
			toDelete = NULL;
		}		


	}
}
