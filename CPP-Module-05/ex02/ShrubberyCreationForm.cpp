#include "ShrubberyCreationForm.hpp"

const char* ShrubberyCreationForm::FileErrorException::what() const throw()
{
	return ("Error upon opening the file");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string new_target) : AForm("ShrubberyCreationForm", 145, 137), target(new_target)
{
	//std::cerr << "[DEBUG] target = \"" << target << "\" (length " << target.length() << ")" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other.getName(), 145, 137), target(other.target)
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		this->target = other.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::executeAction() const
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