#include "ClapTrap.hpp"

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
}