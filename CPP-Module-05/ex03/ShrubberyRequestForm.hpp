#ifndef SHRUBBERYREQUESTFORM_HPP
#define SHRUBBERYREQUESTFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyRequestForm : public AForm
{
	private:
		std::string target;
	public:
		class FileErrorException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		ShrubberyRequestForm(std::string new_target);
		ShrubberyRequestForm(const ShrubberyRequestForm &other);
		ShrubberyRequestForm &operator=(const ShrubberyRequestForm &other);
		~ShrubberyRequestForm();
		void executeAction() const;
};

#endif