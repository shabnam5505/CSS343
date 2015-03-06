#include "TransHistoryAll.h"
#include "Driver.h"



TransHistoryAll::TransHistoryAll(void)
{
}

void TransHistoryAll ::executeTransaction(string input, Driver *driver)
{
	
	driver->displayAllCustHistory();
}

void TransHistoryAll :: print() const
{
	cout << "Please print from Driver Class." << endl;
}


TransHistoryAll::~TransHistoryAll(void)
{
}
