#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	HumanB::name = name;
	HumanB::weapon = NULL;
}

void HumanB::setWeapon(Weapon &weapon)
{
	HumanB::weapon = &weapon;
}

void HumanB::attack()
{
	if (this->weapon)
		std::cout << this->name << " attacks with " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " has no weapon so they throw hands instead!" << std::endl;
}