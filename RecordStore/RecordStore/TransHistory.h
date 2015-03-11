//Shabnam Basmani
//This class inherits from Transactions is used to define how a History call will be made. This class interacts directly with 
//the driver class.
#pragma once
#include "Transactions.h"
class TransHistory : public Transactions
{
public:
	//default constructer creates a TransHistory object
	//no preconditions
	//Postconditions: will create a TransHistory object
	TransHistory(void);

	//executeTransactions is an overriden method that assumes the data being pass in 
	//is a call on the History transaction
	//Preconditions: input must be formatted properly and a History transaction
	//Postconditions: will call the driver class function that performs this operation
	virtual void executeTransaction(string input, Driver *);

	//print function used to print out transaction data
	//Preconditions: none
	//Postconditions: asks user to print from driver class at this time
	virtual void print() const;

	//virtual destructor is used to clean up TransHistory objects
	//no preconditions
	//Postconditions: cleans up all objects created
	virtual ~TransHistory(void);
};

