#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>
#include <limits>

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
		std::vector<int> sort_vec(std::vector<int> values);
		void sort_deq(void);
		std::vector<int> vec;
		std::deque<int> deq;
	private:
		// std::vector<int> vec;
		// std::deque<int> deq;
};

#endif