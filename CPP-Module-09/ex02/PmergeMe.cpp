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

std::vector<int> PmergeMe::sort_vec(std::vector<int> values)
{
	//std::sort(vec.begin(), vec.end());
	std::vector<int> winners;
	std::vector<int> losers;
	size_t sample_size = values.size();
	std::cout << sample_size << std::endl;
	if (sample_size == 1)
	{
		std::vector<int> ret;
		ret.push_back(values[0]);
		return ret;
	}
	winners.reserve(sample_size % 2);
	losers.reserve(sample_size % 2);

	int straggler = -1;
	if (sample_size % 2)
	{
		straggler = values.back();
		values.pop_back();
	}
	for (std::vector<int>::const_iterator it = values.begin(); it != values.end(); it += 2)
	{
		int num1 = *it;
		int num2 = *(it + 1);
		if (num1 > num2)
		{
			winners.push_back(num1);
			losers.push_back(num2);
		}
		else
		{
			winners.push_back(num2);
			losers.push_back(num1);
		}
	}
	std::vector<int> sortedWinners = sort_vec(winners);
	std::vector<int> chain = sortedWinners;

	// Insert each winner's loser, in sorted-winner order
	for (size_t k = 0; k < sortedWinners.size(); k++)
	{
		// Find which loser belongs to this winner (via its position in the ORIGINAL winners vector)
		size_t idx = std::find(winners.begin(), winners.end(), sortedWinners[k]) - winners.begin();
		int loser = losers[idx];

		// The loser is guaranteed <= its winner, so only search up to the winner's position
		std::vector<int>::iterator winnerPos =
			std::find(chain.begin(), chain.end(), sortedWinners[k]);
		std::vector<int>::iterator pos = std::lower_bound(chain.begin(), winnerPos, loser);
		chain.insert(pos, loser);
	}

	// Straggler has no winner, so search the whole chain
	if (straggler >= 0)
	{
		std::vector<int>::iterator pos = std::lower_bound(chain.begin(), chain.end(), straggler);
		chain.insert(pos, straggler);
	}

	return chain;
}

