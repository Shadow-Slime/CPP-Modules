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
	file.open(filename, std::ios::in);
	if (!file)
		return 0;
	return 1;
}

void BitcoinExchange::Closefile(void)
{
	file.close();
}

int BitcoinExchange::CreateDatamap(void)
{
	if (!Openfile("data.csv"))
		return 0;			//possibly replaced with exception
	
	std::string buffer;
	std::getline(file, buffer);
	if (buffer != "date,exchange_rate")
	{
		Closefile();
		return 0;
	}
	std::string date;
	float value;
	char *end;
	while (std::getline(file, buffer))
	{
		date = buffer.substr(0, 10);
		value = strtod(buffer.substr(11, buffer.length()).c_str(), &end);
		data[date] = value;
	}
	std::cout << data.at("2010-11-20") << std::endl; // 0.29
	return 0;
}