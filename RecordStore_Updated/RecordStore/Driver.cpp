#include "Driver.h"

#include "Customer.h"


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

bool Driver :: isCustomerRecord(int id) const
{
	if(Customers[id] != NULL)
		return true;
	else
		return false;

}

void Driver::LoadCustomers(ifstream& infile) {

	if (infile.eof())
		return;
//	infile.ignore();  // throw away '\n' go to next line

   string value; 

   while(getline(infile, value))
   {
	   istringstream csvStream(value);

	   int count = 1;
	   int custId;
	   string lName;
	   string fName;
		while(getline(csvStream,value, ','))
		{
			
			if(count == 1)
				custId = stoi(value);
			else if(count == 2)
				lName = value;
			else
				fName = value;

			count++;

		}
		if(custId < 0)
		{
			cout << "Customer Id must be between 0 and 999." << endl;
		}
		else if(Customers[custId] == NULL)
		{
			Customer *c = new Customer(custId, lName, fName);
			CustTree.insert(c);
			Customers[custId] = c;
		}
		else
			cout << "Customer Id: " << custId << " has already been created." << endl;
		
   }
}

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
			if(type == '\n')
			{
			}
			else
			{
				infile.ignore(2);
				getline(infile,numOfItems, ',');
				infile.ignore();
				getline(infile, transaction);
			
				Warehouse.createInventory(stoi(numOfItems), transaction, type);
				
			}
		}
}



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

void Driver :: displayHistoryPerCust(int custID) const
{
	Customers[custID]->displayHistory(custID);
}

void Driver :: displayAllCustHistory()
{
	cout << "Display history for all customers:" << endl;
	CustTree.Output();
	cout << endl;
}

string Driver:: trim(string const& str)
{
    if(str.empty())
        return str;

    std::size_t first = str.find_first_not_of(' ');
    std::size_t last  = str.find_last_not_of(' ');
    return str.substr(first, last-first+1);
}

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

void Driver :: printCurrentInventory() const
{
	cout << "Current Inventory:" << endl;
	Warehouse.printCurrentInventory();

	cout << endl;
}



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
		Customers[i] = NULL;
	}
}
