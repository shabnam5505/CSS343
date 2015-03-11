//Shabnam Basmani
//This class inherits from Transactions is used to define how a purchase call will be made. This class interacts directly with 
//the inventory class.
#include "TransPurchase.h"
#include "Driver.h"
#include <sstream>

//default constructer creates a TransPurchase object
//no preconditions
//Postconditions: will create a TransPurchase object
TransPurchase::TransPurchase(void)
{
	details = " ";
	DiskType = ' ';
	errorMsg = " ";
}

//executeTransactions is an overriden method that assumes the data being pass in 
//is a call on the purchase transaction
//Preconditions: input must be formatted properly and a purchase transaction
//Postconditions: will call the inventory class function that performs this operation
void TransPurchase ::executeTransaction(string input, Driver *driver)
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
		if(!driver->purchase(type, atoi(custId.c_str()), transaction))
			cout << "Purchase was not sucessful." << endl;
			
	}
}

//print function used to print out purchase data
//Preconditions: none
//Postconditions: prints out details of transaction
void TransPurchase :: print() const
{
	if(errorMsg != " ")
		cout << errorMsg << " ";
	cout << "Purchase: " << DiskType << ", " << details << endl;
}

//setDiskType sets the type of Disk associated with the transaction
//Preconditions: a char is passed in
//Postconditions: sets the transaction's DiskType
void TransPurchase :: setDiskType(char diskObj)
{
	DiskType = diskObj;
}

//setDetails sets the details about a transaction
//Preconditons: valid string is passed in
//Postconditions: sets the details member
void TransPurchase :: setDetails(string info)
{
	details = info;
}

//setErrorMsg sets an error message if one occured
//Preconditons: valid string is passed
//Postconditions: sets the errorMsg member
void TransPurchase :: setErrorMsg(string error)
{
	errorMsg = error;
}

//getDiskType gets the type of Disk used in the transaction
//Preconditions: transaction has been intialized
//Postconditions: returns a char representing the type of Disk object used
char TransPurchase :: getDiskType() const
{
	return DiskType;
}

//getDetails gets the details about a transaction
//Preconditions: transaction has been intialized
//Postconditions: returns a string representing details about the transaction
string TransPurchase :: getDetails() const
{
	return details;
}

//getErrorMsg gets an error message if one happened during the transaction
//Preconditions: transaction has been intialized
//Postconditions: returns a string representing the error msg of a transaction or empty if none
string TransPurchase :: getErrorMsg() const
{
	return errorMsg;
}


//virtual destructor is used to clean up TransPurchase objects
//no preconditions
//Postconditions: cleans up all objects created
TransPurchase::~TransPurchase(void)
{
}
