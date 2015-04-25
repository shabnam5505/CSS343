//Shabnam Basmani
//Simple GraphData class which holds the decription of a Vertex
//Preconditions: all data will be valid when passed into methods
//Postconditions: User can set graph data through the constructor or by the set method. User can retrieve graph data through get method
//or overloaded operator
#pragma once
#include <iostream>
using namespace std;


class GraphData
{
	//Overloaded output operator
	//Preconditions: Valid data will be passed in
	//Postconditions: Will return the description of a Vertex when object is referenced
	friend ostream& operator<<(ostream& os, const GraphData& data);
public:

	//Default constructor
	//Preconditions: None 
	//Postconditons: Will intialize description with a string with a space in it
	GraphData();

	//Constructor with desc passed in
	//Preconditions: a string is passed in
	//Postconditions: description will be intialized to value passed in
	GraphData(string desc);

	//Default destructor
	//Preconditions: none
	//Postcondtions: will clean up variables in class
	~GraphData();

	//setData is a simple set method that allows user to set the description
	//Preconditions: a string is passed in
	//Postconditions: description will be set to value that was passed in
	void setData(string desc);

	//getData is a simple getter method that allows user to retreive the description
	//Preconditions: for valid data value must have already been set
	//Postconditions: will return the string holding the description of the vertex
	string getData() const;

private:
	//holds the description of the Vertex
	string description;
};



