#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	_HitPoints = 10;
	_EnergyPoints = 10;
	_AttackDamage = 0;
	std::cout << "Default constructor called" << std::endl;

}
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
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
	std::cout << "ClapTrap " << _name << " was damaged by " << amount << ". Now has "<< _HitPoints << " of Health left" << std::endl;
	return ;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_EnergyPoints <= 0)
		return ;
	if (_HitPoints + amount > 10)
		_HitPoints = 10;
	else
		_HitPoints += amount;
	_EnergyPoints -= 1;

	std::cout << "ClapTrap " << _name <<  " Repaired +" << amount << " of Health. Now ";
	std::cout << _name << " has " << _HitPoints << " points of health but" << " Spent 1 energy point on Repairing" << std::endl;
	
}