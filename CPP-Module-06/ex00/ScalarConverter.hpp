#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	public:
		static void convert(std::string literal);
	private:
		ScalarConverter(const ScalarConverter &other) = delete;
		ScalarConverter &operator=(const ScalarConverter &other) = delete;
		~ScalarConverter();
};

#endif