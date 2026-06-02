#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	name = "scavtrap";
	HitPoints = MaxHP = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	GuardMode = false;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	ScavTrap::name = name;
	HitPoints = MaxHP = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	GuardMode = false;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->HitPoints = other.HitPoints;
		this->EnergyPoints = other.EnergyPoints;
		this->AttackDamage = other.AttackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->HitPoints == 0)
	{
		std::cout << "ScavTrap " << this->name << " is destroyed!" << std::endl;
		return;
	}
	if (this->EnergyPoints > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->AttackDamage << " points of damage!" << std::endl;
		this->EnergyPoints--;
	}
	else
		std::cout << "ScavTrap " << this->name << "has no energy left to attack!" << std::endl;
}

void ScavTrap::guardGate()
{
	if (this->GuardMode == false)
		std::cout << "ScavTrap " << this->name << " is now in gatekeeper mode!" << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " is no longer in gatekeeper mode!" << std::endl;
	this->GuardMode = !this->GuardMode;
}