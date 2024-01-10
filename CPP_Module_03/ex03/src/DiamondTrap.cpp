#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
{
	_name =  "";
	_HitPoints = FragTrap::_HitPoints;
	_EnergyPoints = ScavTrap::_EnergyPoints;
	_AttackDamage = FragTrap::_AttackDamage;
	std::cout << "DiamondTrap default constructor was called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const &name) //: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	
	
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	_HitPoints = FragTrap::_HitPoints;
	_EnergyPoints = ScavTrap::_EnergyPoints;
	_AttackDamage = FragTrap::_AttackDamage;
	std::cout << "DiamondTrap Constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap &copy)
{
	*this = copy;
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap &copy)
{
	if (this != &copy)
	{
		ClapTrap::_name = copy._name + "_clap_name";
		_name = copy._name;
		_HitPoints = copy.FragTrap::_HitPoints;
		_EnergyPoints = copy.ScavTrap::_EnergyPoints;
		_AttackDamage = copy.FragTrap::_AttackDamage;
	}
	return (*this);
}
void DiamondTrap::whoAmI()
{	
	std::cout << "DiamondTrap name: " << _name << "; ClapTrap name: " << ClapTrap::_name << ";" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}
