//Shabnam Basmani
//This class inherits from Transactions is used to define how a History call will be made. This class interacts directly with 
//the driver class.
#include "TransHistory.h"
#include <sstream>
#include "Driver.h"

//default constructer creates a TransHistory object
//no preconditions
//Postconditions: will create a TransHistory object
TransHistory::TransHistory(void)
{
}

//executeTransactions is an overriden method that assumes the data being pass in 
//is a call on the History transaction
//Preconditions: input must be formatted properly and a History transaction
//Postconditions: will call the driver class function that performs this operation
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

//print function used to print out transaction data
//Preconditions: none
//Postconditions: asks user to print from driver class at this time
void TransHistory :: print() const
{
	cout << "Please print from Driver class." << endl;
}

//virtual destructor is used to clean up TransHistory objects
//no preconditions
//Postconditions: cleans up all objects created
TransHistory::~TransHistory(void)
{
}
