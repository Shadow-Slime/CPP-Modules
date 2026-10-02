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
	long val;
	
	for (int i = 1; argv[i]; i++)
	{
		std::istringstream iss(argv[i]);
		if (!iss >> val || !iss.eof())
			return false;
		
	}
}