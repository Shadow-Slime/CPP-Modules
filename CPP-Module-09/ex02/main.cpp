#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	PmergeMe obj;
	if (!obj.validInput(argc, argv))
		return 1;
	std::cout << "Before: ";
	obj.displayVec();
	obj.vec = obj.sort_vec(obj.vec);
	std::cout << "After: ";
	obj.displayVec();
	for (unsigned int i = 0; i + 1 < obj.vec.size(); i++)
	{
		if (obj.vec[i] > obj.vec[i] + 1)
		{
			return 1;
		}
	}
	return 0;
}