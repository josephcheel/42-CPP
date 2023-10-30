#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
{
	std::cout << "DiamondTrap default constructor was called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string const &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << "DiamondTrap Constructor called" << std::endl;
	_name = name;
	_name = name;
	_HitPoints = FragTrap::_HitPoints;
	_EnergyPoints = ScavTrap::_EnergyPoints;
	_AttackDamage = FragTrap::_AttackDamage;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}
DiamondTrap::DiamondTrap(DiamondTrap &copy)
{
	*this = copy;
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}
DiamondTrap& DiamondTrap::operator=(DiamondTrap &copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_HitPoints =  copy._HitPoints;
		_EnergyPoints = copy._EnergyPoints;
		_AttackDamage = copy._AttackDamage;
	}
	return (*this);
}
void DiamondTrap::whoAmI()
{	
	std::cout << "DiamondTrap name: " << _name << " ClapTrap name: " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}
