#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	comparisons = 0;
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		vec = other.vec;
		deq = other.deq;
		comparisons = other.comparisons;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{

}

static bool isValidNum(long num)
{
	return (num >= 0 && num <= std::numeric_limits<int>::max());
}

bool PmergeMe::validInput(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cerr << "Empty input\n";
		return false;
	}
	vec.reserve(argc - 1);
	long val = 0;

	for (int i = 1; argv[i]; i++)
	{
		std::istringstream iss(argv[i]);
		if (!(iss >> val) || !iss.eof())
		{
			std::cerr << "Invalid input\n";
			return false;
		}
		if (!isValidNum(val))
		{
			std::cerr << "Out of bounds input\n";
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

// Sorts indices into `vals` instead of the values themselves, so every element
// is unique even when the values contain duplicates.
std::vector<size_t> PmergeMe::sort_vec(const std::vector<int> &vals, std::vector<size_t> idx)
{
	size_t n = idx.size();
	if (n <= 1)
		return idx;

	std::vector<size_t> winners;
	std::vector<size_t> losers;
	winners.reserve(n / 2);
	losers.reserve(n / 2 + 1);

	bool hasStraggler = (n % 2 != 0);
	size_t straggler = 0;
	if (hasStraggler)
	{
		straggler = idx.back();
		idx.pop_back();
	}
	for (size_t i = 0; i < idx.size(); i += 2)
	{
		++comparisons;
		if (vals[idx[i]] > vals[idx[i + 1]])
		{
			winners.push_back(idx[i]);
			losers.push_back(idx[i + 1]);
		}
		else
		{
			winners.push_back(idx[i + 1]);
			losers.push_back(idx[i]);
		}
	}
	if (hasStraggler)
		losers.push_back(straggler);

	// Recursion
	std::vector<size_t> sortedWinners = sort_vec(vals, winners);
	std::vector<size_t> chain = sortedWinners;

	// b1: the loser of the smallest winner always goes at the front, no search needed
	size_t first = std::find(winners.begin(), winners.end(), sortedWinners[0]) - winners.begin();
	chain.insert(chain.begin(), losers[first]);

	// Everything else, in Jacobsthal order
	std::vector<size_t> order = insertionOrder(losers.size());
	IdxLess<std::vector<int> > cmp(&vals, &comparisons);
	for (size_t k = 0; k < order.size(); k++)
	{
		size_t b = order[k];                // 1-based b index
		size_t value;
		std::vector<size_t>::iterator bound;

		if (b <= sortedWinners.size())      // has a winner
		{
			size_t winner = sortedWinners[b - 1];
			size_t orig = std::find(winners.begin(), winners.end(), winner) - winners.begin();
			value = losers[orig];
			bound = std::find(chain.begin(), chain.end(), winner);  // recompute each time
		}
		else                                // the straggler: no winner, search the whole chain
		{
			value = losers.back();
			bound = chain.end();
		}
		chain.insert(std::lower_bound(chain.begin(), bound, value, cmp), value);
	}
	return chain;
}

std::deque<size_t> PmergeMe::sort_deq(const std::deque<int> &vals, std::deque<size_t> idx)
{
	size_t n = idx.size();
	if (n <= 1)
		return idx;

	std::deque<size_t> winners;
	std::deque<size_t> losers;

	bool hasStraggler = (n % 2 != 0);
	size_t straggler = 0;
	if (hasStraggler)
	{
		straggler = idx.back();
		idx.pop_back();
	}
	for (size_t i = 0; i < idx.size(); i += 2)
	{
		++comparisons;
		if (vals[idx[i]] > vals[idx[i + 1]])
		{
			winners.push_back(idx[i]);
			losers.push_back(idx[i + 1]);
		}
		else
		{
			winners.push_back(idx[i + 1]);
			losers.push_back(idx[i]);
		}
	}
	if (hasStraggler)
		losers.push_back(straggler);

	// Recursion
	std::deque<size_t> sortedWinners = sort_deq(vals, winners);
	std::deque<size_t> chain = sortedWinners;

	// b1: the loser of the smallest winner always goes at the front, no search needed
	size_t first = std::find(winners.begin(), winners.end(), sortedWinners[0]) - winners.begin();
	chain.insert(chain.begin(), losers[first]);

	// Everything else, in Jacobsthal order
	std::vector<size_t> order = insertionOrder(losers.size());
	IdxLess<std::deque<int> > cmp(&vals, &comparisons);
	for (size_t k = 0; k < order.size(); k++)
	{
		size_t b = order[k];                // 1-based b index
		size_t value;
		std::deque<size_t>::iterator bound;

		if (b <= sortedWinners.size())      // has a winner
		{
			size_t winner = sortedWinners[b - 1];
			size_t orig = std::find(winners.begin(), winners.end(), winner) - winners.begin();
			value = losers[orig];
			bound = std::find(chain.begin(), chain.end(), winner);  // recompute each time
		}
		else                                // the straggler: no winner, search the whole chain
		{
			value = losers.back();
			bound = chain.end();
		}
		chain.insert(std::lower_bound(chain.begin(), bound, value, cmp), value);
	}
	return chain;
}

static double nowMicroseconds(void)
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return ts.tv_sec * 1000000.0 + ts.tv_nsec / 1000.0;
}

void PmergeMe::run(void)
{
	std::cout << "Before: ";
	displayVec();

	// vector (index setup and rebuild are inside the timed region, same as for the deque)
	comparisons = 0;
	double start_vec = nowMicroseconds();
	std::vector<size_t> vecIdx(vec.size());
	for (size_t i = 0; i < vecIdx.size(); i++)
		vecIdx[i] = i;
	std::vector<size_t> sortedVecIdx = sort_vec(vec, vecIdx);
	std::vector<int> sortedVec;
	sortedVec.reserve(sortedVecIdx.size());
	for (size_t i = 0; i < sortedVecIdx.size(); i++)
		sortedVec.push_back(vec[sortedVecIdx[i]]);
	this->vec = sortedVec;
	double vec_time = nowMicroseconds() - start_vec;
	size_t vec_comparisons = comparisons;

	// deque
	comparisons = 0;
	double start_deq = nowMicroseconds();
	std::deque<size_t> deqIdx;
	for (size_t i = 0; i < deq.size(); i++)
		deqIdx.push_back(i);
	std::deque<size_t> sortedDeqIdx = sort_deq(deq, deqIdx);
	std::deque<int> sortedDeq;
	for (size_t i = 0; i < sortedDeqIdx.size(); i++)
		sortedDeq.push_back(deq[sortedDeqIdx[i]]);
	this->deq = sortedDeq;
	double deq_time = nowMicroseconds() - start_deq;
	size_t deq_comparisons = comparisons;

	std::cout << "After: ";
	displayVec();

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << vec_time << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << deq_time << " us" << std::endl;
	std::cout << "Vector implementation comparisons: " << vec_comparisons << std::endl;
	std::cout << "Deque implementation comparisons: " << deq_comparisons << std::endl;
}