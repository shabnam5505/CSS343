//Hash Class created for driver and inventory to have a place to aquire a specific has value with a given input
//Preconditions: dtype is a char
//Postconditions: returns value or returns -1 for invalid input
#include "Hash.h"

//default constructor creates a Hash object
//Preconditions: none
//Preconditions: creates a Hash object
Hash::Hash(void)
{
}

//getHashValue converts a char into a hash index for the either array/ hash table
//Preconditions: only a char can be passed in
//Postconditions: will return an int index from the char passed in
int Hash :: getHashValue(char dtype) const
{
	//const char* c = dtype.c_str();
	int value = dtype;
	value = value - 65;
	if(value < 0 || value > 25)
		return -1;
	return value;
	
}

//default destructor clean up any Hash objects
//Preconditions: none
//Postconditions: cleans up any Hash objects
Hash::~Hash(void)
{
}
