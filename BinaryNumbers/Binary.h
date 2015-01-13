#pragma once
#include <vector>
//Shabnam Basmani
//Basic class allows you to convert from an integer to a binary
//Setbit and Getbit methods allow you to change the in the binary number
//One additional helper method that allows you to convert back to an integer may be useful to add to public in the future 
//most methods are overloaded to allow assignment of binarys and ints to binarys
#include <iostream>
using namespace std;
class Binary
{
public:
	//this is the output operator overload 
	friend ostream& operator<<(ostream &os, Binary &obj);
	//this is the input operator overload 
	friend istream& operator>>(std::istream &inStream, Binary &obj);

	Binary();

	//Precondition: an integer must be passed in
	//Postcondition: converts the number to binary and stores in the vector
	Binary(int convertToBinary);

	//Precondition: an integer value is passed in
	//Postcondition: returns a bool based on the position in vector that was passed in
	bool getBit(int bitPosition) const;

	//Precondition: an integer value is passed in
	//Postcondition: sets a bit to true based on the postion in the vector that was passed in
	void setBit(int bitPosition);

	//Precondition: an integer value is passed in
	//Postcondition: sets a bit to false based on the position in the vector that was passed in
	void clearBit(int bitPosition);

	//Precondition: an integer value is passed in
	//Postcondition: changes the bit to the opposite value based on the position in the vector that was passed in
	void toggleBit(int bitPosition);

	//copy constructor
	//Binary(Binary &obj);

	//copy constructor
	Binary(const Binary &obj);

	//assignment operator overload
	Binary& operator=(const Binary &source);

	//assignment operator overload from assigning and int to a binary
	Binary& operator=(int source);

	//+= overload returns a reference to a binary object 
	Binary& operator+=(Binary& obj);
	//+ overload returns a binary object 
	Binary operator+(const Binary& list);
	//+ overload that takes an binary + int and returns a binary
	Binary operator+(int obj);
	//-= overload returns a reference binary object 
	Binary& operator-=(Binary& obj);
	//- overload returns a binary object 
	Binary& operator-(Binary& list);
	//overload for -operator that takes in a int and returns a binary
	Binary operator-(int obj);
	//== overload returns a bool
	bool operator==(const Binary& obj) const;
	//!= overload returns a bool
	bool operator!=(const Binary& obj) const;




	~Binary();

private:
	//Precondition: pass in an integer
	//Postcondition: sets the integer to a binary number inside an array
	void convertToBinary(int num);

	//Precondition: pass in an integer
	//Postcondition: returns an integer of the size to allocate the array
	int getSize(int val);

	//Precondition: pass in an array
	//Postcondition: returns the value of the binary number passed in
	int convertToInt(bool *arr) const;

	//stores the value of either positive or negetive for the binary number
	bool sign;
	
	//stores the size of the array
	int count;

	//this is the array that holds the binary number
	bool *binary;

	Binary *b;
	




};

