//Shabnam Basmani
//Class calculates the best distance from a given Vertex to another Vertex as well as calculates the path it takes using Dijkstra's algorithm
//Class allows for both display of one source or all sources
//User can both insert and remove an edge
//Preconditions: Input will be formatted properly per specs within text file; all methods will be passed valid data
//Postconditions: Will read in a file, calculate shortest path, and display either one or all sources to cout
//remove and inserting an edge is allowed. User cannot remove a source or add a source without building it into the file
#pragma once
#include <fstream>
#include "GraphData.h"
#include <iostream>
using namespace std;
class Graph
{
public:
	//default constuctor will intialize size variable to 0
	//No preconditions 
	//Posconditions: Will intialize size varible when new graph object is created
	Graph();

	//Constructor which takes in a file 
	//Preconditions: File is formated with valid data as specified by specs
	//Postconditions: Will automatically build Graph for user with file passed in
	Graph(ifstream& infile);

	//destructor will clean up memory allocated within the program for EdgeNodes and GraphData
	//No preconditions
	//Postconditions: will run at the completion of program to clean up any dynamic memory
	~Graph();

	//BuildGraph takes in a txt file with vertices, paths, weights, and decriptions
	//Preconditions: Number of Vertices should be the first input in the file followed by a new line, following lines should be a description per vertex (there should be the same number of following 
	//desciptions as vertices specified). The following lines should be source vertex with a space, adjacent vertex, and weight. Every path should have it's own line with a space in between characteristics. 
	//The ending line should be three 0's with a space between each 0 to specifiy the end of the file. There should be no spaces at the end of the file. Assumptions are made that user does not input 
	//invalid or nonsensical data.
	//Postconditions: File will processed and each vertex with associated paths will be stored 
	void buildGraph(ifstream& infile);

	//insertEdge will insert a new Edge according to source Vertex
	//Preconditions: User will input only postive integer values and will not duplicate any edges already provided
	//Postconditions: Edge will be inserted into a VertexNode object an placed in the vertices array
	void insertEdge(const int &src,const int &dest,const int &cost);

	//removeEdge will allow an edge to be removed
	//Preconditions: user will only input a previously given edge to remove. FindShortestPath should be called after this method is ran to update Display methods outputs.
	//Postconditions: Edge will be removed from VertexNode within array
	void removeEdge(const int &svertex,const int &dvertex);

	//findShortestPath calculates the best path from all source vertices to all other possible vertices
	//Preconditions: buildGraph or insertEdge is assummed to have already been ran with usuable data
	//Postcondtions: will calculate the best possible paths from all sources to all destinations. No output will be provided until a display method is called.
	void findShortestPath();

	//displayAll displays the shortest distance and path of all vertices to all other vertices
	//Preconditions: buildGraph or insertEdge should have been called. In addition, in order to display relevent information user should have called findShortestPath.
	//Postconditions: Method will output details of each vertex to every other vertex's distance and shortest path to cout
	void displayAll() const;    

	//display displays the shortest distance and path of a given source and distination vertex
	//Preconditions: buildGraph or insertEdge should have been called. In addition, in order to display relevent information user should have called findShortestPath. User
	//should provide a source and distance vertex that already exists.
	//Postconditions: Method will output details of source vertex to the destination vertex's distance and shortest path to cout
	void display(const int &svertex,const int &dvertex) const;


	//Overloaded copy constructor is used to create a deep copy of all objects stored in the vertices array
	//no preconditions will be used when necessary automatically
	//Postcondition: After copy is complete you should have two graph data objects that are identical without reusing pointers
	Graph(const Graph &obj);


private:
	//static variable for maxium array size
	static const int MAX_VERTICES = 101;

	//buildTable is a helper method for findShortestPath that builds the T table by performing proper calucations 
	//Preconditions: buildGraph or insert edge has been run. Only provide a positive valid source Vertex
	//Postconditions: For the given source Vertex the T table will be populated (if the Node has already been visited, the best known distance, and the path where the best
	//known distance came from)
	void buildTable(const int &src);

	//calculateShortPath is a helper method used with display and displayAll to print out the shortest path from a source vertex to a distination vertex
	//Preconditions:buildGraph or insertEdge has been ran. buildTable has been called for given src and pos variables. Only valid and postive integers are provided.
	//Postconditions: will print to cout the shortest path from one vertex to another 
	int calculateShortPath(const int &src,const int &pos) const;

	//printShortPathDesc is a helper method used with display to print out description's of the shortest path vertices from a source vertex to a destination vertex
	//Preconditions: buildGraph or insertEdge has been ran. buildTable has been called for given src and pos variables. Only valid and postive integers are provided.
	//Postconditions: will print to cout the descritions of the vertices from the shortert path in order
	int printShortPathDesc(const int &src,const int &pos) const;

	//EdgeNode struct used to store each given edge and weight as well as a pointer to the next edge
	//Preconditions: should only be used internally to store data on Edges inside of a VertexNode
	//Postconditions: Will create a linked list structure for each VertexNode
	struct EdgeNode {			// can change to a class, if desired
		int adjVertex;			// subscript of the adjacent vertex 
		int weight;				// weight of edge
		EdgeNode *nextEdge;
		
		//Default constructor needed for setting pointer to NULL
		EdgeNode :: EdgeNode()
		{
			nextEdge = NULL;
		}


	};

	//VertexNode struct is used to store a linked list of EdgeNodes
	//Preconditions: do not allocate dynamic memory
	//Postcondions: VertexNodes created will be placed inside of the vertices array
	struct VertexNode {
		EdgeNode *edgeHead;		// head of the list of edges
		GraphData *data;		// store vertex data here

		//Default constuctor needed for setting pointers to NULL
		VertexNode :: VertexNode()
		{
			edgeHead = NULL;
			data = NULL;
		}

	};

	//array of VertexNodes
	VertexNode vertices[MAX_VERTICES];

	//Table struct is used to store calculations of relevent info needed to return best known distance and shortest path 
	//from a source vertex to all possible destinations
	//Preconditions: do not allocate dynamic memory
	//Postconditions: Table objects created will be stored in the T array
	struct Table {
		bool visited;			// whether vertex has been visited
		int dist;				// shortest known distance from source
		int path;				// previous vertex in path of min dist

		//Default Constructor used to intialize items.
		Table :: Table ()
		{
			visited = false;			
			dist = INT_MAX;				
			path = NULL;				
		}
		

	};

	int size;					// number of vertices in the graph
	
	//Table T array is a two dimensional array that contains Table objects of all given sources and destinations
	Table T[MAX_VERTICES][MAX_VERTICES];

};


