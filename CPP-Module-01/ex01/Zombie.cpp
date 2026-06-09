#include "Zombie.hpp"

Zombie::Zombie() : name("default")
{
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
	Zombie::name = name;
}

Zombie::~Zombie()
{
	std::cout << name << " has been destroyed" << std::endl;
}

void Zombie::set_name(std::string name)
{
	this->name = name;
}