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
	   string custName;
		while(getline(csvStream,value, ','))
		{
			
			if(count == 1)
				custId = stoi(value);
			else
				custName = value;

			count++;

			//std::cout << "Value: " << trim(value) << endl;;
		}
			Customer *c = new Customer(custId, custName);
			CustTree.insert(c);
			Customers[custId] = c;
		
   }
}

void Driver :: LoadInventory(ifstream &infile)
{
	if (infile.eof())
		return;
		while(infile.good())
		{
			char type;
			char numOfItems;
			string transaction;
			string custId;
			infile.get(type);
			if(type == '\n')
			{
			}
			else
			{
				infile.ignore(2);
				infile.get(numOfItems);
				getline(infile, transaction);
				for(int i = 0; i < numOfItems - '0'; i++)
				{
					Warehouse.tradeIn(type, transaction);
				}
			}
		}




//	if (infile.eof())
//		return;
////	infile.ignore();  // throw away '\n' go to next line
//
//   string value; 
//   while(getline(infile, value))
//   {
//	   istringstream csvStream(value);
//
//	   
//		getline(csvStream,value, ',');
//		string Itype = value;
//		string s;
//		getline(csvStream,value, ',');
//		int numberOfObjects = atoi(value.c_str());
//		while(getline(csvStream,value))
//		{
//
//			s = s.append(value);
//		}
//
//		//Warehouse.createObject(hash);
//			//check customer 
//			//get hash value
//			for(int i = 0; i < numberOfObjects; i++)
//			{
//				//call tradeIn or purchase here
//				//.insert(Warehouse.createObject(Itype, s));
//				Warehouse.purchase(
//			}
//			std::cout << "Value: " << trim(s) << endl;;
//		
//		std::cout << "Line Finished" << std::endl;
//		//InventoryItems.Print();
//   }
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
			int hash = getHashValue(command);
			if(Transactions[hash] != NULL)
			{
				Transactions[hash]->executeTransaction(transaction, this);
			}
			else
			{
				cout << "Transaction code: " << command << " does not exist." << endl;
			}

		}
}
int Driver :: getHashValue(char dtype) const
{
	//const char* c = dtype.c_str();
	int value = dtype;
	value = value - 65;
	if(value < 0 || value > 25)
		return -1;
	return value;
	
}

void Driver :: displayHistoryPerCust(int custID) const
{
	Customers[custID]->displayHistory(custID);
}

void Driver :: displayAllCustHistory()
{
	CustTree.Output();
}

string Driver:: trim(string const& str)
{
    if(str.empty())
        return str;

    std::size_t first = str.find_first_not_of(' ');
    std::size_t last  = str.find_last_not_of(' ');
    return str.substr(first, last-first+1);
}

bool Driver :: tradeIn(char Itype, int custId, string line) const
{

	TransTradeIn *t = new TransTradeIn;
	t->setDiskType(Itype);
	t->setDetails(line);
	Customers[custId]->addToHistory(t);
	return Warehouse.tradeIn(Itype, line);
	
}

bool Driver :: purchase(char Itype, int custId, string line) const
{
	TransPurchase *t = new TransPurchase;
	t->setDiskType(Itype);
	t->setDetails(line);
	Customers[custId]->addToHistory(t);
	return Warehouse.purchase(Itype, line);
}

void Driver :: printCurrentInventory() const
{
	Warehouse.printCurrentInventory();
}



Driver::~Driver(void)
{
}
