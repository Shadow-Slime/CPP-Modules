#ifndef FORM_CPP
#define FORM_CPP

#include <iostream>

class Form
{
	private:
		const int grade_to_sign;
		const int grade_to_exe;
		bool is_signed;
	public:
		Form(int n_grade_to_sign, int n_grade_to_exe);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();
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
		int getGradetoSign() const;
		int getGradetoExe() const;
		void beSigned();
};

std::ostream &operator<<(std::ostream &out, const Form &obj);

#endif