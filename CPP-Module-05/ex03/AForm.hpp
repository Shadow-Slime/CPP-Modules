#ifndef AFORM_CPP
#define AFORM_CPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		const int grade_to_sign;
		const int grade_to_exe;
		bool is_signed;
	public:
		AForm(std::string n_name, int n_grade_to_sign, int n_grade_to_exe);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();
		class GradeTooHighException : public std::exception 
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception 
		{
			public:
				const char* what() const throw();
		};
		class NotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		std::string getName() const;
		int getGradetoSign() const;
		int getGradetoExe() const;
		bool is_It_Signed() const;
		void beSigned(Bureaucrat const &signer);
		void execute(Bureaucrat const &executor) const;
		virtual void executeAction() const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &obj);

#endif