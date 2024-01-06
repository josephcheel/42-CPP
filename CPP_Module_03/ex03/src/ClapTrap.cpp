#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	_HitPoints = 10;
	_EnergyPoints = 10;
	_AttackDamage = 0;
	_MaxHitPoints = _HitPoints;
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << " ClapTrap Copy constructor called" << std::endl;
	*this = (ClapTrap &)copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << " ClapTrap Copy Assignment contrusctor called" << std::endl;
	if (this != &copy)
	{
		// name is not copied
		this->_HitPoints = copy._HitPoints;
		this->_EnergyPoints = copy._EnergyPoints;
		this->_AttackDamage = copy._AttackDamage;
		this->_MaxHitPoints = copy._MaxHitPoints;
	}
	return (*this);
} 

void	ClapTrap::attack(const std::string& target)
{
	if (_HitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is dead. Could not attack" << std::endl;
		return ;
	}
	if (_EnergyPoints <= 0 )
	{
		std::cout << "ClapTrap " << _name << " has no energy points left. Could not attack" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target <<  " causing " << _AttackDamage << " points of damage!" << std::endl;
	_EnergyPoints -= 1;
	std::cout << "1 energy point spent on attacking" << std::endl;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_HitPoints < amount)
		_HitPoints = 0;
	else
		_HitPoints -= amount;
	std::cout << "ClapTrap " << _name << " was damaged by " << amount << ". Now has "<< _HitPoints << " Hit points(health) left" << std::endl;
	return ;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_EnergyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy points left. Could not repair" << std::endl;
		return ;
	}
	else if (_HitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is dead. Could not be repaired" << std::endl;
		return ;
	}
	if (_HitPoints + amount > _MaxHitPoints)
		_HitPoints = _MaxHitPoints;
	else
		_HitPoints += amount;
	_EnergyPoints -= 1;

	std::cout << "ClapTrap " << _name <<  " repaired " << amount << " of Hit Points(health). Now has "<< _HitPoints << " Hit points(health) left" << std::endl;
	std::cout << "1 energy point spent on repairing. Now has " << _EnergyPoints << " left" << std::endl;
}

std::string ClapTrap::getName()
{
	return (_name);
}

unsigned int	ClapTrap::getHitPoints()
{
	return (_HitPoints);
}

unsigned int	ClapTrap::getEnergyPoints()
{
	return (_EnergyPoints);
}

unsigned int	ClapTrap::getAttackDamage()
{
	return (_AttackDamage);
}

void	ClapTrap::setHitPoints(unsigned int amount)
{
	_HitPoints = amount;
}

void	ClapTrap::setEnergyPoints(unsigned int amount)
{
	_EnergyPoints = amount;
}

void	ClapTrap::setAttackDamage(unsigned int amount)
{
	_AttackDamage = amount;
}