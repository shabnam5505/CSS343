//Shabnam Basmani
//This class inherits from Transactions is used to define how a tradeIn call will be made. This class interacts directly with 
//the inventory class.
#pragma once
#include "Transactions.h"
class TransTradeIn : public Transactions
{
public:
	//default constructer creates a TransTradeIn object
	//no preconditions
	//Postconditions: will create a TransTradeIn object
	TransTradeIn(void);

	//executeTransactions is an overriden method that assumes the data being pass in 
	//is a call on the tradeIn transaction
	//Preconditions: input must be formatted properly and a tradeIn transaction
	//Postconditions: will call the inventory class function that performs this operation
	virtual void executeTransaction(string input, Driver *);

	virtual void print() const;

	void setDiskType(char diskObj);

	void setDetails(string info);


	//virtual destructor is used to clean up TransTradeIn objects
	//no preconditions
	//Postconditions: cleans up all objects created
	virtual ~TransTradeIn(void);
private:
	char DiskType;
	string details;
};

