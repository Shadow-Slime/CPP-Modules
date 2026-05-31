#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	ClapTrap::name = "claptrap";
	HitPoints = 10;
	EnergyPoints = 10;
	AttackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	ClapTrap::name = name;
	HitPoints = 10;
	EnergyPoints = 10;
	AttackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->HitPoints = other.HitPoints;
		this->EnergyPoints = this->EnergyPoints;
		this->AttackDamage = this->AttackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->HitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " is destroyed!" << std::endl;
		return;
	}
	if (this->EnergyPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->AttackDamage << " points of damage!" << std::endl;
		this->EnergyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->name << "has no energy left to attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " is destroyed!" << std::endl;
		return;
	}
	if (this->HitPoints > amount)
	{
		std::cout << "ClapTrap " << this->name << " has taken " << amount << " points of damage!" << std::endl;
		this->HitPoints -= amount;
	}
	else
	{
		this->HitPoints = 0;
		std::cout << "ClapTrap " << this->name << " has been destroyed!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->HitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " is destroyed!" << std::endl;
		return;
	}
	if (this->EnergyPoints > 0)
	{
		if (this->HitPoints < 10)
		{
			std::cout << "ClapTrap " << this->name << " repairs itself for " << amount << " points of health!" << std::endl;
			if (this->HitPoints + amount <= 10)
				this->HitPoints += amount;
			else
				this->HitPoints = 10;
			this->EnergyPoints--;
		}
		else
			std::cout << "ClapTrap " << this->name << " is already fully repaired!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->name << "has no energy left to attack!" << std::endl;
}


