#include <iostream>
#include <fstream>
#include "Driver.h"
#include "Inventory.h"
#include <string.h>
using namespace std;


//-------------------------- main -------------------------------------------
// Tests the Graph class by reading data from "HW3.txt" 
// Preconditions:   If HW3.txt file exists, it must be formatted
//                  as described in the specifications.
// Postconditions:  The basic functionalities of the Graph class 
//                  are used.  Should compile, run to completion, and output  
//                  correct answers if the classes are implemented correctly.
int main() {

#ifdef _DEBUG
       int flag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
       flag |= _CRTDBG_LEAK_CHECK_DF; // Turn on leak-checking bit
       _CrtSetDbgFlag(flag);
	   //_CrtSetBreakAlloc(1363);
#endif

	ifstream infile("hw4customers.txt");
	if (!infile) {
		cerr << "File could not be opened." << endl;
		return 1;
	}
	ifstream infile1("hw4inventory.txt");
	if (!infile1) {
		cerr << "File could not be opened." << endl;
		return 1;
	}

	ifstream infile2("hw4commands.txt");
	if (!infile2) {
		cerr << "File could not be opened." << endl;
		return 1;
	}
	int waitVar;
	
	Driver D;
	D.LoadCustomers(infile);
	D.LoadInventory(infile1);
	D.ProcessTransactions(infile2);

	cin >> waitVar;
	



	
	return 0;
}