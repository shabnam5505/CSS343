//The Driver class acts as a overseer of the entire store. Customer, Inventory, and Command files will be
//loaded in 3 seperate function calls from main. This class directly interacts with the inventory class and the customer as well as transactions.  
//When a customer is created a pointer is stored in a hash/array table for easy lookup on custId as well as added to BST of customers.
//Inventory items are passed to the Inventory class to decide which object needs to be created. Commands are sent to the proper 
//transaction object which then returns a call to this class. Transactions objects are passed to the customer to add them to their history.
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Inventory.h"
#include "BSTree.h"
#include "TransHistory.h"
#include "TransHistoryAll.h"
#include "TransInventory.h"
#include "TransPurchase.h"
#include "TransTradeIn.h"
#include "Hash.h"


using namespace std;
class Customer;
class Driver
{
public:
	//default constructor intializes all arrays being used and creates dummy transactions items 
	//Preconditions: none
	//Postconditions: will intialize the driver class to be used properly
	Driver(void);

	//LoadCustomers takes in a txt file and creates new customers so long as they do not already exist
	//Preconditions: File is formated correctly 
	//Postconditions: Customers will be created and pointers will be placed in BST and hash table
	void LoadCustomers(ifstream &);

	//LoadInventory takes a txt file and creates new inventory items by passing the correct data to the Inventory class
	//Preconditions: File is formatted correctly
	//Postconditions: New inventory items will be appropiately handed off to the Inventory class
	void LoadInventory(ifstream &);

	//ProcessTranscations takes in a txt file and loads and processes the given transactions. Some transactions will be handled by 
	//the driver class and others will be passed off to the inventory class
	//Preconditions: file is formatted correctly
	//Postconditions: transactions will be processed according to specs
	void ProcessTransactions(ifstream &);

	//isCustomerRecord returns if a customer already exists or not
	//Preconditions: customer id must be passed in
	//Postconditions: will return a true or false depending on if the customer exists or not
	bool isCustomerRecord(int id) const;

	//displayAllCustHistory displays all transaction history of all customers from the BST in alphabetical order
	//Preconditions: Files have already been loaded with accurate data
	//Postconditions: Will display customers alphabetically with a history of transactions in chronological order
	void displayAllCustHistory();

	//displayHistoryPerCust display all transactions in chronological order for a given customer
	//this method will use the hash table to quickly look up the customer and make a call to the customer class to get the 
	//correct information
	//Preconditions: Files should have been loaded with accurate data
	//Postconditions: will print to cout the history of tranactions for a given customer 
	void displayHistoryPerCust(int custID) const;

	//virtual distructor cleans up the dummy transactions hash table and the customer hash table
	//Preconditions: objects have been created
	//Postconditions: Dummy transaction hash items will be deleted as well as customers in hash table
	virtual ~Driver(void);

	//tradeIn passes partially parsed data to inventory to complete processing
	//Preconditions: file inputs were formatted properly
	//Postconditions: details will be passed the inventory for processing
	bool tradeIn(char Itype, int custId, string line);

	//purchase passes partially parsed data to inventory to complete processing
	//Preconditions: file must be formatted properly
	//Postconditions: details will be passed to inventory for processing
	bool purchase(char Itype, int custId, string line);

	//printCurrentInventory sends a request to inventory to print out its inventory
	//Preconditions: inventory has been intialized
	//Postconditions: sends a request to inventory to print its inventory
	void printCurrentInventory() const;
private:

	////might be usuful to trim strings??
	//string trim(string const& str);

	//An instance of the Inventory is necessary to display an inventory call
	Inventory Warehouse;

	//The BST of the Customers is used for a search call in alphabetical order to help with search time
	BSTree CustTree;

	//a pointer to Hash is needed to aquire the has value of a particular input
	Hash *h;

	//given customer ids must be a 3 digit id, I am assuming the hash table will not exceed 999. If it does it will not 
	//need to be rebuilt because no actual hash function exists. Just using the id in the array
	static const int MAX_ITEMS = 999;

	//hash table of Customers is used for quick look up of individual customers
	Customer* Customers[MAX_ITEMS];

	//This is the max number of transactions pointer the array can hold (based on a 26 letter alphabet)
	static const int MAX_TRANS_ITEMS = 26;
	
	//This is an array of transaction pointers that contain dummy objects to pointers for transaction objects
	Transactions* Transactions[MAX_TRANS_ITEMS];
};

