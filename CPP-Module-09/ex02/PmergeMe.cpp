#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::~PmergeMe()
{

}

static bool isValidNum(long num, const std::vector<int> &vec)
{
	if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
		return false;
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
	long val = 0;
	
	for (int i = 1; argv[i]; i++)
	{
		std::istringstream iss(argv[i]);
		if (!(iss >> val) || !iss.eof())
		{
			std::cout << "Invalid Input" << std::endl;
			return false;
		}
		if (!isValidNum(val, this->vec))
		{
			std::cout << "Duplicate or out of bounds input" << std::endl;
			return false;
		}
		vec.push_back(val);
		deq.push_back(val);
	}
	return true;
}

void PmergeMe::displayVec(void)
{
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != vec.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::displayDeq(void)
{
	for (std::deque<int>::const_iterator it = deq.begin(); it != deq.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != deq.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::sort(void)
{
	std::sort(vec.begin(), vec.end());
	std::sort(deq.begin(), deq.end());
}

