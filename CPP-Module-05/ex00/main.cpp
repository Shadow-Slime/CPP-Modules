#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat Average("Normal", 75);
	Bureaucrat TooHigh("High", -1);
	Bureaucrat TooLow("Low", 175);

	std::cout << Average << std::endl;
	std::cout << TooHigh << std::endl;
	std::cout << TooLow << std::endl;

	TooHigh.inc_grade();
	Average.inc_grade();
	TooLow.dec_grade();

	std::cout << Average << std::endl;
	std::cout << TooHigh << std::endl;
	std::cout << TooLow << std::endl;

	Average.dec_grade();
	std::cout << Average << std::endl;
}