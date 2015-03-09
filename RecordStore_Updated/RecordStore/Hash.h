#pragma once
class Hash
{
public:
	Hash(void);

	//getHashValue converts a char into a hash index for the either array/ hash table
	//Preconditions: only a char can be passed in
	//Postconditions: will return an int index from the char passed in
	int getHashValue(char dtype) const;

	~Hash(void);
};

