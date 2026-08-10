#include "ShrubberyRequestForm.hpp"

ShrubberyRequestForm::ShrubberyRequestForm(std::string new_target) : AForm("ShrubberyRequestForm", 145, 137), target(new_target)
{

}

ShrubberyRequestForm::ShrubberyRequestForm(const ShrubberyRequestForm &other) : AForm(other.getName(), 145, 137), target(other.target)
{

}

ShrubberyRequestForm &ShrubberyRequestForm::operator=(const ShrubberyRequestForm &other)
{
	if (this != &other)
		this->target = other.target;
	return *this;
}

ShrubberyRequestForm::~ShrubberyRequestForm()
{}

void ShrubberyRequestForm::executeAction() const
{
	std::cout << "*DRILLING NOISES*" << std::endl;
	if (std::rand() % 2)
		std::cout << this->target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed!" << std::endl;

}