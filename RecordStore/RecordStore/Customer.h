//Shabnam Basmani
//This class creates individual customers and stores each transaction made by a customer. The driver class interacts directly with this class.
//This class inherits from TreeData inorder for it to be used in the BSTree Class
#pragma once
#include <iostream>
#include <vector>
#include "Transactions.h"
//#include "Transactions.h"
#include "TreeData.h"
using namespace std;
class Customer : public TreeData
{
public:
	//default constructor creates an instance of a customer
	//no preconditions
	//Postconditions: creates a new customer object
	Customer(void);

	//overloaded constructor creates an instance of a customer with parameters
	//Preconditons: Must pass in valid data types
	//Postconditions: creates a new customer object intialzing custId and custName
	Customer(int custId, string custName);

	//virtual destructor used to clean up customer objects
	//no preconditions
	//Postcondtions: deletes customer objects
	virtual ~Customer(void);

	//Overloaded equals operator is used for comparison in the BSTree class
	//Preconditions: a Customer object must be passed in
	//Postconditions: will compare if two Customers are equal to eachother
	virtual bool operator==(const TreeData& obj) const;

	//Overloaded not equals operator is used for comparison in the BSTree class
	//Preconditions: a Customer object must be passed in
	//Postconditions: will compare if two Customers are not equal to eachother
	virtual bool operator!=(const TreeData& obj) const;

	//Overloaded less than operator is used for comparison in the BSTree class
	//Preconditions: a Customer object must be passed in
	//Postconditions: will compare if a Customer is less than another customer according to the instructions to sort
	virtual bool operator<(const TreeData& obj) const;

	//Overloaded greater than operator is used for comparison in the BSTree class
	//Preconditions: a Customer object must be passed in
	//Postconditions: will compare if a Customer is greater than another customer according to the instructions to sort
	virtual bool operator>(const TreeData& obj) const;

	//displayHistory outputs transactions of a customer
	//Precondtions: int must be passed in
	//Postconditions: method will print to console one customer with Transaction History (used directly by Driver class)
	void displayHistory(int id);

	//addCustomerTransaction allows Driver class to add a transaction to a customer
	//Preconditions: input is properly formatted
	//Postconditions: will add a transaction to the History vector
	void addCustomerTransaction(string input);

	//display is a inherited method that outputs a customer
	//Preconditions: A customer must be passed in 
	//Postconditions: will display to console a customer's data
	virtual void display(TreeData &obj);

	void addToHistory(Transactions *);

	//getQuanity gets the quanity of a given item
	//no precondtions
	//Postcondtion: this method will return an integer representing the number of items of a given object
	virtual int getQuanity() const;

	//setQuanity allows other classes to set the value of quanity
	//Precondition: must pass in an int
	//Postcondition: this method will set the quanity of the item
	virtual void setQuanity(int data);
	

private:
	//this stores the customer id
	int custId;

	//this stores the customer name (first and last)
	string custName;

	//this vector contains the History of transaction of each customer
	vector <Transactions*> History;
};

