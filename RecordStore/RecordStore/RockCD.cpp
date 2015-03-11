//Shabnam Basmani
//This class inherits from Disk object. This class is responsible for creating new RockCD's and passing a Disk pointer back to the inventory class. 
//TradeIn added in the event of new fuctionally of a tradeIn including a possible creation 
#include "RockCD.h"
#include <vector>
#include <sstream>


//default constructor creates a RockCD object
//no preconditions
//Postconditions: creates a RockCD object
RockCD::RockCD(void)
{
	title = " ";
	artistName = " ";
	yearOfIssue = NULL;
}

//constructor that takes in a string from the file and parses appropriately
//Preconditions: imput file string is formatted properly
//Postconditions: will create a new RockCD with all data members properly intialized
RockCD :: RockCD(string line)
{
	Create(line);
}

//constructor that sets all data members
//Preconditions: values are acurate
//Postconditions: a RockCD object is created intializes data members
RockCD :: RockCD(string artist, string t, int year)
{
	title = t;
	artistName = artist;
	yearOfIssue = year;
}


//Create creates an instance of a RockCD and passes back a pointer
//Preconditions: input is formatted correctly
//Postconditions: A disk pointer will be returned of a new RockCD object
Disk* RockCD :: Create(string input)
{
	stringstream ss(input);
	string substr;
	RockCD* insDisk = new RockCD;
	//ss.ignore(2);
	getline( ss, substr, ',' );
	insDisk->artistName = substr;
	ss.ignore(1);
	getline( ss, substr, ',' );
	insDisk->title = substr;
	ss.ignore(1);
	getline( ss, substr, ',' );
	insDisk->yearOfIssue = atoi(substr.c_str());

	return insDisk;
}

//purchase method is used to create a new RockCD object and return a pointer to the Driver class
//Preconditions: file is formatted properly
//Postconditions: a new RockCD object will be created and pointer to the object will be returned
Disk* RockCD :: purchase(string input)
{
	return Create(input);

}

//tradeIn method is used to handle future tradeIn requests
//Preconditions: file is formatted properly
//Postconditions: this is open for defination
Disk* RockCD :: tradeIn(string input)
{
	return Create(input);
}

//display is a inherited method that outputs a RockCD
//Preconditions: A RockCD must be passed in 
//Postconditions: will display to console details of a RockCD
void RockCD :: display(TreeData &obj, int count)
{
	//Rock CDs are sorted first by artist name, then by year, then by CD title
	const RockCD &rock = static_cast<const RockCD &>(obj);
	cout << "Number in Inventory: " << count << " " << rock.artistName << ", " << rock.yearOfIssue << ", " << rock.title <<  endl;

}

//Overloaded equals operator is used for comparison in the BSTree class
//Preconditions: a RockCD object must be passed in
//Postconditions: will compare if two RockCD's are equal to eachother
bool RockCD :: operator==(const TreeData& obj) const
{
	const RockCD &cd = static_cast<const RockCD &>(obj);
	if(cd.title == title && cd.yearOfIssue == yearOfIssue && cd.artistName == artistName)
	{
		return true;
	}
	else return false;
}

//Overloaded not equals operator is used for comparison in the BSTree class
//Preconditions: a RockCD object must be passed in
//Postconditions: will compare if two RockCD's are not equal to eachother
bool RockCD :: operator!=(const TreeData& obj) const
{
	const RockCD &cd = static_cast<const RockCD &>(obj);
	//static_cast(obj) RockCD;
	if(cd.title != title && cd.yearOfIssue != yearOfIssue && cd.artistName != artistName)
	{
		return true;
	}
	else return false;
}

//Overloaded less than operator is used for comparison in the BSTree class
//Preconditions: a RockCD object must be passed in
//Postconditions: will compare if a RockCD is less than another customer according to the instructions to sort
bool RockCD :: operator<(const TreeData& obj) const
{
	const RockCD &cd = static_cast<const RockCD &>(obj);

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
//Preconditions: a RockCD object must be passed in
//Postconditions: will compare if a RockCD is greater than another customer according to the instructions to sort
bool RockCD :: operator>(const TreeData& obj) const
{
	const RockCD &cd = static_cast<const RockCD &>(obj);

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

//Overloaded output operator used to directly output a RockCD
//Preconditons: must have valid parameters
//Postconditions: will print to console the contents of a RockCD (this is mostly used for testing or expansions)
ostream& operator<<(ostream &os, RockCD &obj)
{
	os << "Artist: " << obj.getArtistName() << 
		"Year Of Issue: " << obj.getYear() << "Title: " << obj.getTitle();
	return os;
}

//setArtistName allows for the artistName to be set by other classes
//Preconditions: string is passed in
//Postconditions: will set the value accordingly
void RockCD :: setArtistName(string artist)
{
	artistName = artist;
}

//getArtistName allows for other classes to be able to retrieve this value
//Preconditions: none
//Postconditions: will return a string of the value in artistName
string RockCD :: getArtistName() const
{
	return artistName;
}

//getTitle returns the title of the RockCD
//Preconditions: object has been created
//Postconditions: returns a string representing the title
string RockCD :: getTitle() const
{
	return title;
}

//setTitle sets the title of a RockCD 
//Preconditions: a string is passed in
//Postconditions: updates the value of the title
void RockCD :: setTitle(string t)
{
	title = t;
}

//get returns the year of issue of the RockCD
//Preconditions: the object has been intialized
//Postconditions: returns an int representing year of issue
int RockCD :: getYear() const
{
	return yearOfIssue;
}

//setYear sets the year of issue of the RockCD
//Preconditons: passing in a valid int, object exists
//Postconditions: sets the year of issue of the RockCD
void RockCD :: setYear(int year)
{
	yearOfIssue = year;
}

//virtual destructor used to clean up RockCD objects
//no preconditions
//Postconditions: deletes memory of RockCD objects
RockCD::~RockCD(void)
{

}
