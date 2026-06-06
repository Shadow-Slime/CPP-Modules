#include "A_Animal.hpp"

A_Animal::A_Animal() : type("animal")
{
	std::cout << "A_Animal default constructor called" << std::endl;
}

A_Animal::A_Animal(std::string type) : type(type)
{
	std::cout << "A_Animal constructor called" << std::endl;
}

A_Animal::A_Animal(const A_Animal &other)
{
	std::cout << "A_Animal copy constructor called" << std::endl;
	*this = other;
}

A_Animal &A_Animal::operator=(const A_Animal &other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

A_Animal::~A_Animal()
{
	std::cout << "A_Animal destructor called" << std::endl;
}

std::string A_Animal::getType() const
{
	return (this->type);
}