#include "DVD.h"
#include <sstream>

DVD::DVD(void)
{
}

//Disk* DVD :: Create(string t)
//{
//	cout << "This is a DVD." << endl;
//	return this;
//}

DVD :: DVD(string line)
{
	cout << "This is a DVD." << endl;
}


Disk* DVD :: purchase(string input)
{
	stringstream ss(input);
	string substr;
	DVD* insDisk = new DVD;
	ss.ignore(2);
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

Disk* DVD :: tradeIn(string input)
{
	stringstream ss(input);
	string substr;
	DVD* insDisk = new DVD;
	ss.ignore(2);
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

//getQuanity gets the quanity of a given item
//no precondtions
//Postcondtion: this method will return an integer representing the number of items of a given object
int DVD :: getQuanity() const
{
	return quanity;
}

//setQuanity allows other classes to set the value of quanity
//Precondition: must pass in an int
//Postcondition: this method will set the quanity of the item
void DVD :: setQuanity(int data)
{
	quanity = data;
}

		//overloaded equals
bool DVD :: operator==(const TreeData& obj) const
{
	const DVD &dvd = static_cast<const DVD &>(obj);
	if(dvd.title == title && dvd.yearOfIssue == yearOfIssue && dvd.director == director)
	{
		return true;
	}
	else return false;
}
	//overloaded not equals
bool DVD :: operator!=(const TreeData& obj) const
{
	const DVD &dvd = static_cast<const DVD &>(obj);
	if(dvd.title != title && dvd.yearOfIssue != yearOfIssue && dvd.director != director)
	{
		return true;
	}
	else return false;
}
	//overloaded less than 
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
	//overloaded greater than
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

void DVD :: display(TreeData &obj)
{
	//DVDs are sorted first by title, then by year, then by director
	const DVD &dvd = static_cast<const DVD &>(obj);
	cout << "Number in Inventory: " << dvd.quanity << " " << dvd.title << ", " << dvd.yearOfIssue << ", " << dvd.director <<  endl;

}



DVD::~DVD(void)
{
}
