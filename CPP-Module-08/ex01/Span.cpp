#include "Span.hpp"

Span::Span(unsigned int N) : max_size(N)
{
	nums.reserve(N);
}

Span::Span(const Span &other) : max_size(other.max_size)
{
	nums.reserve(max_size);
	for (unsigned int i = 0; i < other.nums.size(); i++)
	{
		nums.push_back(other.nums[i]);
	}
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->nums = other.nums;
		this->max_size = other.max_size;

	}
	return *this;
}

Span::~Span(){}

void Span::addNumber(int num)
{
	if (nums.size() >= max_size)
		throw(std::out_of_range("ERROR: container full"));
	nums.push_back(num);
}

int Span::shortestSpan()
{
	if (nums.size() < 2)
		throw(std::out_of_range("ERROR: Not enough elements to form a span"));
	std::vector<int> tmp = nums;
	std::sort(tmp.begin(), tmp.end());
	int res = std::numeric_limits<int>::max();
	for (unsigned int i = 0; i < nums.size() - 1; i++)
	{
		if (tmp[i + 1] - tmp[i] < res)
			res = tmp[i + 1] - tmp[i];
	}
	return res;
}

int Span::longestSpan()
{

	if (nums.size() < 2)
		throw(std::out_of_range("ERROR: Not enough elements to form a span"));
	std::vector<int>::iterator max_element_ptr = std::max_element(nums.begin(), nums.end());
	std::vector<int>::iterator min_element_ptr = std::min_element(nums.begin(), nums.end());
	return *max_element_ptr - *min_element_ptr;
}