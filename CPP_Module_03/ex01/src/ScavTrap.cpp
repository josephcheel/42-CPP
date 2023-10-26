#include "ScavTrap.hpp"
#include "ClapTrap.hpp"


ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) 
{	
	_name = name;
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << "ScavTrap default construtor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScapTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & copy)
{
	std::cout << "ScavTrap destructor called" << std::endl;
	*this = (ScavTrap &)copy;
}

ScavTrap &ScavTrap::operator=(ScavTrap &copy)
{
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_HitPoints = copy._HitPoints;
		this->_EnergyPoints = copy._EnergyPoints;
		this->_AttackDamage = copy._AttackDamage;
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (_EnergyPoints <= 0)
		return ;
	std::cout << "ScavTrap " << _name << " attacks " << target <<  " causing " << _AttackDamage << " points of damage!";
	_EnergyPoints -= 1;
	std::cout << " and Spent 1 energy point on Attack" << std::endl;
}	


void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now on Gate keeper mode" << std::endl;
}