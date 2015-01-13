#include "stdafx.h"
#include "Binary.h"


Binary::Binary()
{
	count = 1;
	//count = getSize(convertToBinary);
	binary = new bool[count];
	sign = false;

}

//Precondition: an integer must be passed in
//Postcondition: converts the number to binary and stores in the vector
Binary:: Binary(int val)
{
	sign = false;

	count = 1;
	count = getSize(val);
	binary = new bool[count];
	convertToBinary(val);

}

int Binary:: getSize(int input) 
{
	int A = input;  // using a leter variable because I can,  MWAHAHAAAHA
	int B = 1;


		if (A < 0)
		{
		A = -A;
		}
		while (A > 1)
		{
			A = A / 2;
			B++;
		}

		return B;

}

//Precondition: pass in an integer
//Postcondition: sets the integer to a binary number inside an array
void Binary :: convertToBinary(int num)
{

	if (num < 0)
	{
		num *= -1;
		sign = false;
	}
	else if (num > 0)
	{
		sign = true;
	}
	else if (num == 0)
	{
		sign = true;
		return;
	}

	//basically the values get allocated in the array backwards; important to note
	for (int i = 0; i < count; i++)
	{
		if (num == 0)
		{
			binary[i] = false;
		}

		if (num == 1)
		{
			binary[i] = true;
		}

		if (num % 2 == 0 && num > 1)
			binary[i] = false;
		else
			binary[i] = true;

		num = num / 2;
	}

}

//Precondition: pass in an array
//Postcondition: returns the value of the binary number passed in
int Binary:: convertToInt(bool *arr) const
{
	int returnVal = 0;
	int bitValue = 1;

	for (int i = 0; i < count; i++)
	{
		if (binary[i] == 1)
		{
			returnVal += bitValue;
		}
		
		bitValue *= 2;

	}
	if (sign == true)
		return returnVal;
	else return -returnVal;
}

//void Binary::printVector() const
//{
//	if (sign == false)
//		cout << '-';
//	for (int i = 0; i < count; i++)
//	{
//		if (binary[count - 1 - i] == true)
//			cout << 1;
//		else
//			cout << 0;
//
//	}
//}

//Precondition: pass in an integer
//Postcondition: returns an integer of the size to allocate the array
bool Binary::getBit(int bitPosition) const
{
	if (bitPosition > count)
		return false;
	//note that array has been filled in the backwards order
	if (binary[bitPosition - 1] == true)
		return true;
	else
		return false;

}

//Precondition: an integer value is passed in
//Postcondition: sets a bit to true based on the postion in the array that was passed in
void Binary::setBit(int bitPosition)
{
	if (bitPosition > count - 1)
		return;
	else
		binary[bitPosition - 1] = true;
}

//Precondition: an integer value is passed in
//Postcondition: sets a bit to false based on the position in the array that was passed in
void Binary::clearBit(int bitPosition)
{
	if (bitPosition > count - 1)
		return;
	else
		binary[bitPosition - 1] = false;

}

//Precondition: an integer value is passed in
//Postcondition: changes the bit to the opposite value based on the position in the array that was passed in
void Binary::toggleBit(int bitPosition)
{
	if (bitPosition > count - 1)
		return;
	else if (binary[bitPosition - 1] == true)
		binary[bitPosition - 1] = false;
	else
		binary[bitPosition - 1] = true;
}

//copy constructor
//Binary::Binary(Binary &obj)
//{
//	sign = false;
//	count = 1;
//	this->count = getSize(obj.convertToInt(obj.binary));
//	binary = new bool[count];
//	convertToBinary(obj.convertToInt(obj.binary));
//	
//	/**binary = *obj.binary;*/
//
//}

//copy constructor
Binary::Binary(const Binary &obj)
{ 
	//if (this != NULL)
	//	delete binary;
	//Binary temp = obj;
	sign = obj.sign;
	count = 1;
	this->count = obj.count;
	
		//delete binary;
	this->binary = new bool[count];
	
	
	convertToBinary(count);
	//convertToBinary(temp.convertToInt(temp.binary));

	/**binary = *obj.binary;*/

}

