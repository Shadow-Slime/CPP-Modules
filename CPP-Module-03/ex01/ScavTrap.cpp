#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->name = "scavtrap";
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->name = name;
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other)
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
		this->EnergyPoints = this->EnergyPoints;
		this->AttackDamage = this->AttackDamage;
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

void ScavTrap::takeDamage(unsigned int amount)
{
	if (this->HitPoints == 0)
	{
		std::cout << "ScavTrap " << this->name << " is destroyed!" << std::endl;
		return;
	}
	if (this->HitPoints > amount)
	{
		std::cout << "ScavTrap " << this->name << " has taken " << amount << " points of damage!" << std::endl;
		this->HitPoints -= amount;
	}
	else
	{
		this->HitPoints = 0;
		std::cout << "ScavTrap " << this->name << " has been destroyed!" << std::endl;
	}
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->HitPoints == 0)
	{
		std::cout << "ScavTrap " << this->name << " is destroyed!" << std::endl;
		return;
	}
	if (this->EnergyPoints > 0)
	{
		if (this->HitPoints < 10)
		{
			std::cout << "ScavTrap " << this->name << " repairs itself for " << amount << " points of health!" << std::endl;
			if (this->HitPoints + amount <= 10)
				this->HitPoints += amount;
			else
				this->HitPoints = 10;
			this->EnergyPoints--;
		}
		else
			std::cout << "ScavTrap " << this->name << " is already fully repaired!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->name << "has no energy left to attack!" << std::endl;
}

void ScavTrap::guardGate()
{
	
}