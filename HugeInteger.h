//============================================================
// Name        : HugeInteger.h
// Author      : Shivakumar S Soppannavar
//============================================================

// HugeInteger Class uses a 40 - element array of digits to store
// integers as large as 40 digits each. HugeInteger is represented internally as a vector of short
// values.The vector should is initialized to 40 elements and each digit is stored in one element of the
// vector.The class HugeInteger has the following public member functions :


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class  HugeInteger
{

private:
	vector <short int> number;

public:
	HugeInteger(long = 0); // conversion/default constructor
	HugeInteger(const string &); // copy constructor

	// addition operator; HugeInteger + HugeInteger
	HugeInteger add(HugeInteger);

	// addition operator; HugeInteger + int
	HugeInteger add(int);

	// addition operator HugeInteger + string that represents large integer value
	HugeInteger add(const string &);

	// subtraction operator; HugeInteger - HugeInteger
	HugeInteger subtract(HugeInteger);

	// subtraction operator; HugeInteger - int
	HugeInteger subtract(int);

	// subtraction operator;
	// HugeInteger - string that represents large integer value
	HugeInteger subtract(const string &);

	bool isEqualTo(HugeInteger); // is equal to
	bool isNotEqualTo(HugeInteger); // not equal to
	bool isGreaterThan(HugeInteger); // greater than
	bool isLessThan(HugeInteger); // less than
	bool isGreaterThanOrEqualTo(HugeInteger); // greater than  or equal to
	bool isLessThanOrEqualTo(HugeInteger); // less than or equal
	bool isZero(); // is zero
	void Input(const string &); // input
	void output(); // output

};

