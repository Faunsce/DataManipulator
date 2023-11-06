#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <random>
#include <numeric>

#include "Functions.hpp"

int main()
{
	std::random_device randomDevice;
	std::mt19937_64 randomEngine(randomDevice());

	std::cout << "Welcome to the Data manipulator!" << std::endl;

	programWait(500);

	clearScreen();

	std::cout << "Please enter a value between 10 and 10000 (inclusive) : ";

	int dataSetSize = obtainUserSelection(10, 100000);

	std::vector<int> dataSet(dataSetSize);
	std::iota(dataSet.begin(), dataSet.end(), 1);
	std::shuffle(dataSet.begin(), dataSet.end(), randomEngine);
	
	bool goAgain = false;
	do {
		goAgain = operateOnDataset(dataSet, randomEngine);
	} while (goAgain);

	std::cin.ignore(1);
}

/*
Data maniuplator is a program in which at runtime, a user creates a data set of a user defined size.

This data set will not contain missing elements.

The datas size may be modified.

The data set should also be able to be searched, sorted, and randomized.
*/
