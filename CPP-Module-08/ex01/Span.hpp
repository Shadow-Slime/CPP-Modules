#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int num);
		int shortestSpan();
		int longestSpan();
		template <typename iterator> void addNumbers(iterator begin, iterator end)
		{
			if (nums.size() >= max_size)
				throw(std::out_of_range("ERROR: container full"));
			int dist = std::distance(begin, end);
			if (dist < 0)
				throw(std::out_of_range("ERROR: invalid iterator range"));
			if (static_cast<unsigned int>(dist) > max_size - nums.size())
				throw(std::out_of_range("ERROR: not enough capacity for range"));
			nums.insert(nums.end(), begin, end);
		}
	private:
		std::vector<int> nums;
		unsigned int max_size;
};

#endif