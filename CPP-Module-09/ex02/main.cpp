#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	PmergeMe obj;
	if (!obj.validInput(argc, argv))
		return 1;
	std::cout << "Before: ";
	obj.displayVec();
	obj.sort();
	std::cout << "After: ";
	obj.displayVec();
}