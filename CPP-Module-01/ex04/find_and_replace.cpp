#include "header.hpp"

void find_and_replace(std::fstream &file, std::fstream &newfile, std::string to_find, std::string to_replace)
{
	std::string str;
	unsigned long substr_pos;
	while (getline(file, str))
	{
		do {
			substr_pos = str.find(to_find, 0);
			if(substr_pos == std::string::npos)
				break;
			str.erase(substr_pos, to_find.length());
			str.insert(substr_pos, to_replace);
		} while (substr_pos != std::string::npos);
		newfile << str << "\n";
	}
}