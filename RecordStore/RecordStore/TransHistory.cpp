#include "TransHistory.h"
#include <sstream>
#include "Driver.h"

TransHistory::TransHistory(void)
{
}

void TransHistory ::executeTransaction(string input, Driver *driver)
{
	stringstream ss(input);
	string custId;
	char type;
	string transaction;
	ss.ignore(2);
	getline(ss,custId, ',');
	int custIdNum = atoi(custId.c_str());

	if(driver->isCustomerRecord(custIdNum))
	{
		driver->displayHistoryPerCust(custIdNum);
	}
	else
		cout << "Invalid customer number: " << custIdNum << " No history available." << endl;
}

void TransHistory :: print() const
{
	cout << "Please print from Driver class." << endl;
}


TransHistory::~TransHistory(void)
{
}
