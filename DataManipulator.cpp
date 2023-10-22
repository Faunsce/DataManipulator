#include <iostream>
#include <thread>
#include <chrono>

#define CLEAR_SCREEN() std::cout << "\x1b[2J\x1b[H"
#define PROGRAM_WAIT(x) std::this_thread::sleep_for(std::chrono::milliseconds(x));

int main()
{
	std::cout << "Welcome to the Data manipulator!" << std::endl;

	PROGRAM_WAIT(500);

	CLEAR_SCREEN();

	std::cout << "What would like like to do to the data today?" << std::endl;

	std::cin.ignore(1);
}
