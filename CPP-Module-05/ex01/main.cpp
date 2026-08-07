#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
	{
		Bureaucrat Average("Normal", 75);
		Bureaucrat TooHigh("High", -1);
		Bureaucrat TooLow("Low", 175);

		std::cout << Average << std::endl;
		std::cout << TooHigh << std::endl;
		std::cout << TooLow << std::endl;

		TooHigh.inc_grade();
		TooLow.dec_grade();
		Average.inc_grade();

		std::cout << Average << std::endl;
		std::cout << TooHigh << std::endl;
		std::cout << TooLow << std::endl;
		std::cout << "\n\n\n" << std::endl;
	}
	{
		Bureaucrat Average("Normal", 75);
		Bureaucrat High("High", 1);
		Bureaucrat Low("Low", 150);

		Form Lower("Lower", 125, 100);
		Form Higher("Higher", 25, 10);
		try
		{
			Form TooHigh("Too High", -1, 25);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Form TooLow("Too Low", 150, 175);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << Lower << std::endl;
		std::cout << Higher << std::endl;
		Low.signForm(Lower);
		Average.signForm(Lower);
		std::cout << Lower << std::endl;
		Average.signForm(Higher);
		High.signForm(Higher);
		std::cout << Higher << std::endl;
	}
	
}