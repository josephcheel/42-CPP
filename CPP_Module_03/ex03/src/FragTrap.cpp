#include "FragTrap.hpp"
#include "Color.hpp"

FragTrap::FragTrap()
{
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
	std::cout << CYAN << "FragTrap Default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << CYAN << "FragTrap constructor called" << RESET << std::endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{	
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = (FragTrap &)copy;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	std::cout << MAGENTA << "FragTrap copy Assignment operator called" << RESET << std::endl;
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
	std::cout << GREEN << "Give me some high fives, guys!" << RESET << std::endl;
}