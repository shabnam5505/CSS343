//Shabnam Basmani
//This class creates individual customers and stores each transaction made by a customer. The driver class interacts directly with this class.
//This class inherits from TreeData inorder for it to be used in the BSTree Class
#include "Customer.h"
#include <string>
#include <vector>

//default constructor creates an instance of a customer
//no preconditions
//Postconditions: creates a new customer object
Customer::Customer(void)
{
	custId = NULL;
	lName = " ";
	fName = " ";
}

//overloaded constructor creates an instance of a customer with parameters
//Preconditons: Must pass in valid data types
//Postconditions: creates a new customer object intialzing custId and custName
Customer :: Customer(int id, string last, string first)
{
	custId = id;
	lName = last;
	fName = first;;
}

//Overloaded equals operator is used for comparison in the BSTree class
//Preconditions: a Customer object must be passed in
//Postconditions: will compare if two Customers are equal to eachother
bool Customer :: operator==(const TreeData& obj) const
{
	const Customer &cust = static_cast<const Customer &>(obj);
	if(lName == cust.lName && fName == cust.fName && custId == cust.custId)
		return true;
	else return false;
}

//Overloaded not equals operator is used for comparison in the BSTree class
//Preconditions: a Customer object must be passed in
//Postconditions: will compare if two Customers are not equal to eachother
bool Customer :: operator!=(const TreeData& obj) const
{
	const Customer &cust = static_cast<const Customer &>(obj);
	if(lName != cust.lName && fName != cust.fName && custId == cust.custId)
		return true;
	else return false;
}
	
//Overloaded less than operator is used for comparison in the BSTree class
//Preconditions: a Customer object must be passed in
//Postconditions: will compare if a Customer is less than another customer according to the instructions to sort
bool Customer :: operator<(const TreeData& obj) const
{
	const Customer &cust = static_cast<const Customer &>(obj);
	if(lName <= cust.lName)
	{
		if(lName == cust.lName)
		{
			if(fName < cust.fName)
				return true;
			else return false;
		}
		return true;
	}
	else return false;
}

//Overloaded greater than operator is used for comparison in the BSTree class
//Preconditions: a Customer object must be passed in
//Postconditions: will compare if a Customer is greater than another customer according to the instructions to sort
bool Customer :: operator>(const TreeData& obj) const
{
	const Customer &cust = static_cast<const Customer &>(obj);
	if(lName >= cust.lName)
	{
		if(lName == cust.lName)
		{
			if(fName > cust.fName)
				return true;
			else return false;
		}
		return true;
	}
	else return false;
}

//display is a inherited method that outputs a customer
//Preconditions: A customer must be passed in 
//Postconditions: will display to console a customer's data
void Customer :: display(TreeData &obj, int count)
{
	const Customer &cust = static_cast<const Customer &>(obj);
	cout << endl;
	cout << "Customer Name: " << cust.fName << " " << cust.lName << " Customer ID: " << cust.custId << " Transaction History: " << endl;
	for(int i = 0; i < History.size(); i++)
	{
		if(History[i] != NULL)
			History[i]->print();
	}
	cout << endl;
}

//displayHistory outputs transactions of a customer
//Precondtions: int must be passed in
//Postconditions: method will print to console one customer with Transaction History (used directly by Driver class)
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
	cout << endl;
}


//addToHistory adds a new transaction to the customer's history
//Preconditions: customer is created and valid transaction object is passed in
//Postconditons: a new transaction object is added to the history vector
void Customer :: addToHistory(Transactions *trans)
{
	History.push_back(trans);
}


//virtual destructor used to clean up customer objects
//no preconditions
//Postcondtions: deletes customer objects
Customer::~Customer(void)
{
	for(int i = 0; i < History.size(); i++)
	{
		delete History[i];
		History[i] = NULL;
	}
}
