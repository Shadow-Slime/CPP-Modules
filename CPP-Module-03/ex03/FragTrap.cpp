#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	name = "fragtrap";
	HitPoints = MaxHP = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	FragTrap::name = name;
	HitPoints = MaxHP = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->HitPoints = other.HitPoints;
		this->EnergyPoints = other.EnergyPoints;
		this->AttackDamage = other.AttackDamage;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (this->HitPoints == 0)
	{
		std::cout << "FragTrap " << this->name << " is destroyed!" << std::endl;
		return;
	}
	if (this->EnergyPoints > 0)
	{
		std::cout << "FragTrap " << this->name << " attacks " << target << " causing " << this->AttackDamage << " points of damage!" << std::endl;
		this->EnergyPoints--;
	}
	else
		std::cout << "FragTrap " << this->name << "has no energy left to attack!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->HitPoints > 0)
		std::cout << "FragTrap " << this->name << " is requesting high fives!" << std::endl;
	else
		std::cout << "FragTrap " << this->name << " can't high five anyone cus he's dead!" << std::endl;
}