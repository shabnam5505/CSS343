//Shabnam Basmani
//The inventory class contains the items for sale in the record store. Given the data can only be a capital letter 26 possible items could be sold. 
//This class interacts with the classes which represent the proper item. When inventory processes transactions it send the transaction to the object to be created then 
//stores that object in the proper BST of its proper object
#pragma once

#include "DVD.h"
#include "ClassicalCD.h"
#include "BSTree.h"
class Inventory
{

public:
	
	//default constructor and destructor is sufficant given how inventory deals with items
	Inventory(void);
	virtual ~Inventory(void);

	//tradeIn removes an item from the BST of its object
	//Preconditions: Inventory file must have been loaded and files must be formated correctly
	//in addition only a char and string can be passed in as a const
	//Postconditions: tradeIn will attempt to retreive the item from the BST, if it is found it will 
	//then process its removal
	bool tradeIn(char Itype, string line) const;

	//purchase inserts an item into inventory (proper BST)
	//Preconditions: file must be formatted correctly, only char and string can be passed in as a const
	//Postconditions: purchase will call the object to create itself, the pointer will be stored in the proper BST 
	//it will return a bool if the insert was sucessful or not
	bool purchase(char Itype, string line) const;

	//printCurrentInventory works with the command inventory and prints out the current items in inventory
	//Preconditions: none
	//Postconditions: this method is called from TransInventory as a command that was passed in from the file
	//it will in turn loop through the TreeCollection array and print out each BST with inventory items
	void printCurrentInventory() const;

	

private:

	//getHashValue converts a char into a hash index for the either array/ hash table
	//Preconditions: only a char can be passed in
	//Postconditions: will return an int index from the char passed in
	int getHashValue(char dtype) const;

	//MAX_ITEMS is a static const variable to indicate the size of the two arrays
	static const int MAX_ITEMS = 26;

	//Disk pointer array of dummy *Disk objects to be used to create new objects
	Disk* inventoryItems[MAX_ITEMS];

	//A BST is stored for each item in inventory in this array
	BSTree* TreeCollection[MAX_ITEMS];

	
};

