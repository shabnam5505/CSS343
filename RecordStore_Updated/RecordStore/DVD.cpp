#include "DVD.h"
#include <sstream>

DVD::DVD(void)
{
}

DVD :: DVD(string line)
{
	
}

Disk* DVD :: Create(string input)
{
	stringstream ss(input);
	string substr;
	DVD* insDisk = new DVD;
	//ss.ignore(2);
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

Disk* DVD :: purchase(string input)
{
	return Create(input);
}

Disk* DVD :: tradeIn(string input)
{
	return Create(input);
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

void DVD :: display(TreeData &obj, int count)
{
	//DVDs are sorted first by title, then by year, then by director
	const DVD &dvd = static_cast<const DVD &>(obj);
	cout << "Number in Inventory: " << count << " " << dvd.title << ", " << dvd.yearOfIssue << ", " << dvd.director <<  endl;

}



DVD::~DVD(void)
{
}
