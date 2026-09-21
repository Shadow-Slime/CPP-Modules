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

//PARSING

static std::string strtrim(std::string const& s)
{
	std::string::size_type start = s.find_first_not_of(" \t\r\n");
	if (start == std::string::npos) {
		return ("");
	}
	std::string::size_type end = s.find_last_not_of(" \t\r\n");
	return (s.substr(start, end - start + 1));
}

static bool isLeapYear(int year)
{
	if (year % 4 != 0)
		return false;
	if (year % 100 != 0)
		return true;
	return (year % 400 == 0);
}

static bool validate_date(std::string date)
{
	std::istringstream iss(date);
	int year, month, day;
	char dash1, dash2;

	if (!(iss >> year >> dash1 >> month >> dash2 >> day) || (dash1 != '-' || dash2 != '-') || !iss.eof())
		return false;
	if (year < 0 || year > 9999)
		return false;
	if (month < 1 || month > 12)
		return false;
	static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day < 0 || (month == 2 && isLeapYear(year) && day > 29) || day > days[month - 1])
		return false;
	return true;
}

static bool validate_value(std::string valuestr, float &value)
{
	std::istringstream iss(valuestr);
	if (!(iss >> value) || !iss.eof())
		return false;
	return true;
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
	std::string valuestr;
	float value;
	std::string::size_type sep;
	while (std::getline(file, buffer))
	{
		sep = buffer.find(',');
		if (sep == std::string::npos)
		{
			return 0; //possibly replaced with exception
		}
		date = strtrim(buffer.substr(0, sep));
		valuestr = strtrim(buffer.substr(sep + 1));
		if (!validate_date(date))
		{
			std::cout << "Failed with: " << date << std::endl;
			return 0; //possibly replaced with exception
		}
		if (!validate_value(valuestr, value))
		{
			std::cout << "Failed with: " << valuestr << std::endl;
			return 0;
		}
		data.insert(std::make_pair(date, value));
	}
	return 1;
}