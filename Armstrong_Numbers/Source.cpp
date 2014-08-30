#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::stoi;

// Returns the number of digits in a number
unsigned int numOfDigits(unsigned int number)
{
	unsigned int digits = 0;
	while (number)
	{
		number /= 10;
		++digits;
	}
	return digits;
}

// Determines whether a number is an armstrong number
bool isArmstrongNum(const unsigned int number)
{
	unsigned int n = numOfDigits(number);
	int sum = 0;
	unsigned int number_to_test = number;
	// Calculates the total sum of each digit to the nth power
	while (number_to_test > 0) {
		int digit = number_to_test % 10;
		sum += pow(digit, n);
		number_to_test /= 10;
	}
	return (number == sum) ? 1 : 0;
	
}

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	unsigned int number;
	while (ifs >> number)
	{
		if (isArmstrongNum(number))
		{
			cout << "True" << endl;
		}
		else
		{
			cout << "False" << endl;
		}
	}
	return 0;
}