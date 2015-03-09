#include "TreeData.h"

//Default constructer sets data to a space
TreeData::TreeData()
{
	quanity = NULL;
}

//int TreeData :: getQuanity() const
//{
//	return quanity;
//}
//
////Precondition: must pass in an int
////Postcondition: this method will set the quanity of the item
//void TreeData :: setQuanity(int data)
//{
//	quanity = data;
//}

////Constructor sets value to the data in the class
//TreeData::TreeData(char value)
//{
//	data = value;
//}
//
////no precondtions
////Postcondtion: this method will return the current char value
//char TreeData::getChar() const
//{
//	return data;
//}
//
////Precondition: must pass in a const ref char
////Postcondition: this method will set the character value
//void TreeData::setChar(const char &value)
//{
//	data = value;
//}
//
////overloaded equals
//bool TreeData :: operator==(const TreeData& obj) const
//{
//	if (data == obj.data)
//	{
//		return true;
//	}
//	else return false;
//}
//
////overloaded not equals
//bool TreeData :: operator!=(const TreeData& obj) const
//{
//	if (data != obj.data)
//	{
//		return true;
//	}
//	else return false;
//}

//overloaded less than
//bool TreeData :: operator<(const TreeData& obj) const
//{
//	if (data < obj.data)
//	{
//		return true;
//	}
//	else return false;
//}
//
////overloaded greater than
//bool TreeData :: operator>(const TreeData& obj) const
//{
//	if (data > obj.data)
//	{
//		return true;
//	}
//	else return false;
//}

//overloaded output operator
ostream& operator<<(ostream &os, TreeData &obj)
{
	return os;
	/*os << obj.getChar(); os << " ";
	return os;*/
}

//ostream& TreeData :: display(ostream &os, TreeData &obj)
//{
//	/*os << obj.getChar(); os << " ";*/
//	return os;
//}

TreeData::~TreeData()
{
}
