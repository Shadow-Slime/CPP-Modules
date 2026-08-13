#include "AForm.hpp"

const char*  AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char*  AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("Form is not signed!");
}

AForm::AForm(std::string n_name, int n_grade_to_sign, int n_grade_to_exe) : name(n_name), grade_to_sign(n_grade_to_sign), grade_to_exe(n_grade_to_exe), is_signed(false)
{
	if (grade_to_exe < 1 || grade_to_sign < 1)
		throw(GradeTooHighException());
	if (grade_to_exe > 150 || grade_to_sign > 150)
		throw(GradeTooLowException());
}

AForm::AForm(const AForm &other) : name(other.getName()), grade_to_sign(other.getGradetoSign()), grade_to_exe(other.getGradetoExe()), is_signed(false)
{
	
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->is_signed = other.is_It_Signed();
	return *this;
}

AForm::~AForm()
{

}

std::string AForm::getName() const
{
	return (this->name);
}

int AForm::getGradetoSign() const
{
	return (this->grade_to_sign);
}

int AForm::getGradetoExe() const
{
	return (this->grade_to_exe);
}

bool AForm::is_It_Signed() const
{
	return (this->is_signed);
}

void AForm::beSigned(Bureaucrat const &signer)
{
	if (signer.getGrade() > this->getGradetoSign())
		throw(GradeTooLowException());
	else
		this->is_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!is_It_Signed())
		throw(NotSignedException());
	else if (executor.getGrade() > this->getGradetoExe())
		throw(GradeTooLowException());
	else
		executeAction();
}

std::ostream &operator<<(std::ostream &out, const AForm &obj)
{
	out << obj.getName() << ": Grade to sign: " << obj.getGradetoSign() << ", Grade to execute: " << obj.getGradetoExe() << ", ";
	if (obj.is_It_Signed())
		out << "Form is signed.";
	else
		out << "Form is not signed.";
	return out;
}

