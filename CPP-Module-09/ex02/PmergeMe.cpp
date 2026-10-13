#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	comparisons = 0;
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

std::vector<size_t> PmergeMe::insertionOrder(size_t m)   // 1-based indices, excluding b1
{
	std::vector<size_t> order;
	size_t prev = 1;   // consecutive Jacobsthal numbers: 1, 3, 5, 11, ...
	size_t cur = 3;
	while (prev < m)
	{
		size_t top = (cur < m) ? cur : m;
		for (size_t k = top; k > prev; --k)
			order.push_back(k);
		size_t next = cur + 2 * prev;   // J(n) = J(n-1) + 2*J(n-2)
		prev = cur;
		cur = next;
	}
	return order;
}

std::vector<int> PmergeMe::sort_vec(std::vector<int> values)
{
	//std::sort(vec.begin(), vec.end());
	std::vector<int> winners;
	std::vector<int> losers;
	size_t sample_size = values.size();
	//std::cout << sample_size << std::endl;
	if (sample_size <= 1)
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
		++comparisons;		
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

	if (straggler != -1)
		losers.push_back(straggler);

	// Recursion
	std::vector<int> sortedWinners = sort_vec(winners);
	std::vector<int> chain = sortedWinners;

	// b1: the loser of the smallest winner always goes at the front, no search needed
	size_t first = std::find(winners.begin(), winners.end(), sortedWinners[0]) - winners.begin();
	chain.insert(chain.begin(), losers[first]);

	// Everything else, in Jacobsthal order
	std::vector<size_t> order = insertionOrder(losers.size());
	for (size_t n = 0; n < order.size(); n++)
	{
		size_t idx = order[n];              // 1-based b index
		int value;
		std::vector<int>::iterator bound;

		if (idx <= sortedWinners.size())    // has a winner
		{
			int winner = sortedWinners[idx - 1];
			size_t orig = std::find(winners.begin(), winners.end(), winner) - winners.begin();
			value = losers[orig];
			bound = std::find(chain.begin(), chain.end(), winner);  // recompute each time
		}
		else                                // the straggler: no winner, search the whole chain
		{
			value = losers.back();
			bound = chain.end();
		}
		chain.insert(std::lower_bound(chain.begin(), bound, value, CountingLess(&comparisons)), value);
	}

	//std::cout << "\nComparisons: " << comparisons << std::endl;
	
	return chain;
}

std::deque<int> PmergeMe::sort_deq(std::deque<int> values)
{
	//std::sort(vec.begin(), vec.end());
	std::deque<int> winners;
	std::deque<int> losers;
	size_t sample_size = values.size();
	//std::cout << sample_size << std::endl;
	if (sample_size <= 1)
	{
		std::deque<int> ret;
		ret.push_back(values[0]);
		return ret;
	}
	
	// winners.reserve(sample_size % 2);
	// losers.reserve(sample_size % 2);

	int straggler = -1;
	if (sample_size % 2)
	{
		straggler = values.back();
		values.pop_back();
	}
	for (std::deque<int>::const_iterator it = values.begin(); it != values.end(); it += 2)
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

	if (straggler != -1)
		losers.push_back(straggler);

	// Recursion
	std::deque<int> sortedWinners = sort_deq(winners);
	std::deque<int> chain = sortedWinners;

	// b1: the loser of the smallest winner always goes at the front, no search needed
	size_t first = std::find(winners.begin(), winners.end(), sortedWinners[0]) - winners.begin();
	chain.insert(chain.begin(), losers[first]);

	// Everything else, in Jacobsthal order
	std::vector<size_t> order = insertionOrder(losers.size());
	for (size_t n = 0; n < order.size(); n++)
	{
		size_t idx = order[n];              // 1-based b index
		int value;
		std::deque<int>::iterator bound;

		if (idx <= sortedWinners.size())    // has a winner
		{
			int winner = sortedWinners[idx - 1];
			size_t orig = std::find(winners.begin(), winners.end(), winner) - winners.begin();
			value = losers[orig];
			bound = std::find(chain.begin(), chain.end(), winner);  // recompute each time
		}
		else                                // the straggler: no winner, search the whole chain
		{
			value = losers.back();
			bound = chain.end();
		}
		chain.insert(std::lower_bound(chain.begin(), bound, value), value);
	}
	return chain;
}


