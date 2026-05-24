#include "Harl.hpp"

const std::string Harl::levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl(){};

void Harl::debug(void)
{
	std::cout << "I love bacon!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I love cured, dehydrated, and smoked adipose and muscle tissue of the porcine ventral region!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "My bacon is getting stale!" << std::endl;
}

void Harl::error(void)
{
	std::cout << "My cured, dehydrated, and smoked adipose and muscle tissue of the porcine ventral region is rotten!" << std::endl;
}

void Harl::complain(std::string level)
{
	int i;
	for (i = 0; i < 4 && level != levels[i]; i++);
	switch(i)
	{
		case(0):
			std::cout << "[DEBUG]" << std::endl;
			debug();
			/* Falls through */
		case(1):
			std::cout << "[INFO]" << std::endl;
			info();
			/* Falls through */
		case(2):
			std::cout << "[WARNING]" << std::endl;
			warning();
			/* Falls through */
		case(3):
			std::cout << "[ERROR]" << std::endl;
			error();
			break;
		default:
			std::cout << "[Loud pork related grumbling and mumbling]" << std::endl;
	}
}

