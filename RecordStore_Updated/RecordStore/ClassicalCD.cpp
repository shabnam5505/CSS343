#include "ClassicalCD.h"
#include <sstream>




ClassicalCD::ClassicalCD(void)
{
}

ClassicalCD :: ClassicalCD(string line)
{
	cout << "This is a classicalCD." << endl;
}

//Disk* ClassicalCD :: Create(string line)
//{
//	cout << "This is a classicalCD." << endl;
//		return this;
//}

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

//if object does not exist create new object
Disk* ClassicalCD :: purchase(string input)
{
	return Create(input);
}

Disk* ClassicalCD :: tradeIn(string input)
{
	return Create(input);
}

//overloaded equals
bool ClassicalCD :: operator==(const TreeData& obj) const
{
	const ClassicalCD &cd = static_cast<const ClassicalCD &>(obj);
	if(cd.title == title && cd.yearOfIssue == yearOfIssue && cd.artistName == artistName && composer == cd.composer)
	{
		return true;
	}
	else return false;
}
//overloaded not equals
bool ClassicalCD :: operator!=(const TreeData& obj) const
{
	const ClassicalCD &cd = static_cast<const ClassicalCD &>(obj);
	if(cd.title != title && cd.yearOfIssue != yearOfIssue && cd.artistName != artistName && composer != cd.composer)
	{
		return true;
	}
	else return false;
}
//overloaded less than 
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

//overloaded greater than
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

void ClassicalCD :: display(TreeData &obj, int count)
{
	//Classical CDs are sorted first by composer, then by artist name, then by year, then by title
	const ClassicalCD &cd = static_cast<const ClassicalCD &>(obj);
	cout << "Number in Inventory: " << count << " " << cd.composer << ", " << cd.artistName << ", " << cd.yearOfIssue << ", " << cd.title << endl;
}

//getQuanity gets the quanity of a given item
//no precondtions
//Postcondtion: this method will return an integer representing the number of items of a given object
int ClassicalCD :: getQuanity() const
{
	return quanity;
}

//setQuanity allows other classes to set the value of quanity
//Precondition: must pass in an int
//Postcondition: this method will set the quanity of the item
void ClassicalCD :: setQuanity(int data)
{
	quanity = data;
}


ClassicalCD::~ClassicalCD(void)
{
}
