#ifndef FORM_CPP
#define FORM_CPP

#include <iostream>

class Form
{
	private:
		const std::string name;
		const int grade_to_sign;
		const int grade_to_exe;
		bool is_signed;
	public:
		Form(std::string n_name, int n_grade_to_sign, int n_grade_to_exe);
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
		std::string getName() const;
		int getGradetoSign() const;
		int getGradetoExe() const;
		bool is_It_Signed() const;
		void beSigned();
};

std::ostream &operator<<(std::ostream &out, const Form &obj);

#endif