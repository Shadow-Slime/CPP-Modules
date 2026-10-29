#include "ScalarConverter.hpp"


static void printFloat(float f)
{
	std::ios_base::fmtflags flags = std::cout.flags();
	std::streamsize prec = std::cout.precision();
	if (f == std::floor(f))
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout.flags(flags);
	std::cout.precision(prec);
}

static void printDouble(double d)
{
	std::ios_base::fmtflags flags = std::cout.flags();
	std::streamsize prec = std::cout.precision();
	if (d == std::floor(d))
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: " << d << std::endl;
	std::cout.flags(flags);
	std::cout.precision(prec);
}

static void print_pseudo_literal(std::string ps_lit)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (ps_lit == "nan" || ps_lit == "-inf" || ps_lit == "+inf")
	{
		std::cout << "float: " << ps_lit + "f" << std::endl;
		std::cout << "double: " << ps_lit << std::endl;
	}
	else
	{
		std::cout << "float: " << ps_lit << std::endl;
		std::cout << "double: " << ps_lit.substr(0, ps_lit.size()-1) << std::endl;
	}
}

static bool isChar(const std::string& s) 
{
	if (s.size() != 1)
		return false;
	unsigned char c = static_cast<unsigned char>(s[0]);
	return (c <= 127 && !std::isdigit(c));
}

static bool isInt(const std::string& s, int& out) {
	if (s.empty())
		return false;
	char* end;
	errno = 0;
	long val = std::strtol(s.c_str(), &end, 10);
	if (*end != '\0')
		return false;
	if (errno == ERANGE || val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
		return false;
	out = static_cast<int>(val);
	return true;
}

static bool isFloat(const std::string& s, float& out) {
	if (s.empty() || s[s.size() - 1] != 'f')
		return false;
	std::string digits = s.substr(0, s.size() - 1);
	if (digits.empty())
		return false;
	char* end;
	errno = 0;
	double val = std::strtod(digits.c_str(), &end);
	if (*end != '\0')
		return false;
	if (errno == ERANGE || val > std::numeric_limits<float>::max() || val < -(std::numeric_limits<float>::max()))
		return false;
	out = static_cast<float>(val);
	return true;
}

static bool isDouble(const std::string& s, double& out) {
	if (s.empty())
		return false;
	char* end;
	double val = std::strtod(s.c_str(), &end);
	if (*end != '\0')
		return false;
	out = val;
	return true;
}

void ScalarConverter::convert(std::string literal)
{
	if (literal == "nan" || literal == "nanf" || literal == "-inf" || literal == "+inf" || literal == "+inff" || literal == "-inff")
		return (print_pseudo_literal(literal));
	char c = literal[0];
	int i;
	float f;
	double d;
	bool is_char = isChar(literal);
	bool is_int = isInt(literal, i);
	bool is_float = isFloat(literal, f);
	bool is_double = isDouble(literal, d);
	if (is_char)
	{
		if (std::isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		printFloat(static_cast<float>(c));
		printDouble(static_cast<double>(c));
		return ;
	}
	if (is_int)
	{
		if (i >= 0 && i <= 127)
		{
			c = static_cast<char>(i);
			if (std::isprint(c))
				std::cout << "char: '" << c << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << i << std::endl;
		printFloat(static_cast<float>(i));
		printDouble(static_cast<double>(i));
		return ;
	}
	if (is_float)
	{
		if ((roundf(f) == f) && (f >= 0 && f <= 127))
		{
			c = static_cast<char>(f);
			if (std::isprint(c))
				std::cout << "char: '" << c << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;
		if (f > std::numeric_limits<int>::min() && f < std::numeric_limits<int>::max())
			std::cout << "int: " << static_cast<int>(f) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		printFloat(f);
		printDouble(static_cast<double>(f));
		return ;
	}
	if (is_double)
	{
		if ((roundf(d) == d) && (d >= 0 && d <= 127))
		{
			c = static_cast<char>(d);
			if (std::isprint(c))
				std::cout << "char: '" << c << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;
		if (d > std::numeric_limits<int>::min() && d < std::numeric_limits<int>::max())
			std::cout << "int: " << static_cast<int>(d) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		if (d > -(std::numeric_limits<float>::max()) && d < std::numeric_limits<float>::max())
			printFloat(static_cast<float>(d));
		else
			std::cout << "float: impossible" << std::endl;
		printDouble(d);
		return ;
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter(){}