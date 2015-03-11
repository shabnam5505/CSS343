//Shabnam Basmani
//This class is an abstract class used by the driver class to decide which transaction is being called on file read in
#include "Transactions.h"
#include "Driver.h"

//default constructor creates instance of object/ should never be called
//no preconditions
//creates a transaction object
Transactions::Transactions(void)
{
}

//virtual destructor is used to clean up any Transaction objects
//no precondtions
//will release memory of Transaction objects
Transactions::~Transactions(void)
{
}
