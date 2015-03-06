#include "Customer.h"
#include <string>
#include <vector>


Customer::Customer(void)
{
}

Customer :: Customer(int id, string name)
{
	custId = id;
	custName = name;
}
//getQuanity gets the quanity of a given item
//no precondtions
//Postcondtion: this method will return an integer representing the number of items of a given object
int Customer :: getQuanity() const
{
	return quanity;
}

//setQuanity allows other classes to set the value of quanity
//Precondition: must pass in an int
//Postcondition: this method will set the quanity of the item
void Customer :: setQuanity(int data)
{
	quanity = data;
}

bool Customer :: operator==(const TreeData& obj) const
{
	const Customer &cust = static_cast<const Customer &>(obj);
	if(custName == cust.custName)
		return true;
	else return false;
}

//overloaded not equals
bool Customer :: operator!=(const TreeData& obj) const
{
	const Customer &cust = static_cast<const Customer &>(obj);
	if(custName != cust.custName)
		return true;
	else return false;
}
	
//overloaded less than 
bool Customer :: operator<(const TreeData& obj) const
{
	const Customer &cust = static_cast<const Customer &>(obj);
	if(custName < cust.custName)
		return true;
	else return false;
}

//overloaded greater than
bool Customer :: operator>(const TreeData& obj) const
{
	const Customer &cust = static_cast<const Customer &>(obj);
	if(custName > cust.custName)
		return true;
	else return false;
}

void Customer :: display(TreeData &obj)
{
	const Customer &cust = static_cast<const Customer &>(obj);
	cout << "Customer Name: " << cust.custName << " Customer ID: " << cust.custId << " Transaction History: " << endl;
	for(int i = 0; i < History.size(); i++)
	{
		if(History[i] != NULL)
			History[i]->print();
	}
}

void Customer :: displayHistory(int id)
{
		for(int i = 0; i < History.size(); i++)
	{
		if(History[i] != NULL)
		{
			cout << "History for Customer ID: " << custId << endl;
			History[i]->print();
		}

	}
}

void Customer :: addToHistory(Transactions *trans)
{
	History.push_back(trans);
}


Customer::~Customer(void)
{
}
