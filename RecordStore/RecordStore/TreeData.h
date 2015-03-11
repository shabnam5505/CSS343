//Shabnam Basmani
//This is an abstract class created so that objects that wish to use the BST class can inherit from this class. 
#pragma once
#include <iostream>
using namespace std;
class TreeData
{

public:

	//default constructor will not be used because this is an abstract class
	//no pre or post conditions
	TreeData();

	//virtual destructor will not be used because this is an abstract class
	//no pre or post conditions
	virtual ~TreeData(void);

	//overloaded equals is a pure virtual method used in the derived classes
	//Preconditions: none
	//Postconditons: none
	virtual bool operator==(const TreeData& obj) const = 0;

	//overloaded not equals is a pure virtual method used in the derived classes
	//Preconditions: none
	//Postconditons: none
	virtual bool operator!=(const TreeData& obj) const = 0;

	//overloaded less than is a pure virtual method used in the derived classes
	//Preconditions: none
	//Postconditons: none
	virtual bool operator<(const TreeData& obj) const = 0;

	//overloaded greater than is a pure virtual method used in the derived classes
	//Preconditions: none
	//Postconditons: none
	virtual bool operator>(const TreeData& obj) const = 0;

	//display is a pure virtual method used in the derived classes
	//Preconditions: none
	//Postconditons: none
	virtual void display(TreeData &obj, int count) = 0;


protected:

};

