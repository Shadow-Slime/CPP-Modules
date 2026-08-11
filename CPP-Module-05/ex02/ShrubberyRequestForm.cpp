#include "ShrubberyRequestForm.hpp"

const char* ShrubberyRequestForm::FileErrorException::what() const throw()
{
	return ("Error upon opening the file");
}

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
	std::string name = target + "_shrubbery";
	std::fstream file;
	file.open(name.c_str(), std::ios::out);
	if (!file)
		throw(FileErrorException());
	file << "               ,@@@@@@@,\n";
	file << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
	file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
	file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
	file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
	file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
	file << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
	file << "       |o|        | |         | |\n";
	file << "       |.|        | |         | |\n";
	file << "   \\\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	file.close();
}