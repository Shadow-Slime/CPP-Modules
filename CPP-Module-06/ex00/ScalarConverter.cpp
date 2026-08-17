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

void ScalarConverter::convert(std::string literal)
{
	if (literal == "nan" || literal == "nanf" || literal == "-inf" || literal == "+inf" || literal == "+inff" || literal == "-inff")
		return (print_pseudo_literal(literal));
	char c;
	int i;
	
}




ScalarConverter::~ScalarConverter(){}