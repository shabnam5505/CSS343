//Shabnam Basmani
//This class inherits from Disk object. This class is responsible for creating new DVD's and passing a Disk pointer back to the inventory class. 
//TradeIn added in the event of new fuctionally of a tradeIn including a possible creation 
#pragma once
#include <iostream>
#include "Disk.h"
class DVD : public Disk
{
public:
	//default constructor creates and instance of the object
	//no preconditions
	//Postconditions: creates a DVD object
	DVD(void);

	//virtual destructor used to clean up DVD objects
	//no preconditions
	//Postconditions: deletes memory of DVD objects
	virtual ~DVD(void);

	//constructor that takes in a string from the file and parses appropriately
	//Preconditions: imput file string is formatted properly
	//Postconditions: will create a new DVD with all data members properly intialized
	DVD(string line);

	//constructor that takes in all parameters for DVD 
	//Preconditions: data members are accurate
	//Postconditons: will create a DVD object with all data members intialized
	DVD(string title, int year, string director);

	virtual Disk* Create(string input);


	//purchase method is used to create a new DVD object and return a pointer to the Driver class
	//Preconditions: file is formatted properly
	//Postconditions: a new DVD object will be created and pointer to the object will be returned
	virtual Disk* purchase(string input);

	//tradeIn method is used to handle future tradeIn requests
	//Preconditions: file is formatted properly
	//Postconditions: this is open for defination
	virtual Disk* tradeIn(string input);

	//setDirectorName allows other classes to set the director in the object
	//Preconditions: string must be passed in
	//Postconditions: sets the director of the DVD object
	void setDirectorName(string director);

	//getDirectorName allows other classes to retrieve the director
	//Preconditions: none
	//Postconditions: will return a string that is the director of the DVD object
	string getDirectorName() const;

	//Overloaded equals operator is used for comparison in the BSTree class
	//Preconditions: a DVD object must be passed in
	//Postconditions: will compare if two DVD's are equal to eachother
	virtual bool operator==(const TreeData& obj) const;

	//Overloaded not equals operator is used for comparison in the BSTree class
	//Preconditions: a DVD object must be passed in
	//Postconditions: will compare if two DVD's are not equal to eachother
	virtual bool operator!=(const TreeData& obj) const;

	//Overloaded less than operator is used for comparison in the BSTree class
	//Preconditions: a DVD object must be passed in
	//Postconditions: will compare if a DVD is less than another customer according to the instructions to sort
	virtual bool operator<(const TreeData& obj) const;

	//Overloaded greater than operator is used for comparison in the BSTree class
	//Preconditions: a DVD object must be passed in
	//Postconditions: will compare if a DVD is greater than another customer according to the instructions to sort
	virtual bool operator>(const TreeData& obj) const;

	//display is a inherited method that outputs a DVD
	//Preconditions: A DVD must be passed in 
	//Postconditions: will display to console details of a DVD
	virtual void display(TreeData &obj, int count);

	//getQuanity gets the quanity of a given item
	//no precondtions
	//Postcondtion: this method will return an integer representing the number of items of a given object
	virtual int getQuanity() const;

	//setQuanity allows other classes to set the value of quanity
	//Precondition: must pass in an int
	//Postcondition: this method will set the quanity of the item
	virtual void setQuanity(int data);
protected:

	//stores a director
	string director;

};

