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
		int openFile(const char *filename);
		void closeFile(void);
		int createDatamap(void);
		int processInput(const char *filename);
		std::fstream file;
	private:
		std::map<std::string, float> data;
		
};


#endif
