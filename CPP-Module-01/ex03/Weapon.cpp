#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	Weapon::type = type;
}

const std::string& Weapon::getType()
{
	return (this->type);
}

void Weapon::setType(std::string new_type)
{
	this->type = new_type;
}