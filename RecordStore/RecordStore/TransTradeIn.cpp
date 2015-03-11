//Shabnam Basmani
//This class inherits from Transactions is used to define how a tradeIn call will be made. This class interacts directly with 
//the inventory class.
#include "TransTradeIn.h"
#include <sstream>
#include "Driver.h"

//default constructer creates a TransTradeIn object
//no preconditions
//Postconditions: will create a TransTradeIn object
TransTradeIn::TransTradeIn(void)
{
	details = " ";
	DiskType = ' ';
	errorMsg = " ";
}

//executeTransactions is an overriden method that assumes the data being pass in 
//is a call on the tradeIn transaction
//Preconditions: input must be formatted properly and a tradeIn transaction
//Postconditions: will call the inventory class function that performs this operation
void TransTradeIn ::executeTransaction(string input, Driver *driver)
{
	stringstream ss(input);
	string custId;
	char type;
	string transaction;
	ss.ignore(2);
	getline(ss,custId, ',');
	if(driver->isCustomerRecord(atoi(custId.c_str())))
	{
		ss.ignore();
		ss.get(type);
		ss.ignore(2);
		getline(ss, transaction);
		if(!driver->tradeIn(type, atoi(custId.c_str()), transaction))
			cout << "Trade in was not sucessful." << endl;
			
	}
}

//print function used to print out trade in data
//Preconditions: none
//Postconditions: prints out details of transaction
void TransTradeIn :: print() const
{
	if(errorMsg != " ")
		cout << errorMsg << " ";

	cout << "TradeIn: " << DiskType  << ", " << details << endl;
}

//setDiskType sets the type of Disk associated with the transaction
//Preconditions: a char is passed in
//Postconditions: sets the transaction's DiskType
void TransTradeIn :: setDiskType(char diskObj)
{
	DiskType = diskObj;
}

//setDetails sets the details about a transaction
//Preconditons: valid string is passed in
//Postconditions: sets the details member
void TransTradeIn :: setDetails(string info)
{
	details = info;
}

//setErrorMsg sets an error message if one occured
//Preconditons: valid string is passed
//Postconditions: sets the errorMsg member
void TransTradeIn :: setErrorMsg(string error)
{
	errorMsg = error;
}

//getDiskType gets the type of Disk used in the transaction
//Preconditions: transaction has been intialized
//Postconditions: returns a char representing the type of Disk object used
char TransTradeIn :: getDiskType() const
{
	return DiskType;
}

//getDetails gets the details about a transaction
//Preconditions: transaction has been intialized
//Postconditions: returns a string representing details about the transaction
string TransTradeIn :: getDetails() const
{
	return details;
}

//getErrorMsg gets an error message if one happened during the transaction
//Preconditions: transaction has been intialized
//Postconditions: returns a string representing the error msg of a transaction or empty if none
string TransTradeIn :: getErrorMsg() const
{
	return errorMsg;
}

//virtual destructor is used to clean up TransTradeIn objects
//no preconditions
//Postconditions: cleans up all objects created
TransTradeIn::~TransTradeIn(void)
{
}
