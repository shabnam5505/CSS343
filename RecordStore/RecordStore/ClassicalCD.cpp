//Shabnam Basmani
//This class is derived from RockCD. ClassicalCD represents items that have the atributes associated with a classical CD. 
//This class handles its own creation of objects and passes a pointer back to the inventory class to store its data
#include "ClassicalCD.h"
#include <sstream>


//constructor that takes in all 4 data members
//Preconditons: data members are correct
//Postconditions: creates a new instance of objects with given data members
ClassicalCD :: ClassicalCD(string t, string artist, string comp, int year)
{
	title = t;
	artistName = artist;
	composer = comp;
	yearOfIssue = year;
}


//default constructor creates and instance of the object
//no preconditions
//Postconditions: creates a ClassicalCD object
ClassicalCD::ClassicalCD(void)
{
	composer = " ";
}

//constructor that takes in a line of input from a file and parses that data out
//Preconditions: input must be formatted correctly
//Postconditions: creates a new ClassicalCD setting all the data members with appropriate data
ClassicalCD :: ClassicalCD(string line)
{
	Create(line);
}

//output operator overloaded to print out a classical cd object
//Preconditions: a valid classicalCD object is passed in
//Postconditions: prints out a classicalCD object
ostream& operator<<(ostream &os, ClassicalCD &classical)
{
	os << "Composer: " << classical.getComposer() 
	<< "Artist: " << classical.getArtistName() 
	<< "Year Of Issue: " << classical.getYear() << "Title: " << classical.getTitle();
	return os;
}

//Create creates an instance of a ClassicalCD and passes back a pointer
//Preconditions: input is formatted correctly
//Postconditions: A disk pointer will be returned of a new ClassicalCD object
Disk* ClassicalCD :: Create(string input)
{
	stringstream ss(input);
	string substr;
	ClassicalCD* insDisk = new ClassicalCD;
	//ss.ignore(2);
	getline( ss, substr, ',' );
	insDisk->artistName = substr;
	ss.ignore(1);
	getline( ss, substr, ',' );
	insDisk->title = substr;
	ss.ignore(1);
	getline( ss, substr, ',' );
	insDisk->yearOfIssue = atoi(substr.c_str());
	ss.ignore(1);
	getline( ss, substr, ',' );
	insDisk->composer = substr;

	return insDisk;
}

//purchase at this time just calls create so the object can be searched for in inventory
//options to expand this method are available
//Preconditions: input from file must be formatted correctly
//Postconditions: returns a Disk pointer to inventory after object is created
Disk* ClassicalCD :: purchase(string input)
{
	return Create(input);
}


//tradeIn is an overriden method that just calls create at this time so object can
//be added to the inventory, options to expand are available
//Preconditions: must pass in valid input
//Postconditions: Returns a disk pointer after object is created
Disk* ClassicalCD :: tradeIn(string input)
{
	return Create(input);
}

//Overloaded equals operator is used for comparison in the BSTree class
//Preconditions: a ClassicalCD object must be passed in
//Postconditions: will compare if two CkassicalCD's are equal to eachother
bool ClassicalCD :: operator==(const TreeData& obj) const
{
	const ClassicalCD &cd = static_cast<const ClassicalCD &>(obj);
	if(cd.title == title && cd.yearOfIssue == yearOfIssue && cd.artistName == artistName && composer == cd.composer)
	{
		return true;
	}
	else return false;
}

//Overloaded not equals operator is used for comparison in the BSTree class
//Preconditions: a ClassicalCD object must be passed in
//Postconditions: will compare if two ClassicalCD's are not equal to eachother
bool ClassicalCD :: operator!=(const TreeData& obj) const
{
	const ClassicalCD &cd = static_cast<const ClassicalCD &>(obj);
	if(cd.title != title && cd.yearOfIssue != yearOfIssue && cd.artistName != artistName && composer != cd.composer)
	{
		return true;
	}
	else return false;
}

