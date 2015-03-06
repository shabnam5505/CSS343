//Shabnam Basmani
//This is an abstract class that is used for all Disk items to inherit from. It is possible to add an additional Item class if needed to handle the record
//store being able to sell items not related to Disks. All disks should have a title and year of issue. This class inherits from treedata to be used in the BST. 
#pragma once
#include <iostream>
#include <string>
#include "TreeData.h"
using namespace std;
class Disk : public TreeData
{
	//output overloaded probably won't be used. maybe remove this??
	//output operator cannot be inherited
	friend ostream& operator<<(ostream &os, Disk &obj);
public:
	//Default constructor has no preconditions
	//Postconditions: will create a new Disk object 
	Disk(void);

	//Disk constructor that can handle a line from the file with proper parameters
	//Preconditions: file must be formatted properly
	//Postconditons: Will create an Disk object intializing title and year of issue
	Disk(string input);

	//Disk constructor that can take in a title and year of issue
	//Preconditions: must be correct data types
	//Postconditions: will create a disk object with both data members intialized
	Disk(string title, int year);

	//Creates and object. Most likely will not be needed
	virtual Disk* Create(string input);

	//overloaded equals is a pure virtual method used in the derived classes
	//Preconditions: none
	//Postconditons: none
	virtual bool operator==(const TreeData& obj) const = 0;


	//overloaded not equals is a pure virtual method used in the derived classes
	//Preconditions: none
	//Postconditons: none
	virtual bool operator!=(const TreeData& obj) const = 0;


	//overloaded less than is a pure virtual method used in the derived classes
	//Preconditions: none
	//Postconditons: none
	virtual bool operator<(const TreeData& obj) const = 0;


	//overloaded greater than is a pure virtual method used in the derived classes
	//Preconditions: none
	//Postconditons: none
	virtual bool operator>(const TreeData& obj) const = 0;

	//purchase is a pure virtual method used in the derived classes
	//Preconditions: none
	//Postconditons: none
	virtual Disk* purchase(string input) = 0;

	//tradeIn is a pure virtual method used in the derived classes
	//Preconditions: none
	//Postconditons: none
	virtual Disk* tradeIn(string input) = 0;

	//display is a pure virtual method used in the derived classes
	//Preconditions: none
	//Postconditons: none
	virtual void display(TreeData &obj) = 0;

	//virtual destructor used to clean up possible Disk objects
	virtual ~Disk(void);

	//getQuanity gets the quanity of a given item
	//no precondtions
	//Postcondtion: this method will return an integer representing the number of items of a given object
	virtual int getQuanity() const = 0;

	//setQuanity allows other classes to set the value of quanity
	//Precondition: must pass in an int
	//Postcondition: this method will set the quanity of the item
	virtual void setQuanity(int data) = 0;

protected:

	//title is used to store the title of the Disk
	//all derived classes can use this member
	string title;

	//yearOfIssue is used to store the year the Disk was issued
	//all derived classes can use this member
	int yearOfIssue;

	//trim trims a string of whitespace (I don't think this function is necessary)
	//Preconditions: a string must be passed in
	//Postconditions: will return a string without whitespace
	string trim(string const& str);

	
	
};

