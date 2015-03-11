//Shabnam Basmani
//The inventory class contains the items for sale in the record store. Given the data can only be a capital letter 26 possible items could be sold. 
//This class interacts with the classes which represent the proper item. When inventory processes transactions it send the transaction to the object to be created then 
//stores that object in the proper BST of its proper object
#include "Inventory.h"

//default constructor intializes both arrays and creates dummy objects for Disk objects
//Preconditions: none
//Postconditions: creates a inventory object
Inventory::Inventory(void)
{
	for(int i = 0; i < MAX_ITEMS; i++)
	{
		inventoryItems[i] = NULL;
		TreeCollection[i] = NULL;
	}


	inventoryItems[2] = new ClassicalCD;
	inventoryItems[3] = new DVD;
	inventoryItems[17] = new RockCD;

	BSTree *ClassicalCDInventory = new BSTree;
	TreeCollection[2] = ClassicalCDInventory;

	BSTree *DVDInventory = new BSTree;
	TreeCollection[3] = DVDInventory;

	BSTree *RockCDInventory = new BSTree;
	TreeCollection[17] = RockCDInventory;


}

//tradeIn removes an item from the BST of its object
//Preconditions: Inventory file must have been loaded and files must be formated correctly
//in addition only a char and string can be passed in as a const
//Postconditions: tradeIn will attempt to retreive the item from the BST, if it is found it will 
//then process its removal
bool Inventory :: tradeIn(char Itype, string line)
{
	int hash = h->getHashValue(Itype); 

	if(isValidItem(hash))
	{
		//create item first
		Disk *d = inventoryItems[hash]->tradeIn(line);
		if(TreeCollection[hash]->insert(d))
			return true;
		else 
		{
			delete d;
			d = NULL;
			return false;
		}
	}
		 
	else 
	{
		cout << "Invalid item type: " << Itype << " Item not processed." << endl;
		return false;
	}
	
}

//purchase inserts an item into inventory (proper BST)
//Preconditions: file must be formatted correctly, only char and string can be passed in as a const
//Postconditions: purchase will call the object to create itself, the pointer will be stored in the proper BST 
//it will return a bool if the insert was sucessful or not
bool Inventory :: purchase(char Itype, string line)
{
	int hash = h->getHashValue(Itype);

	if(isValidItem(hash))
	{
		Disk *d = inventoryItems[hash]->purchase(line);
		if(TreeCollection[hash]->remove(*d))
		{
			delete d;
			d = NULL;
			return true;
		}
		else
		{
			delete d;
			d = NULL;
			return false;
		}
			 
	}
	else 
	{
		cout << "Invalid item type: " << Itype << " Item not processed." << endl;
		return false;
	}
}

//isValidItem checks to see if the item is in the dummy table created
//Preconditions: a valid hash value is passed
//Postconditions: returns true or false depending on if the object exists
bool Inventory :: isValidItem(int hashValue)
{
	if(hashValue != -1 && inventoryItems[hashValue] != NULL)
		return true;
	else return false;

}

//createInventory is used for loading the inventory file; it allows for the counter to be updated rather than processing x number of items
//Preconditions: file has been formatted properly
//Postconditions: createInventory will create object as well as update the counter in the BSTree Class
bool Inventory :: createInventory(int numOfItems, string input, char type)
{
	int hash = h->getHashValue(type); 

	if(isValidItem(hash))
	{
		//create object first
		Disk *d = inventoryItems[hash]->Create(input);

		if(TreeCollection[hash]->insert(d))
		{
			//update counter in BSTree
			TreeCollection[hash]->updateQuanity(d, numOfItems);
			return true;
		}
		else
		{
			delete d;
			d = NULL;
			return false;
		}
	}
		 
	else 
	{
		cout << "Invalid item type: " << type << " Item not processed." << endl;
		return false;
	}

}


//printCurrentInventory works with the command inventory and prints out the current items in inventory
//Preconditions: none
//Postconditions: this method is called from TransInventory as a command that was passed in from the file
//it will in turn loop through the TreeCollection array and print out each BST with inventory items
void Inventory :: printCurrentInventory() const
{
	//print out Rock CD's, Classical CD's, and then DVD's
	int rock = h->getHashValue('R');
	int classical = h->getHashValue('C');
	int dvdDisk = h->getHashValue('D');

	if(TreeCollection[rock] != NULL)
	{
		cout << "Rock CD's:" << endl;
		TreeCollection[rock]->Output();
		cout << endl; 
	}

	if(TreeCollection[classical] != NULL)
	{
		cout << "Classical CD's:" << endl;
		TreeCollection[classical]->Output();
		cout << endl;
	}

	if(TreeCollection[dvdDisk] != NULL)
	{
		cout << "DVD's:" << endl;
		TreeCollection[dvdDisk]->Output();
		cout << endl;
	}
	
}

//virtual destructor used just in case inventory can be expanded upon; cleans up any inventory objects
//Preconditions: none
//Postconditions: cleans up items stored in InventoryItems and TreeCollection
Inventory::~Inventory(void)
{
	for (int i = 0; i < 26; i++) {
		if(inventoryItems[i] != NULL)
		{
			delete inventoryItems[i];
			inventoryItems[i] = NULL;
		}
		if(TreeCollection[i] != NULL)
		{
			delete TreeCollection[i];
			TreeCollection[i] = NULL;
		}
	}
}
