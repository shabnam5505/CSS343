#include "TransTradeIn.h"
#include <sstream>
#include "Driver.h"

TransTradeIn::TransTradeIn(void)
{
	details = " ";
	DiskType = ' ';
	errorMsg = " ";
}

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

void TransTradeIn :: print() const
{
	if(errorMsg != " ")
		cout << errorMsg << " ";

	cout << "TradeIn: " << DiskType  << ", " << details << endl;
}

void TransTradeIn :: setDiskType(char diskObj)
{
	DiskType = diskObj;
}

void TransTradeIn :: setDetails(string info)
{
	details = info;
}

void TransTradeIn :: setErrorMsg(string error)
{
	errorMsg = error;
}



TransTradeIn::~TransTradeIn(void)
{
}
