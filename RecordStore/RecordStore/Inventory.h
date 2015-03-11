//Shabnam Basmani
//The inventory class contains the items for sale in the record store. Given the data can only be a capital letter 26 possible items could be sold. 
//This class interacts with the classes which represent the proper item. When inventory processes transactions it send the transaction to the object to be created then 
//stores that object in the proper BST of its proper object
#pragma once

#include "DVD.h"
#include "ClassicalCD.h"
#include "BSTree.h"
#include "Hash.h"
class Inventory
{

public:
	
	//default constructor intializes both arrays and creates dummy objects for Disk objects
	//Preconditions: none
	//Postconditions: creates a inventory object
	Inventory(void);

	//virtual destructor used just in case inventory can be expanded upon; cleans up any inventory objects
	//Preconditions: none
	//Postconditions: cleans up items stored in InventoryItems and TreeCollection
	virtual ~Inventory(void);

	//tradeIn removes an item from the BST of its object
	//Preconditions: Inventory file must have been loaded and files must be formated correctly
	//in addition only a char and string can be passed in as a const
	//Postconditions: tradeIn will attempt to retreive the item from the BST, if it is found it will 
	//then process its removal
	bool tradeIn(char Itype, string line);

	//purchase inserts an item into inventory (proper BST)
	//Preconditions: file must be formatted correctly, only char and string can be passed in as a const
	//Postconditions: purchase will call the object to create itself, the pointer will be stored in the proper BST 
	//it will return a bool if the insert was sucessful or not
	bool purchase(char Itype, string line);

	//createInventory is used for loading the inventory file; it allows for the counter to be updated rather than processing x number of items
	//Preconditions: file has been formatted properly
	//Postconditions: createInventory will create object as well as update the counter in the BSTree Class
	bool createInventory(int numOfItems, string input, char type);

	//printCurrentInventory works with the command inventory and prints out the current items in inventory
	//Preconditions: none
	//Postconditions: this method is called from TransInventory as a command that was passed in from the file
	//it will in turn loop through the TreeCollection array and print out each BST with inventory items
	void printCurrentInventory() const;

	

private:

	//isValidItem checks to see if the item is in the dummy table created
	//Preconditions: a valid hash value is passed
	//Postconditions: returns true or false depending on if the object exists
	bool isValidItem(int hashValue);

	//MAX_ITEMS is a static const variable to indicate the size of the two arrays
	static const int MAX_ITEMS = 26;

	//Disk pointer array of dummy *Disk objects to be used to create new objects
	Disk* inventoryItems[MAX_ITEMS];

	//A BST is stored for each item in inventory in this array
	BSTree* TreeCollection[MAX_ITEMS];

	//A pointer to Hash is needed to check the Hash value of a given input
	Hash *h;

	
};

