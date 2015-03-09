#include "Hash.h"


Hash::Hash(void)
{
}

int Hash :: getHashValue(char dtype) const
{
	//const char* c = dtype.c_str();
	int value = dtype;
	value = value - 65;
	if(value < 0 || value > 25)
		return -1;
	return value;
	
}


Hash::~Hash(void)
{
}
