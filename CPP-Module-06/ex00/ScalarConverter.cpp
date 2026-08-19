#include "ScalarConverter.hpp"


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
	return !std::isdigit(c);
}

static bool isInt(const std::string& s, int& out) {
	if (s.empty())
		return false;
	char* end;
	errno = 0;
	long val = std::strtol(s.c_str(), &end, 10);
	if (*end != '\0')
		return false;
	if (errno == ERANGE || val > INT_MAX || val < INT_MIN)
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
	double val = std::strtod(digits.c_str(), &end);
	if (*end != '\0')
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
	int i;
	float f;
	double d;
	if (isChar(literal))
	{
		if (std::isprint(literal[0]))
			std::cout << "char: " << 
	}

}




ScalarConverter::~ScalarConverter(){}