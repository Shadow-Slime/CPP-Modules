#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
int main()
{
	{
		Bureaucrat a("Bill", 75);
		Bureaucrat b("Jill", 150);
		Bureaucrat c("Kill", 1);

		PresidentialPardonForm Form("Hillbilly");

		a.executeForm(Form);
		b.signForm(Form);
		c.signForm(Form);
		std::cout << Form << std::endl;
		a.executeForm(Form);
		b.executeForm(Form);
		c.executeForm(Form);
	}
	std::cout << "\n\n\n" << std::endl;
	{
		Bureaucrat a("Bill", 75);
		Bureaucrat b("Jill", 150);
		Bureaucrat c("Kill", 1);

		std::srand(time(NULL));
		RobotomyRequestForm Form("Hillbilly");

		a.executeForm(Form);
		b.signForm(Form);
		c.signForm(Form);
		std::cout << Form << std::endl;
		a.executeForm(Form);
		b.executeForm(Form);
		c.executeForm(Form);
	}
}