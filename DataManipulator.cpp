#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <random>

void programWait(short int x) { std::this_thread::sleep_for(std::chrono::milliseconds(x)); };
void clearScreen() { std::cout << "\x1b[2J\x1b[H"; };
int obtainUserSelection(int valMin, int valMax);

void sortDataSet(std::vector<int>& dataSet) {};
void searchDataSet(std::vector<int>& dataSet) {};

int main()
{
	std::random_device randomDevice;
	std::mt19937_64 randomEngine(randomDevice());

	std::cout << "Welcome to the Data manipulator!" << std::endl;

	programWait(500);

	clearScreen();

	std::cout << "Please enter a value between 10 and 100 (inclusive) : ";

	int dataSetSize = obtainUserSelection(10, 100);

	std::vector<int> dataSet(1, dataSetSize);

	clearScreen();
	std::cout << "What would like like to do to the data today?" << std::endl
		<< "1 : Shuffle Dataset" << std::endl
		<< "2 : Sort Dataset" << std::endl
		<< "3 : Search Dataset" << std::endl
		<< "4 : Generate New Dataset" << std::endl
		<< "5 : End program" << std::endl;

	int userSelection = obtainUserSelection(1, 5);

	switch (userSelection)
	{
	case 1:
		std::shuffle(dataSet.begin(), dataSet.end(), randomEngine);
		break;
	case 2:
		sortDataSet(dataSet);
		break;
	case 3:
		searchDataSet(dataSet);
		break;
	case 4:
		dataSetSize = obtainUserSelection(10, 100);
		dataSet = std::vector<int>(1, dataSetSize);
		break;
	case 5:
		break;
	default:
		throw std::invalid_argument("value 'userSelection' must be between 1 and 5");
		break;
	}

	// log and/or print state of dataset

	// Loop back through choice selection

	// Prompt user to save their data

	// Program End

	std::cin.ignore(1);
}

/*
Data maniuplator is a program in which at runtime, a user creates a data set of a user defined size.

This data set will not contain missing elements.

The datas size may be modified.

The data set should also be able to be searched, sorted, and randomized.

A logging monad could be useful in tracking the state of the dataset throughout the programs lifetime.

This log may or may not be saved at the end of runtime to a file.
*/

int obtainUserSelection(int valMin, int valMax)
{
	std::string userInput;
	bool validInput;
	while (true) {
		validInput = true;
		std::getline(std::cin, userInput);

		for (const auto& element : userInput)
		{
			if (!std::isdigit(element))
				validInput = false;
		}

		int userNum = 0;

		if (validInput)
			userNum = std::stoi(userInput);

		if (userNum < valMin || userNum > valMax)
			validInput = false;

		if (validInput)
			return userNum;
		else
			std::cout << std::endl << "Invalid input, please try again. : ";
	};
}