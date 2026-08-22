#include "Data.hpp"

Data::Data(int integer, std::string string)
{
	i = integer;
	str = string;
}

std::ostream &operator<<(std::ostream &out, const Data &obj)
{
	out << "Integer: " << obj.i << "\nString: " << obj.str;
	return out;
}