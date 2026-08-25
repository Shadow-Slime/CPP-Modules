#include <iostream>
#include "iter.hpp"

void printInt(const int &n)
{
	std::cout << n << " ";
}
void doubleInt(int &n) 
{
	n *= 2; 
}

void nextChar(char &c) 
{
	c++;
}

void printChar(const char &c)
{
	std::cout << c << " ";
}


int main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	char arr2[] = {'a', 'b', 'c', 'd'};
	::iter(arr, 5, printInt);
	std::cout << std::endl;
	::iter(arr, 5, doubleInt);
	::iter(arr, 5, printInt);
	std::cout << std::endl;
	::iter(arr2, 4, printChar);
	std::cout << std::endl;
	::iter(arr2, 4, nextChar);
	::iter(arr2, 4, printChar);
	std::cout << std::endl;
}