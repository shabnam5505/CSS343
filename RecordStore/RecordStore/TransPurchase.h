//Shabnam Basmani
//This class inherits from Transactions is used to define how a purchase call will be made. This class interacts directly with 
//the inventory class.
#pragma once
#include "Transactions.h"
class TransPurchase : public Transactions
{
public:
	//default constructer creates a TransPurchase object
	//no preconditions
	//Postconditions: will create a TransPurchase object
	TransPurchase(void);

	//executeTransactions is an overriden method that assumes the data being pass in 
	//is a call on the purchase transaction
	//Preconditions: input must be formatted properly and a purchase transaction
	//Postconditions: will call the inventory class function that performs this operation
	virtual void executeTransaction(string input, Driver *);

	//print function used to print out purchase data
	//Preconditions: none
	//Postconditions: prints out details of transaction
	virtual void print() const;

	//setDiskType sets the type of Disk associated with the transaction
	//Preconditions: a char is passed in
	//Postconditions: sets the transaction's DiskType
	void setDiskType(char diskObj);

	//setDetails sets the details about a transaction
	//Preconditons: valid string is passed in
	//Postconditions: sets the details member
	void setDetails(string info);

	//setErrorMsg sets an error message if one occured
	//Preconditons: valid string is passed
	//Postconditions: sets the errorMsg member
	void setErrorMsg(string error);

	//getDiskType gets the type of Disk used in the transaction
	//Preconditions: transaction has been intialized
	//Postconditions: returns a char representing the type of Disk object used
	char getDiskType() const;

	//getDetails gets the details about a transaction
	//Preconditions: transaction has been intialized
	//Postconditions: returns a string representing details about the transaction
	string getDetails() const;

	//getErrorMsg gets an error message if one happened during the transaction
	//Preconditions: transaction has been intialized
	//Postconditions: returns a string representing the error msg of a transaction or empty if none
	string getErrorMsg() const;

	//virtual destructor is used to clean up TransPurchase objects
	//no preconditions
	//Postconditions: cleans up all objects created
	virtual ~TransPurchase(void);

private:
	//type of Disk used in the transaction
	char DiskType;

	//details about the transaction
	string details;

	//errorMsg if one exists for transaction
	string errorMsg;
};

