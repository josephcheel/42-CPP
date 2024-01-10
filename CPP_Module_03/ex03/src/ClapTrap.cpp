#include "ClapTrap.hpp"
#include "Color.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << CYAN << "ClapTrap Constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap() : _name(""), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << CYAN << "ClapTrap Default constructor called" << RESET << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "ClapTrap Destructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << BLUE << "ClapTrap Copy constructor called" << RESET << std::endl;
	*this = (ClapTrap &)copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << MAGENTA << "ClapTrap Copy Assignment constructor called" << RESET << std::endl;
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_HitPoints = copy._HitPoints;
		this->_EnergyPoints = copy._EnergyPoints;
		this->_AttackDamage = copy._AttackDamage;
	}
	return (*this);
} 

void	ClapTrap::attack(const std::string& target)
{
	if (_HitPoints <= 0)
	{
		std::cout << YELLOW << "ClapTrap " << _name << " is dead. Could not attack" << RESET << std::endl;
		return ;
	}
	if (_EnergyPoints <= 0 )
	{
		std::cout <<  YELLOW << "ClapTrap " << _name << " has no energy points left. Could not attack" << RESET << std::endl;
		return ;
	}
	std::cout <<  YELLOW << "ClapTrap " << _name << " attacks " << target <<  " causing " << _AttackDamage << " points of damage!" << RESET << std::endl;
	_EnergyPoints -= 1;
	std::cout <<  YELLOW << "1 energy point spent on attacking" << RESET << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_HitPoints < amount)
		_HitPoints = 0;
	else
		_HitPoints -= amount;
	std::cout << RED << "ClapTrap " << _name << " was damaged by " << amount << ". Now has "<< _HitPoints << " Hit points(health) left" << RESET << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_EnergyPoints <= 0)
	{
		std::cout << CYAN << "ClapTrap " << _name << " has no energy points left. Could not be repaired" << RESET << std::endl;
		return ;
	}
	else if (_HitPoints <= 0)
	{
		std::cout << CYAN << "ClapTrap " << _name << " is dead. Could not be repaired" << RESET << std::endl;
		return ;
	}

	_HitPoints += amount;
	_EnergyPoints -= 1;

	std::cout << CYAN << "ClapTrap " << _name <<  " repaired " << amount << " of Hit Points(health). Now has "<< _HitPoints << " Hit points(health) left" << std::endl;
	std::cout << CYAN << "1 energy point spent on repairing. Now has " << _EnergyPoints << " left" << RESET << std::endl;
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
