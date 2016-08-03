//============================================================
// Name        : testHugeInteger.cpp
// Author      : Shivakumar S Soppannavar
// Description : This test driver program tests the methods included in HIgeinteger.cpp
//============================================================
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "HugeInteger.h"

using namespace std;
void DriverFunction(HugeInteger , HugeInteger );  // All bool functions are called

int main()
{
	int TestInteger;
	char CaseNumber;
	long TestLong;
	string FirstTestString, SecondTestString;
	char ToContinue = 'Y';
	HugeInteger Sum, Differrence;

	// loop is executed until user press any key other than y/Y
	while ((ToContinue == 'Y') || (ToContinue == 'y'))
	{
		cout << "HugeInteger library implemenation by SHIVAKUMAR \n Select any case you want to test \n";
		cout << "case 1: Operations on HugeInteger and Integer \n"
				<< "case 2: Operations on HugeInteger and Long Integer \n"
				<< "case 3: Operations on HugeInteger and HugeInteger \n";

		cin >> CaseNumber;
		if ((CaseNumber == '1') || (CaseNumber == '2') || (CaseNumber == '3'))
		{
			cout << "\n You can test the below functionalities \n"
				<< "Addition of given inputs \n"
				<< "Subtraction of given inputs (First number - second number)\n"
				<< "---Also you can verify the below bool functions too --- \n"
				<< "A] isEqualTo \n"
				<< "B] isNotEqualTo \n"
				<< "C] isGreaterThan \n"
				<< "D] isLessThan \n"
				<< "E] isGreaterThanOrEqualTo \n"
				<< "F] isLessThanOrEqualTo \n"
				<< "G] iszero \n \n";

			switch (CaseNumber)
			{
				case '1':		// Opeartions are performed on HugeInteger and integer
				{					
					cout << "Enter any number with maximum of 40 digits \n";
					cin >> FirstTestString; 
					if (FirstTestString.length() > 40)
						break;
					cout << "Enter any integer \n";
					cin  >> TestInteger;

					HugeInteger ob1(FirstTestString), ob2(TestInteger);
					Sum = ob1.add(TestInteger);
					cout << "\n Output: \n Addition of two numbers is  ";
					Sum.output();
					cout << "\n";
					cout << " Differrence of two numbers is  "; 
					Differrence = ob1.subtract(TestInteger);
					Differrence.output();
					cout << "\n";
					DriverFunction(ob1, ob2);
					break; 
				}
			
				case '2':		// Opeartions are performed on HugeInteger and Long integer
				{
					cout << "Enter any number with maximum of 40 digits \n";
					cin >> FirstTestString;					
					if (FirstTestString.length() > 40)
						break; 
					cout << "Enter any Long integer \n";
					cin >> TestLong;
					
					HugeInteger ob1(FirstTestString), ob2(TestLong);
					Sum = ob1.add(ob2);					
					cout << "\n Output: \n Addition of two numbers is  ";
					Sum.output();
					cout << "\n";					
					cout << " Differrence of two numbers is  "; 
					Differrence = ob1.subtract(ob2);
					Differrence.output();
					cout << "\n";
					DriverFunction(ob1, ob2); 
					break;
				}

				case '3':      // Opeartions are performed on two HugeIntegers
				{
					cout << "Enter any number with maximum of 40 digits \n";
					cin >> FirstTestString;
					if (FirstTestString.length() > 40)
						break; 
					cout << "Enter any number with maximum of 40 digits \n";
					cin >> SecondTestString;
					if (SecondTestString.length() > 40)
						break;

					HugeInteger ob1(FirstTestString), ob2(SecondTestString);
					Sum = ob1.add(SecondTestString);										
					cout << "\n Output: \n Addition of two numbers is  ";
					Sum.output();
					cout << "\n";
					cout << " Differrence of two numbers is ";
					Differrence = ob1.subtract(SecondTestString);
					Differrence.output();
					cout << "\n";
					DriverFunction(ob1, ob2);
					break;
				}
				default: break;
			}
		}
		else
		{
			cout << "You entered invalid number \n";
		}
		cout << "Press 'y' to continue ";
		cin >> ToContinue;		
	}
}

// This fucntions takes two integer to as input parameters and perofrm all bool operations 
// mentioned in hugeinteger.h and return type is void.
void DriverFunction(HugeInteger A, HugeInteger B)
{
	// Tests isEqualTo methods
	if (A.isEqualTo(B) == 1)
	{
		A.output();		cout << "  is equal to  "; 		B.output(); 		cout << "\n";
	}
	else
	{
		A.output(); 		cout << "  is not equal to  ";	B.output();		cout << "\n";
	}

	// Tests isGreaterThanmethod
	if (A.isGreaterThan(B) == 1)
	{
		A.output();		cout << "  is greater than ";	B.output();		 cout << "\n";
	}
	else
	{
		A.output();		cout << "  is not greater than ";	B.output();		 cout << "\n";
	}

	// Tests isGreaterThanOrEqualTo method
	if (A.isGreaterThanOrEqualTo(B) == 1)
	{
		A.output();		 cout << "  is greater than or equal to ";   B.output(); cout << "\n";
	}
	else
	{
		A.output();		 cout << "  is not greater than or equal to ";   B.output(); cout << "\n";
	}

	// Tests isLessThanOrEqualTo method
	if (A.isLessThanOrEqualTo(B) == 1)
	{
		A.output(); cout << "  is less than or equal to  "; B.output(); cout << "\n";
	}
	else
	{
		A.output(); cout << "  is not less than or equal to  ";  B.output(); cout << "\n";
	}

	// Tests isNotEqualTo method
	if (A.isNotEqualTo(B) == 1)
	{
		A.output(); cout << "  is not equal to  "; B.output(); cout << "\n";
	}
	else
	{
		A.output(); cout << "  is equal to  ";  B.output();  cout << "\n";
	}

	// Tests isZero method 
	if (A.isZero() == 1)
	{
		A.output(); cout << "  is equal to  zero  \n";
	}
	else
	{
		A.output(); cout << "  is not equal to  zero \n"; 
	}
}

//End of testHugeInteger.cpp