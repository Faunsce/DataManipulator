#include "Functions.hpp"

void programWait(short int x) 
{ 
	std::this_thread::sleep_for(std::chrono::milliseconds(x)); 
};

void clearScreen() 
{ 
	std::cout << "\x1b[2J\x1b[H"; 
};

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

[[nodiscard]] bool operateOnDataset(std::vector<int>& dataSet, std::mt19937_64& randomEngine)
{
	int dataSetSize = dataSet.size();

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
		std::cout << "Please enter a value between 10 and 10000 (inclusive) : ";
		dataSetSize = obtainUserSelection(10, 10000);
		dataSet = std::vector<int>(1, dataSetSize);
		break;
	case 5:
		return false;
		break;
	default:
		throw std::invalid_argument("value 'userSelection' must be between 1 and 5");
		break;
	}

	programWait(2000);

	return true;
};

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
}

void searchDataSet(std::vector<int>& dataSet)
{
	clearScreen();
	std::cout << "Which search method should we use?" << std::endl
		<< "1: Linear Search" << std::endl
		<< "2: Binary Search" << std::endl;
	int userSelection = obtainUserSelection(1, 2);

	std::cout << "What value are we looking for?" << std::endl
		<< "Value to find :";
	int secondaryUserSelection = obtainUserSelection(1, dataSet.size());


	//std::cout << "Your data beforehand." << std::endl << dataSet << std::endl;

	int posOfValue;

	switch (userSelection)
	{
	case 1:
		posOfValue = Algorithms::linearSearch(dataSet, secondaryUserSelection);
		break;
	case 2:
		posOfValue = Algorithms::binarySearch(dataSet, secondaryUserSelection);
		break;
	default:
		throw std::invalid_argument("value 'userSelection' must be between 1 and 2");
	}

	std::cout << "The index of the value was [" << std::to_string(posOfValue) << "]" << std::endl;
	//std::cout << "Your data afterwards." << std::endl << dataSet << std::endl;

	programWait(2000);
}
;


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

		}
		else {
			if (dataSet.size() > 1 && (dataSet[0] > dataSet[1])) {
				std::swap(dataSet[0], dataSet[1]);
			}
			return;
		}
	}

	int linearSearch(std::vector<int>& dataSet, int valueToFind) {

		for (int i = 0; i < dataSet.size(); i++)
		{
			if (dataSet[i] == valueToFind)
				return i;
		}

		return -1;
	}

	int binarySearch(std::vector<int>& dataSet, int valueToFind) {
		// TODO: Implement Binary Search
		return -1;
	}
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