#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << " FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << " FragTrap constructor called" << std::endl;
	this->_name = name;
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << " ScapTrap destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{	
	std::cout << " FragTrap Copy constructor called" << std::endl;
	*this = (FragTrap &)copy;
}
FragTrap &FragTrap::operator=(FragTrap &copy)
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

void FragTrap::highFivesGuys(void)
{
	std::cout << "Give me some high fives, guys!" << std::endl;
}