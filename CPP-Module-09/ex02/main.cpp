#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	PmergeMe obj;
	if (!obj.validInput(argc, argv))
		return 1;
	obj.run();
	return 0;
}