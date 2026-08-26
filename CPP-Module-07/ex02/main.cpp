#include "Array.hpp"

int main(void)
{
	Array<int> intArray;
	try
	{
		std::cout << intArray[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}