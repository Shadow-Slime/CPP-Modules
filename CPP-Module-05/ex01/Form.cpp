#include "Form.hpp"

const char*  Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char*  Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

Form::Form(std::string n_name, int n_grade_to_sign, int n_grade_to_exe) : name(n_name), grade_to_sign(n_grade_to_sign), grade_to_exe(n_grade_to_exe), is_signed(false)
{
	if (grade_to_exe < 1 || grade_to_sign < 1)
		throw(GradeTooHighException());
	if (grade_to_exe > 150 || grade_to_sign > 150)
		throw(GradeTooLowException());
}

Form::Form(const Form &other) : name(other.getName()), grade_to_sign(other.getGradetoSign()), grade_to_exe(other.getGradetoExe()), is_signed(false)
{
	
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->is_signed = other.is_It_Signed();
	return *this;
}

Form::~Form()
{

}

std::string Form::getName() const
{
	return (this->name);
}

int Form::getGradetoSign() const
{
	return (this->grade_to_sign);
}

int Form::getGradetoExe() const
{
	return (this->grade_to_exe);
}

bool Form::is_It_Signed() const
{
	return (this->is_signed);
}

void Form::beSigned()
{
	if (!this->is_It_Signed())
		this->is_signed = true;
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
	out << obj.getName() << ": Grade to sign: " << obj.getGradetoSign() << ", Grade to execute: " << obj.getGradetoExe() << ", ";
	if (obj.is_It_Signed())
		out << "Form is signed.";
	else
		out << "Form is not signed.";
	return out;
}

