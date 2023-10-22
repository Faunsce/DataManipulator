#include <iostream>
#include <thread>
#include <chrono>

#define CLEAR_SCREEN() std::cout << "\x1b[2J\x1b[H"
#define PROGRAM_WAIT(x) std::this_thread::sleep_for(std::chrono::milliseconds(x))

int main()
{
	std::cout << "Welcome to the Data manipulator!" << std::endl;

	PROGRAM_WAIT(500);

	CLEAR_SCREEN();

	// Obtain user input for creation of data set

	// Create Data set

	std::cout << "What would like like to do to the data today?" << std::endl;

	// Obtain user input on choice of option

	// perform option, options are modify set, shuffle, sort, search, and end program.

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