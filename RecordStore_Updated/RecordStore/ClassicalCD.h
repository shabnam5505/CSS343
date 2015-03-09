//Shabnam Basmani
//This class is derived from RockCD. ClassicalCD represents items that have the atributes associated with a classical CD. 
//This class handles its own creation of objects and passes a pointer back to the inventory class to store its data
#pragma once
#include "RockCD.h"
class ClassicalCD : public RockCD
{
public:
	//default constructor creates and instance of the object
	//no preconditions
	//Postconditions: creates a ClassicalCD object
	ClassicalCD(void);

	//constructor that takes in a line of input from a file and parses that data out
	//Preconditions: input must be formatted correctly
	//Postconditions: creates a new ClassicalCD setting all the data members with appropriate data
	ClassicalCD(string input);

	//virtual destructor allows for cleanup of objects
	//Preconditions: none
	//Postconditions: will release any memory created for ClassicalCDs
	virtual ~ClassicalCD(void);

	//constructor that takes in all data members individually
	//Preconditions: data types must be correct
	//Postcondtions: creates a ClassicalCD and intializes all data members
	ClassicalCD(string title, int year, string artist, string composer);

	//setComposer allows for the commposer to be set by other classes
	//Preconditions: must pass in a string
	//Postconditions: will set the composer accordlingly
	void setComposer(string composer);

	virtual Disk* Create(string input);


	//purchase is an overridden method that creates new ClassicalCDs
	//Preconditions: input from file must be formatted correctly
	//Postconditions: returns a Disk pointer to inventory after object is created
	virtual Disk* purchase(string input);

	//tradeIn is an overriden method that will control the tradeIn of an object 
	//(should it involve something other than remove)
	//Preconditions: must pass in valid input
	//Postconditions: to be defined 
	virtual Disk* tradeIn(string input);

	//Overloaded equals operator is used for comparison in the BSTree class
	//Preconditions: a ClassicalCD object must be passed in
	//Postconditions: will compare if two CkassicalCD's are equal to eachother
	virtual bool operator==(const TreeData& obj) const;

	//Overloaded not equals operator is used for comparison in the BSTree class
	//Preconditions: a ClassicalCD object must be passed in
	//Postconditions: will compare if two ClassicalCD's are not equal to eachother
	virtual bool operator!=(const TreeData& obj) const;

	//Overloaded less than operator is used for comparison in the BSTree class
	//Preconditions: a ClassicalCD object must be passed in
	//Postconditions: will compare if a ClassicalCD is less than another customer according to the instructions to sort
	virtual bool operator<(const TreeData& obj) const;

	//Overloaded greater than operator is used for comparison in the BSTree class
	//Preconditions: a ClassicalCD object must be passed in
	//Postconditions: will compare if a ClassicalCD is greater than another customer according to the instructions to sort
	virtual bool operator>(const TreeData& obj) const;

	//display is a inherited method that outputs a RockCD
	//Preconditions: A RockCD must be passed in 
	//Postconditions: will display to console details of a RockCD
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

	//stores the composer data
	string composer;
};

