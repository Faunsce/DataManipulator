#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <random>

void programWait(short int x);
void clearScreen();

int obtainUserSelection(int valMin, int valMax);

[[nodiscard]] bool operateOnDataset(std::vector<int>& dataSet, std::mt19937_64& randomEngine);
void sortDataSet(std::vector<int>& dataSet);
void searchDataSet(std::vector<int>& dataSet);

namespace Algorithms {
	void bubbleSort(std::vector<int>& dataSet);
	void insertionSort(std::vector<int>& dataSet);
	void mergeSort(std::vector<int>& dataSet);

	int linearSearch(std::vector<int>& dataSet, int valueToFind);
	int binarySearch(std::vector<int>& dataSet, int valueToFind);
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& intVec);
