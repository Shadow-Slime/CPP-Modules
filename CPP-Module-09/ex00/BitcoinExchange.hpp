#ifndef BITCOINTEXCHANGE_HPP
#define BITCOINTEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();
		int Openfile(const char *filename);
		void Closefile(void);
		std::fstream input;
	private:
		std::map<int, float> data;
		
};


#endif
