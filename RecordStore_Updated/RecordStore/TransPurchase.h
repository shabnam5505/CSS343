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

	virtual void print() const;

	void setDiskType(char diskObj);

	void setDetails(string info);

	void setErrorMsg(string error);


	//virtual destructor is used to clean up TransPurchase objects
	//no preconditions
	//Postconditions: cleans up all objects created
	virtual ~TransPurchase(void);

private:
	char DiskType;
	string details;
	string errorMsg;
};

