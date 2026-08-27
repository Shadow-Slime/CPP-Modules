#include <iostream>
#include <string>
#include "Array.hpp"

template <typename T>
static void printArray(const std::string &label, Array<T> &arr)
{
	std::cout << label << " [size=" << arr.size() << "]: ";
	for (unsigned int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i];
		if (i + 1 < arr.size())
			std::cout << ", ";
	}
	std::cout << std::endl;
}

static void testDefaultConstruction()
{
	std::cout << "\n--- Default construction (empty array) ---" << std::endl;
	Array<int> a;
	std::cout << "size(): " << a.size() << std::endl;

	try
	{
		a[0] = 42;
		std::cout << "ERROR: no exception thrown on empty array access" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}
}

static void testSizedConstruction()
{
	std::cout << "\n--- Sized construction (default-initialized elements) ---" << std::endl;

	Array<int> ints(5);
	printArray("ints", ints);
	for (unsigned int i = 0; i < ints.size(); i++)
	{
		if (ints[i] != 0)
			std::cout << "ERROR: expected default-initialized int to be 0" << std::endl;
	}

	Array<float> floats(3);
	printArray("floats", floats);

	Array<std::string> strings(3);
	printArray("strings", strings);
}

static void testCopyAndAssignmentIndependence()
{
	std::cout << "\n--- Copy construction / assignment independence ---" << std::endl;

	Array<int> original(4);
	for (unsigned int i = 0; i < original.size(); i++)
		original[i] = static_cast<int>(i * 10);
	printArray("original (before)", original);

	// Copy construction
	Array<int> copyCtor(original);
	copyCtor[0] = 999;
	printArray("original (after modifying copyCtor)", original);
	printArray("copyCtor (after modifying copyCtor)", copyCtor);
	if (original[0] == copyCtor[0])
		std::cout << "ERROR: copy constructor did not deep copy" << std::endl;
	else
		std::cout << "OK: original untouched by copy constructor mutation" << std::endl;

	// Assignment operator
	Array<int> assigned;
	assigned = original;
	assigned[1] = -1;
	printArray("original (after modifying assigned)", original);
	printArray("assigned (after modifying assigned)", assigned);
	if (original[1] == assigned[1])
		std::cout << "ERROR: assignment operator did not deep copy" << std::endl;
	else
		std::cout << "OK: original untouched by assigned mutation" << std::endl;

	// Self-assignment should not break anything.
	// Indirected through a pointer so the compiler can't statically detect
	// (and warn/error on) a literal "x = x" self-assignment; this still
	// genuinely exercises operator=() with this == &other at runtime.
	Array<int> *selfPtr = &assigned;
	assigned = *selfPtr;
	printArray("assigned (after self-assignment)", assigned);

	// Assigning a different-sized array should resize correctly
	Array<int> other(2);
	other[0] = 1;
	other[1] = 2;
	assigned = other;
	printArray("assigned (after assigning smaller array)", assigned);
}

static void testOutOfBoundsAccess()
{
	std::cout << "\n--- Out-of-bounds access ---" << std::endl;

	Array<int> arr(3);
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	printArray("arr", arr);

	try
	{
		std::cout << arr[3] << std::endl;
		std::cout << "ERROR: no exception thrown for index == size()" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught expected exception at index 3: " << e.what() << std::endl;
	}

	try
	{
		std::cout << arr[100] << std::endl;
		std::cout << "ERROR: no exception thrown for far out-of-bounds index" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught expected exception at index 100: " << e.what() << std::endl;
	}
}

static void testSizeConstCorrectness()
{
	std::cout << "\n--- size() const-correctness ---" << std::endl;

	const Array<int> arr(6);
	// This line only compiles if size() is properly marked const.
	std::cout << "const arr.size(): " << arr.size() << std::endl;
}

int main()
{
	testDefaultConstruction();
	testSizedConstruction();
	testCopyAndAssignmentIndependence();
	testOutOfBoundsAccess();
	testSizeConstCorrectness();

	std::cout << "\nAll tests completed." << std::endl;
	return 0;
}