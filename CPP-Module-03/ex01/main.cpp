#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap original("Claptrap P. Claptrappington");
	ClapTrap clone = original;
	original.beRepaired(10);
	original.attack("your shins");
	std::cout << "Your shins fight back!" << std::endl;
	original.takeDamage(5);
	original.beRepaired(2);
	original.takeDamage(7);
	original.attack("your shins");
	original.beRepaired(10);
	std::cout << "------------------------------------ScavTrap------------------------------------" << std::endl;
	ScavTrap gateguard("SC4V-TP");
	gateguard.beRepaired(10);
	gateguard.guardGate();
	gateguard.attack("raider");
	std::cout << "The raider fights back!" << std::endl;
	gateguard.takeDamage(90);
	gateguard.attack("raider");
	for (int i = 0; i < 50; i++)
	{
		gateguard.beRepaired(1);
	}
	gateguard.beRepaired(1);
	
}