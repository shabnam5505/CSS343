//The Driver class acts as a overseer of the entire store. Customer, Inventory, and Command files will be
//loaded in 3 seperate function calls from main. This class directly interacts with the inventory class and the customer as well as transactions.  
//When a customer is created a pointer is stored in a hash/array table for easy lookup on custId as well as added to BST of customers.
//Inventory items are passed to the Inventory class to decide which object needs to be created. Commands are sent to the proper 
//transaction object which then returns a call to this class. Transactions objects are passed to the customer to add them to their history.
#include "Driver.h"

#include "Customer.h"


//default constructor intializes all arrays being used and creates dummy transactions items 
//Preconditions: none
//Postconditions: will intialize the driver class to be used properly
Driver::Driver(void)
{
	for(int i = 0; i < MAX_TRANS_ITEMS; i++)
	{
		Transactions[i] = NULL;
	}

	Transactions[0] = new TransHistoryAll;
	Transactions[7] = new TransHistory;
	Transactions[8] = new TransInventory;
	Transactions[15] = new TransPurchase;
	Transactions[19] = new TransTradeIn;

	for(int i = 0; i < MAX_ITEMS; i++)
	{
		Customers[i] = NULL;
	}
}

//isCustomerRecord returns if a customer already exists or not
//Preconditions: customer id must be passed in
//Postconditions: will return a true or false depending on if the customer exists or not
bool Driver :: isCustomerRecord(int id) const
{
	if(Customers[id] != NULL)
		return true;
	else
		return false;

}

//LoadCustomers takes in a txt file and creates new customers so long as they do not already exist
//Preconditions: File is formated correctly 
//Postconditions: Customers will be created and pointers will be placed in BST and hash table
void Driver::LoadCustomers(ifstream& infile) {

	if (infile.eof())
		return;

   string value; 

   while(getline(infile, value))
   {
	   istringstream csvStream(value);

	   int count = 1;
	   int custId = -1;
	   string lName;
	   string fName;

	   //gets the value of each string before the comma and places it in the proper given the count of the loop
		while(getline(csvStream,value, ','))
		{
			if(value == "/n")
				break;
			if(count == 1)
				custId = stoi(value);
			else if(count == 2)
				lName = value;
			else
				fName = value;

			count++;

		}
		//a blank line was passed
		if(custId == -1)
		{
			cout << "Empty line." << endl;
		}
		//invalid customer id passed
		else if(custId < 0 || custId > MAX_ITEMS)
		{
			cout << "Customer Id must be between 0 and 999." << endl;
		}
		//new customer is created 
		else if(Customers[custId] == NULL)
		{
			Customer *c = new Customer(custId, lName, fName);
			CustTree.insert(c);
			Customers[custId] = c;
		}
		//the customer already exists and cannot be created
		else
			cout << "Customer Id: " << custId << " has already been created." << endl;
		
   }
}

//LoadInventory takes a txt file and creates new inventory items by passing the correct data to the Inventory class
//Preconditions: File is formatted correctly
//Postconditions: New inventory items will be appropiately handed off to the Inventory class
void Driver :: LoadInventory(ifstream &infile)
{
	if (infile.eof())
		return;
		while(infile.good())
		{
			char type;
			string numOfItems;
			string transaction;
			string custId;
			infile.get(type);
			//blank line has been passed
			if(type == '\n')
			{
			}
			else
			{
				infile.ignore(2);
				getline(infile,numOfItems, ',');
				infile.ignore();
				getline(infile, transaction);
				//after proper parsing send data to inventory to create
				Warehouse.createInventory(stoi(numOfItems), transaction, type);
				
			}
		}
}


