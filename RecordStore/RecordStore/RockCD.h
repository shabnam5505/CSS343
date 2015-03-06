//Shabnam Basmani
//This class inherits from Disk object. This class is responsible for creating new RockCD's and passing a Disk pointer back to the inventory class. 
//TradeIn added in the event of new fuctionally of a tradeIn including a possible creation 
#pragma once
#include "Disk.h"
class RockCD : public Disk
{
	//Overloaded output operator used to directly output a RockCD
	//Preconditons: must have valid parameters
	//Postconditions: will print to console the contents of a RockCD (this is mostly used for testing or expansions)
	friend ostream& operator<<(ostream &os, RockCD &obj);
public:
	//default constructor creates a RockCD object
	//no preconditions
	//Postconditions: creates a RockCD object
	RockCD(void);

	//virtual destructor used to clean up RockCD objects
	//no preconditions
	//Postconditions: deletes memory of RockCD objects
	virtual ~RockCD(void);

	//constructor that takes in a string from the file and parses appropriately
	//Preconditions: imput file string is formatted properly
	//Postconditions: will create a new RockCD with all data members properly intialized
	RockCD(string line);

	//constructor that takes in all parameters for RockCD 
	//Preconditions: data members are accurate
	//Postconditons: will create a RockCD object with all data members intialized
	RockCD(string title, int year, string artist);

	//purchase method is used to create a new RockCD object and return a pointer to the Driver class
	//Preconditions: file is formatted properly
	//Postconditions: a new RockCD object will be created and pointer to the object will be returned
	virtual Disk* purchase(string input);

	//tradeIn method is used to handle future tradeIn requests
	//Preconditions: file is formatted properly
	//Postconditions: this is open for defination
	virtual Disk* tradeIn(string input);

	//setArtistName allows for the artistName to be set by other classes
	//Preconditions: string is passed in
	//Postconditions: will set the value accordingly
	void setArtistName(string artist);

	//getArtistName allows for other classes to be able to retrieve this value
	//Preconditions: none
	//Postconditions: will return a string of the value in artistName
	string getArtistName() const;

	//Overloaded equals operator is used for comparison in the BSTree class
	//Preconditions: a RockCD object must be passed in
	//Postconditions: will compare if two RockCD's are equal to eachother
	virtual bool operator==(const TreeData& obj) const;

	//Overloaded not equals operator is used for comparison in the BSTree class
	//Preconditions: a RockCD object must be passed in
	//Postconditions: will compare if two RockCD's are not equal to eachother
	virtual bool operator!=(const TreeData& obj) const;

	//Overloaded less than operator is used for comparison in the BSTree class
	//Preconditions: a RockCD object must be passed in
	//Postconditions: will compare if a RockCD is less than another customer according to the instructions to sort
	virtual bool operator<(const TreeData& obj) const;

	//Overloaded greater than operator is used for comparison in the BSTree class
	//Preconditions: a RockCD object must be passed in
	//Postconditions: will compare if a RockCD is greater than another customer according to the instructions to sort
	virtual bool operator>(const TreeData& obj) const;

	//display is a inherited method that outputs a RockCD
	//Preconditions: A RockCD must be passed in 
	//Postconditions: will display to console details of a RockCD
	virtual void display(TreeData &obj);

	//getQuanity gets the quanity of a given item
	//no precondtions
	//Postcondtion: this method will return an integer representing the number of items of a given object
	virtual int getQuanity() const;

	//setQuanity allows other classes to set the value of quanity
	//Precondition: must pass in an int
	//Postcondition: this method will set the quanity of the item
	virtual void setQuanity(int data);

protected:
	//artistName contains the artist name of the RockCD
	string artistName;
};

