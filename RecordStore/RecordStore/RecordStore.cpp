#include <iostream>
#include <fstream>
#include "Driver.h"
#include "Inventory.h"
using namespace std;

//-------------------------- main -------------------------------------------
// Tests the Graph class by reading data from "HW3.txt" 
// Preconditions:   If HW3.txt file exists, it must be formatted
//                  as described in the specifications.
// Postconditions:  The basic functionalities of the Graph class 
//                  are used.  Should compile, run to completion, and output  
//                  correct answers if the classes are implemented correctly.
int main() {
	ifstream infile("Customers.txt");
	if (!infile) {
		cerr << "File could not be opened." << endl;
		return 1;
	}
	ifstream infile1("Inventory.txt");
	if (!infile1) {
		cerr << "File could not be opened." << endl;
		return 1;
	}

	ifstream infile2("Commands.txt");
	if (!infile2) {
		cerr << "File could not be opened." << endl;
		return 1;
	}
	int waitVar;
	
	Driver D;
	Inventory I;
	D.LoadCustomers(infile);
	D.LoadInventory(infile1);
	//I.hash('R');
	D.ProcessTransactions(infile2);


	cin >> waitVar;
	return 0;
}