#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>
#include <limits>
#include <ctime>
#include <iomanip>

struct CountingLess
{
	size_t *count;
	CountingLess(size_t *c);
	bool operator()(int a, int b) const
	{
		++(*count);
		return a < b;
	}
};

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		bool validInput(int argc, char **argv);
		void displayVec(void);
		void displayDeq(void);
		std::vector<size_t> insertionOrder(size_t m);
		std::vector<int> sort_vec(std::vector<int> values);
		std::deque<int> sort_deq(std::deque<int> values);
		void run(void);
	private:
		std::vector<int> vec;
		std::deque<int> deq;
		size_t comparisons;
};

#endif