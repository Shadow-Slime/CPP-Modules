#include <iostream>
#include <sstream>
#include <stack>
#include <list>
#include "MutantStack.hpp"

static void runMutantStackSequence(std::ostringstream &out)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	out << "Last value inserted:" << mstack.top() << std::endl;
	mstack.pop();
	out << "Container size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	out << "Full Container contents as printed by iterator" << std::endl;
	while (it != ite)
	{
		out << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
	out << s.size() << std::endl;
}

static void runListSequence(std::ostringstream &out)
{
	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	out << "Last value inserted:" << list.back() << std::endl;
	list.pop_back();
	out << "Container size: " << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();
	++it;
	--it;
	out << "Full Container contents as printed by iterator" << std::endl;
	while (it != ite)
	{
		out << *it << std::endl;
		++it;
	}

	std::list<int> l(list);
	out << l.size() << std::endl;
}

static void testOutputsMatch()
{
	std::cout << "--- Comparing MutantStack<int> output against std::list<int> ---" << std::endl;

	std::ostringstream mutantOut;
	std::ostringstream listOut;

	runMutantStackSequence(mutantOut);
	runListSequence(listOut);

	std::cout << "MutantStack output:" << std::endl << mutantOut.str();
	std::cout << "std::list output:" << std::endl << listOut.str();

	if (mutantOut.str() == listOut.str())
		std::cout << "OK: outputs are identical" << std::endl;
	else
		std::cout << "ERROR: outputs differ" << std::endl;
}

static void testEmptyStackIteration()
{
	std::cout << "\n--- Iterating an empty MutantStack ---" << std::endl;

	MutantStack<int> mstack;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	if (it == ite)
		std::cout << "OK: begin() == end() on an empty stack" << std::endl;
	else
		std::cout << "ERROR: begin() != end() on an empty stack" << std::endl;
}

static void testMutationThroughIterator()
{
	std::cout << "\n--- Mutating elements through an iterator ---" << std::endl;

	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);

	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		*it *= 10;

	std::cout << "top() after mutation: " << mstack.top()
			   << " (expected 30)" << std::endl;

	int sum = 0;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		sum += *it;
	std::cout << "sum after mutation: " << sum << " (expected 60)" << std::endl;
}

static void testOrthodoxCanonicalForm()
{
	std::cout << "\n--- Orthodox Canonical Form ---" << std::endl;

	// Default construction
	MutantStack<int> a;
	a.push(1);
	a.push(2);
	a.push(3);

	// Copy construction
	MutantStack<int> b(a);
	std::cout << "b.size() after copy construction: " << b.size()
			   << " (expected 3)" << std::endl;

	// Independence after copy construction
	b.push(4);
	std::cout << "a.size() after modifying b: " << a.size()
			   << " (expected 3, unaffected)" << std::endl;
	std::cout << "b.size() after modifying b: " << b.size()
			   << " (expected 4)" << std::endl;

	// Assignment operator
	MutantStack<int> c;
	c = a;
	std::cout << "c.size() after assignment: " << c.size()
			   << " (expected 3)" << std::endl;

	// Independence after assignment
	c.push(99);
	std::cout << "a.size() after modifying c: " << a.size()
			   << " (expected 3, unaffected)" << std::endl;
	std::cout << "c.size() after modifying c: " << c.size()
			   << " (expected 4)" << std::endl;

	// Self-assignment, indirected through a pointer so the compiler doesn't
	// statically flag a literal "x = x" as a warning/error.
	MutantStack<int> *selfPtr = &c;
	c = *selfPtr;
	std::cout << "c.size() after self-assignment: " << c.size()
			   << " (expected 4, unchanged)" << std::endl;

	// Destructor: nothing to assert directly here, but running this whole
	// function under valgrind with no leaks/errors is the real test.
}

int main()
{
	testOutputsMatch();
	testEmptyStackIteration();
	testMutationThroughIterator();
	testOrthodoxCanonicalForm();

	std::cout << "\nAll tests completed." << std::endl;
	return 0;
}