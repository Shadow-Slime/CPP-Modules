#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

struct Data
{
	int i;
	std::string str;
	Data(int integer, std::string string);
};

std::ostream &operator<<(std::ostream &out, const Data &obj);

#endif