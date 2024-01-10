#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "Color.hpp"


ScavTrap::ScavTrap() : ClapTrap("")
{
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << CYAN << "ScavTrap Default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << CYAN << "ScavTrap Construtor called" << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << YELLOW << "ScapTrap destructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = (ScavTrap &)copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy) 
{
	std::cout <<  MAGENTA << "ScavTrap copy assignment operator called" << RESET << std::endl;
	if (this != &copy)
	{
		_name = copy._name;
		_HitPoints = copy._HitPoints;
		_EnergyPoints = copy._EnergyPoints;
		_AttackDamage = copy._AttackDamage;
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (_HitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " is dead. Could not attack" << std::endl;
		return ;
	}
	if (_EnergyPoints <= 0 )
	{
		std::cout << "ScavTrap " << _name << " has no energy points left. Could not attack" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target <<  " causing " << _AttackDamage << " points of damage!" << std::endl;
	_EnergyPoints -= 1;
	std::cout << WHITE << "1 energy point spent on attacking" << std::endl;
}	


void ScavTrap::guardGate()
{
	std::cout << GREEN << "ScavTrap " << _name << " is now on Gate keeper mode" << RESET << std::endl;
}