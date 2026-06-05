#include "Bird.hpp"

Bird::Bird() : Animal("Bird")
{
	std::cout << "Bird default constructor called" << std::endl;
}

Bird::Bird(const Bird &other) : Animal(other.type)
{
	std::cout << "Bird copy constructor called" << std::endl;
	*this = other;
}

Bird &Bird::operator=(const Bird &other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

Bird::~Bird()
{
	std::cout << "Bird destructor called" << std::endl;
}

void Bird::makeSound() const
{
	std::cout << "Chirp" << std::endl;
}