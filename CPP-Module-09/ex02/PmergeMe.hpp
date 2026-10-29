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

template <typename C>
struct IdxLess
{
	const C *vals;
	size_t  *count;
	IdxLess(const C *v, size_t *c) : vals(v), count(c) {}
	bool operator()(size_t a, size_t b) const
	{
		++(*count);
		return (*vals)[a] < (*vals)[b];
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
		std::vector<size_t> sort_vec(const std::vector<int> &vals, std::vector<size_t> idx);
		std::deque<size_t>  sort_deq(const std::deque<int> &vals, std::deque<size_t> idx);
		void run(void);
	private:
		std::vector<int> vec;
		std::deque<int> deq;
		size_t comparisons;
};

#endif