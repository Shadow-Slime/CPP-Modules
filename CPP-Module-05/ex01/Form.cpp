#include "Form.hpp"

const char*  Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high! Max: 1");
}

const char*  Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low! Min: 150");
}

Form::Form(int n_grade_to_sign, int n_grade_to_exe) : grade_to_sign(n_grade_to_sign), grade_to_exe(n_grade_to_exe), is_signed(false)
{
	try
	{
		if (grade_to_exe < 1 || grade_to_exe < 1)
			throw(GradeTooHighException());
		if (grade_to_exe > 150 || grade_to_exe > 150)
			throw(GradeTooLowException());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}