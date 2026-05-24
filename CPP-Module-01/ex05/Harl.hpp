#include <iostream>

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		void (Harl::*funcs[4])(void);
		const static std::string levels[4];
	public:
		void complain(std::string level);
		Harl();
};