#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	_HitPoints = 10;
	_EnergyPoints = 10;
	_AttackDamage = 0;
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
ClapTrap &ClapTrap::operator=(ClapTrap &copy)
{
	if (this != &copy)
	{
		const_cast<std::string&>(this->_name) = copy._name;
		this->_HitPoints = copy._HitPoints;
		this->_EnergyPoints = copy._EnergyPoints;
		this->_AttackDamage = copy._AttackDamage;
	}
	return (*this);
} 

void	ClapTrap::attack(const std::string& target)
{
	if (_EnergyPoints <= 0)
		return ;
	std::cout << "ClapTrap " << _name << " attacks " << target <<  " causing " << _AttackDamage << " points of damage!";
	_EnergyPoints -= 1;
	std::cout << " and Spent 1 energy point on Attack" << std::endl;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_HitPoints < amount)
		_HitPoints = 0;
	else
		_HitPoints -= amount;
	std::cout << "ClapTrap " << _name << " was damaged by" << amount << ". Now is "<< _HitPoints << " of Health left" << std::endl;
	return ;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_EnergyPoints <= 0)
		return ;
	_HitPoints += amount;
	_EnergyPoints -= 1;

	std::cout << "ClapTrap " << _name <<  " Repaired +" << amount << " of Health. Now ";
	std::cout << _name << " has " << _HitPoints << " points of health and" << " Spent 1 energy point on Repairing" << std::endl;
	
}

std::string ClapTrap::getName()
{
	return (this->_name);
}
unsigned int ClapTrap::getHitPoints()
{
	return (this->_HitPoints);
}
unsigned int ClapTrap::getEnergyPoints()
{
	return (this->_EnergyPoints);
}
unsigned int ClapTrap::getAttackDamage()
{
	return (this->_AttackDamage);
}