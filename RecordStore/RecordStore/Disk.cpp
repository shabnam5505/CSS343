#include "Disk.h"


Disk::Disk(void)
{
	quanity = 1;
}
Disk* Disk :: Create(string t)
{
	cout << "this is the disk class." << endl;
	return this;
}

//bool Disk ::operator==(const Disk& obj) const
//{
//	if(title == obj.title && yearOfIssue == obj.yearOfIssue)
//		return true;
//	else
//		return false;
//}
////overloaded not equals
//bool Disk :: operator!=(const Disk& obj) const
//{
//	if(title != obj.title && yearOfIssue != obj.yearOfIssue)
//		return true;
//	else
//		return false;
//}
//
////overloaded less than 
//bool Disk :: operator<(const Disk& obj) const
//{ 
//	if(title < obj.title)
//		return true;
//	else return false;
//}
////overloaded greater than
//bool Disk :: operator>(const Disk& obj) const
//{
//	if(title > obj.title)
//		return true;
//	else return false;
//}

string Disk:: trim(string const& str)
{
    if(str.empty())
        return str;

    std::size_t first = str.find_first_not_of(' ');
    std::size_t last  = str.find_last_not_of(' ');
    return str.substr(first, last-first+1);
}

Disk::~Disk(void)
{
}
