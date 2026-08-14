#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyRequestForm.hpp"
#include "Intern.hpp"
int main()
{
	{
		Bureaucrat a("Bill", 75);
		Bureaucrat b("Jill", 150);
		Bureaucrat c("Kill", 1);
		Intern Jerry;

		AForm *form1 = Jerry.makeForm("presidential pardon request", "Bob");
		AForm *form2 = Jerry.makeForm("robotomy request", "Bender");
		AForm *form3 = Jerry.makeForm("shrubbery request", "Aplace");
		AForm *form4 = Jerry.makeForm("some request", "A time");


		std::cout << "\n\n" << std::endl;
		a.executeForm(*form1);
		b.signForm(*form1);
		c.signForm(*form1);
		std::cout <<*form1 << std::endl;
		a.executeForm(*form1);
		b.executeForm(*form1);
		c.executeForm(*form1);
		std::cout << "\n\n" << std::endl;
		a.executeForm(*form2);
		b.signForm(*form2);
		c.signForm(*form2);
		std::cout << *form2 << std::endl;
		a.executeForm(*form2);
		b.executeForm(*form2);
		c.executeForm(*form2);
		std::cout << "\n\n" << std::endl;
		a.executeForm(*form3);
		b.signForm(*form3);
		c.signForm(*form3);
		std::cout << *form3 << std::endl;
		a.executeForm(*form3);
		b.executeForm(*form3);
		c.executeForm(*form3);

		delete form1;
		delete form2;
		delete form3;
		delete form4;
	}

}