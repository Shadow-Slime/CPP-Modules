#ifndef BUREAUCRAT_CPP
#define BUREAUCRAT_CPP

#include <iostream>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
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
		const std::string getName();
		int getGrade();
		void inc_grade();
		void dec_grade();
};



#endif