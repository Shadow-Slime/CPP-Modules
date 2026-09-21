#ifndef BITCOINTEXCHANGE_HPP
#define BITCOINTEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib>
#include <sstream>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();
		int Openfile(const char *filename);
		void Closefile(void);
		int CreateDatamap(void);
		std::fstream file;
	private:
		std::map<std::string, float> data;
		
};


#endif
