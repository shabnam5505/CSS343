//Hash Class created for driver and inventory to have a place to aquire a specific has value with a given input
//Preconditions: dtype is a char
//Postconditions: returns value or returns -1 for invalid input
#pragma once
class Hash
{
public:
	//default constructor creates a Hash object
	//Preconditions: none
	//Preconditions: creates a Hash object
	Hash(void);

	//getHashValue converts a char into a hash index for the either array/ hash table
	//Preconditions: only a char can be passed in
	//Postconditions: will return an int index from the char passed in
	int getHashValue(char dtype) const;

	//default destructor clean up any Hash objects
	//Preconditions: none
	//Postconditions: cleans up any Hash objects
	virtual ~Hash(void);
};