//ProcessTranscations takes in a txt file and loads and processes the given transactions. Some transactions will be handled by 
//the driver class and others will be passed off to the inventory class
//Preconditions: file is formatted correctly
//Postconditions: transactions will be processed according to specs
void Driver :: ProcessTransactions(ifstream &infile)
{
		if (infile.eof())
		return;
		while(infile.good())
		{
			char command;
			char type;
			string transaction;
			string custId;
			infile.get(command);
			getline(infile, transaction);
			int hash = h->getHashValue(command);
			//if a transaction object exists pass it to object to parse
			if(Transactions[hash] != NULL)
			{
				Transactions[hash]->executeTransaction(transaction, this);
			}
			else if(command == '\n')
			{
				cout << "End of file." ;
			}
			else
			{
				cout << "Transaction code: " << command << " does not exist." << endl;
			}

		}
}


//displayHistoryPerCust display all transactions in chronological order for a given customer
//this method will use the hash table to quickly look up the customer and make a call to the customer class to get the 
//correct information
//Preconditions: Files should have been loaded with accurate data
//Postconditions: will print to cout the history of tranactions for a given customer 
void Driver :: displayHistoryPerCust(int custID) const
{
	Customers[custID]->displayHistory(custID);
}

//displayAllCustHistory displays all transaction history of all customers from the BST in alphabetical order
//Preconditions: Files have already been loaded with accurate data
//Postconditions: Will display customers alphabetically with a history of transactions in chronological order
void Driver :: displayAllCustHistory()
{
	cout << "Display history for all customers:" << endl;
	CustTree.Output();
	cout << endl;
}

//string Driver:: trim(string const& str)
//{
//    if(str.empty())
//        return str;
//
//    std::size_t first = str.find_first_not_of(' ');
//    std::size_t last  = str.find_last_not_of(' ');
//    return str.substr(first, last-first+1);
//}


//tradeIn passes an item to the inventory to process 
//Preconditions: file inputs were formatted properly
//Postconditions: details will be passed the inventory for processing
bool Driver :: tradeIn(char Itype, int custId, string line)
{

	TransTradeIn *t = new TransTradeIn;
	t->setDiskType(Itype);
	t->setDetails(line);
	
	//Send to Inventory to tradeIn; if not sucessful add an error message to transaction 
	if(! Warehouse.tradeIn(Itype, line))
	{
		string errorMsg = "TRANSACTION NOT PROCESSED:";
		t->setErrorMsg(errorMsg);
	}
	//Add transaction to customer's history
	Customers[custId]->addToHistory(t);

	return true;
	
}

//purchase passes partially parsed data to inventory to complete processing
//Preconditions: file must be formatted properly
//Postconditions: details will be passed to inventory for processing
bool Driver :: purchase(char Itype, int custId, string line)
{
	TransPurchase *t = new TransPurchase;
	t->setDiskType(Itype);
	t->setDetails(line);

	//Send to Inventory to purchase; if not sucessful add an error message to transaction 
	if(! Warehouse.purchase(Itype, line))
	{
		string errorMsg = "TRANSACTION NOT PROCESSED:";
		t->setErrorMsg(errorMsg);
	}
	//Add transaction to customer's history
	Customers[custId]->addToHistory(t);

	return true;

}

//printCurrentInventory sends a request to inventory to print out its inventory
//Preconditions: inventory has been intialized
//Postconditions: sends a request to inventory to print its inventory
void Driver :: printCurrentInventory() const
{
	cout << "Current Inventory:" << endl;
	Warehouse.printCurrentInventory();

	cout << endl;
}


//virtual distructor cleans up the dummy transactions hash table and the customer hash table
//Preconditions: objects have been created
//Postconditions: Dummy transaction hash items will be deleted as well as customers in hash table
Driver::~Driver(void)
{
	for(int i = 0; i < MAX_TRANS_ITEMS; i++)
	{
		if(Transactions[i] != NULL)
		{
			delete Transactions[i];
			Transactions[i] = NULL;
		}
	}

	for(int i = 0; i < MAX_ITEMS; i++)
	{
		if(Customers[i] != NULL)
		{
			//customer objects already deleted by BST set memory to null
			Customers[i] = NULL;
		}
	}

}
