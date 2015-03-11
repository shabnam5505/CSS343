//Shabnam Basmani
//This class inherits from Disk object. This class is responsible for creating new DVD's and passing a Disk pointer back to the inventory class. 
//TradeIn added in the event of new fuctionally of a tradeIn including a possible creation 
#pragma once
#include <iostream>
#include "Disk.h"
class DVD : public Disk
{
public:
	//output operator overloaded to print out a classical cd object
	//Preconditions: a valid classicalCD object is passed in
	//Postconditions: prints out a classicalCD object
	friend ostream& operator<<(ostream &os, DVD &dvd);

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

	//Create creates an instance of a DVD and passes back a pointer
	//Preconditions: input is formatted correctly
	//Postconditions: A disk pointer will be returned of a new DVD object
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
	virtual void setDirectorName(string director);

	//getDirectorName allows other classes to retrieve the director
	//Preconditions: none
	//Postconditions: will return a string that is the director of the DVD object
	virtual string getDirectorName() const;

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

	//getTitle returns the title of the DVD
	//Preconditions: object has been created
	//Postconditions: returns a string representing the title
	virtual string getTitle() const;

	//setTitle sets the title of a DVD 
	//Preconditions: a string is passed in
	//Postconditions: updates the value of the title
	virtual void setTitle(string t);

	//get returns the year of issue of the DVD
	//Preconditions: the object has been intialized
	//Postconditions: returns an int representing year of issue
	virtual int getYear() const;

	//setYear sets the year of issue of the DVD
	//Preconditons: passing in a valid int, object exists
	//Postconditions: sets the year of issue of the DVD
	virtual void setYear(int year);

protected:

	//stores a director
	string director;

};

