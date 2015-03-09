#include "TransInventory.h"
#include "Driver.h"


TransInventory::TransInventory(void)
{
}

void TransInventory ::executeTransaction(string input, Driver *driver)
{
	driver->printCurrentInventory();
}

void TransInventory :: print() const
{
	cout << "Please print from Inventory class." << endl;
}


TransInventory::~TransInventory(void)
{
}
