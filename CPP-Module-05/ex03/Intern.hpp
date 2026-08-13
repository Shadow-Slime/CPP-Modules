#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyRequestForm.hpp"

class Intern
{
	private:

	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();
		AForm *makeForm(std::string form_name, std::string target);
		class NonExistentFormException : public std::exception
		{
			const char* what() const throw();
		};
};

#endif