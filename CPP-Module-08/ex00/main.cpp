#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include "easyfind.hpp"

template <typename T>
static void printContainer(const std::string &label, const T &c)
{
	std::cout << label << ": [";
	typename T::const_iterator it = c.begin();
	typename T::const_iterator ite = c.end();
	for (; it != ite; ++it)
	{
		std::cout << *it;
		typename T::const_iterator next = it;
		++next;
		if (next != ite)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

template <typename T>
static void tryFind(const std::string &label, T &container, int value)
{
	typename T::iterator it = easyfind(container, value);
	if (it != container.end())
		std::cout << label << " -> found " << value
				   << " (points to " << *it << ")" << std::endl;
	else
		std::cout << label << " -> not found (got end())" << std::endl;
}

static void testVector()
{
	std::cout << "\n--- std::vector<int> ---" << std::endl;
	std::vector<int> vec;
	vec.push_back(4);
	vec.push_back(8);
	vec.push_back(15);
	vec.push_back(16);
	vec.push_back(23);
	vec.push_back(42);
	printContainer("vec", vec);

	tryFind("find 15 (present, middle)", vec, 15);
	tryFind("find 4 (present, first)", vec, 4);
	tryFind("find 42 (present, last)", vec, 42);
	tryFind("find 99 (absent)", vec, 99);
}

static void testList()
{
	std::cout << "\n--- std::list<int> ---" << std::endl;
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	printContainer("lst", lst);

	tryFind("find 2 (present)", lst, 2);
	tryFind("find 7 (absent)", lst, 7);
}

static void testDeque()
{
	std::cout << "\n--- std::deque<int> ---" << std::endl;
	std::deque<int> dq;
	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);
	printContainer("dq", dq);

	tryFind("find 20 (present)", dq, 20);
	tryFind("find 1000 (absent)", dq, 1000);
}

static void testEmptyContainer()
{
	std::cout << "\n--- empty std::vector<int> ---" << std::endl;
	std::vector<int> empty;
	printContainer("empty", empty);

	tryFind("find 0 (absent, empty container)", empty, 0);

	std::vector<int>::iterator it = easyfind(empty, 0);
	if (it == empty.end())
		std::cout << "OK: not-found case returns exactly container.end()" << std::endl;
	else
		std::cout << "ERROR: not-found case did not return container.end()" << std::endl;
}

static void testDuplicates()
{
	std::cout << "\n--- duplicates: first occurrence ---" << std::endl;
	std::vector<int> dup;
	dup.push_back(5);
	dup.push_back(9);
	dup.push_back(9);
	dup.push_back(9);
	dup.push_back(1);
	printContainer("dup", dup);

	// Should return an iterator to the FIRST occurrence of 9, not any later one.
	std::vector<int>::iterator it = easyfind(dup, 9);
	std::ptrdiff_t index = std::distance(dup.begin(), it);
	std::cout << "find 9 -> found at index " << index
			   << " (expected index 1)" << std::endl;
}

static void testMutationThroughReturnedIterator()
{
	std::cout << "\n--- mutating through the returned iterator ---" << std::endl;
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	printContainer("vec (before)", vec);

	std::vector<int>::iterator it = easyfind(vec, 2);
	*it = 999;
	printContainer("vec (after modifying *it)", vec);
}

int main()
{
	testVector();
	testList();
	testDeque();
	testEmptyContainer();
	testDuplicates();
	testMutationThroughReturnedIterator();

	std::cout << "\nAll tests completed." << std::endl;
	return 0;
}