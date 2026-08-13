#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	return *this;
}

Intern::~Intern()
{

}

const char* Intern::NonExistentFormException::what() const throw()
{
	return ("Form does not exist!");
}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
	std::string names[3] = {"presidential pardon request", "robotomy request", "shrubbery request"};
	AForm *form = NULL;
	int i;
	for (i = 0; i < 3; i++)
		if (form_name == names[i])
			break ;
	try
	{
		switch (i)
		{
			case 0:
				form = new PresidentialPardonForm(target);
				break;
			case 1:
				form = new RobotomyRequestForm(target);
				break;
			case 2:
				form = new ShrubberyRequestForm(target);
				break;
			default:
				throw(NonExistentFormException());
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return form;
}
