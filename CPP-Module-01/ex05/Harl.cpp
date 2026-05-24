#include "Harl.hpp"

const std::string Harl::levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl()
{
	funcs[0] = &Harl::debug;
	funcs[1] = &Harl::info;
	funcs[2] = &Harl::warning;
	funcs[3] = &Harl::error;
}

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
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*funcs[i])();
			return ;
		}
	}
	std::cerr << "Non existent complaint level" << std::endl;
}