//assignment operator overload
Binary& Binary:: operator=(const Binary &source)
{

	if (&source == this)
		return *this;

	if (this != &source)
	{
		
		this->count = source.count;
		this->sign = source.sign;
		bool *todelete = binary;
		delete binary;
		this->binary = new bool[count];

		for (int i = 0; i < count; i++)
		{
			this->binary[count - 1 - i] = getBit(count - i);
		}
		
		
	}
	return *this;
	
}

//assignment operator overload for passing in an int
Binary& Binary:: operator=(int source)
{
	if (&source == NULL)
		return *this;

	if (this->convertToInt(binary) != source)
	{
		//delete binary;
		//binary = NULL;

		this->count = getSize(source);
		if (this != NULL)
			this->binary = new bool[count];
		convertToBinary(source);

		//remember to set array in backwards order
		for (int i = 0; i < count; i++)
		{
			this->binary[count - 1 - i] = getBit(count - i);
		}
		cout << "Value of this is :" << convertToInt(binary) << endl;
		
	}
	return *this;

}


//+= overload returns a reference to a binary object 
Binary& Binary:: operator+=(Binary& obj)
{
	int firstVal, secondVal;
	firstVal = convertToInt(binary);
	secondVal = obj.convertToInt(obj.binary);
	firstVal += secondVal;
	count = getSize(firstVal);
	convertToBinary(firstVal);

	return *this;

}

//+ overload returns a binary object 
Binary Binary:: operator+(const Binary& list)
{


	int firstVal, secondVal;
	firstVal = convertToInt(binary);
	secondVal = list.convertToInt(list.binary);
	
	Binary b(firstVal + secondVal);

	return b;
}

//-= overload returns a reference binary object 
Binary& Binary:: operator-=(Binary& obj)
{
	int firstVal, secondVal;
	firstVal = convertToInt(binary);
	secondVal = obj.convertToInt(obj.binary);
	secondVal -= firstVal;
	
	//count needs to be reset when changing *this
	count = getSize(secondVal);
	convertToBinary(secondVal);

	return *this;
}

//overload for -operator that takes a binary - int and returns a binary
Binary Binary :: operator-(int obj)
{
	Binary b(obj);
	*this -= b;
	
	return *this;
}

//overload for +operator that takes a binary + int and returns a binary
Binary Binary :: operator+(int obj)
{
	Binary b(obj);
	*this += b;

	return *this;
}

//- overload returns a binary object 
Binary& Binary:: operator-(Binary& list)
{
	//int firstVal, secondVal;
	//firstVal = convertToInt(binary);
	//secondVal = list.convertToInt(list.binary);

	//Binary returnVal;
	//returnVal.count = getSize(firstVal - secondVal);
	//returnVal.binary = new bool[returnVal.count];
	//returnVal.convertToBinary(firstVal - secondVal);

	return *this -= list;
	
}

//== overload returns a bool
bool Binary:: operator==(const Binary& obj) const
{
	if (count == obj.count)
	{
		for (int i = 0; i < count; i++)
		{
			if (binary[i] == obj.binary[i])
			{

			}
			else
			{
				return false;
			}
		}
		return true;
	}
	else return false;
}

//!= overload returns a bool
bool Binary:: operator!=(const Binary& obj) const
{
	if (*this == obj)
		return false;
	else
		return true;
}

//output operator overload
ostream& operator<<(ostream &os, Binary &list)
{
	for (int i = 0; i < list.count; i++)
	{
		if (list.sign == false)
			os << '-';
		for (int i = 0; i < list.count; i++)
		{
			if (list.binary[list.count - 1 - i] == true)
				os << 1;
			else
				os << 0;
		}
		return os;
	}
	return os;
}

//input operator overload
istream& operator>>(std::istream &inStream, Binary &obj)
{
	int i;
	inStream >> i;
	obj.count = obj.getSize(i);
	obj.convertToBinary(i);
	return inStream;
}


Binary::~Binary()
{
	delete binary;
	//binary = NULL;
}
