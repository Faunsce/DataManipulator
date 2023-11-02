#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <random>
#include <numeric>

void programWait(short int x) { std::this_thread::sleep_for(std::chrono::milliseconds(x)); };
void clearScreen() { std::cout << "\x1b[2J\x1b[H"; };

int obtainUserSelection(int valMin, int valMax);

void sortDataSet(std::vector<int>& dataSet);
void searchDataSet(std::vector<int>& dataSet) {};

namespace Algorithms {
	void bubbleSort(std::vector<int>& dataSet);
	void insertionSort(std::vector<int>& dataSet);
	void mergeSort(std::vector<int>& dataSet);
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& intVec)
{
	for (int i = 0; i < intVec.size(); i++) {
		os << intVec[i] << " ";
		if ((i != 0) && ((i + 1) % 20 == 0))
		{
			os << std::endl;
		}
	}
	return os;
}

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

	clearScreen();
	std::cout << "What would like like to do to the data today?" << std::endl
		<< "1 : Shuffle Dataset" << std::endl
		<< "2 : Sort Dataset" << std::endl
		<< "3 : Search Dataset" << std::endl
		<< "4 : Generate New Dataset" << std::endl
		<< "5 : End program" << std::endl;

	int userSelection = obtainUserSelection(1, 5);

	std::chrono::steady_clock::time_point start, end;
	switch (userSelection)
	{
	case 1:
		std::shuffle(dataSet.begin(), dataSet.end(), randomEngine);
		break;
	case 2:
		start = std::chrono::steady_clock::now();
		sortDataSet(dataSet);
		end = std::chrono::steady_clock::now();
		auto diff = end - start;
		std::cout << std::chrono::duration<double, std::milli>(diff).count() << " ms" << std::endl;
		break;
	case 3:
		searchDataSet(dataSet);
		break;
	case 4:
		dataSetSize = obtainUserSelection(10, 500);
		dataSet = std::vector<int>(1, dataSetSize);
		break;
	case 5:
		break;
	default:
		throw std::invalid_argument("value 'userSelection' must be between 1 and 5");
		break;
	}

	// Loop back through choice selection

	// Program End

	std::cin.ignore(1);
}

/*
Data maniuplator is a program in which at runtime, a user creates a data set of a user defined size.

This data set will not contain missing elements.

The datas size may be modified.

The data set should also be able to be searched, sorted, and randomized.
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

void sortDataSet(std::vector<int>& dataSet) 
{
	clearScreen();
	std::cout << "Which sorting method should we use?" << std::endl
		<< "1: Bubble Sort" << std::endl
		<< "2: Insertion Sort" << std::endl
		<< "3: Merge Sort" << std::endl;

	int userSelection = obtainUserSelection(1, 3);

	//std::cout << "Your data beforehand." << std::endl << dataSet << std::endl;

	switch (userSelection)
	{
	case 1:
		Algorithms::bubbleSort(dataSet);
		break;
	case 2:
		Algorithms::insertionSort(dataSet);
		break;
	case 3:
		Algorithms::mergeSort(dataSet);
		break;
	default:
		throw std::invalid_argument("value 'userSelection' must be between 1 and 3");
	}

	//std::cout << "Your data afterwards." << std::endl << dataSet << std::endl;

	programWait(2000);
};


	namespace Algorithms {
		void bubbleSort(std::vector<int>& dataSet) {
			bool isClean = false;
			for (int i = dataSet.size() - 1; i > 0; i--)
			{
				isClean = true;
				for (int j = 0; j < i; j++)
				{
					if (dataSet[j] > dataSet[j + 1])
					{
						std::swap(dataSet[j], dataSet[j + 1]);
						isClean = false;
					}
				}
				if (isClean)
					return;
			}
		}
		
		void insertionSort(std::vector<int>& dataSet) {
			for (int i = 1; i < dataSet.size(); i++)
			{
				int j = i;
				while (j > 0 && dataSet[j] < dataSet[j - 1])
				{
					std::swap(dataSet[j], dataSet[j - 1]);
					j--;
				}
			}
		}
		
		void mergeSort(std::vector<int>& dataSet) {
			if (dataSet.size() > 2) {
				std::vector<int> left(dataSet.begin(), dataSet.begin() + (dataSet.size() / 2));
				mergeSort(left);
				std::vector<int> right(dataSet.begin() + (dataSet.size() / 2), dataSet.end());
				mergeSort(right);
				
				//std::cout << left << std::endl << right << std::endl;

				//programWait(500);

				for (const auto& element : right)
				{
					for (int i = 0; i < left.size(); i++)
					{
						if (left[i] > element)
						{
							left.insert(left.begin() + i, element);
							break;
						}
						else if (i == left.size() - 1) 
						{
							left.emplace_back(element);
							break;
						}
					}
				}

				dataSet = left;

			} else {
				if (dataSet.size() > 1 && (dataSet[0] > dataSet[1])) {
					std::swap(dataSet[0], dataSet[1]);
				}
				return;
			}
		}
	}