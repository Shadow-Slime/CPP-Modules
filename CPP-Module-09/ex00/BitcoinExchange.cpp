#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->data = other.data;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{

}

int BitcoinExchange::Openfile(const char *filename)
{
	input.open(filename, std::ios::in);
	if (!input)
		return 0;
	return 1;
}

void BitcoinExchange::Closefile(void)
{
	input.close();
}
