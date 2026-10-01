#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

static bool isValidNum(int num, const std::vector<int> &vec)
{
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (*it == num)
			return false;
	}
	return true;
}

bool PmergeMe::validInput(int argc, char **argv)
{
	if (argc <= 1)
		return false;
	vec.reserve(argc - 1);
	for (int i = 0; argv[i]; i++)
	{
		
	}
}