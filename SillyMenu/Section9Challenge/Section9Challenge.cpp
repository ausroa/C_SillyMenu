// Section9Challenge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

void DisplayMenu();
void ClearList();
int MenuSelection();
int AddNumber();
int DisplayNumbers();
int SmallestNumber();
int SearchForNumber();
int LargestNumber();
char AskForInput();
double GetAverage();

using namespace std;

bool IsQ = false;
vector<int> numbers = {};

int main()
{
	do
	{
		DisplayMenu();
		MenuSelection();
	} while (!IsQ);

	return 0;
}

void DisplayMenu()
{
	// Display Menu
	cout << "\nP - Print Numbers\n";
	cout << "A - Add a number\n";
	cout << "M - Display mean of the numbers\n";
	cout << "S - Display smallest number\n";
	cout << "L - Display the largest number\n";
	cout << "T - Search for number and how many times it appears\n";
	cout << "C - Clear list\n";
	cout << "Q - Quit\n" << endl;

	return;
}

char AskForInput()
{
	char Input = 0;

	// Ask for input selection
	cout << "Please select an option: ";
	cin >> Input;

	return Input;
}

int MenuSelection()
{
	char Input = AskForInput();

	// Display numbers in vector
	if (Input == 'P' || Input == 'p')
	{
		DisplayNumbers();
	}
	else if (Input == 'A' || Input == 'a') // Add number to vector
	{
		AddNumber();
	}
	else if (Input == 'M' || Input == 'm')
	{
		GetAverage();
	}
	else if (Input == 'S' || Input == 's')
	{
		SmallestNumber();
	}
	else if (Input == 'L' || Input == 'l')
	{
		LargestNumber();
	}
	else if (Input == 'Q' || Input == 'q')
	{
		IsQ = true;
	}
	else if (Input == 'T' || Input == 't')
	{
		SearchForNumber();
	}
	else if (Input == 'C' || Input == 'c')
	{
		ClearList();
	}
	else
	{
		cout << "Not a valid input\n";
	}

	return 0;
}

int AddNumber()
{
	int number = 0;

	cout << "\nWhat number would you like to add to the list? ";
	cin >> number;

	for(int i = 0; i < numbers.size(); i++)
		if (numbers[i] == number)
		{
			cout << "No Duplicates!\n";
			return 0;
		}

	numbers.push_back(number);
	return 0;
}

int DisplayNumbers()
{
	if (numbers.size() == 0)
		cout << "[] - the list is empty" << endl;
	else
	{
		cout << "[ ";
		for (auto num : numbers)
			cout << num << " ";
		cout << "]" << endl;
	}
	return 0;
}

double GetAverage()
{
	if (numbers.size() == 0)
		cout << "Unable to calculate mean - no data\n";
	else
	{
		double Total = 0.0;
		for (auto num : numbers)
			Total += num;
		cout << "The mean is: " << Total / numbers.size();
		cout << endl;
	}
	return 0.0;
}

int SmallestNumber()
{
	if (numbers.size() == 0)
		cout << "There are no numbers!\n";
	else
	{
		int smallest = numbers.at(0);
		for (auto num : numbers)
			if (num < smallest)
				smallest = num;
		cout << "The smallest number is " << smallest << endl;
	}
	return 0;
}

int LargestNumber()
{
	if (numbers.size() == 0)
		cout << "Your jaunt is empty!\n";
	else
	{
		int largest = numbers.at(0);
		for (auto num : numbers)
			if (num > largest)
				largest = num;
		cout << "The largest number is " << largest << endl;
	}
	return 0;
}

int SearchForNumber()
{
	int SearchNum = 0;
	int occurence = 0;

	cout << "\nWhat number would you like to search for? ";
	cin >> SearchNum;

	for (int i = 0; i < numbers.size(); i++)
		if (numbers[i] == SearchNum)
			occurence++;

	cout << "The number " << SearchNum << " appears " << occurence;
	cout << " times!" << endl;

	return 0;
}

void ClearList()
{
	numbers.clear();
}




	
