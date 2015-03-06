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

bool Inventory :: tradeIn(char Itype, string line) const
{
	int hash = getHashValue(Itype); 
	 if(hash != -1)
	 {
		 if(inventoryItems[hash] != NULL)
		 {
			 //maybe intial all values in array to NULL??
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
	 cout << "Invalid item type: " << Itype << " Item not processed." << endl;
	 return false;
}

bool Inventory :: purchase(char Itype, string line) const
{
	int hash = getHashValue(Itype);
	if(hash != -1)
	{
		if(inventoryItems[hash] != NULL)
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
	else
	{
		cout << "Invalid item type: " << Itype << " Item not processed." << endl;
		return false;
	}
}

int Inventory :: getHashValue(char dtype) const
{
	//const char* c = dtype.c_str();
	int value = dtype;
	value = value - 65;
	if(value < 0 || value > 25)
		return -1;
	return value;
	
}

void Inventory :: printCurrentInventory() const
{
	for(int i = 1; i < MAX_ITEMS; i++)
	{
		if(TreeCollection[i] != NULL)
			TreeCollection[i]->Output();
	}
}


Inventory::~Inventory(void)
{
	for (int i = 0; i < 26; i++) {
		if(inventoryItems[i] != NULL)
		{
			//delete inventoryItems[i];
			inventoryItems[i] = NULL;
		}
	}
}
