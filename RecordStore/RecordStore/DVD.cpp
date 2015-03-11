//Shabnam Basmani
//This class inherits from Disk object. This class is responsible for creating new DVD's and passing a Disk pointer back to the inventory class. 
//TradeIn added in the event of new fuctionally of a tradeIn including a possible creation 
#include "DVD.h"
#include <sstream>

//default constructor creates and instance of the object
//no preconditions
//Postconditions: creates a DVD object
DVD::DVD(void)
{
	title = " ";
	director = " ";
	yearOfIssue = NULL;
}

//constructor that takes in a string from the file and parses appropriately
//Preconditions: imput file string is formatted properly
//Postconditions: will create a new DVD with all data members properly intialized
DVD :: DVD(string line)
{
	Create(line);
}

//constructor that takes in all parameters for DVD 
//Preconditions: data members are accurate
//Postconditons: will create a DVD object with all data members intialized
DVD :: DVD(string t, int year, string dir)
{
	title = t;
	yearOfIssue = year;
	director = dir;
}

//output operator overloaded to print out a DVD object
//Preconditions: a valid DVD object is passed in
//Postconditions: prints out a DVD object
ostream& operator<<(ostream &os, DVD &dvd)
{
	os << "Title: " << dvd.getTitle() << "Year Of Issue: " << dvd.getYear() 
		<< "Artist: " << dvd.getDirectorName(); 
	return os;
}

//Create creates an instance of a DVD and passes back a pointer
//Preconditions: input is formatted correctly
//Postconditions: A disk pointer will be returned of a new DVD object
Disk* DVD :: Create(string input)
{
	stringstream ss(input);
	string substr;
	DVD* insDisk = new DVD;
	getline( ss, substr, ',' );
	insDisk->director = substr;
	ss.ignore(1);
	getline( ss, substr, ',' );
	insDisk->title = substr;
	ss.ignore(1);
	getline( ss, substr, ',' );
	insDisk->yearOfIssue = atoi(substr.c_str());
	return insDisk;
}

//purchase method is used to create a new DVD object and return a pointer to the Driver class
//Preconditions: file is formatted properly
//Postconditions: a new DVD object will be created and pointer to the object will be returned
Disk* DVD :: purchase(string input)
{
	return Create(input);
}

//tradeIn method is used to handle future tradeIn requests
//Preconditions: file is formatted properly
//Postconditions: this is open for defination
Disk* DVD :: tradeIn(string input)
{
	return Create(input);
}


//Overloaded equals operator is used for comparison in the BSTree class
//Preconditions: a DVD object must be passed in
//Postconditions: will compare if two DVD's are equal to eachother
bool DVD :: operator==(const TreeData& obj) const
{
	const DVD &dvd = static_cast<const DVD &>(obj);
	if(dvd.title == title && dvd.yearOfIssue == yearOfIssue && dvd.director == director)
	{
		return true;
	}
	else return false;
}

//Overloaded not equals operator is used for comparison in the BSTree class
//Preconditions: a DVD object must be passed in
//Postconditions: will compare if two DVD's are not equal to eachother
bool DVD :: operator!=(const TreeData& obj) const
{
	const DVD &dvd = static_cast<const DVD &>(obj);
	if(dvd.title != title && dvd.yearOfIssue != yearOfIssue && dvd.director != director)
	{
		return true;
	}
	else return false;
}

//Overloaded less than operator is used for comparison in the BSTree class
//Preconditions: a DVD object must be passed in
//Postconditions: will compare if a DVD is less than another customer according to the instructions to sort
bool DVD :: operator<(const TreeData& obj) const
{
	const DVD &dvd = static_cast<const DVD &>(obj);

	if(title <= dvd.title)
	{
		if(title == dvd.title)
		{
			if(yearOfIssue <= dvd.yearOfIssue)
			{
				if(yearOfIssue == dvd.yearOfIssue)
				{
					if(director < dvd.director)
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
//Preconditions: a DVD object must be passed in
//Postconditions: will compare if a DVD is greater than another customer according to the instructions to sort
bool DVD :: operator>(const TreeData& obj) const
{
	const DVD &dvd = static_cast<const DVD &>(obj);

	if(title >= dvd.title)
	{
		if(title == dvd.title)
		{
			if(yearOfIssue >= dvd.yearOfIssue)
			{
				if(yearOfIssue == dvd.yearOfIssue)
				{
					if(director > dvd.director)
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

//display is a inherited method that outputs a DVD
//Preconditions: A DVD must be passed in 
//Postconditions: will display to console details of a DVD
void DVD :: display(TreeData &obj, int count)
{
	//DVDs are sorted first by title, then by year, then by director
	const DVD &dvd = static_cast<const DVD &>(obj);
	cout << "Number in Inventory: " << count << " " << dvd.title << ", " << dvd.yearOfIssue << ", " << dvd.director <<  endl;

}

//getTitle returns the title of the DVD
//Preconditions: object has been created
//Postconditions: returns a string representing the title
string DVD :: getTitle() const
{
	return title;
}

//setTitle sets the title of a DVD 
//Preconditions: a string is passed in
//Postconditions: updates the value of the title
void DVD :: setTitle(string t)
{
	title = t;
}

//get returns the year of issue of the DVD
//Preconditions: the object has been intialized
//Postconditions: returns an int representing year of issue
int DVD :: getYear() const
{
	return yearOfIssue;
}

//setYear sets the year of issue of the DVD
//Preconditons: passing in a valid int, object exists
//Postconditions: sets the year of issue of the DVD
void DVD :: setYear(int year)
{
	yearOfIssue = year;
}

//setDirectorName allows other classes to set the director in the object
//Preconditions: string must be passed in
//Postconditions: sets the director of the DVD object
void DVD :: setDirectorName(string d)
{
	director = d;
}

//getDirectorName allows other classes to retrieve the director
//Preconditions: none
//Postconditions: will return a string that is the director of the DVD object
string DVD :: getDirectorName() const
{
	return director;
}


//virtual destructor used to clean up DVD objects
//no preconditions
//Postconditions: deletes memory of DVD objects
DVD::~DVD(void)
{
}