//Overloaded less than operator is used for comparison in the BSTree class
//Preconditions: a ClassicalCD object must be passed in
//Postconditions: will compare if a ClassicalCD is less than another customer according to the instructions to sort
bool ClassicalCD :: operator<(const TreeData& obj) const
{
	const ClassicalCD &cd = static_cast<const ClassicalCD &>(obj);

	if(composer <= cd.composer)
	{
		if(composer == cd.composer)
		{
			if(artistName <= cd.artistName)
			{
				if(artistName == cd.artistName)
				{
					if(yearOfIssue <= cd.yearOfIssue)
					{
						if(yearOfIssue == cd.yearOfIssue)
						{
							if(title < cd.title)
								return true;
							else
								return false;
						}
						else return true;
					}
					else return false;
				}
				else return true;
			}
			else return false;
		}
		else return true;
	}
	return false;
}

//Overloaded greater than operator is used for comparison in the BSTree class
//Preconditions: a ClassicalCD object must be passed in
//Postconditions: will compare if a ClassicalCD is greater than another customer according to the instructions to sort
bool ClassicalCD :: operator>(const TreeData& obj) const
{
	const ClassicalCD &cd = static_cast<const ClassicalCD &>(obj);

	if(composer >= cd.composer)
	{
		if(composer == cd.composer)
		{
			if(artistName >= cd.artistName)
			{
				if(artistName == cd.artistName)
				{
					if(yearOfIssue >= cd.yearOfIssue)
					{
						if(yearOfIssue == cd.yearOfIssue)
						{
							if(title > cd.title)
								return true;
							else
								return false;
						}
						else return true;
					}
					else return false;
				}
				else return true;
			}
			else return false;
		}
		else return true;
	}
	return false;
}

//display is a inherited method that outputs a RockCD
//Preconditions: A RockCD must be passed in 
//Postconditions: will display to console details of a RockCD
void ClassicalCD :: display(TreeData &obj, int count)
{
	//Classical CDs are sorted first by composer, then by artist name, then by year, then by title
	const ClassicalCD &cd = static_cast<const ClassicalCD &>(obj);
	cout << "Number in Inventory: " << count << " " << cd.composer << ", " << cd.artistName << ", " << cd.yearOfIssue << ", " << cd.title << endl;
}

//getComposer gets the value of the composer stored in the object
//Preconditions: none
//Postconditions: returns a string of the composer in the ClassicalCD
string ClassicalCD :: getComposer() const
{
	return composer;
}

//getComposer gets the value of the composer stored in the object
//Preconditions: none
//Postconditions: returns a string of the composer in the ClassicalCD
void ClassicalCD :: setComposer(string c)
{
	composer = c; 
}


//getTitle returns the title of the Classical CD
//Preconditions: object has been created
//Postconditions: returns a string representing the title
string ClassicalCD :: getTitle() const
{
	return title;
}

//setTitle sets the title of a Classical CD
//Preconditions: a string is passed in
//Postconditions: updates the value of the title
void ClassicalCD :: setTitle(string t)
{
	title = t;
}

//setTitle sets the title of a Classical CD
//Preconditions: a string is passed in
//Postconditions: updates the value of the title
int ClassicalCD :: getYear() const
{
	return yearOfIssue;
}

//get returns the year of issue of the Classical CD
//Preconditions: the object has been intialized
//Postconditions: returns an int representing year of issue
void ClassicalCD :: setYear(int year)
{
	yearOfIssue = year;
}

//setArtistName allows for the artistName to be set by other classes
//Preconditions: string is passed in
//Postconditions: will set the value accordingly
void ClassicalCD :: setArtistName(string artist)
{
	artistName = artist;
}

//getArtistName allows for other classes to be able to retrieve this value
//Preconditions: none
//Postconditions: will return a string of the value in artistName
string ClassicalCD :: getArtistName() const
{
	return artistName;
}


//virtual destructor allows for cleanup of objects
//Preconditions: none
//Postconditions: will release any memory created for ClassicalCDs
ClassicalCD::~ClassicalCD(void)
{
}
