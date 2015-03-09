#include "TransPurchase.h"
#include "Driver.h"
#include <sstream>


TransPurchase::TransPurchase(void)
{
	details = " ";
	DiskType = ' ';
	errorMsg = " ";
}

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

void TransPurchase :: print() const
{
	if(errorMsg != " ")
		cout << errorMsg << " ";
	cout << "Purchase: " << DiskType << ", " << details << endl;
}

void TransPurchase :: setDiskType(char diskObj)
{
	DiskType = diskObj;
}

void TransPurchase :: setDetails(string info)
{
	details = info;
}

void TransPurchase :: setErrorMsg(string error)
{
	errorMsg = error;
}



TransPurchase::~TransPurchase(void)
{
}
