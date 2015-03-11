//Shabnam Basmani
//This class inherits from Transactions is used to define how a History all call will be made. This class interacts directly with 
//the driver class.
#include "TransHistoryAll.h"
#include "Driver.h"


//default constructer creates a TransHistoryAll object
//no preconditions
//Postconditions: will create a TransHistoryAll object
TransHistoryAll::TransHistoryAll(void)
{
}

//executeTransactions is an overriden method that assumes the data being pass in 
//is a call on the History All transaction
//Preconditions: input must be formatted properly and a History All transaction
//Postconditions: will call the driver class function that performs this operation
void TransHistoryAll ::executeTransaction(string input, Driver *driver)
{
	
	driver->displayAllCustHistory();
}

//print allows for a transaction object to be printed
//Preconditions: none
//Postconditions: at this time asks to print from driver class, perhaps use if required to track all transaction made to Record Store??
void TransHistoryAll :: print() const
{
	cout << "Please print from Driver Class." << endl;
}

//virtual destructor is used to clean up TransHistoryAll objects
//no preconditions
//Postconditions: cleans up all objects created
TransHistoryAll::~TransHistoryAll(void)
{
}
