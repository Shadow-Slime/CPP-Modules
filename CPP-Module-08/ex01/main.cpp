#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "Span.hpp"

// NOTE: this assumes a member function named addNumbers() that takes a pair of
// iterators, e.g.:
//     template <typename InputIterator>
//     void addNumbers(InputIterator first, InputIterator last);
// Rename the calls below if your own function is named differently.

static void testSubjectExample()
{
	std::cout << "\n--- Subject's exact example ---" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "(expected: 2 then 14)" << std::endl;
}

static void testAddNumberPastCapacity()
{
	std::cout << "\n--- addNumber() past capacity throws ---" << std::endl;
	Span sp(2);
	sp.addNumber(1);
	sp.addNumber(2);
	try
	{
		sp.addNumber(3);
		std::cout << "ERROR: no exception thrown when exceeding capacity" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}
}

static void testSpanWithZeroOrOneElement()
{
	std::cout << "\n--- shortestSpan()/longestSpan() with < 2 elements ---" << std::endl;

	Span empty(5);
	try
	{
		empty.shortestSpan();
		std::cout << "ERROR: no exception on shortestSpan() with 0 elements" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught expected exception (0 elements, shortestSpan): " << e.what() << std::endl;
	}
	try
	{
		empty.longestSpan();
		std::cout << "ERROR: no exception on longestSpan() with 0 elements" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught expected exception (0 elements, longestSpan): " << e.what() << std::endl;
	}

	Span single(5);
	single.addNumber(42);
	try
	{
		single.shortestSpan();
		std::cout << "ERROR: no exception on shortestSpan() with 1 element" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught expected exception (1 element, shortestSpan): " << e.what() << std::endl;
	}
}

static void testAddRangeBasic()
{
	std::cout << "\n--- addNumbers() basic usage ---" << std::endl;

	std::vector<int> nums;
	nums.push_back(4);
	nums.push_back(8);
	nums.push_back(15);
	nums.push_back(16);
	nums.push_back(23);

	Span sp(5);
	sp.addNumbers(nums.begin(), nums.end());
	std::cout << "shortestSpan(): " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan(): " << sp.longestSpan() << std::endl;
	std::cout << "(expected: 1 then 19)" << std::endl;
}

static void testAddRangeFromDifferentContainerType()
{
	std::cout << "\n--- addNumbers() works with any iterator type (std::list) ---" << std::endl;

	std::list<int> nums;
	nums.push_back(100);
	nums.push_back(1);
	nums.push_back(50);

	Span sp(3);
	sp.addNumbers(nums.begin(), nums.end());
	std::cout << "shortestSpan(): " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan(): " << sp.longestSpan() << std::endl;
	std::cout << "(expected: 49 then 99)" << std::endl;
}

static void testAddRangeExceedingCapacity()
{
	std::cout << "\n--- addNumbers() with a range larger than remaining capacity ---" << std::endl;

	std::vector<int> nums;
	for (int i = 0; i < 10; i++)
		nums.push_back(i);

	Span sp(5);
	try
	{
		sp.addNumbers(nums.begin(), nums.end());
		std::cout << "ERROR: no exception thrown when range exceeds capacity" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	// All-or-nothing check: confirm nothing was partially added.
	try
	{
		sp.addNumber(999);
		sp.addNumber(998);
		sp.addNumber(997);
		sp.addNumber(996);
		sp.addNumber(995);
		std::cout << "OK: rejected range left Span with full original capacity available" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "ERROR: Span appears to have been partially filled by the rejected range: "
				   << e.what() << std::endl;
	}
}

static void testAddRangeFillingRemainingSpaceExactly()
{
	std::cout << "\n--- addNumbers() filling exactly the remaining space ---" << std::endl;

	Span sp(5);
	sp.addNumber(1);
	sp.addNumber(2);

	std::vector<int> nums;
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);

	sp.addNumbers(nums.begin(), nums.end());
	std::cout << "shortestSpan(): " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan(): " << sp.longestSpan() << std::endl;
	std::cout << "(expected: 1 then 4)" << std::endl;

	try
	{
		sp.addNumber(6);
		std::cout << "ERROR: Span accepted a number past its now-full capacity" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught expected exception (Span correctly full): " << e.what() << std::endl;
	}
}

static void testCopyAndAssignmentIndependence()
{
	std::cout << "\n--- Copy construction / assignment independence ---" << std::endl;

	Span original(5);
	original.addNumber(1);
	original.addNumber(10);

	Span copyCtor(original);
	copyCtor.addNumber(100);
	std::cout << "original.longestSpan() after modifying copy: " << original.longestSpan()
			   << " (expected 9, unaffected by copy)" << std::endl;
	std::cout << "copyCtor.longestSpan(): " << copyCtor.longestSpan()
			   << " (expected 99)" << std::endl;

	Span assigned(5);
	assigned = original;
	assigned.addNumber(50);
	std::cout << "original.longestSpan() after modifying assigned: " << original.longestSpan()
			   << " (expected 9, unaffected by assignment)" << std::endl;
	std::cout << "assigned.longestSpan(): " << assigned.longestSpan()
			   << " (expected 49)" << std::endl;
}

static void testLargeSpan()
{
	std::cout << "\n--- Large Span (10,000+ numbers) ---" << std::endl;

	const unsigned int N = 50000;
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::vector<int> nums;
	nums.reserve(N);
	for (unsigned int i = 0; i < N; i++)
		nums.push_back(std::rand());

	Span sp(N);
	sp.addNumbers(nums.begin(), nums.end());

	std::cout << "shortestSpan(): " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan(): " << sp.longestSpan() << std::endl;

	// Sanity check: longestSpan should equal max - min of the raw data.
	int minVal = *std::min_element(nums.begin(), nums.end());
	int maxVal = *std::max_element(nums.begin(), nums.end());
	std::cout << "expected longestSpan (max - min): " << (maxVal - minVal) << std::endl;

	// Same test again, but filling one at a time via addNumber() instead of
	// addNumbers(), to confirm both filling methods agree on the result.
	Span spOneByOne(N);
	for (unsigned int i = 0; i < N; i++)
		spOneByOne.addNumber(nums[i]);
	std::cout << "one-by-one shortestSpan(): " << spOneByOne.shortestSpan()
			   << " (should match addNumbers() result above)" << std::endl;
	std::cout << "one-by-one longestSpan(): " << spOneByOne.longestSpan()
			   << " (should match addNumbers() result above)" << std::endl;
}

int main()
{
	testSubjectExample();
	testAddNumberPastCapacity();
	testSpanWithZeroOrOneElement();
	testAddRangeBasic();
	testAddRangeFromDifferentContainerType();
	testAddRangeExceedingCapacity();
	testAddRangeFillingRemainingSpaceExactly();
	testCopyAndAssignmentIndependence();
	testLargeSpan();

	std::cout << "\nAll tests completed." << std::endl;
	return 0;
}