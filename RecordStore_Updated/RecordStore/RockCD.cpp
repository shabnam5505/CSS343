#include "RockCD.h"
#include <vector>
#include <sstream>



RockCD::RockCD(void)
{
}

RockCD :: RockCD(string line)
{
	Create(line);
}



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

Disk* RockCD :: purchase(string input)
{
	return Create(input);

}

Disk* RockCD :: tradeIn(string input)
{
	return Create(input);
}

void RockCD :: display(TreeData &obj, int count)
{
	//Rock CDs are sorted first by artist name, then by year, then by CD title
	const RockCD &rock = static_cast<const RockCD &>(obj);
	cout << "Number in Inventory: " << count << " " << rock.artistName << ", " << rock.yearOfIssue << ", " << rock.title <<  endl;

}

//getQuanity gets the quanity of a given item
//no precondtions
//Postcondtion: this method will return an integer representing the number of items of a given object
int RockCD :: getQuanity() const
{
	return quanity;
}

//setQuanity allows other classes to set the value of quanity
//Precondition: must pass in an int
//Postcondition: this method will set the quanity of the item
void RockCD :: setQuanity(int data)
{
	quanity = data;
}

bool RockCD :: operator==(const TreeData& obj) const
{
	const RockCD &cd = static_cast<const RockCD &>(obj);
	if(cd.title == title && cd.yearOfIssue == yearOfIssue && cd.artistName == artistName)
	{
		return true;
	}
	else return false;
}

	//overloaded not equals
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

	//overloaded less than 
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

	//overloaded greater than
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

//ostream& operator<<(ostream &os, RockCD &obj)
//{
//	return os;
//}


RockCD::~RockCD(void)
{
}
