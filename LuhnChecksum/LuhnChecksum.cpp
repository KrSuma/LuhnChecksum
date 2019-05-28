// LuhnChecksum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int printAndSum(vector<int> arr)
{
	int sum{};
	cout << "The new value is: ";

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i];
		sum += arr[i];
	}
	return sum;
}

void checksum(int sum)
{
	if (sum % 10 == 0)
	{
		cout << "\n" << "This satisfies the Luhn Checksum.";
	}
	else
	{
		cout << "\n" << "This does not satisfies the Lubh Checksum.";
	}
}

int main()
{
	/// Luhn Checksum problem
	// 1. take original number, double the value of every other digit from the right.
	// 2. if a doubled avlue now had two digits, add the digits individually
	// 3. ID number is valid if sum is divisible by 10

	int input{};

	//take an input number
	cout << "give an input number." << endl;
	cin >> input;

	//convert to string to determine the length of the digits
	string convertToChar{ to_string(input) };
	int length = convertToChar.length();
	vector<int> array{};

	//insert each digits inside the vector
	for (int i = 1; i < length + 1; i++)
	{
		int digit = input % 10;
		input /= 10;

		//for every 2nd , from the right
		if (i % 2 == 0)
		{
			//double it
			digit *= 2;

			//if the doubled digit is 2 in length
			if (digit > 9)
			{
				//split the digit in 2
				int toDivide = digit;
				int secondDigit = toDivide % 10;
				int firstDigit = toDivide / 10;

				array.insert(array.begin(), secondDigit);
				array.insert(array.begin(), firstDigit);
			}
			else
			{
				array.insert(array.begin(), digit);
			}
		}
		else
		{
			array.insert(array.begin(), digit);
		}
	}

	//print out the sum and check
	int sum{ printAndSum(array) };
	checksum(sum);
}