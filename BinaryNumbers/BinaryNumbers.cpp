// BinaryNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Binary.h"
using namespace std;


//put some notes in
int main()
{
	int waitVar;
	//Binary b(-987);


	Binary a;
	Binary	b(42);
	Binary c(b);
	Binary d = -13;
	Binary x;
	Binary y = x - 1;

	cout << "This is the new value of Y " << y << endl;
	a = 27;
	b = 3;
	y = 1;

	cout << "a += b" << endl;
	x = a + b;
	cout << x << endl;

	cout << a << endl;

	cout << "a -= b" << endl;
	x = a -= b;
	cout << x << endl;

	

	cout << "Enter integer to be converted to binary:  ";
	cin >> a;
	cout << "The binary representation of this number is: " << endl;
	cout << a << endl;
	cout << "The 4th bit (four bits away from bit 0) is: " << endl;
	cout << a.getBit(4) << endl << endl;

	cout << "This is A " << a << endl;
	cout << "This is C: " << c << endl;
	cout << "This is B : " << b << endl;
	cout << "This is D : " << d << endl;

	cout << "Compute c = a + b" << endl;
	c = a + b;
	cout << "c = " << c << endl;
	cout << "Compute d = a + b - c" << endl;
	d = a + b - c;
	cout << "d = " << d << endl << endl;

	cout << "Does a == c? " << endl;
	cout << ((a == c) ? "a == c" : "a != c") << endl << endl;

	cout << "Test assignment operators" << endl;
	x = c = d = d;    y += a -= b += b;
	cout << "x = " << x << "    y = " << y << endl << endl;

	a.setBit(-1);			// handle bad input
	a.setBit(3);			// set 3rd bit (three over from bit zero)
	a.setBit(1000);			// set 1000th bit; handle as desired, but don't crash
	a.clearBit(3);			// clear 3rd bit
	a.clearBit(10000);		// clear 10000th bit
	a.toggleBit(3);			// toggle 3rd bit




	//b.convertToBinary(10238766565);

	cin >> waitVar;
	

	return 0;
}

