#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):weapon(weapon)
{
	HumanA::name = name;
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with " << this->weapon.getType() << std::endl;
}