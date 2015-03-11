//Shabnam Basmani
//This class inherits from Transactions is used to define how a History all call will be made. This class interacts directly with 
//the driver class.
#pragma once
#include "Transactions.h"
class TransHistoryAll : public Transactions
{
public:
	//default constructer creates a TransHistoryAll object
	//no preconditions
	//Postconditions: will create a TransHistoryAll object
	TransHistoryAll(void);

	//executeTransactions is an overriden method that assumes the data being pass in 
	//is a call on the History All transaction
	//Preconditions: input must be formatted properly and a History All transaction
	//Postconditions: will call the driver class function that performs this operation
	virtual void executeTransaction(string input, Driver *);

	//print allows for a transaction object to be printed
	//Preconditions: none
	//Postconditions: at this time asks to print from driver class, perhaps use if required to track all transaction made to Record Store??
	virtual void print() const;

	//virtual destructor is used to clean up TransHistoryAll objects
	//no preconditions
	//Postconditions: cleans up all objects created
	virtual ~TransHistoryAll(void);

};

