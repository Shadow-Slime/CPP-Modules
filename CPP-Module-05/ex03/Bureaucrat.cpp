#include "Bureaucrat.hpp"


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high! Max: 1");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low! Min: 150");
}

Bureaucrat::Bureaucrat(std::string n_name, int n_grade) : name(n_name)
{
	try
	{
		if (n_grade < 1)
			throw GradeTooHighException();
		if (n_grade > 150)
			throw GradeTooLowException();
		grade = n_grade;
	}
	catch(const GradeTooHighException& h)
	{
		std::cout << h.what() << std::endl;
		grade = 1;
	}
	catch(const GradeTooLowException& l)
	{
		std::cout << l.what() << std::endl;
		grade = 150;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
	*this = other;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::inc_grade()
{
	try
	{
		if (grade == 1)
			throw GradeTooHighException();
		grade--;
	}
	catch(const GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}
void Bureaucrat::dec_grade()
{
	try
	{
		if (grade == 150)
			throw GradeTooLowException();
		grade++;
	}
	catch(const GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return out;
}

void Bureaucrat::signForm(AForm &obj)
{
	try
	{
		obj.beSigned(*this);
		std::cout << this->getName() << " signed " << obj.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign " << obj.getName()  << " because their grade is too low!" << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}