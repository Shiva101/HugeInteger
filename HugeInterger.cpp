//============================================================
// Name        : HugeInteger.cpp
// Author      : Shivakumar S Soppannavar
//============================================================

// HugeInteger Class uses a 40 - element array of digits to store
// integers as large as 40 digits each. HugeInteger is represented internally as a vector of short
// values.The vector should is initialized to 40 elements and each digit is stored in one element of the
// vector.The class HugeInteger has the following public member functions :

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "HugeInteger.h"

const int size = 40;  // HugeInteger calss can hold only 40 digits

using namespace std;

// constructor: converts a long integer into a HugeInteger object
HugeInteger::HugeInteger(long lng_int)
{
	for (int i = 0; i < size; i++)
		number.push_back(0);

	for (int i = size - 1; i >= 0; i--)
	{
		number[i] = lng_int % 10;
		lng_int = lng_int / 10;
	}
}

// constructor: converts a string representing a large int to a HugeInteger object
HugeInteger::HugeInteger(const std::string& my_str)
{
	Input(my_str);
}

// convert a string representing a large integer into a HugeInteger
void HugeInteger::Input(const string &my_str)
{
	for (int i = 0; i < size; i++)
		number.push_back(0);

	for (int i = (size - my_str.length()), j = 0; i < size; i++, j++)
		number[i] = my_str[j] - '0';
}

// Addition operator: HugeInteger + HugeInteger
HugeInteger	HugeInteger::add(HugeInteger op2)
{
	HugeInteger temp;

	int carry = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		temp.number[i] = ((number[i] + op2.number[i] + carry) % 10);
		carry = ((number[i] + op2.number[i] + carry) / 10);
	}
	if (carry == 1)		// if Overflow print error and return zero in hugeinteger
	{
		cout << "Error: Addition overflow \n";
		return HugeInteger(0);
	}
	return(temp);
}

// Addition operator: HugeInteger + int
HugeInteger HugeInteger::add(int op2)
{
	return add(HugeInteger(op2));
}

// Addition operator: HugeInteger + string representing large integer value
HugeInteger HugeInteger::add(const string &op2)
{
	return add(HugeInteger(op2));
}

// subtraction operator (subtract op2 from *this); op1 – op2
// where op1 is a HugeInteger and op2 is also a HugeInteger
HugeInteger HugeInteger::subtract(HugeInteger  op2)
{
	HugeInteger temp(0);

	int carry = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		if( (number[i] - op2.number[i] - carry) < 0)
		{
			temp.number[i] = 10 + number[i] - carry - op2.number[i];
			carry = 1;
		}
		else
		{
			temp.number[i] =  number[i] - op2.number[i]- carry;
			carry = 0;
		}
	}
	if (carry == 1)  // if op1 < op2, print error and return zero in hugeinteger
	{
		cout << "Error: Tried to subtract larger value from smaller value \n";
		return HugeInteger(0);
	}
	return(temp);
}

// subtraction operator (subtract op2 from *this); op1 – op2
// where op1 is a HugeInteger and op2 is int
HugeInteger HugeInteger::subtract(int op2)
{
	return subtract(HugeInteger(op2));
}

// subtraction operator; subtract op2 from *this); op1 – op2
// where op1 is a HugeInteger and op2 is a string representing large integer value
HugeInteger HugeInteger::subtract(const string & op2)
{
	return subtract(HugeInteger(op2));
}


//Returns true if op1 ==op2 else false
bool HugeInteger::isEqualTo(HugeInteger hugeint)
{
	for (int i = size - 1; i >= 0; i--)
		if (number[i] != hugeint.number[i])
			return false;

	return true;
}

//Returns true if op1 not equal to op2 else false
bool HugeInteger::isNotEqualTo(HugeInteger hugeint)
{
	return !(isEqualTo(hugeint));
}

//Returns true if op1 is greatre than p2 else false
bool HugeInteger::isGreaterThan(HugeInteger hugeint)
{
	return (hugeint.isLessThan(*this));
}

//Returns true if op1 is less than op2 else false
bool HugeInteger::isLessThan(HugeInteger hugeint)
{
	for (int i = 0; i < 40; i++)
		if (number[i] > hugeint.number[i])
			return false;
		else if (number[i] < hugeint.number[i])
			return true;

	return false;
}

//Returns true if op1 is greater than of equal to op2 else false
bool HugeInteger::isGreaterThanOrEqualTo(HugeInteger hugeint)
{
	return (!isLessThan(hugeint));
}

//Returns true if op1 is less than of equal to op2 else false
bool HugeInteger::isLessThanOrEqualTo(HugeInteger hugeint)
{
	return (isEqualTo(hugeint) || isLessThan(hugeint));
}

//Returns true if op1 is zero else false
bool HugeInteger::isZero()
{
	for (int i = 0; i < 40; i++)
		if (number[i] != 0)
			return false;

	return true;
}

// display the HugeInteger, skips leading zeros
void HugeInteger::output()
{
	int i,j=0, allzero=1;
	for (i = 0; i < size; i++)
	{		
		if (number[i] > 0)
		{
			j = i;
			allzero = 0; //number contains non zero value
			break;
		}
	}
	if (j == 0)
		i=0;

	if (allzero == 1)
		cout << 0;
	else
	{
		for (int i = j; i < size; i++)
			cout << number[i];
	}
}

// End of HugeInteger.cpp file
