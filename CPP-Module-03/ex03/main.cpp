#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	{
	std::cout << "------------------------------------ClapTrap------------------------------------" << std::endl;
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
	}
	{
	std::cout << "------------------------------------ScavTrap------------------------------------" << std::endl;
	ScavTrap gateguard("SC4V-TP");
	gateguard.beRepaired(10);
	gateguard.guardGate();
	gateguard.attack("raider");
	std::cout << "The raider fights back!" << std::endl;
	gateguard.takeDamage(90);
	gateguard.attack("raider");
	gateguard.beRepaired(1);
	}
	{
	std::cout << "------------------------------------FragTrap------------------------------------" << std::endl;
	FragTrap boomtrap("R4MB0-TP");
	boomtrap.beRepaired(10);
	boomtrap.highFivesGuys();
	boomtrap.attack("innocent bystander");
	std::cout << "The innocent bystander deflects the explosive back!" << std::endl;
	boomtrap.takeDamage(100);
	boomtrap.highFivesGuys();
	}
	{
	std::cout << "------------------------------------DiamondTrap---------------------------------" << std::endl;
	DiamondTrap blingbling("G3M-TP");
	blingbling.beRepaired(10);
	blingbling.highFivesGuys();
	blingbling.guardGate();
	blingbling.guardGate();
	blingbling.attack("An inferior gem");
	}
	
}