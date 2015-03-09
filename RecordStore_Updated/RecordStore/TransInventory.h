//Shabnam Basmani
//This class inherits from Transactions is used to define how an inventory call will be made. This class interacts directly with 
//the inventory class.
#pragma once
#include "Transactions.h"
class TransInventory : public Transactions
{
public:
	//default constructer creates a TransInventory object
	//no preconditions
	//Postconditions: will create a TransInventory object
	TransInventory(void);

	//executeTransactions is an overriden method that assumes the data being pass in 
	//is a call on the inventory transaction
	//Preconditions: input must be formatted properly and an inventory transaction
	//Postconditions: will call the inventory class function that performs this operation
	virtual void executeTransaction(string input, Driver *);

	virtual void print() const;


	//virtual destructor is used to clean up TransInventory objects
	//no preconditions
	//Postconditions: cleans up all objects created
	virtual ~TransInventory(void);
};

