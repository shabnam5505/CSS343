//Shabnam Basmani
//This class is derived from RockCD. ClassicalCD represents items that have the atributes associated with a classical CD. 
//This class handles its own creation of objects and passes a pointer back to the inventory class to store its data
#pragma once
#include "RockCD.h"

class ClassicalCD : public RockCD
{
public:
	//output operator overloaded to print out a classical cd object
	//Preconditions: a valid classicalCD object is passed in
	//Postconditions: prints out a classicalCD object
	friend ostream& operator<<(ostream &os, ClassicalCD &classical);

	//default constructor creates and instance of the object
	//no preconditions
	//Postconditions: creates a ClassicalCD object
	ClassicalCD(void);

	//constructor that takes in a line of input from a file and parses that data out
	//Preconditions: input must be formatted correctly
	//Postconditions: creates a new ClassicalCD setting all the data members with appropriate data
	ClassicalCD(string input);

	//constructor that takes in all 4 data members
	//Preconditons: data members are correct
	//Postconditions: creates a new instance of objects with given data members
	ClassicalCD(string title, string artistName, string composer, int year);

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
	virtual void setComposer(string composer);

	//getComposer gets the value of the composer stored in the object
	//Preconditions: none
	//Postconditions: returns a string of the composer in the ClassicalCD
	virtual string getComposer() const;

	//setArtistName allows for the artistName to be set by other classes
	//Preconditions: string is passed in
	//Postconditions: will set the value accordingly
	virtual void setArtistName(string artist);

	//getArtistName allows for other classes to be able to retrieve this value
	//Preconditions: none
	//Postconditions: will return a string of the value in artistName
	virtual string getArtistName() const;

	//getTitle returns the title of the Classical CD
	//Preconditions: object has been created
	//Postconditions: returns a string representing the title
	virtual string getTitle() const;

	//setTitle sets the title of a Classical CD
	//Preconditions: a string is passed in
	//Postconditions: updates the value of the title
	virtual void setTitle(string t);

	//get returns the year of issue of the Classical CD
	//Preconditions: the object has been intialized
	//Postconditions: returns an int representing year of issue
	virtual int getYear() const;

	//setYear sets the year of issue of the Classical CD
	//Preconditons: passing in a valid int, object exists
	//Postconditions: sets the year of issue of the Classical CD
	virtual void setYear(int year);

	//Create creates an instance of a ClassicalCD and passes back a pointer
	//Preconditions: input is formatted correctly
	//Postconditions: A disk pointer will be returned of a new ClassicalCD object
	virtual Disk* Create(string input);


	//purchase at this time just calls create so the object can be searched for in inventory
	//options to expand this method are available
	//Preconditions: input from file must be formatted correctly
	//Postconditions: returns a Disk pointer to inventory after object is created
	virtual Disk* purchase(string input);

	//tradeIn is an overriden method that just calls create at this time so object can
	//be added to the inventory, options to expand are available
	//Preconditions: must pass in valid input
	//Postconditions: Returns a disk pointer after object is created
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

protected:

	//stores the composer data
	string composer;
};

