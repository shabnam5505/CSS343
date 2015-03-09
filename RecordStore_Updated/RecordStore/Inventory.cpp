#include "Inventory.h"


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

bool Inventory :: tradeIn(char Itype, string line)
{
	int hash = h->getHashValue(Itype); 

	if(isValidItem(hash))
	{
		//create item first
		Disk *d = inventoryItems[hash]->tradeIn(line);
		if(TreeCollection[hash]->insert(d))
		return true;
		else return false;
	}
		 
	else 
	{
		cout << "Invalid item type: " << Itype << " Item not processed." << endl;
		return false;
	}
	
}

bool Inventory :: purchase(char Itype, string line)
{
	int hash = h->getHashValue(Itype);

	if(isValidItem(hash))
	{
		Disk *d = inventoryItems[hash]->purchase(line);
		if(TreeCollection[hash]->remove(*d))
		{
			delete d;
			return true;
		}
		else return false;
			 
	}
	else 
	{
		cout << "Invalid item type: " << Itype << " Item not processed." << endl;
		return false;
	}
}
bool Inventory :: isValidItem(int hashValue)
{
	if(hashValue != -1 && inventoryItems[hashValue] != NULL)
		return true;
	else return false;

}

bool Inventory :: createInventory(int numOfItems, string input, char type)
{
	int hash = h->getHashValue(type); 

	if(isValidItem(hash))
	{
		//create object first
		Disk *d = inventoryItems[hash]->Create(input);

		if(TreeCollection[hash]->insert(d))
		{
			TreeCollection[hash]->updateQuanity(d, numOfItems);
			return true;
		}
		else return false;
	}
		 
	else 
	{
		cout << "Invalid item type: " << type << " Item not processed." << endl;
		return false;
	}

}


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
			delete inventoryItems[i];
			inventoryItems[i] = NULL;
		}
	}
}
