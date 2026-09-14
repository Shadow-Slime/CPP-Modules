#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	btc.Openfile(argv[1]);
	std::string str;
	std::getline(btc.input, str);
	std::cout << str << std::endl;
	return 0;
}