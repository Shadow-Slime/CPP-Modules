#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	btc.CreateDatamap();
	return 0;
}