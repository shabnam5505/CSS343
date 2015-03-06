//Shabnam Basmani
//This class is an abstract class used by the driver class to decide which transaction is being called on file read in
#pragma once
#include <iostream>

using namespace std;
class Driver;
class Transactions
{
public:
	//default constructor is all that is needed. This object should never been created
	Transactions(void);

	//executeTransactions is a pure virtual method that will be used by derived classes
	//no preconditions
	//no postconditions
	virtual void executeTransaction(string input, Driver *) = 0;

	virtual void print() const = 0;

	//virtual destructor is used to clean up any Transaction objects
	//no precondtions
	//will release memory of Transaction objects
	virtual ~Transactions(void);

protected:






};

